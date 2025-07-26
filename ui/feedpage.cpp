#include "feedpage.h"
#include "ui_feedpage.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include "filemanager.h"
#include <QSpacerItem>
FeedPage::FeedPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FeedPage)
    , m_reports(nullptr)
    , m_count(0)
    , m_fileManager(nullptr)
{
    ui->setupUi(this);
    setObjectName("FeedPageWidget");
}

FeedPage::~FeedPage()
{
    clearFeed();
    delete ui;
}

void FeedPage::on_editBtn_clicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    int idx = btn->property("reportIndex").toInt();
    emit editRequested(idx); // Signal to main window
}


void FeedPage::on_deleteBtn_clicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    int idx = btn->property("reportIndex").toInt();
    emit deleteRequested(idx); // Signal to main window
}

void FeedPage::clearFeed() {
    QLayoutItem* child;
    while ((child = ui->verticalLayout_2->takeAt(0)) != nullptr) {
        delete child->widget(); // delete the report card widget
        delete child;           // delete the layout item
    }
}

QWidget* FeedPage::createReportCard(int index) {
    const Report& r = m_reports[index];

    // Parent it to the scroll area contents
    QFrame* frame = new QFrame(ui->scrollAreaWidgetContents);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);

    frame->setStyleSheet(R"(
    QFrame {
        background-color: white;
        border: 1px solid #cccccc;
        border-radius: 12px;
        padding: 8px;
    }
    QFrame QLabel {
        background-color: transparent;
        border-radius: 6px;       /* if you want each label rounded */
        padding: 2px;
    }
)");

    // Use a layout on the frame
    QVBoxLayout* layout = new QVBoxLayout(frame);
    layout->setContentsMargins(8,8,8,8);
    layout->setSpacing(6);

    // Full strings, not single chars:
    QLabel* lblTitle = new QLabel(QString("Type: %1").arg(r.type), frame);
    layout->addWidget(lblTitle);

    QLabel* lblArea  = new QLabel(QString("📍 Location: %1").arg(r.area), frame);
    layout->addWidget(lblArea);

    QLabel* lblMsg   = new QLabel(QString("💬 Message: %1").arg(r.message), frame);
    layout->addWidget(lblMsg);

    QLabel* lblTime  = new QLabel(
        QString("📅 Date & Time: %1-%2-%3 %4:%5")
            .arg(r.day,   2, 10, QChar('0'))
            .arg(r.month, 2, 10, QChar('0'))
            .arg(r.year)
            .arg(r.hour,  2, 10, QChar('0'))
            .arg(r.minute,2, 10, QChar('0')),
        frame);
    layout->addWidget(lblTime);

    QLabel* lblBy    = new QLabel(QString("✍️ Submitted By: %1").arg(r.submittedBy), frame);
    layout->addWidget(lblBy);

    // Edit/Delete buttons if allowed
    if (r.submittedBy == m_currentUser || m_currentUser == "admin") {
        QHBoxLayout* btnLayout = new QHBoxLayout;
        btnLayout->addStretch();

        auto makeBtn = [&](const QString& text, auto slot){
            QPushButton* btn = new QPushButton(text, frame);
            btn->setProperty("reportIndex", index);
            connect(btn, &QPushButton::clicked, this, slot);
            btnLayout->addWidget(btn);
        };
        makeBtn("Edit",   &FeedPage::on_editBtn_clicked);
        makeBtn("Delete", &FeedPage::on_deleteBtn_clicked);

        layout->addLayout(btnLayout);
    }

    return frame;
}

void FeedPage::displayReports(Report* reports, int count, const QString& currentUser, fileManager& fm) {
    clearFeed();
    m_reports = reports;
    m_count = count;
    m_currentUser = currentUser;
    m_fileManager = &fm;

    for (int i = 0; i < m_count; ++i) {

        if (m_filterType != "All" && reports[i].type != m_filterType)
            continue;
        QWidget* card = createReportCard(i);
        ui->verticalLayout_2->addWidget(card);
    }
    ui->verticalLayout_2->addStretch(); // Pushes cards to the top
}


void FeedPage::on_comboFilter_currentTextChanged(const QString &arg1)
{
    m_filterType = arg1;
    // Simply re‑display with the new filter
    if (m_reports && m_fileManager) {
        displayReports(m_reports, m_count, m_currentUser, *m_fileManager);
    }
}

