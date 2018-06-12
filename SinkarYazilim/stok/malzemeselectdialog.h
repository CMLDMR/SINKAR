#ifndef MALZEMESELECTDIALOG_H
#define MALZEMESELECTDIALOG_H


#include <QtGlobal>
#include "../snkkey.h"
#include "mongoheaders.h"


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


#include <QMessageBox>

#include <QStandardItemModel>
#include <QStandardItem>


namespace Ui {
class MalzemeSelectDialog;
}

class MalzemeSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MalzemeSelectDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~MalzemeSelectDialog();

    bool clickAccepted() const;

    bsoncxx::types::value malzemeOid() const;

    void setKategori(const QString &kategoriName);

private slots:

    void on_comboBox_KategoriFilter_currentIndexChanged(const QString &arg1);

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_iptal_clicked();

private:
    Ui::MalzemeSelectDialog *ui;

    mongocxx::database* db;

    void showMessage(QString mesaj , QMessageBox::Icon icon = QMessageBox::Icon::Information);

    QStandardItemModel* model;


    bool mClickAccepted;
    void setClickAccepted(bool clickAccepted);

    bsoncxx::types::value mMalzemeOid;
    void setMalzemeOid(const bsoncxx::types::value &malzemeOid);



};

#endif // MALZEMESELECTDIALOG_H
