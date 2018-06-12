#ifndef MALZEMEGIRDIALOG_H
#define MALZEMEGIRDIALOG_H

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

#include <QCompleter>
#include <QMessageBox>

namespace Ui {
class MalzemeGirDialog;
}

class MalzemeGirDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MalzemeGirDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~MalzemeGirDialog();

private slots:
    void on_pushButton_cancel_clicked();

private:
    Ui::MalzemeGirDialog *ui;

    mongocxx::database* db;



    void setmessage(bsoncxx::exception &e);
    void setmessage(mongocxx::exception &e);
    void setmessage(QString e);
    void setmessage(bsoncxx::exception &e, QString mesaj);
    void setmessage(mongocxx::exception &e, QString mesaj);

    void showMessage(QString mesaj, QMessageBox::Icon icon = QMessageBox::Icon::Information);


    QCompleter* mKategoriCompleter;
    QStringList KategoriList;
    QStringList KategoriListOid;
    void initKategoriList();

    QCompleter* mMalzemeListCompleter;
    QStringList MalzemeList;
    QStringList MalzemeListOid;
    void initMalzemeList();

    void setMalzemeOid(const char* oid);

    void initDepo();


    mongocxx::cursor find(std::string collection , bsoncxx::builder::basic::document filter);
    auto find_one(std::string collection , bsoncxx::builder::basic::document filter);
    auto insert(std::string collection , const bsoncxx::builder::basic::document &insertDoc);


    void setToplamTutar();

    void initFirmalar();





private slots:
    void selectedKategori(const QString &kategoriName);
    void selectedMalzeme(const QString &malzemeName);
    void on_pushButton_SelectMalzeme_clicked();
    void on_doubleSpinBox_miktar_valueChanged(double arg1);
    void on_doubleSpinBox_birimFiyati_valueChanged(double arg1);
    void on_pushButton_clicked();
    void on_pushButton_save_clicked();
};

#endif // MALZEMEGIRDIALOG_H
