#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QDialog>
#include <QCryptographicHash>
#include <QRandomGenerator>
#include "data.h"
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
     QString getUsername();
    void ensureDefaultAdminUser();

private slots:


    void on_loginButton_clicked();

    void on_calcelBtn_clicked();

    void on_signUpBtn_clicked();

private:
    Ui::LoginDialog *ui;
    QString m_username;
    QVector<User> users;
    QString generateSalt(int length = 8)const;
    QString hashPassword(const QString& password, const QString& salt)const;
    void saveUsers(const QVector<User>& users)const;
    QVector<User> loadUsers()const;
    QString getUserFilePath()const;

};

#endif // LOGINDIALOG_H
