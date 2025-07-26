#include "resourcepage.h"
#include "ui_resourcepage.h"
#include <QDate>
#include <QMessageBox>
#include <QInputDialog>
#include <QHBoxLayout>
ResourcePage::ResourcePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResourcePage)
{
    ui->setupUi(this);
}

ResourcePage::~ResourcePage()
{
    delete ui;
}
void ResourcePage::setContext(const QString& currentUser,
                              fileManager& fm,
                              Resource* resources,
                              int* resourceCount)
{
    m_currentUser   = currentUser;
    m_fileManager   = &fm;
    m_resources     = resources;
    m_resourceCount = resourceCount;

    // Load existing resources and display
    m_fileManager->loadResources(m_resources, *m_resourceCount);
    displayResources();
}
void ResourcePage::on_btnSubmit_clicked()
{
    const QString item         = ui->editItem->text().trimmed();
    const QString availability = ui->editAvailability->text().trimmed();

    if (item.isEmpty() || availability.isEmpty()) {
        ui->lblStatus->setText("❗ Please enter both item and availability.");
        return;
    }

    // 2) Build a new Resource
    Resource r;
    r.item         = item;
    r.owner        = m_currentUser;
    r.availability = availability;

    // 3) Emit it
    emit resourceSubmitted(r);

    // 4) Update UI
    ui->editItem->clear();
    ui->editAvailability->clear();
    ui->lblStatus->setText("✅ Resource submitted!");
}
void ResourcePage::clearTable()
{
    ui->tblResources->setRowCount(0);
}
void ResourcePage::displayResources()
{
    clearTable();
    int rows = *m_resourceCount;
    ui->tblResources->setRowCount(rows);

    for (int i = 0; i < rows; ++i) {
        const Resource& r = m_resources[i];

        ui->tblResources->setItem(i, 0, new QTableWidgetItem(r.item));
        ui->tblResources->setItem(i, 1, new QTableWidgetItem(r.owner));
        ui->tblResources->setItem(i, 2, new QTableWidgetItem(r.availability));

        // Status column
        QString status = r.isAssigned
                             ? QString("Checked out to %1\nDue: %2")
                                   .arg(r.assignedTo)
                                   .arg(r.dueDateTime.toString("dd-MM-yyyy hh:mm"))
                             : "Available";
        auto *statusItem = new QTableWidgetItem(status);
        statusItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        ui->tblResources->setItem(i, 3, statusItem);
        ui->tblResources->setItem(i, 3, new QTableWidgetItem(status));

        // Build action buttons
        QWidget* actionWidget = new QWidget;
        QHBoxLayout* hl = new QHBoxLayout(actionWidget);
        hl->setContentsMargins(0,0,0,0);

        // Assign/Return button
        QPushButton* btnAssign = new QPushButton(
            r.isAssigned ? "Return" : "Assign", actionWidget);
        btnAssign->setProperty("row", i);

        connect(btnAssign, &QPushButton::clicked,
                this, &ResourcePage::handleAssignReturn);
        hl->addWidget(btnAssign);

        // Delete button
        QPushButton* btnDel = new QPushButton("Delete", actionWidget);
        btnDel->setProperty("row", i);

        connect(btnDel, &QPushButton::clicked,
                this, &ResourcePage::handleDelete);
        hl->addWidget(btnDel);
        QString btnStyle = R"(
    QPushButton {
        background-color: #5A9;      /* teal-ish */
        color: white;
        border: none;
        border-radius: 6px;
        padding: 4px;
        font: 12px \"Segoe UI\";
    }
    QPushButton:hover {
        background-color: #6BA;      /* lighter on hover */
    }
    QPushButton:pressed {
        background-color: #498;      /* darker on press */
    }
)";

        btnAssign->setStyleSheet(btnStyle);
        btnDel   ->setStyleSheet(R"(
    QPushButton {
        background-color: #E55;      /* red-ish */
        color: white;
        border: none;
        border-radius: 6px;
        padding: 4px;
        font: 12px \"Segoe UI\";
    }
    QPushButton:hover {
        background-color: #F66;
    }
    QPushButton:pressed {
        background-color: #C44;
    }
)");
        ui->tblResources->setCellWidget(i, 4, actionWidget);

    }
    ui->tblResources->resizeRowsToContents();
}
void ResourcePage::handleAssignReturn() {
    auto btn = qobject_cast<QPushButton*>(sender());
    int i = btn->property("row").toInt();
    auto& r = m_resources[i];

    if (r.owner != m_currentUser && m_currentUser != "admin") {
        QMessageBox::warning(this, "Permission Denied",
                             "⚠️ Only the owner or admin can assign or return this resource.");
        return;
    }
    if (!r.isAssigned) {
        // Assign: prompt for who and due date
        bool ok;
        QString who = QInputDialog::getText(
            this, "Assign Resource", "Assign to:", QLineEdit::Normal,
            "", &ok);
        if (!ok || who.isEmpty()) return;

        QDateTime due = QDateTime::fromString(
            QInputDialog::getText(
                this, "Due DateTime",
                "Enter due (YYYY-MM-DD hh:mm):",
                QLineEdit::Normal,
                QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm"),
                &ok),
            "yyyy-MM-dd hh:mm");
        if (!ok) return;

        r.isAssigned = true;
        r.assignedTo = who;
        r.dueDateTime = due;
    } else {
        // Return
        r.isAssigned = false;
        r.assignedTo.clear();
        r.dueDateTime = QDateTime();
    }

    m_fileManager->saveResources(m_resources, *m_resourceCount);
    displayResources();
}
void ResourcePage::handleDelete() {
    auto btn = qobject_cast<QPushButton*>(sender());
    int i = btn->property("row").toInt();
    auto& r = m_resources[i];

    // ✅ Check if user is owner or admin
    if (r.owner != m_currentUser && m_currentUser != "admin") {
        QMessageBox::warning(this, "Permission Denied",
                             "⚠️ Only the owner or admin can delete this resource.");
        return;
    }
    if (QMessageBox::question(
            this, "Delete Resource",
            "Delete this resource?") != QMessageBox::Yes) return;

    // Remove from array
    for (int j = i; j < *m_resourceCount - 1; ++j)
        m_resources[j] = m_resources[j+1];
    (*m_resourceCount)--;

    m_fileManager->saveResources(m_resources, *m_resourceCount);
    displayResources();
}
