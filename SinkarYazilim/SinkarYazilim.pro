#-------------------------------------------------
#
# Project created by QtCreator 2018-02-23T14:30:59
#
#-------------------------------------------------

QT       += core gui printsupport

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
    ayarlar/addmalzemedialog.cpp \
    stok/stokdialog.cpp \
    stok/malzemegirdialog.cpp \
    stok/malzemeselectdialog.cpp \
    stok/selectfirmadialog.cpp \
    ayarlar/addfirmadialog.cpp \
    stok/malzemecikdialog.cpp \
    stok/sevkmiktardialog.cpp \
    ayarlar/kasamasadialog.cpp \
    Kasa/kasadialog.cpp \
    Kasa/siparisdialog.cpp \
    Kasa/hesabikapatdialog.cpp \
    Kasa/caridialog.cpp \
    Kasa/addcarihesapdialog.cpp \
    Cari/carihesapdialog.cpp \
    Cari/odemealdialog.cpp \
    Cari/detaylihesapdialog.cpp \
    dbuser.cpp \
    delegate.cpp \
    Harici/haricigiderdialog.cpp \
    ayarlar/haricigiderayardialog.cpp \
    Cari/gelirgidersceneitem.cpp

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
    ayarlar/addmalzemedialog.h \
    stok/stokdialog.h \
    stok/malzemegirdialog.h \
    stok/malzemeselectdialog.h \
    stok/selectfirmadialog.h \
    ayarlar/addfirmadialog.h \
    stok/malzemecikdialog.h \
    stok/sevkmiktardialog.h \
    ayarlar/kasamasadialog.h \
    Kasa/kasadialog.h \
    Kasa/siparisdialog.h \
    Kasa/hesabikapatdialog.h \
    Kasa/caridialog.h \
    Kasa/addcarihesapdialog.h \
    Cari/carihesapdialog.h \
    Cari/odemealdialog.h \
    Cari/detaylihesapdialog.h \
    dbuser.h \
    delegate.h \
    Harici/haricigiderdialog.h \
    ayarlar/haricigiderayardialog.h \
    Cari/gelirgidersceneitem.h

FORMS += \
        mainwindow.ui \
    personel/personeldialog.ui \
    personel/logindialog.ui \
    ayarlar/ayarlardialog.ui \
    ayarlar/depodialog.ui \
    ayarlar/malzemekalemidialog.ui \
    ayarlar/recetedialog.ui \
    ayarlar/addmalzemedialog.ui \
    stok/stokdialog.ui \
    stok/malzemegirdialog.ui \
    stok/malzemeselectdialog.ui \
    stok/selectfirmadialog.ui \
    ayarlar/addfirmadialog.ui \
    stok/malzemecikdialog.ui \
    stok/sevkmiktardialog.ui \
    ayarlar/kasamasadialog.ui \
    Kasa/kasadialog.ui \
    Kasa/siparisdialog.ui \
    Kasa/hesabikapatdialog.ui \
    Kasa/caridialog.ui \
    Kasa/addcarihesapdialog.ui \
    Cari/carihesapdialog.ui \
    Cari/odemealdialog.ui \
    Cari/detaylihesapdialog.ui \
    Harici/haricigiderdialog.ui \
    ayarlar/haricigiderayardialog.ui






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





win32: LIBS += -L$$PWD/KDReports/lib/ -llibkdreports.dll

INCLUDEPATH += $$PWD/KDReports/include
DEPENDPATH += $$PWD/KDReports/include

RESOURCES += \
    appresource.qrc


win32 {
    RC_FILE = iconrc.rc
}
