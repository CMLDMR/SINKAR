/****************************************************************************
** Meta object code from reading C++ file 'detaylihesapdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/Cari/detaylihesapdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detaylihesapdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DetayliHesapDialog_t {
    QByteArrayData data[11];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DetayliHesapDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DetayliHesapDialog_t qt_meta_stringdata_DetayliHesapDialog = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DetayliHesapDialog"
QT_MOC_LITERAL(1, 19, 41), // "on_lineEdit_CariControlFilter..."
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 4), // "arg1"
QT_MOC_LITERAL(4, 67, 40), // "on_listView_CariiControlKisiL..."
QT_MOC_LITERAL(5, 108, 5), // "index"
QT_MOC_LITERAL(6, 114, 16), // "mCurrentTabIndex"
QT_MOC_LITERAL(7, 131, 38), // "on_pushButton_toggleFullScree..."
QT_MOC_LITERAL(8, 170, 30), // "on_pushButton_Minimize_clicked"
QT_MOC_LITERAL(9, 201, 27), // "on_pushButton_Close_clicked"
QT_MOC_LITERAL(10, 229, 49) // "on_pushButton_MalzemeGiderCre..."

    },
    "DetayliHesapDialog\0"
    "on_lineEdit_CariControlFilter_textChanged\0"
    "\0arg1\0on_listView_CariiControlKisiList_clicked\0"
    "index\0mCurrentTabIndex\0"
    "on_pushButton_toggleFullScreen_clicked\0"
    "on_pushButton_Minimize_clicked\0"
    "on_pushButton_Close_clicked\0"
    "on_pushButton_MalzemeGiderCreateTestEntry_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DetayliHesapDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x08 /* Private */,
       6,    1,   55,    2, 0x08 /* Private */,
       7,    0,   58,    2, 0x08 /* Private */,
       8,    0,   59,    2, 0x08 /* Private */,
       9,    0,   60,    2, 0x08 /* Private */,
      10,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DetayliHesapDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DetayliHesapDialog *_t = static_cast<DetayliHesapDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_lineEdit_CariControlFilter_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_listView_CariiControlKisiList_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->mCurrentTabIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_toggleFullScreen_clicked(); break;
        case 4: _t->on_pushButton_Minimize_clicked(); break;
        case 5: _t->on_pushButton_Close_clicked(); break;
        case 6: _t->on_pushButton_MalzemeGiderCreateTestEntry_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject DetayliHesapDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DetayliHesapDialog.data,
      qt_meta_data_DetayliHesapDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DetayliHesapDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetayliHesapDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DetayliHesapDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "DBUser"))
        return static_cast< DBUser*>(this);
    return QDialog::qt_metacast(_clname);
}

int DetayliHesapDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
