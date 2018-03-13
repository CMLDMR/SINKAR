/****************************************************************************
** Meta object code from reading C++ file 'recetedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/ayarlar/recetedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recetedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReceteDialog_t {
    QByteArrayData data[15];
    char stringdata0[371];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReceteDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReceteDialog_t qt_meta_stringdata_ReceteDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ReceteDialog"
QT_MOC_LITERAL(1, 13, 39), // "on_pushButton_addreceteKatego..."
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 28), // "on_pushButton_addNew_clicked"
QT_MOC_LITERAL(4, 83, 8), // "save_new"
QT_MOC_LITERAL(5, 92, 32), // "on_pushButton_receteSave_clicked"
QT_MOC_LITERAL(6, 125, 32), // "on_pushButton_addMalzeme_clicked"
QT_MOC_LITERAL(7, 158, 37), // "on_listView_MalzemeList_doubl..."
QT_MOC_LITERAL(8, 196, 5), // "index"
QT_MOC_LITERAL(9, 202, 40), // "on_doubleSpinBox_recete_kdv_v..."
QT_MOC_LITERAL(10, 243, 4), // "arg1"
QT_MOC_LITERAL(11, 248, 38), // "on_doubleSpinBox_karmarji_val..."
QT_MOC_LITERAL(12, 287, 35), // "on_pushButton_refreshRecete_c..."
QT_MOC_LITERAL(13, 323, 19), // "on_listView_clicked"
QT_MOC_LITERAL(14, 343, 27) // "on_pushButton_kapat_clicked"

    },
    "ReceteDialog\0on_pushButton_addreceteKategori_clicked\0"
    "\0on_pushButton_addNew_clicked\0save_new\0"
    "on_pushButton_receteSave_clicked\0"
    "on_pushButton_addMalzeme_clicked\0"
    "on_listView_MalzemeList_doubleClicked\0"
    "index\0on_doubleSpinBox_recete_kdv_valueChanged\0"
    "arg1\0on_doubleSpinBox_karmarji_valueChanged\0"
    "on_pushButton_refreshRecete_clicked\0"
    "on_listView_clicked\0on_pushButton_kapat_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReceteDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    1,   84,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,

       0        // eod
};

void ReceteDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReceteDialog *_t = static_cast<ReceteDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_addreceteKategori_clicked(); break;
        case 1: _t->on_pushButton_addNew_clicked(); break;
        case 2: _t->save_new(); break;
        case 3: _t->on_pushButton_receteSave_clicked(); break;
        case 4: _t->on_pushButton_addMalzeme_clicked(); break;
        case 5: _t->on_listView_MalzemeList_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_doubleSpinBox_recete_kdv_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_doubleSpinBox_karmarji_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_refreshRecete_clicked(); break;
        case 9: _t->on_listView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_kapat_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ReceteDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ReceteDialog.data,
      qt_meta_data_ReceteDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ReceteDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReceteDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReceteDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ReceteDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
