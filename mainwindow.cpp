#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_feedpage.h"
#include "QMessageBox"
#include "filemanager.h"
#include <QInputDialog>
#include "analytics.h"
MainWindow::MainWindow(User user,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentUser(user)
    , reportCount(0)
    , encryptionKey("OutageLink2025")
{
    ui->setupUi(this);

    fm.loadReports(reports, reportCount, encryptionKey.toUtf8().constData());
    fm.loadResources(resources, resCount);
    fm.loadRequests(requests, requestCount);
    fm.loadAnnouncements(announcements, announceCount);
    connect(ui->FeedPageWidget, &FeedPage::editRequested, this, &MainWindow::handleEditReport);
    connect(ui->FeedPageWidget, &FeedPage::deleteRequested, this, &MainWindow::handleDeleteReport);

    ui->FeedPageWidget->displayReports(
        reports,
        reportCount,
        currentUser.username,
        fm
        );
    // 4) Initialize the OutagePage so it can submit new reports
    ui->OutagePageWidget->setContext(
        currentUser.username,
        fm,
        reports,
        &reportCount
        );
    ui->ResourcePageWidget->setContext(
        currentUser.username,
        fm,
        resources,
        &resCount
        );
    ui->RequestPageWidget->setContext(
        currentUser.username,
        fm,
        requests,
        &requestCount
        );

    ui->loginLabel->setText("Login as: "+currentUser.username);
    plotOutagesPerDay(ui->customPlotOutages, reports, reportCount);
    plotOutageTypes   (ui->customPlotTypes,   reports, reportCount);
    plotResourceUsage (ui->customPlotResources, resources, resCount);


    // If there’s at least one, start blinking
    if (announceCount > 0) {
        blinkTimer = new QTimer(this);
        blinkTimer->setInterval(500); // blink every 500ms
        connect(blinkTimer, &QTimer::timeout, this, [&](){
            blinkState = !blinkState;
            ui->btnAnnounce->setVisible(blinkState);
        });
        blinkTimer->start();
    }

    // ──────────────────────────────────────────────────────────
    // STEP 5: Wire up the server‑backed sync via NetworkClient
    // ──────────────────────────────────────────────────────────

    QString brokerUrl = "http://127.0.0.1:3000";   // fallback default

    QFile f("server.conf");
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&f);
        QString line = in.readLine().trimmed();
        if (!line.isEmpty())
            brokerUrl = line;
        f.close();
    }

    // 5.2 Create the client, pointing at whatever URL we loaded
    client = new NetworkClient(brokerUrl, this);


    // 5.2 When the broker returns the full list, overwrite our local arrays + refresh UI:

    connect(client, &NetworkClient::reportsFetched, this, [&](auto vec){
        reportCount = vec.size();
        for (int i = 0; i < reportCount; ++i)
            reports[i] = vec[i];
        ui->FeedPageWidget->displayReports(
            reports, reportCount, currentUser.username, fm);
        plotOutagesPerDay(ui->customPlotOutages, reports, reportCount);
        plotOutageTypes   (ui->customPlotTypes,   reports, reportCount);
    });

    connect(client, &NetworkClient::resourcesFetched, this, [&](auto vec){
        resCount = vec.size();
        for (int i = 0; i < resCount; ++i)
            resources[i] = vec[i];
        ui->ResourcePageWidget->displayResources();
        plotResourceUsage(ui->customPlotResources, resources, resCount);
    });

    connect(client, &NetworkClient::requestsFetched, this, [&](auto vec){
        requestCount = vec.size();
        for (int i = 0; i < requestCount; ++i)
            requests[i] = vec[i];
        ui->RequestPageWidget->displayRequests();
    });

    connect(client, &NetworkClient::announcementsFetched, this, [&](auto vec){
        announceCount = vec.size();
        for (int i = 0; i < announceCount; ++i)
            announcements[i] = vec[i];
        // restart blink if needed:
        if (announceCount > 0 && blinkTimer) blinkTimer->start();
    });

    // 5.3 Error reporting
    connect(client, &NetworkClient::networkError, this, [&](const QString &err){
        statusBar()->showMessage("Network error: " + err, 5000);
    });

    // 5.4 Fetch all four lists from the broker:
    client->fetchReports();
    client->fetchResources();
    client->fetchRequests();
    client->fetchAnnouncements();
    // ──────────────────────────────────────────────────────────

    // ──────────────────────────────────────────────────────────
    // STEP 6: Hook page‑level “submitted” signals into local save + network
    // ──────────────────────────────────────────────────────────

    // When OutagePage emits reportSubmitted, save locally and push to broker:
    connect(ui->OutagePageWidget, &OutagePage::reportSubmitted,
            this, [&](const Report &r){
                // 1) append & save locally
                reports[reportCount++] = r;
                fm.saveReports(reports, reportCount, encryptionKey.toUtf8().constData());
                // 2) push to server
                client->postReport(r);
                // 3) update UI & charts
                ui->FeedPageWidget->displayReports(
                    reports, reportCount, currentUser.username, fm);
                plotOutagesPerDay(ui->customPlotOutages, reports, reportCount);
                plotOutageTypes   (ui->customPlotTypes,   reports, reportCount);
            });

    // When ResourcePage emits resourceSubmitted:
    connect(ui->ResourcePageWidget, &ResourcePage::resourceSubmitted,
            this, [&](const Resource &r){
                resources[resCount++] = r;
                fm.saveResources(resources, resCount);
                client->postResource(r);
                ui->ResourcePageWidget->displayResources();
                plotResourceUsage(ui->customPlotResources, resources, resCount);
            });

    // When RequestPage emits requestSubmitted:
    connect(ui->RequestPageWidget, &RequestPage::requestSubmitted,
            this, [&](const Request &r){
                requests[requestCount++] = r;
                fm.saveRequests(requests, requestCount);
                client->postRequest(r);
                ui->RequestPageWidget->displayRequests();
            });
    // ──────────────────────────────────────────────────────────

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOutage_clicked()
{
    ui->centralStack->setCurrentIndex(1);
}


void MainWindow::on_btnfeed_clicked()
{
    ui->FeedPageWidget->displayReports(
        reports,
        reportCount,
        currentUser.username,
        fm
        );

    ui->centralStack->setCurrentIndex(0);
}


void MainWindow::on_btnResource_clicked()
{
    ui->centralStack->setCurrentIndex(2);
    ui->ResourcePageWidget->displayResources();
}


void MainWindow::on_btnRequest_clicked()
{
    ui->centralStack->setCurrentIndex(3);
    ui->RequestPageWidget->displayRequests();
}

void MainWindow::handleEditReport(int index) {
    // Load the report at `index`
    Report& r = reports[index];

    //Open dialog to edit message
    bool ok;
    QString newMsg = QInputDialog::getText(
        this, "Edit Message", "New Message:", QLineEdit::Normal,
        r.message, &ok);

    if (ok && !newMsg.trimmed().isEmpty()) {
        r.message = newMsg.trimmed();
        fm.saveReports(reports, reportCount, encryptionKey.toUtf8().constData());
        ui->FeedPageWidget->displayReports(reports, reportCount, currentUser.username, fm);
    }
}

void MainWindow::handleDeleteReport(int index) {
    if (QMessageBox::question(this, "Delete Report",
                              "Are you sure you want to delete this report?") == QMessageBox::Yes) {

        // Shift left to remove report
        for (int i = index; i < reportCount - 1; ++i) {
            reports[i] = reports[i + 1];
        }
        reportCount--;

        fm.saveReports(reports, reportCount, encryptionKey.toUtf8().constData());
        ui->FeedPageWidget->displayReports(reports, reportCount, currentUser.username, fm);
    }
}


void MainWindow::on_btnAnalytics_clicked()
{
    ui->centralStack->setCurrentIndex(4);
    plotOutagesPerDay(ui->customPlotOutages, reports, reportCount);
    plotOutageTypes   (ui->customPlotTypes,   reports, reportCount);
    plotResourceUsage (ui->customPlotResources, resources, resCount);
}


void MainWindow::on_btnAnnounce_clicked()
{
    if (blinkTimer) {
        blinkTimer->stop();
        ui->btnAnnounce->setVisible(true);
    }

    // Build a simple dialog
    QDialog dlg(this);
    dlg.setObjectName("announceDialog");
    dlg.setWindowTitle("Announcements");
    QVBoxLayout *lay = new QVBoxLayout(&dlg);


    // List each announcement
    for (int i = 0; i < announceCount; ++i) {
        auto &a = announcements[i];
        QString header = QString("[%1] by %2")
                             .arg(a.timestamp.toString("yyyy‑MM‑dd hh:mm"))
                             .arg(a.postedBy);
        QLabel *lbl = new QLabel(header + "\n" + a.text, &dlg);
        lbl->setObjectName("announceLabel");
        lbl->setWordWrap(true);
        lay->addWidget(lbl);

        // If current user is admin, add a delete button
        if (currentUser.username == "admin") {
            QPushButton *del = new QPushButton("Delete", &dlg);
            del->setObjectName("announceDeleteBtn");
            int index = i;

            lay->addWidget(del);

            connect(del, &QPushButton::clicked, this, [=, &dlg, this]() {
                int btn = QMessageBox::question(this, "Confirm", "Delete this announcement?");
                if (btn == QMessageBox::Yes) {
                    // delete from array
                    for (int j = index; j + 1 < announceCount; ++j)
                        announcements[j] = announcements[j + 1];
                    --announceCount;
                    fm.saveAnnouncements(announcements, announceCount);

                    dlg.accept();              // close old dialog
                    on_btnAnnounce_clicked();  // reopen updated dialog
                }
            });
        }
        lay->addSpacing(10);
    }

    // Allow admin to post a new announcement
    if (currentUser.username == "admin") {
        QPushButton *add = new QPushButton("New Announcement", &dlg);
        add->setObjectName("announceAddBtn");
        lay->addWidget(add);
        connect(add, &QPushButton::clicked, this, [&](){
            if (announceCount >= 5) {
                QMessageBox::information(
                    &dlg,
                    "Limit Reached",
                    "You can only have up to 5 announcements at a time.");
                return;
            }

            bool ok;
            QString text = QInputDialog::getMultiLineText(
                this, "New Announcement",
                "Message:", QString(), &ok);
            if (!ok || text.trimmed().isEmpty()) return;
            // append to array
            announcements[announceCount] = {
                text.trimmed(),
                QDateTime::currentDateTime(),
                currentUser.username
            };
            ++announceCount;
            fm.saveAnnouncements(announcements, announceCount);
            dlg.accept();
            on_btnAnnounce_clicked();  // reopen with updated list
        });
    }
dlg.setStyleSheet(R"(
  /* Dialog background and border */
  QDialog#announceDialog {
    background: #fefefe;
    border: 1px solid #ccc;
    border-radius: 8px;
    padding: 16px;
  }

  /* Announcement text labels */
  QLabel#announceLabel {
    background: #fff;
    color: #333;
    font-size: 14px;
    padding: 8px;
    border: 1px solid #ddd;
    border-radius: 4px;
    margin-bottom: 8px;
  }
 /* Delete buttons */
  QPushButton#announceDeleteBtn {
    background-color: #e74c3c;
    color: white;
    border: none;
    border-radius: 4px;
    padding: 4px 8px;
    font-size: 12px;
  }
  QPushButton#announceDeleteBtn:hover {
    background-color: #c0392b;
  }

  /* “New Announcement” button */
  QPushButton#announceAddBtn {
    background-color: #27ae60;
    color: white;
    border: none;
    border-radius: 4px;
    padding: 6px 12px;
    font-size: 13px;
    margin-top: 12px;
  }
  QPushButton#announceAddBtn:hover {
    background-color: #1e8449;
  }
)");
    dlg.exec();
}

