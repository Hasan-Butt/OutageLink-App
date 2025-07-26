/********************************************************************************
** Form generated from reading UI file 'resourcepage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESOURCEPAGE_H
#define UI_RESOURCEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResourcePage
{
public:
    QLabel *label;
    QLabel *label_4;
    QLineEdit *editItem;
    QLabel *label_5;
    QLineEdit *editAvailability;
    QPushButton *btnSubmit;
    QLabel *label_6;
    QLabel *lblStatus;
    QLabel *label_8;
    QTableWidget *tblResources;

    void setupUi(QWidget *ResourcePage)
    {
        if (ResourcePage->objectName().isEmpty())
            ResourcePage->setObjectName("ResourcePage");
        ResourcePage->resize(555, 397);
        label = new QLabel(ResourcePage);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 10, 161, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\342\200\234Segoe UI\342\200\235")});
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 15px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        label_4 = new QLabel(ResourcePage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(11, 47, 101, 21));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        editItem = new QLineEdit(ResourcePage);
        editItem->setObjectName("editItem");
        editItem->setGeometry(QRect(111, 50, 221, 20));
        label_5 = new QLabel(ResourcePage);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(11, 90, 101, 21));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        editAvailability = new QLineEdit(ResourcePage);
        editAvailability->setObjectName("editAvailability");
        editAvailability->setGeometry(QRect(111, 90, 221, 20));
        btnSubmit = new QPushButton(ResourcePage);
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
        label_6 = new QLabel(ResourcePage);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(11, 170, 71, 21));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        lblStatus = new QLabel(ResourcePage);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setGeometry(QRect(100, 170, 301, 21));
        lblStatus->setFont(font);
        lblStatus->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        label_8 = new QLabel(ResourcePage);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(11, 200, 171, 21));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #345;\n"
"    font: 13px \342\200\234Segoe UI\342\200\235;\n"
"	font:bold;\n"
"}"));
        tblResources = new QTableWidget(ResourcePage);
        if (tblResources->columnCount() < 5)
            tblResources->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblResources->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblResources->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblResources->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblResources->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblResources->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tblResources->rowCount() < 4)
            tblResources->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblResources->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblResources->setItem(0, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblResources->setItem(0, 2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblResources->setItem(1, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblResources->setItem(1, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblResources->setItem(1, 2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblResources->setItem(2, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblResources->setItem(2, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblResources->setItem(2, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblResources->setItem(3, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblResources->setItem(3, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblResources->setItem(3, 2, __qtablewidgetitem16);
        tblResources->setObjectName("tblResources");
        tblResources->setGeometry(QRect(10, 220, 471, 171));
        tblResources->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        tblResources->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tblResources->setAlternatingRowColors(true);
        tblResources->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);

        retranslateUi(ResourcePage);

        QMetaObject::connectSlotsByName(ResourcePage);
    } // setupUi

    void retranslateUi(QWidget *ResourcePage)
    {
        ResourcePage->setWindowTitle(QCoreApplication::translate("ResourcePage", "Form", nullptr));
        label->setText(QCoreApplication::translate("ResourcePage", "\360\237\244\235 Resource Sharing", nullptr));
        label_4->setText(QCoreApplication::translate("ResourcePage", "Reource Item:", nullptr));
        label_5->setText(QCoreApplication::translate("ResourcePage", "Availability:", nullptr));
        btnSubmit->setText(QCoreApplication::translate("ResourcePage", "\342\234\205 Submit Resource", nullptr));
        label_6->setText(QCoreApplication::translate("ResourcePage", "\342\204\271\357\270\217Status:", nullptr));
        lblStatus->setText(QCoreApplication::translate("ResourcePage", "Submit Resource to Check Status", nullptr));
        label_8->setText(QCoreApplication::translate("ResourcePage", "\360\237\223\246 Availible Resources:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblResources->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ResourcePage", "Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblResources->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ResourcePage", "Owner", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblResources->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ResourcePage", "Availability", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblResources->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ResourcePage", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblResources->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ResourcePage", "Actions", nullptr));

        const bool __sortingEnabled = tblResources->isSortingEnabled();
        tblResources->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem5 = tblResources->item(0, 0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ResourcePage", "UPS", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblResources->item(0, 1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ResourcePage", "Ali", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblResources->item(0, 2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ResourcePage", "9 am", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblResources->item(1, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ResourcePage", "Generator", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblResources->item(1, 1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ResourcePage", "Ahmed", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblResources->item(1, 2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ResourcePage", "10 pm", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblResources->item(2, 0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ResourcePage", "Water Bottles", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblResources->item(2, 1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("ResourcePage", "Sara", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblResources->item(2, 2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("ResourcePage", "12 pm", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblResources->item(3, 0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("ResourcePage", "Vaccum", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblResources->item(3, 1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("ResourcePage", "Hasan", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblResources->item(3, 2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("ResourcePage", "8 am", nullptr));
        tblResources->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class ResourcePage: public Ui_ResourcePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESOURCEPAGE_H
