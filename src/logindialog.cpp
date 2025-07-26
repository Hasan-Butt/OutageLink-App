#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent)
    :  QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    QDir().mkpath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    ensureDefaultAdminUser();



    users = loadUsers();
}


LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::getUsername(){
    return ui->editUser->text();
}
void LoginDialog::on_loginButton_clicked()
{
    QString username = ui->editUser->text();
    QString password = ui->editPass->text();

    for (const User& u : users) {
        if (u.username == username) {
            QString checkHash = hashPassword(password, u.salt);
            if (checkHash == u.hash) {
                m_username = username;
                accept();
                return;
            }
        }
    }

    QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
}


void LoginDialog::on_calcelBtn_clicked()
{
    reject();
}

QString LoginDialog::generateSalt(int length)const {
    const QString chars("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString salt;
    for (int i = 0; i < length; ++i)
        salt += chars[QRandomGenerator::global()->bounded(chars.size())];
    return salt;
}

QString LoginDialog::hashPassword(const QString& password, const QString& salt)const {
    QByteArray data = (salt + password).toUtf8();
    auto hash = QCryptographicHash::hash(data, QCryptographicHash::Sha256);
    return hash.toHex();
}


QString LoginDialog::getUserFilePath()const {
    return QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/users.json";
}

QVector<User> LoginDialog::loadUsers()const {
    QVector<User> users;
    QFile file(getUserFilePath());
    if (!file.open(QIODevice::ReadOnly)) return users;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    for (const QJsonValue& val : doc.array()) {
        QJsonObject obj = val.toObject();
        users.append({
            obj["username"].toString(),
            obj["salt"].toString(),
            obj["hash"].toString(),
        });
    }
    return users;
}

void LoginDialog::saveUsers(const QVector<User>& users)const {
    QJsonArray arr;
    for (const User& u : users) {
        QJsonObject obj;
        obj["username"] = u.username;
        obj["salt"] = u.salt;
        obj["hash"] = u.hash;
        arr.append(obj);
    }
    QFile file(getUserFilePath());
    file.open(QIODevice::WriteOnly);
    file.write(QJsonDocument(arr).toJson());
}


void LoginDialog::on_signUpBtn_clicked()
{
    QString username = ui->editUser->text().trimmed();
    QString password = ui->editPass->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Signup Error", "Username and password required.");
        return;
    }

    // Check username uniqueness
    for (const User& u : users) {
        if (u.username == username) {
            QMessageBox::warning(this, "Signup Error",
                                 QString("The username \"%1\" is already taken.").arg(username));
            return;
        }
    }
    // Password must not match any existing password
    for (const User& u : users) {
        if (hashPassword(password, u.salt) == u.hash) {
            QMessageBox::warning(this, "Signup Error", "Password already used by another user.");
            return;
        }
    }
    QString salt = generateSalt();
    QString hash = hashPassword(password, salt);
    users.append({username, salt, hash});
    saveUsers(users);

    QMessageBox::information(this, "Signup Success", "Account created. You can now login.");
}
void LoginDialog::ensureDefaultAdminUser() {
    auto list = loadUsers();
    for (auto& u : list) {
        if (u.username == "admin")
            return;  // already exists
    }
    // Create default admin
    QString salt = generateSalt();
    QString hash = hashPassword("220055", salt);
    list.append({ "admin", salt, hash });
    saveUsers(list);
}
