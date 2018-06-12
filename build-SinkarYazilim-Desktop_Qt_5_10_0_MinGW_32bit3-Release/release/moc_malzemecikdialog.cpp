/****************************************************************************
** Meta object code from reading C++ file 'malzemecikdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/stok/malzemecikdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'malzemecikdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MalzemeCikDialog_t {
    QByteArrayData data[10];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MalzemeCikDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MalzemeCikDialog_t qt_meta_stringdata_MalzemeCikDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MalzemeCikDialog"
QT_MOC_LITERAL(1, 17, 18), // "setDestinationDepo"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "index"
QT_MOC_LITERAL(4, 43, 30), // "on_lineEdit_filter_textChanged"
QT_MOC_LITERAL(5, 74, 4), // "arg1"
QT_MOC_LITERAL(6, 79, 38), // "on_listView_currentStock_doub..."
QT_MOC_LITERAL(7, 118, 39), // "on_listView_selectedStock_dou..."
QT_MOC_LITERAL(8, 158, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(9, 187, 24) // "on_pushButton_ok_clicked"

    },
    "MalzemeCikDialog\0setDestinationDepo\0"
    "\0index\0on_lineEdit_filter_textChanged\0"
    "arg1\0on_listView_currentStock_doubleClicked\0"
    "on_listView_selectedStock_doubleClicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_pushButton_ok_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MalzemeCikDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       6,    1,   50,    2, 0x08 /* Private */,
       7,    1,   53,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MalzemeCikDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MalzemeCikDialog *_t = static_cast<MalzemeCikDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setDestinationDepo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_lineEdit_filter_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_listView_currentStock_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_listView_selectedStock_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_cancel_clicked(); break;
        case 5: _t->on_pushButton_ok_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MalzemeCikDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MalzemeCikDialog.data,
      qt_meta_data_MalzemeCikDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MalzemeCikDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MalzemeCikDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MalzemeCikDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MalzemeCikDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
