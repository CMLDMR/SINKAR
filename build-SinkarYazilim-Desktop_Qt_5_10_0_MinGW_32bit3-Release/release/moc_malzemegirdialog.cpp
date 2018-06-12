/****************************************************************************
** Meta object code from reading C++ file 'malzemegirdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/stok/malzemegirdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'malzemegirdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MalzemeGirDialog_t {
    QByteArrayData data[13];
    char stringdata0[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MalzemeGirDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MalzemeGirDialog_t qt_meta_stringdata_MalzemeGirDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MalzemeGirDialog"
QT_MOC_LITERAL(1, 17, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 16), // "selectedKategori"
QT_MOC_LITERAL(4, 64, 12), // "kategoriName"
QT_MOC_LITERAL(5, 77, 15), // "selectedMalzeme"
QT_MOC_LITERAL(6, 93, 11), // "malzemeName"
QT_MOC_LITERAL(7, 105, 35), // "on_pushButton_SelectMalzeme_c..."
QT_MOC_LITERAL(8, 141, 36), // "on_doubleSpinBox_miktar_value..."
QT_MOC_LITERAL(9, 178, 4), // "arg1"
QT_MOC_LITERAL(10, 183, 41), // "on_doubleSpinBox_birimFiyati_..."
QT_MOC_LITERAL(11, 225, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(12, 247, 26) // "on_pushButton_save_clicked"

    },
    "MalzemeGirDialog\0on_pushButton_cancel_clicked\0"
    "\0selectedKategori\0kategoriName\0"
    "selectedMalzeme\0malzemeName\0"
    "on_pushButton_SelectMalzeme_clicked\0"
    "on_doubleSpinBox_miktar_valueChanged\0"
    "arg1\0on_doubleSpinBox_birimFiyati_valueChanged\0"
    "on_pushButton_clicked\0on_pushButton_save_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MalzemeGirDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       5,    1,   58,    2, 0x08 /* Private */,
       7,    0,   61,    2, 0x08 /* Private */,
       8,    1,   62,    2, 0x08 /* Private */,
      10,    1,   65,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MalzemeGirDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MalzemeGirDialog *_t = static_cast<MalzemeGirDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_cancel_clicked(); break;
        case 1: _t->selectedKategori((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->selectedMalzeme((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_SelectMalzeme_clicked(); break;
        case 4: _t->on_doubleSpinBox_miktar_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_doubleSpinBox_birimFiyati_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pushButton_save_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MalzemeGirDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MalzemeGirDialog.data,
      qt_meta_data_MalzemeGirDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MalzemeGirDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MalzemeGirDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MalzemeGirDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MalzemeGirDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
