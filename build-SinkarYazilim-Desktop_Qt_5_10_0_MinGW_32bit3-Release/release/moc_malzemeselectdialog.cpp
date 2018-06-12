/****************************************************************************
** Meta object code from reading C++ file 'malzemeselectdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/stok/malzemeselectdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'malzemeselectdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MalzemeSelectDialog_t {
    QByteArrayData data[7];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MalzemeSelectDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MalzemeSelectDialog_t qt_meta_stringdata_MalzemeSelectDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "MalzemeSelectDialog"
QT_MOC_LITERAL(1, 20, 46), // "on_comboBox_KategoriFilter_cu..."
QT_MOC_LITERAL(2, 67, 0), // ""
QT_MOC_LITERAL(3, 68, 4), // "arg1"
QT_MOC_LITERAL(4, 73, 25), // "on_listView_doubleClicked"
QT_MOC_LITERAL(5, 99, 5), // "index"
QT_MOC_LITERAL(6, 105, 27) // "on_pushButton_iptal_clicked"

    },
    "MalzemeSelectDialog\0"
    "on_comboBox_KategoriFilter_currentIndexChanged\0"
    "\0arg1\0on_listView_doubleClicked\0index\0"
    "on_pushButton_iptal_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MalzemeSelectDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    1,   32,    2, 0x08 /* Private */,
       6,    0,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,

       0        // eod
};

void MalzemeSelectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MalzemeSelectDialog *_t = static_cast<MalzemeSelectDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBox_KategoriFilter_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_listView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_iptal_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MalzemeSelectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MalzemeSelectDialog.data,
      qt_meta_data_MalzemeSelectDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MalzemeSelectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MalzemeSelectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MalzemeSelectDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MalzemeSelectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
