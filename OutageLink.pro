QT       += core gui
QT       += core gui widgets network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += printsupport
+DEFINES += QCP_NO_PRINTER
INCLUDEPATH += $$PWD/libs
INCLUDEPATH += $$PWD/src
CONFIG += c++17

# CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    libs/qcustomplot.cpp \
    main.cpp \
    mainwindow.cpp \
    src/logindialog.cpp \
    src/analytics.cpp \
    src/encryption.cpp \
    src/filemanager.cpp \
    src/network.cpp \
    ui/feedpage.cpp \
    ui/outagepage.cpp \
    ui/requestpage.cpp \
    ui/resourcepage.cpp

HEADERS += \
    libs/qcustomplot.h \
    mainwindow.h \
    src/logindialog.h \
    src/analytics.h \
    src/data.h \
    src/encryption.h \
    src/filemanager.h \
    src/network.h \
    ui/feedpage.h \
    ui/outagepage.h \
    ui/requestpage.h \
    ui/resourcepage.h

FORMS += \
    mainwindow.ui \
    ui/logindialog.ui \
    ui/feedpage.ui \
    ui/outagepage.ui \
    ui/requestpage.ui \
    ui/resourcepage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
