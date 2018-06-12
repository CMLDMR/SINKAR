/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "showMainWindow"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "std::string"
QT_MOC_LITERAL(4, 39, 11), // "personelOid"
QT_MOC_LITERAL(5, 51, 10), // "setMessage"
QT_MOC_LITERAL(6, 62, 11), // "const char*"
QT_MOC_LITERAL(7, 74, 7), // "message"
QT_MOC_LITERAL(8, 82, 30), // "on_pushButton_Personel_clicked"
QT_MOC_LITERAL(9, 113, 29), // "on_pushButton_options_clicked"
QT_MOC_LITERAL(10, 143, 15), // "applicationQuit"
QT_MOC_LITERAL(11, 159, 26), // "on_pushButton_Stok_clicked"
QT_MOC_LITERAL(12, 186, 30), // "on_pushButton_OpenKasa_clicked"
QT_MOC_LITERAL(13, 217, 27), // "on_pushButton_Close_clicked"
QT_MOC_LITERAL(14, 245, 26), // "on_pushButton_Cari_clicked"
QT_MOC_LITERAL(15, 272, 38) // "on_pushButton_ExternalOutGoin..."

    },
    "MainWindow\0showMainWindow\0\0std::string\0"
    "personelOid\0setMessage\0const char*\0"
    "message\0on_pushButton_Personel_clicked\0"
    "on_pushButton_options_clicked\0"
    "applicationQuit\0on_pushButton_Stok_clicked\0"
    "on_pushButton_OpenKasa_clicked\0"
    "on_pushButton_Close_clicked\0"
    "on_pushButton_Cari_clicked\0"
    "on_pushButton_ExternalOutGoing_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x0a /* Public */,
       5,    1,   67,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,
      12,    0,   74,    2, 0x08 /* Private */,
      13,    0,   75,    2, 0x08 /* Private */,
      14,    0,   76,    2, 0x08 /* Private */,
      15,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showMainWindow((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->setMessage((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_Personel_clicked(); break;
        case 3: _t->on_pushButton_options_clicked(); break;
        case 4: _t->applicationQuit(); break;
        case 5: _t->on_pushButton_Stok_clicked(); break;
        case 6: _t->on_pushButton_OpenKasa_clicked(); break;
        case 7: _t->on_pushButton_Close_clicked(); break;
        case 8: _t->on_pushButton_Cari_clicked(); break;
        case 9: _t->on_pushButton_ExternalOutGoing_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
