#-------------------------------------------------
#
# Project created by QtCreator 2018-02-23T14:30:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SinkarYazilim
TEMPLATE = app

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
    personel/personeldialog.cpp

HEADERS += \
        mainwindow.h \
    mongoheaders.h \
    ../snkkey.h \
    personel/personeldialog.h

FORMS += \
        mainwindow.ui \
    personel/personeldialog.ui





LIBS += -L$$PWD/../mongocxx/lib/ -llibbsoncxx.dll

INCLUDEPATH += $$PWD/../mongocxx/include/bsoncxx/v_noabi
DEPENDPATH += $$PWD/../mongocxx/include/bsoncxx/v_noabi




LIBS += -L$$PWD/../mongocxx/lib/ -llibmongocxx.dll

INCLUDEPATH += $$PWD/../mongocxx/include/mongocxx/v_noabi
DEPENDPATH += $$PWD/../mongocxx/include/mongocxx/v_noabi

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../
