/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"
#include "ui/feedpage.h"
#include "ui/outagepage.h"
#include "ui/requestpage.h"
#include "ui/resourcepage.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *loginLabel;
    QStackedWidget *centralStack;
    FeedPage *FeedPageWidget;
    OutagePage *OutagePageWidget;
    ResourcePage *ResourcePageWidget;
    RequestPage *RequestPageWidget;
    QWidget *analyticsPageWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QCustomPlot *customPlotResources;
    QCustomPlot *customPlotOutages;
    QCustomPlot *customPlotTypes;
    QPushButton *btnRequest;
    QPushButton *btnResource;
    QPushButton *btnfeed;
    QPushButton *btnOutage;
    QPushButton *btnAnalytics;
    QToolButton *btnAnnounce;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("/*#MainWindow{\n"
" background-image: url(:/images/assets/feedPageImg.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#centralStack{\n"
" background-image: url(:/images/assets/feedPageImg.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 10, 161, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\342\200\234Segoe UI\342\200\235")});
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"/*font-size: 20px*/;\n"
"  font: 20px \342\200\234Segoe UI\342\200\235, bold;\n"
"font:bold;\n"
"\n"
"}"));
        loginLabel = new QLabel(centralwidget);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(660, 10, 141, 21));
        loginLabel->setFont(font);
        loginLabel->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 13px \342\200\234Segoe UI\342\200\235;\n"
"font:bold;\n"
"}"));
        centralStack = new QStackedWidget(centralwidget);
        centralStack->setObjectName("centralStack");
        centralStack->setGeometry(QRect(149, 120, 491, 401));
        centralStack->setStyleSheet(QString::fromUtf8("#FeedPageWidget{\n"
" background-image: url(:/images/assets/feedPageImg.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    \n"
"}"));
        FeedPageWidget = new FeedPage();
        FeedPageWidget->setObjectName("FeedPageWidget");
        FeedPageWidget->setStyleSheet(QString::fromUtf8(""));
        centralStack->addWidget(FeedPageWidget);
        OutagePageWidget = new OutagePage();
        OutagePageWidget->setObjectName("OutagePageWidget");
        centralStack->addWidget(OutagePageWidget);
        ResourcePageWidget = new ResourcePage();
        ResourcePageWidget->setObjectName("ResourcePageWidget");
        centralStack->addWidget(ResourcePageWidget);
        RequestPageWidget = new RequestPage();
        RequestPageWidget->setObjectName("RequestPageWidget");
        centralStack->addWidget(RequestPageWidget);
        analyticsPageWidget = new QWidget();
        analyticsPageWidget->setObjectName("analyticsPageWidget");
        layoutWidget = new QWidget(analyticsPageWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(1, 0, 491, 401));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        customPlotResources = new QCustomPlot(layoutWidget);
        customPlotResources->setObjectName("customPlotResources");

        gridLayout->addWidget(customPlotResources, 0, 0, 1, 1);

        customPlotOutages = new QCustomPlot(layoutWidget);
        customPlotOutages->setObjectName("customPlotOutages");

        gridLayout->addWidget(customPlotOutages, 0, 1, 1, 1);

        customPlotTypes = new QCustomPlot(layoutWidget);
        customPlotTypes->setObjectName("customPlotTypes");

        gridLayout->addWidget(customPlotTypes, 1, 0, 1, 2);

        centralStack->addWidget(analyticsPageWidget);
        btnRequest = new QPushButton(centralwidget);
        btnRequest->setObjectName("btnRequest");
        btnRequest->setGeometry(QRect(530, 80, 111, 31));
        btnRequest->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnResource = new QPushButton(centralwidget);
        btnResource->setObjectName("btnResource");
        btnResource->setGeometry(QRect(409, 80, 101, 31));
        btnResource->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnfeed = new QPushButton(centralwidget);
        btnfeed->setObjectName("btnfeed");
        btnfeed->setGeometry(QRect(149, 80, 111, 31));
        btnfeed->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnOutage = new QPushButton(centralwidget);
        btnOutage->setObjectName("btnOutage");
        btnOutage->setGeometry(QRect(279, 80, 111, 31));
        btnOutage->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        btnAnalytics = new QPushButton(centralwidget);
        btnAnalytics->setObjectName("btnAnalytics");
        btnAnalytics->setGeometry(QRect(360, 528, 101, 31));
        btnAnalytics->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"/* background-color:#1E90FF; /* Dodger Blue */\n"
"   background-color: #5a9;\n"
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
        btnAnnounce = new QToolButton(centralwidget);
        btnAnnounce->setObjectName("btnAnnounce");
        btnAnnounce->setGeometry(QRect(14, 8, 41, 31));
        btnAnnounce->setStyleSheet(QString::fromUtf8("/*QToolButton{\n"
"background-image:url(:images/assets/announcementIcon.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/assets/announcementIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAnnounce->setIcon(icon);
        btnAnnounce->setIconSize(QSize(41, 41));
        btnAnnounce->setAutoRaise(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        centralStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\360\237\223\241 OutageLink", nullptr));
        loginLabel->setText(QCoreApplication::translate("MainWindow", "Login As: ", nullptr));
        btnRequest->setText(QCoreApplication::translate("MainWindow", "Request", nullptr));
        btnResource->setText(QCoreApplication::translate("MainWindow", "Resource", nullptr));
        btnfeed->setText(QCoreApplication::translate("MainWindow", "Feed", nullptr));
        btnOutage->setText(QCoreApplication::translate("MainWindow", "Outage", nullptr));
        btnAnalytics->setText(QCoreApplication::translate("MainWindow", "Analytics", nullptr));
        btnAnnounce->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
