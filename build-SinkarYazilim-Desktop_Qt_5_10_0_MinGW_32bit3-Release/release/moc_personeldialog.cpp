/****************************************************************************
** Meta object code from reading C++ file 'personeldialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/personel/personeldialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'personeldialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PersonelDialog_t {
    QByteArrayData data[14];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PersonelDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PersonelDialog_t qt_meta_stringdata_PersonelDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PersonelDialog"
QT_MOC_LITERAL(1, 15, 6), // "status"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "const char*"
QT_MOC_LITERAL(4, 35, 26), // "on_pushButton_Save_clicked"
QT_MOC_LITERAL(5, 62, 9), // "setstatus"
QT_MOC_LITERAL(6, 72, 19), // "bsoncxx::exception&"
QT_MOC_LITERAL(7, 92, 1), // "e"
QT_MOC_LITERAL(8, 94, 20), // "mongocxx::exception&"
QT_MOC_LITERAL(9, 115, 29), // "on_pushButton_Refresh_clicked"
QT_MOC_LITERAL(10, 145, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(11, 166, 5), // "index"
QT_MOC_LITERAL(12, 172, 28), // "on_pushButton_addNew_clicked"
QT_MOC_LITERAL(13, 201, 28) // "on_pushButton_delete_clicked"

    },
    "PersonelDialog\0status\0\0const char*\0"
    "on_pushButton_Save_clicked\0setstatus\0"
    "bsoncxx::exception&\0e\0mongocxx::exception&\0"
    "on_pushButton_Refresh_clicked\0"
    "on_tableView_clicked\0index\0"
    "on_pushButton_addNew_clicked\0"
    "on_pushButton_delete_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PersonelDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       5,    1,   66,    2, 0x08 /* Private */,
       5,    1,   69,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 8,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PersonelDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PersonelDialog *_t = static_cast<PersonelDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->status((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_Save_clicked(); break;
        case 2: _t->setstatus((*reinterpret_cast< bsoncxx::exception(*)>(_a[1]))); break;
        case 3: _t->setstatus((*reinterpret_cast< mongocxx::exception(*)>(_a[1]))); break;
        case 4: _t->setstatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_Refresh_clicked(); break;
        case 6: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_addNew_clicked(); break;
        case 8: _t->on_pushButton_delete_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PersonelDialog::*_t)(const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PersonelDialog::status)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PersonelDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PersonelDialog.data,
      qt_meta_data_PersonelDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PersonelDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PersonelDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PersonelDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PersonelDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void PersonelDialog::status(const char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
