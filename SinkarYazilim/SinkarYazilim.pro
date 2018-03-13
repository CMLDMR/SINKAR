#-------------------------------------------------
#
# Project created by QtCreator 2018-02-23T14:30:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SinkarYazilim
TEMPLATE = app

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    personel/personeldialog.cpp \
    personel/logindialog.cpp \
    ayarlar/ayarlardialog.cpp \
    ayarlar/depodialog.cpp \
    ayarlar/malzemekalemidialog.cpp \
    ../../Comman/qtbsonobject.cpp \
    ayarlar/recetedialog.cpp \
    ayarlar/addmalzemedialog.cpp

HEADERS += \
        mainwindow.h \
    mongoheaders.h \
    ../snkkey.h \
    personel/personeldialog.h \
    personel/logindialog.h \
    ayarlar/ayarlardialog.h \
    ayarlar/depodialog.h \
    src/quickwidget.h \
    ayarlar/malzemekalemidialog.h \
    ../../Comman/qtbsonobject.h \
    ayarlar/recetedialog.h \
    ayarlar/addmalzemedialog.h

FORMS += \
        mainwindow.ui \
    personel/personeldialog.ui \
    personel/logindialog.ui \
    ayarlar/ayarlardialog.ui \
    ayarlar/depodialog.ui \
    ayarlar/malzemekalemidialog.ui \
    ayarlar/recetedialog.ui \
    ayarlar/addmalzemedialog.ui





LIBS += -L$$PWD/../mongocxx/lib/ -llibbsoncxx.dll

INCLUDEPATH += $$PWD/../mongocxx/include/bsoncxx/v_noabi
DEPENDPATH += $$PWD/../mongocxx/include/bsoncxx/v_noabi




LIBS += -L$$PWD/../mongocxx/lib/ -llibmongocxx.dll

INCLUDEPATH += $$PWD/../mongocxx/include/mongocxx/v_noabi
DEPENDPATH += $$PWD/../mongocxx/include/mongocxx/v_noabi

INCLUDEPATH += $$PWD/../../Comman/
DEPENDPATH += $$PWD/../../Comman/

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
