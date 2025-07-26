/********************************************************************************
** Form generated from reading UI file 'outagepage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTAGEPAGE_H
#define UI_OUTAGEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutagePage
{
public:
    QComboBox *cmbType;
    QTextEdit *editArea;
    QTextEdit *editMessage;
    QPushButton *btnSubmit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *lblStatus;

    void setupUi(QWidget *OutagePage)
    {
        if (OutagePage->objectName().isEmpty())
            OutagePage->setObjectName("OutagePage");
        OutagePage->resize(555, 367);
        QFont font;
        font.setBold(false);
        OutagePage->setFont(font);
        cmbType = new QComboBox(OutagePage);
        cmbType->addItem(QString());
        cmbType->addItem(QString());
        cmbType->addItem(QString());
        cmbType->addItem(QString());
        cmbType->addItem(QString());
        cmbType->addItem(QString());
        cmbType->addItem(QString());
        cmbType->setObjectName("cmbType");
        cmbType->setGeometry(QRect(200, 77, 138, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\342\200\234Segoe UI\342\200\235")});
        font1.setBold(false);
        font1.setItalic(false);
        cmbType->setFont(font1);
        cmbType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    border: 1px solid #9ab;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    font: 14px \342\200\234Segoe UI\342\200\235, sans-serif;\n"
"    min-width: 120px;\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #9ab;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(:/images/assets/downArrow.png);\n"
"    width: 12px; height: 12px;\n"
"}\n"
""));
        editArea = new QTextEdit(OutagePage);
        editArea->setObjectName("editArea");
        editArea->setGeometry(QRect(200, 131, 171, 31));
        editArea->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #9ab;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    font: 14px \342\200\234Segoe UI\342\200\235, sans-serif;\n"
"    color: #333;\n"
"}\n"
"QTextEdit:focus {\n"
"    border: 2px solid #6a9;\n"
"}\n"
""));
        editMessage = new QTextEdit(OutagePage);
        editMessage->setObjectName("editMessage");
        editMessage->setGeometry(QRect(200, 180, 171, 101));
        editMessage->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #9ab;\n"
"    border-radius: 6px;\n"
"    padding: 6px;\n"
"    font: 14px \342\200\234Segoe UI\342\200\235, sans-serif;\n"
"    color: #333;\n"
"}\n"
"QTextEdit:focus {\n"
"    border: 2px solid #6a9;\n"
"}\n"
""));
        btnSubmit = new QPushButton(OutagePage);
        btnSubmit->setObjectName("btnSubmit");
        btnSubmit->setGeometry(QRect(190, 320, 161, 31));
        btnSubmit->setStyleSheet(QString::fromUtf8("#btnSubmit {\n"
"    background-color: #5a9;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    font: 14px \342\200\234Segoe UI\342\200\235, bold;\n"
"    color: white;\n"
"}\n"
"#btnSubmit:hover {\n"
"    background-color: #6ba;\n"
"}\n"
"#btnSubmit:pressed {\n"
"    background-color: #498;\n"
"}"));
        label = new QLabel(OutagePage);
        label->setObjectName("label");
        label->setGeometry(QRect(67, 80, 111, 21));
        QFont font2;
        font2.setBold(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size: 14px;\n"
"}"));
        label_2 = new QLabel(OutagePage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 20, 191, 31));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:15px;\n"
"}"));
        label_3 = new QLabel(OutagePage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 132, 111, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\342\200\234Segoe UI\342\200\235")});
        font3.setBold(true);
        font3.setItalic(false);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size: 13px;\n"
"}"));
        label_4 = new QLabel(OutagePage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 180, 121, 21));
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size: 13px;\n"
"}"));
        lblStatus = new QLabel(OutagePage);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setGeometry(QRect(190, 300, 181, 16));
        lblStatus->setFont(font1);
        lblStatus->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 12px \342\200\234Segoe UI\342\200\235;\n"
"}"));

        retranslateUi(OutagePage);

        cmbType->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(OutagePage);
    } // setupUi

    void retranslateUi(QWidget *OutagePage)
    {
        OutagePage->setWindowTitle(QCoreApplication::translate("OutagePage", "Form", nullptr));
        cmbType->setItemText(0, QCoreApplication::translate("OutagePage", "\342\232\241 Electricity", nullptr));
        cmbType->setItemText(1, QCoreApplication::translate("OutagePage", "\360\237\214\220 Internet", nullptr));
        cmbType->setItemText(2, QCoreApplication::translate("OutagePage", "\360\237\222\247 Water", nullptr));
        cmbType->setItemText(3, QCoreApplication::translate("OutagePage", "\360\237\224\245 Gas", nullptr));
        cmbType->setItemText(4, QCoreApplication::translate("OutagePage", "\360\237\223\266 Mobile Network", nullptr));
        cmbType->setItemText(5, QCoreApplication::translate("OutagePage", "\360\237\222\241 Street Light", nullptr));
        cmbType->setItemText(6, QCoreApplication::translate("OutagePage", "\342\235\223 Other", nullptr));

        cmbType->setCurrentText(QString());
        cmbType->setPlaceholderText(QCoreApplication::translate("OutagePage", "Select Type", nullptr));
        btnSubmit->setText(QCoreApplication::translate("OutagePage", "Submit Report \360\237\223\244", nullptr));
        label->setText(QCoreApplication::translate("OutagePage", "\360\237\223\241 Outage Type", nullptr));
        label_2->setText(QCoreApplication::translate("OutagePage", "\360\237\223\235 Submit Outage Report", nullptr));
        label_3->setText(QCoreApplication::translate("OutagePage", "\360\237\223\215 Area/Location", nullptr));
        label_4->setText(QCoreApplication::translate("OutagePage", "\360\237\222\254 Message Details", nullptr));
        lblStatus->setText(QCoreApplication::translate("OutagePage", "\360\237\223\242 Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutagePage: public Ui_OutagePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTAGEPAGE_H
