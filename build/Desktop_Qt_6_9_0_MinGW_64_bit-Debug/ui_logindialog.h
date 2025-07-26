/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLineEdit *editUser;
    QLineEdit *editPass;
    QPushButton *loginButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *calcelBtn;
    QPushButton *signUpBtn;

    void setupUi(QWidget *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(800, 600);
        LoginDialog->setStyleSheet(QString::fromUtf8("#LoginDialog{\n"
" background-image: url(:/images/assets/loginbackground.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}"));
        editUser = new QLineEdit(LoginDialog);
        editUser->setObjectName("editUser");
        editUser->setGeometry(QRect(260, 241, 131, 20));
        editPass = new QLineEdit(LoginDialog);
        editPass->setObjectName("editPass");
        editPass->setGeometry(QRect(260, 294, 131, 21));
        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(270, 390, 91, 31));
        QFont font;
        font.setBold(true);
        loginButton->setFont(font);
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF; /* Dodger Blue */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:#63B8FF; \n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1874CD; /* Even darker on press */\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}"));
        label = new QLabel(LoginDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 20, 331, 61));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:20px;\n"
"color:blue;\n"
"}"));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 170, 331, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:13px;\n"
"background-color:#1E90FF;\n"
"color:white;\n"
"\n"
"}"));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 240, 81, 21));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:13px;\n"
"background:#1E90FF;\n"
"color:white;\n"
"}"));
        label_4 = new QLabel(LoginDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 294, 81, 21));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:13px;\n"
"background:#1E90FF;\n"
"color:white;\n"
"}"));
        calcelBtn = new QPushButton(LoginDialog);
        calcelBtn->setObjectName("calcelBtn");
        calcelBtn->setGeometry(QRect(480, 390, 91, 31));
        calcelBtn->setFont(font);
        calcelBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF; /* Dodger Blue */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:#63B8FF; \n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1874CD; /* Even darker on press */\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}"));
        signUpBtn = new QPushButton(LoginDialog);
        signUpBtn->setObjectName("signUpBtn");
        signUpBtn->setGeometry(QRect(377, 440, 91, 31));
        signUpBtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #1E90FF; /* Dodger Blue */\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:#63B8FF; \n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1874CD; /* Even darker on press */\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}"));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QWidget *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Form", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginDialog", "LOGIN", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "\360\237\224\214             OutageLink\n"
"Your Local Outage & Resource Hub ", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "Welcome! Please Login if you have already registered,\n"
"otherwise Sign Up to continue.", nullptr));
        label_3->setText(QCoreApplication::translate("LoginDialog", "User Name:", nullptr));
        label_4->setText(QCoreApplication::translate("LoginDialog", "Password:", nullptr));
        calcelBtn->setText(QCoreApplication::translate("LoginDialog", "Cancel", nullptr));
        signUpBtn->setText(QCoreApplication::translate("LoginDialog", "SignUP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
