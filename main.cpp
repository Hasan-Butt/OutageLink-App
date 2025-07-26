#include "mainwindow.h"
#include "logindialog.h"
#include "data.h"
#include <QApplication>
#include <QDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Show the login dialog first
    LoginDialog login;
    login.ensureDefaultAdminUser();
    if (login.exec() != QDialog::Accepted) {
        return 0;
    }
    User currentUser;
    currentUser.username = login.getUsername();  // From LoginDialog
    MainWindow w(currentUser);
    w.show();
    return a.exec();
}
