#include "requestpage.h"
#include "ui_requestpage.h"
#include <QHBoxLayout>
#include <QMessageBox>

RequestPage::RequestPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RequestPage)
{
    ui->setupUi(this);
    ui->tblRequests->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tblRequests->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
}

RequestPage::~RequestPage()
{
    delete ui;
}

void RequestPage::on_btnSubmit_clicked()
{
    const QString reqText = ui->editRequest->text().trimmed();
    const QString loc     = ui->editLocation->text().trimmed();

    if (reqText.isEmpty() || loc.isEmpty()) {
        ui->lblStatus->setText("❗ Please enter request and location.");
        return;
    }

    // 2) Build a new Request
    Request r;
    r.request  = reqText;
    r.name     = m_currentUser;
    r.location = loc;

    // 3) Emit it
    emit requestSubmitted(r);

    // 4) Update UI
    ui->editRequest->clear();
    ui->editLocation->clear();
    ui->lblStatus->setText("✅ Request submitted!");
}
void RequestPage::setContext(const QString& currentUser,
                             fileManager& fm,
                             Request* requests,
                             int* requestCount)
{
    m_currentUser  = currentUser;
    m_fileManager  = &fm;
    m_requests     = requests;
    m_requestCount = requestCount;

    // Load existing requests
    m_fileManager->loadRequests(m_requests, *m_requestCount);
    displayRequests();

}
void RequestPage::clearTable()
{
    ui->tblRequests->setRowCount(0);
}
void RequestPage::displayRequests()
{
    clearTable();
    int rows = *m_requestCount;
    ui->tblRequests->setRowCount(rows);

    for (int i = 0; i < rows; ++i) {
        const Request &r = m_requests[i];

        ui->tblRequests->setItem(i, 0, new QTableWidgetItem(r.request));
        ui->tblRequests->setItem(i, 1, new QTableWidgetItem(r.name));
        ui->tblRequests->setItem(i, 2, new QTableWidgetItem(r.location));

        // Action: Delete button
        QWidget* actionWidget = new QWidget;
        QHBoxLayout* hl = new QHBoxLayout(actionWidget);
        hl->setContentsMargins(0,0,0,0);

        QPushButton* btnDel = new QPushButton("Delete", actionWidget);
        btnDel->setProperty("row", i);
        connect(btnDel, &QPushButton::clicked,
                this, &RequestPage::handleDeleteRequest);
        hl->addWidget(btnDel);
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
        ui->tblRequests->setCellWidget(i, 3, actionWidget);
    }
    ui->tblRequests->resizeRowsToContents();
}
void RequestPage::handleDeleteRequest()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    int row = btn->property("row").toInt();
    auto& r = m_requests[row];
    if (r.name != m_currentUser && m_currentUser != "admin") {
        QMessageBox::warning(this, "Permission Denied",
                             "⚠️ Only the owner or admin delete this request.");
        return;
    }
    if (QMessageBox::question(this, "Delete Request",
                              "Are you sure you want to delete this request?")
        != QMessageBox::Yes) return;

    // Remove from array
    for (int j = row; j + 1 < *m_requestCount; ++j) {
        m_requests[j] = m_requests[j+1];
    }
    (*m_requestCount)--;

    // Persist and refresh
    m_fileManager->saveRequests(m_requests, *m_requestCount);
    displayRequests();
}
