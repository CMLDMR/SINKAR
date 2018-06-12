#ifndef AYARLARDIALOG_H
#define AYARLARDIALOG_H

#include <QtGlobal>



#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif


#include "dbuser.h"

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

class AyarlarDialog : public QDialog , public DBUser
{
    Q_OBJECT

public:
    explicit AyarlarDialog(mongocxx::database* _db , bsoncxx::document::value* _user , QWidget *parent = nullptr);
    ~AyarlarDialog();

private slots:
    void on_pushButton_depo_clicked();

    void on_pushButton_malzeme_clicked();

    void on_pushButton_recete_clicked();

    void on_pushButton_KasaMasa_clicked();

    void on_pushButton_HariciGiderler_clicked();

private:
    Ui::AyarlarDialog *ui;
};

#endif // AYARLARDIALOG_H
