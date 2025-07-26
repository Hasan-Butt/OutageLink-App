#include "outagepage.h"
#include "ui_outagepage.h"
#include <QDateTime>
#include "network.h"
#include "mainwindow.h"
OutagePage::OutagePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OutagePage)
{
    ui->setupUi(this);
}

OutagePage::~OutagePage()
{
    delete ui;
}
void OutagePage::setContext(const QString &username,
                            fileManager &fm,
                            Report      *reports,
                            int         *reportCount)
{
    m_currentUser  = username;
    m_fileManager  = &fm;
    m_reports      = reports;
    m_reportCount  = reportCount;
}

void OutagePage::on_btnSubmit_clicked()
{

    const QString type = ui->cmbType->currentText();
    const QString area = ui->editArea->toPlainText().trimmed();
    const QString msg  = ui->editMessage->toPlainText().trimmed();

    if (type.isEmpty() || area.isEmpty()) {
        ui->lblStatus->setText("⚠ Type and area are required.");
        return;
    }

    // 2) Build a new Report struct
    Report r;
    r.type        = type;
    r.area        = area;
    r.message     = msg;
    r.submittedBy = m_currentUser;
    auto now = QDateTime::currentDateTime();
    r.day    = now.date().day();
    r.month  = now.date().month();
    r.year   = now.date().year();
    r.hour   = now.time().hour();
    r.minute = now.time().minute();

    // 3) Emit it—no local array
    emit reportSubmitted(r);

    // 4) Update the local page UI
    ui->lblStatus->setText("✔ Report submitted successfully!");
    ui->editArea->clear();
    ui->editMessage->clear();
}

