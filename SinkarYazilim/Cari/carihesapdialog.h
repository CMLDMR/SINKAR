#ifndef CARIHESAPDIALOG_H
#define CARIHESAPDIALOG_H

#include <QtGlobal>

#include "../snkkey.h"
#include "mongoheaders.h"

#include "dbuser.h"


#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <QMap>
#include <QMapIterator>
#include <utility>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QSortFilterProxyModel>


using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

namespace Ui {
class CariHesapDialog;
}

class CariHesapDialog : public QDialog , public DBUser
{
    Q_OBJECT

public:
    explicit CariHesapDialog(mongocxx::database* _db ,bsoncxx::document::value* _user, QWidget *parent = 0);
    ~CariHesapDialog();

private slots:
    void on_pushButton_OdemeAl_clicked();

    void on_pushButton_Hesaplar_clicked();

private:
    Ui::CariHesapDialog *ui;

    mongocxx::database* db;
};

#endif // CARIHESAPDIALOG_H
