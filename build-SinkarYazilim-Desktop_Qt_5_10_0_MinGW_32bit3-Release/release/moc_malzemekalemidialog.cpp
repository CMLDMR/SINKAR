/****************************************************************************
** Meta object code from reading C++ file 'malzemekalemidialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SinkarYazilim/ayarlar/malzemekalemidialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'malzemekalemidialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MalzemeKalemiDialog_t {
    QByteArrayData data[17];
    char stringdata0[426];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MalzemeKalemiDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MalzemeKalemiDialog_t qt_meta_stringdata_MalzemeKalemiDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "MalzemeKalemiDialog"
QT_MOC_LITERAL(1, 20, 33), // "on_pushButton_NewKategori_cli..."
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 32), // "on_pushButton_NewMalzeme_clicked"
QT_MOC_LITERAL(4, 88, 28), // "on_listView_kategori_clicked"
QT_MOC_LITERAL(5, 117, 5), // "index"
QT_MOC_LITERAL(6, 123, 18), // "refreshMalzemeList"
QT_MOC_LITERAL(7, 142, 13), // "QtBsonObject&"
QT_MOC_LITERAL(8, 156, 6), // "filter"
QT_MOC_LITERAL(9, 163, 27), // "on_listView_malzeme_clicked"
QT_MOC_LITERAL(10, 191, 33), // "on_pushButton_SaveMalzeme_cli..."
QT_MOC_LITERAL(11, 225, 47), // "on_comboBox_MalzemeKategori_c..."
QT_MOC_LITERAL(12, 273, 4), // "arg1"
QT_MOC_LITERAL(13, 278, 36), // "on_pushButton_deleteKategori_..."
QT_MOC_LITERAL(14, 315, 37), // "on_pushButton_refreshKategori..."
QT_MOC_LITERAL(15, 353, 35), // "on_pushButton_deleteMalzeme_c..."
QT_MOC_LITERAL(16, 389, 36) // "on_pushButton_refreshMalzeme_..."

    },
    "MalzemeKalemiDialog\0"
    "on_pushButton_NewKategori_clicked\0\0"
    "on_pushButton_NewMalzeme_clicked\0"
    "on_listView_kategori_clicked\0index\0"
    "refreshMalzemeList\0QtBsonObject&\0"
    "filter\0on_listView_malzeme_clicked\0"
    "on_pushButton_SaveMalzeme_clicked\0"
    "on_comboBox_MalzemeKategori_currentIndexChanged\0"
    "arg1\0on_pushButton_deleteKategori_clicked\0"
    "on_pushButton_refreshKategori_clicked\0"
    "on_pushButton_deleteMalzeme_clicked\0"
    "on_pushButton_refreshMalzeme_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MalzemeKalemiDialog[] = {

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
       4,    1,   71,    2, 0x08 /* Private */,
       6,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    1,   81,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,
      15,    0,   86,    2, 0x08 /* Private */,
      16,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MalzemeKalemiDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MalzemeKalemiDialog *_t = static_cast<MalzemeKalemiDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_NewKategori_clicked(); break;
        case 1: _t->on_pushButton_NewMalzeme_clicked(); break;
        case 2: _t->on_listView_kategori_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->refreshMalzemeList((*reinterpret_cast< QtBsonObject(*)>(_a[1]))); break;
        case 4: _t->on_listView_malzeme_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_SaveMalzeme_clicked(); break;
        case 6: _t->on_comboBox_MalzemeKategori_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_deleteKategori_clicked(); break;
        case 8: _t->on_pushButton_refreshKategori_clicked(); break;
        case 9: _t->on_pushButton_deleteMalzeme_clicked(); break;
        case 10: _t->on_pushButton_refreshMalzeme_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MalzemeKalemiDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MalzemeKalemiDialog.data,
      qt_meta_data_MalzemeKalemiDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MalzemeKalemiDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MalzemeKalemiDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MalzemeKalemiDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MalzemeKalemiDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
