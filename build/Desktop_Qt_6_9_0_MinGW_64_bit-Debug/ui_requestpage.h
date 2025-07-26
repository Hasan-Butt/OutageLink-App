/********************************************************************************
** Form generated from reading UI file 'requestpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUESTPAGE_H
#define UI_REQUESTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RequestPage
{
public:
    QLabel *label_5;
    QLabel *label_4;
    QPushButton *btnSubmit;
    QLabel *lblStatus;
    QTableWidget *tblRequests;
    QLineEdit *editLocation;
    QLineEdit *editRequest;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label;

    void setupUi(QWidget *RequestPage)
    {
        if (RequestPage->objectName().isEmpty())
            RequestPage->setObjectName("RequestPage");
        RequestPage->resize(555, 397);
        label_5 = new QLabel(RequestPage);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(11, 90, 101, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\342\200\234Segoe UI\342\200\235")});
        font.setBold(true);
        font.setItalic(false);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        label_4 = new QLabel(RequestPage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(9, 47, 111, 21));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        btnSubmit = new QPushButton(RequestPage);
        btnSubmit->setObjectName("btnSubmit");
        btnSubmit->setGeometry(QRect(11, 126, 141, 31));
        btnSubmit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: #5a9;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    font: 14px \342\200\234Segoe UI\342\200\235, bold;\n"
"    color: white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6ba;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #498;\n"
"}"));
        lblStatus = new QLabel(RequestPage);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setGeometry(QRect(100, 170, 301, 21));
        lblStatus->setFont(font);
        lblStatus->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        tblRequests = new QTableWidget(RequestPage);
        if (tblRequests->columnCount() < 4)
            tblRequests->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblRequests->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblRequests->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblRequests->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblRequests->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tblRequests->rowCount() < 9)
            tblRequests->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblRequests->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblRequests->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblRequests->setItem(0, 2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblRequests->setItem(1, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblRequests->setItem(1, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblRequests->setItem(1, 2, __qtablewidgetitem9);
        tblRequests->setObjectName("tblRequests");
        tblRequests->setGeometry(QRect(10, 220, 421, 171));
        tblRequests->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 8px;\n"
"    gridline-color: #e0e0e0;\n"
"    selection-background-color: #a8d5e2;\n"
"    selection-color: #003344;\n"
"    font: 13px \"Segoe UI\", sans-serif;\n"
"}\n"
"\n"
"/* Horizontal header */\n"
"QHeaderView::section {\n"
"    background-color: #f0f4f8;\n"
"    color: #333;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    border-bottom: 1px solid #ccc;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Vertical header (hide if desired) */\n"
"QTableView QHeaderView::verticalHeader {\n"
"    background: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"/* Rows */\n"
"QTableWidget::item {\n"
"   /* padding: 6px;*/\n"
"}\n"
"\n"
"/* Alternate row coloring */\n"
"QTableWidge {\n"
"    alternate-background-color: #f9fcff;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QTableWidget::item:hover {\n"
"    background-color: #d0eef7;\n"
"}\n"
"\n"
"/* Selected row */\n"
"QTableWidget::item:selected {\n"
"    background-"
                        "color: #a8d5e2;\n"
"    color: #003344;\n"
"}\n"
"\n"
"/* Remove focus rectangle */\n"
"QTableWidget#tblResources::item:focus {\n"
"    outline: none;\n"
"}"));
        tblRequests->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tblRequests->setAlternatingRowColors(true);
        tblRequests->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        editLocation = new QLineEdit(RequestPage);
        editLocation->setObjectName("editLocation");
        editLocation->setGeometry(QRect(130, 90, 201, 20));
        editRequest = new QLineEdit(RequestPage);
        editRequest->setObjectName("editRequest");
        editRequest->setGeometry(QRect(130, 50, 201, 20));
        label_6 = new QLabel(RequestPage);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(11, 170, 71, 21));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        label_8 = new QLabel(RequestPage);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(11, 200, 171, 21));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        label = new QLabel(RequestPage);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 10, 161, 21));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 15px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));

        retranslateUi(RequestPage);

        QMetaObject::connectSlotsByName(RequestPage);
    } // setupUi

    void retranslateUi(QWidget *RequestPage)
    {
        RequestPage->setWindowTitle(QCoreApplication::translate("RequestPage", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("RequestPage", "\360\237\223\215 Location:", nullptr));
        label_4->setText(QCoreApplication::translate("RequestPage", "\342\235\223 Request Item:", nullptr));
        btnSubmit->setText(QCoreApplication::translate("RequestPage", "\342\234\205 Submit Request", nullptr));
        lblStatus->setText(QCoreApplication::translate("RequestPage", "Submit Request to Check Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblRequests->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RequestPage", "Request", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblRequests->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RequestPage", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblRequests->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("RequestPage", "Location", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblRequests->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("RequestPage", "Action", nullptr));

        const bool __sortingEnabled = tblRequests->isSortingEnabled();
        tblRequests->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tblRequests->item(0, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("RequestPage", "Phone charging", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblRequests->item(0, 1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("RequestPage", "Hasan", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblRequests->item(0, 2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("RequestPage", "Street 5", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblRequests->item(1, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("RequestPage", "Need water", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblRequests->item(1, 1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("RequestPage", "Sarim", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblRequests->item(1, 2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("RequestPage", "Sector F", nullptr));
        tblRequests->setSortingEnabled(__sortingEnabled);

        label_6->setText(QCoreApplication::translate("RequestPage", "\342\204\271\357\270\217Status:", nullptr));
        label_8->setText(QCoreApplication::translate("RequestPage", "\360\237\223\213 Current Requests:", nullptr));
        label->setText(QCoreApplication::translate("RequestPage", "\342\234\211\357\270\217 Resource Request", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RequestPage: public Ui_RequestPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTPAGE_H
