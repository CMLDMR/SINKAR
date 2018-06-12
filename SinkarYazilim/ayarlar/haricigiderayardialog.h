#ifndef HARICIGIDERAYARDIALOG_H
#define HARICIGIDERAYARDIALOG_H

#include "dbuser.h"
#include "delegate.h"

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif


#include <QStandardItemModel>


namespace Ui {
class HariciGiderAyarDialog;
}

class HariciGiderAyarDialog : public QDialog , public DBUser
{
    Q_OBJECT

public:
    explicit HariciGiderAyarDialog(mongocxx::database* _db , bsoncxx::document::value* _user , QWidget *parent = nullptr);
    ~HariciGiderAyarDialog();

    bool selectedKategori() const;
    void setSelectedKategori(bool selectedKategori);

private slots:
    void on_pushButton_addNew_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_change_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::HariciGiderAyarDialog *ui;

    Delegate::KisiDelegate* delegate;
    QStandardItemModel* model;

    void listKategori();


    void changeKategirName(std::string oid );
    void deleteKategori(std::string oid);


    bool mSelectedKategori;
};

#endif // HARICIGIDERAYARDIALOG_H
