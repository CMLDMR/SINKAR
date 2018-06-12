/****************************************************************************
** Meta object code from reading C++ file 'kasadialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/Kasa/kasadialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kasadialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KasaDialog_t {
    QByteArrayData data[14];
    char stringdata0[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KasaDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KasaDialog_t qt_meta_stringdata_KasaDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "KasaDialog"
QT_MOC_LITERAL(1, 11, 32), // "on_pushButton_siparis_al_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 17), // "addSelectedRecete"
QT_MOC_LITERAL(4, 63, 3), // "oid"
QT_MOC_LITERAL(5, 67, 6), // "miktar"
QT_MOC_LITERAL(6, 74, 27), // "on_listView_Masalar_clicked"
QT_MOC_LITERAL(7, 102, 5), // "index"
QT_MOC_LITERAL(8, 108, 33), // "on_listView_Masalar_doubleCli..."
QT_MOC_LITERAL(9, 142, 33), // "on_pushButton_masayiKapat_cli..."
QT_MOC_LITERAL(10, 176, 37), // "on_listView_siparisList_doubl..."
QT_MOC_LITERAL(11, 214, 30), // "on_pushButton_minimize_clicked"
QT_MOC_LITERAL(12, 245, 34), // "on_pushButton_ToggleScreen_cl..."
QT_MOC_LITERAL(13, 280, 27) // "on_pushButton_close_clicked"

    },
    "KasaDialog\0on_pushButton_siparis_al_clicked\0"
    "\0addSelectedRecete\0oid\0miktar\0"
    "on_listView_Masalar_clicked\0index\0"
    "on_listView_Masalar_doubleClicked\0"
    "on_pushButton_masayiKapat_clicked\0"
    "on_listView_siparisList_doubleClicked\0"
    "on_pushButton_minimize_clicked\0"
    "on_pushButton_ToggleScreen_clicked\0"
    "on_pushButton_close_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KasaDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    2,   60,    2, 0x08 /* Private */,
       6,    1,   65,    2, 0x08 /* Private */,
       8,    1,   68,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Double,    4,    5,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KasaDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KasaDialog *_t = static_cast<KasaDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_siparis_al_clicked(); break;
        case 1: _t->addSelectedRecete((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->on_listView_Masalar_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_listView_Masalar_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_masayiKapat_clicked(); break;
        case 5: _t->on_listView_siparisList_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_minimize_clicked(); break;
        case 7: _t->on_pushButton_ToggleScreen_clicked(); break;
        case 8: _t->on_pushButton_close_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject KasaDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_KasaDialog.data,
      qt_meta_data_KasaDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *KasaDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KasaDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KasaDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int KasaDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
