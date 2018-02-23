#ifndef PERSONELDIALOG_H
#define PERSONELDIALOG_H


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
class PersonelDialog;
}

class PersonelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonelDialog(mongocxx::database* _db,QWidget *parent = 0);
    ~PersonelDialog();

signals:

    void status(const char*);

private slots:
    void on_pushButton_Save_clicked();
    void setstatus(bsoncxx::exception &e);
    void setstatus(mongocxx::exception &e);
    void setstatus(QString e);

    void on_pushButton_Refresh_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_addNew_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::PersonelDialog *ui;

    void saveNew();

    mongocxx::database* db;

    QStandardItemModel *mModel;
    void removeRows();
    void refreshList();
};

#endif // PERSONELDIALOG_H
