#ifndef AYARLARDIALOG_H
#define AYARLARDIALOG_H

#include <QtGlobal>



#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif



#include "../snkkey.h"
#include "mongoheaders.h"

#include <QStandardItem>
#include <QStandardItemModel>


using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;



namespace Ui {
class AyarlarDialog;
}

class AyarlarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AyarlarDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~AyarlarDialog();

private slots:
    void on_pushButton_depo_clicked();

    void on_pushButton_malzeme_clicked();

private:
    Ui::AyarlarDialog *ui;

    mongocxx::database* db;
};

#endif // AYARLARDIALOG_H
