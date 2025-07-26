#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_feedpage.h"
#include "filemanager.h"
#include "data.h"
#include <QString>
#include "analytics.h"
#include "network.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(User user,QWidget *parent = nullptr);
    ~MainWindow();
    NetworkClient* client;

private slots:
    void on_btnOutage_clicked();

    void on_btnfeed_clicked();

    void on_btnResource_clicked();

    void on_btnRequest_clicked();

    void on_btnAnalytics_clicked();

    void on_btnAnnounce_clicked();

private:
    Ui::MainWindow *ui;
    User currentUser;

    Report reports[100];
    int reportCount = 0;
    Resource resources[50];
    int resCount = 0;
    Request requests[50];
    int requestCount = 0;
    QString encryptionKey = "your-default-key";
    fileManager fm;
    Announcement announcements[5];
    int announceCount = 0;
    QTimer* blinkTimer = nullptr;
    bool blinkState = false;
    void handleEditReport(int index);
    void handleDeleteReport(int index);
};
#endif // MAINWINDOW_H
