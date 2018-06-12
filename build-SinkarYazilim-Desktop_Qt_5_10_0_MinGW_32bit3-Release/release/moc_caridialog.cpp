/****************************************************************************
** Meta object code from reading C++ file 'caridialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/Kasa/caridialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'caridialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CariDialog_t {
    QByteArrayData data[11];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CariDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CariDialog_t qt_meta_stringdata_CariDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CariDialog"
QT_MOC_LITERAL(1, 11, 33), // "on_pushButton_CloseDialog_cli..."
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 29), // "on_pushButton_addKisi_clicked"
QT_MOC_LITERAL(4, 76, 35), // "on_lineEdit_ProxyFilter_textC..."
QT_MOC_LITERAL(5, 112, 4), // "arg1"
QT_MOC_LITERAL(6, 117, 34), // "on_pushButton_refereshList_cl..."
QT_MOC_LITERAL(7, 152, 25), // "on_listView_doubleClicked"
QT_MOC_LITERAL(8, 178, 5), // "index"
QT_MOC_LITERAL(9, 184, 32), // "on_pushButton_SelectKisi_clicked"
QT_MOC_LITERAL(10, 217, 19) // "on_listView_clicked"

    },
    "CariDialog\0on_pushButton_CloseDialog_clicked\0"
    "\0on_pushButton_addKisi_clicked\0"
    "on_lineEdit_ProxyFilter_textChanged\0"
    "arg1\0on_pushButton_refereshList_clicked\0"
    "on_listView_doubleClicked\0index\0"
    "on_pushButton_SelectKisi_clicked\0"
    "on_listView_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CariDialog[] = {

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
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    1,   55,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,

       0        // eod
};

void CariDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CariDialog *_t = static_cast<CariDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_CloseDialog_clicked(); break;
        case 1: _t->on_pushButton_addKisi_clicked(); break;
        case 2: _t->on_lineEdit_ProxyFilter_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_refereshList_clicked(); break;
        case 4: _t->on_listView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_SelectKisi_clicked(); break;
        case 6: _t->on_listView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CariDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CariDialog.data,
      qt_meta_data_CariDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CariDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CariDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CariDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CariDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
