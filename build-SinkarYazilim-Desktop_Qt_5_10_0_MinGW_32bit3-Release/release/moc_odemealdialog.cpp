/****************************************************************************
** Meta object code from reading C++ file 'odemealdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/Cari/odemealdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'odemealdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OdemeAlDialog_t {
    QByteArrayData data[13];
    char stringdata0[321];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OdemeAlDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OdemeAlDialog_t qt_meta_stringdata_OdemeAlDialog = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OdemeAlDialog"
QT_MOC_LITERAL(1, 14, 27), // "on_pushButton_close_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 36), // "on_pushButton_toogleMaximize_..."
QT_MOC_LITERAL(4, 80, 30), // "on_pushButton_minimize_clicked"
QT_MOC_LITERAL(5, 111, 30), // "on_lineEdit_filter_textChanged"
QT_MOC_LITERAL(6, 142, 4), // "arg1"
QT_MOC_LITERAL(7, 147, 28), // "on_listView_KisiList_clicked"
QT_MOC_LITERAL(8, 176, 5), // "index"
QT_MOC_LITERAL(9, 182, 29), // "on_pushButton_OdemeAl_clicked"
QT_MOC_LITERAL(10, 212, 41), // "on_pushButton_OdemeListesiniC..."
QT_MOC_LITERAL(11, 254, 33), // "on_pushButton_NakitTamami_cli..."
QT_MOC_LITERAL(12, 288, 32) // "on_pushButton_KrediOdeme_clicked"

    },
    "OdemeAlDialog\0on_pushButton_close_clicked\0"
    "\0on_pushButton_toogleMaximize_clicked\0"
    "on_pushButton_minimize_clicked\0"
    "on_lineEdit_filter_textChanged\0arg1\0"
    "on_listView_KisiList_clicked\0index\0"
    "on_pushButton_OdemeAl_clicked\0"
    "on_pushButton_OdemeListesiniCikar_clicked\0"
    "on_pushButton_NakitTamami_clicked\0"
    "on_pushButton_KrediOdeme_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OdemeAlDialog[] = {

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
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OdemeAlDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OdemeAlDialog *_t = static_cast<OdemeAlDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_close_clicked(); break;
        case 1: _t->on_pushButton_toogleMaximize_clicked(); break;
        case 2: _t->on_pushButton_minimize_clicked(); break;
        case 3: _t->on_lineEdit_filter_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_listView_KisiList_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_OdemeAl_clicked(); break;
        case 6: _t->on_pushButton_OdemeListesiniCikar_clicked(); break;
        case 7: _t->on_pushButton_NakitTamami_clicked(); break;
        case 8: _t->on_pushButton_KrediOdeme_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject OdemeAlDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OdemeAlDialog.data,
      qt_meta_data_OdemeAlDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OdemeAlDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OdemeAlDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OdemeAlDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int OdemeAlDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
