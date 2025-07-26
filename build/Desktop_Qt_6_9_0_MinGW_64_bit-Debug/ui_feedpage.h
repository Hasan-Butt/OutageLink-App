/********************************************************************************
** Form generated from reading UI file 'feedpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDPAGE_H
#define UI_FEEDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FeedPage
{
public:
    QFrame *backgroundframe;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QFrame *reportCardTemplate;
    QLabel *label_9;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_10;
    QComboBox *comboFilter;
    QLabel *label_2;

    void setupUi(QWidget *FeedPage)
    {
        if (FeedPage->objectName().isEmpty())
            FeedPage->setObjectName("FeedPage");
        FeedPage->resize(555, 367);
        FeedPage->setStyleSheet(QString::fromUtf8("/*#FeedPage{\n"
" background-image: url(:/images/assets/feedPageImg.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}*/\n"
"#backgroundframe {\n"
"    background-image:  url(:/images/assets/feedPageImg.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover;\n"
"}"));
        backgroundframe = new QFrame(FeedPage);
        backgroundframe->setObjectName("backgroundframe");
        backgroundframe->setGeometry(QRect(-1, -1, 561, 361));
        backgroundframe->setStyleSheet(QString::fromUtf8(""));
        backgroundframe->setFrameShape(QFrame::Shape::StyledPanel);
        backgroundframe->setFrameShadow(QFrame::Shadow::Raised);
        scrollArea = new QScrollArea(backgroundframe);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 59, 431, 301));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 299));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        reportCardTemplate = new QFrame(scrollAreaWidgetContents);
        reportCardTemplate->setObjectName("reportCardTemplate");
        reportCardTemplate->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #f9f9f9;\n"
"    border: 1px solid #d3d3d3;\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"}"));
        reportCardTemplate->setFrameShape(QFrame::Shape::StyledPanel);
        reportCardTemplate->setFrameShadow(QFrame::Shadow::Raised);
        label_9 = new QLabel(reportCardTemplate);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(230, 344, 379, 45));
        QFont font;
        font.setBold(true);
        label_9->setFont(font);
        label_12 = new QLabel(reportCardTemplate);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(230, 296, 379, 44));
        label_12->setFont(font);
        label_8 = new QLabel(reportCardTemplate);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 10, 391, 45));
        label_8->setFont(font);
        label_13 = new QLabel(reportCardTemplate);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 60, 391, 41));
        label_13->setFont(font);
        label_11 = new QLabel(reportCardTemplate);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 110, 391, 45));
        label_11->setFont(font);
        label_14 = new QLabel(reportCardTemplate);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 160, 391, 44));
        label_14->setFont(font);
        label_10 = new QLabel(reportCardTemplate);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 210, 391, 45));
        label_10->setFont(font);

        verticalLayout_2->addWidget(reportCardTemplate);

        scrollArea->setWidget(scrollAreaWidgetContents);
        comboFilter = new QComboBox(backgroundframe);
        comboFilter->addItem(QString());
        comboFilter->addItem(QString());
        comboFilter->addItem(QString());
        comboFilter->addItem(QString());
        comboFilter->addItem(QString());
        comboFilter->addItem(QString());
        comboFilter->addItem(QString());
        comboFilter->addItem(QString());
        comboFilter->setObjectName("comboFilter");
        comboFilter->setGeometry(QRect(108, 8, 138, 31));
        comboFilter->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_2 = new QLabel(backgroundframe);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(32, 10, 71, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\342\200\234Segoe UI\342\200\235")});
        font1.setBold(true);
        font1.setItalic(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 14px \342\200\234Segoe UI\342\200\235;\n"
"font:bold;\n"
"}"));

        retranslateUi(FeedPage);

        QMetaObject::connectSlotsByName(FeedPage);
    } // setupUi

    void retranslateUi(QWidget *FeedPage)
    {
        FeedPage->setWindowTitle(QCoreApplication::translate("FeedPage", "Form", nullptr));
        label_9->setText(QCoreApplication::translate("FeedPage", "Submitted: Ali", nullptr));
        label_12->setText(QCoreApplication::translate("FeedPage", "Date & Time: 10-07-2025 15:00", nullptr));
        label_8->setText(QCoreApplication::translate("FeedPage", "Type: \342\232\241 Power Outage", nullptr));
        label_13->setText(QCoreApplication::translate("FeedPage", "Location: \360\237\223\215 Sector F", nullptr));
        label_11->setText(QCoreApplication::translate("FeedPage", "Message: No power since 3PM", nullptr));
        label_14->setText(QCoreApplication::translate("FeedPage", "Date & Time: 10-07-2025 15:00", nullptr));
        label_10->setText(QCoreApplication::translate("FeedPage", "Submitted: Ali", nullptr));
        comboFilter->setItemText(0, QCoreApplication::translate("FeedPage", "All", nullptr));
        comboFilter->setItemText(1, QCoreApplication::translate("FeedPage", "\342\232\241 Electricity", nullptr));
        comboFilter->setItemText(2, QCoreApplication::translate("FeedPage", "\360\237\214\220 Internet", nullptr));
        comboFilter->setItemText(3, QCoreApplication::translate("FeedPage", "\360\237\222\247 Water", nullptr));
        comboFilter->setItemText(4, QCoreApplication::translate("FeedPage", "\360\237\224\245 Gas", nullptr));
        comboFilter->setItemText(5, QCoreApplication::translate("FeedPage", "\360\237\223\266 Mobile Network", nullptr));
        comboFilter->setItemText(6, QCoreApplication::translate("FeedPage", "\360\237\222\241 Street Light", nullptr));
        comboFilter->setItemText(7, QCoreApplication::translate("FeedPage", "\342\235\223 Other", nullptr));

        comboFilter->setCurrentText(QString());
        comboFilter->setPlaceholderText(QCoreApplication::translate("FeedPage", "SELECT TYPE", nullptr));
        label_2->setText(QCoreApplication::translate("FeedPage", "\360\237\247\255 Filter:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FeedPage: public Ui_FeedPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDPAGE_H
