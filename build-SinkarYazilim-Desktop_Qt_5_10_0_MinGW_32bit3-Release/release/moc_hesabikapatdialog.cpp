/****************************************************************************
** Meta object code from reading C++ file 'hesabikapatdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/Kasa/hesabikapatdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hesabikapatdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HesabiKapatDialog_t {
    QByteArrayData data[10];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HesabiKapatDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HesabiKapatDialog_t qt_meta_stringdata_HesabiKapatDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "HesabiKapatDialog"
QT_MOC_LITERAL(1, 18, 33), // "on_pushButton_masayiKapat_cli..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 35), // "on_doubleSpinBox_Nakit_valueC..."
QT_MOC_LITERAL(4, 89, 4), // "arg1"
QT_MOC_LITERAL(5, 94, 40), // "on_doubleSpinBox_KrediKarti_v..."
QT_MOC_LITERAL(6, 135, 33), // "on_pushButton_TamamiNakit_cli..."
QT_MOC_LITERAL(7, 169, 38), // "on_pushButton_TamamiKrediKart..."
QT_MOC_LITERAL(8, 208, 34), // "on_pushButton_CariHesabaAt_cl..."
QT_MOC_LITERAL(9, 243, 32) // "on_pushButton_OdemeIptal_clicked"

    },
    "HesabiKapatDialog\0on_pushButton_masayiKapat_clicked\0"
    "\0on_doubleSpinBox_Nakit_valueChanged\0"
    "arg1\0on_doubleSpinBox_KrediKarti_valueChanged\0"
    "on_pushButton_TamamiNakit_clicked\0"
    "on_pushButton_TamamiKrediKarti_clicked\0"
    "on_pushButton_CariHesabaAt_clicked\0"
    "on_pushButton_OdemeIptal_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HesabiKapatDialog[] = {

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
       3,    1,   50,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HesabiKapatDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HesabiKapatDialog *_t = static_cast<HesabiKapatDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_masayiKapat_clicked(); break;
        case 1: _t->on_doubleSpinBox_Nakit_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_doubleSpinBox_KrediKarti_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_TamamiNakit_clicked(); break;
        case 4: _t->on_pushButton_TamamiKrediKarti_clicked(); break;
        case 5: _t->on_pushButton_CariHesabaAt_clicked(); break;
        case 6: _t->on_pushButton_OdemeIptal_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject HesabiKapatDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HesabiKapatDialog.data,
      qt_meta_data_HesabiKapatDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HesabiKapatDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HesabiKapatDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HesabiKapatDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int HesabiKapatDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
