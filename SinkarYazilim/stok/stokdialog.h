#ifndef STOKDIALOG_H
#define STOKDIALOG_H

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



#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QPainter>


class StokItemDeletegate;


namespace Ui {
class StokDialog;
}

class StokDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StokDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~StokDialog();

private slots:
    void on_pushButton_malzemeGirisi_clicked();

    void on_pushButton_malzemeCikisi_clicked();

private:
    Ui::StokDialog *ui;
    mongocxx::database* db;


    void setmessage(QString msg);
    void setmessage(QString msg,mongocxx::exception &e);
    void setmessage(QString msg,bsoncxx::exception &e);


    void initDepoList();

    QStandardItemModel* model;
    StokItemDeletegate* mItemDelegate;

private slots:
    void initMalzemeList(QString depo = "Hepsi");

    void on_pushButton_close_clicked();
};



class StokItemDeletegate : public QStyledItemDelegate
{
public:
    StokItemDeletegate();

    enum DataRole
    {
        MiktarRole = Qt::UserRole + 1,
        BirimRole,
        OidRole,
        DepoRole
    };

    void paint(QPainter* painter , const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option , const QModelIndex &index) const;


private:
    const int padding = 5;
};

#endif // STOKDIALOG_H
