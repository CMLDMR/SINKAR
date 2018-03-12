#ifndef DEPODIALOG_H
#define DEPODIALOG_H

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


#include "src/quickwidget.h"

#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;

namespace Ui {
class DepoDialog;
}




class DepoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DepoDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~DepoDialog();






private slots:

    void on_pushButton_ekle_clicked();

    void refreshList();

    void on_pushButton_close_clicked();

    void on_pushButton_yenile_clicked();

    void on_pushButton_delete_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::DepoDialog *ui;

    void setNewDepo(std::string newDepoName);

    mongocxx::database* db;

    QStandardItemModel* model;

    void deleteItem(std::string oid);
};











#endif // DEPODIALOG_H
