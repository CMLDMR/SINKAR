#ifndef CARIDIALOG_H
#define CARIDIALOG_H

#include <QtGlobal>

#include "../snkkey.h"
#include "mongoheaders.h"


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
class CariDialog;
}

class CariDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CariDialog(mongocxx::database* _db ,double _toplamMiktar , double _indirimliMiktar , std::string _siparisOid , QWidget *parent = 0);
    ~CariDialog();

    bool setHesap() const;



private slots:
    void on_pushButton_CloseDialog_clicked();

    void on_pushButton_addKisi_clicked();

    void on_lineEdit_ProxyFilter_textChanged(const QString &arg1);

    void on_pushButton_refereshList_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_SelectKisi_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::CariDialog *ui;
    mongocxx::database *db;


    void initKisiList();

    bool mSetHesap;
    void setSetHesap(bool setHesap);


    QStandardItemModel* model;
    QSortFilterProxyModel* proxyModel;

    double ToplamMiktar;

    double ToplamMiktar_ind;


    bool mSelectedKisi;
    bool selectedKisi() const;
    void setSelectedKisi(bool selectedKisi);

    std::string siparisOid;

    bsoncxx::array::value getSiparisArray(std::string _SiparisOid);
    std::string getSiparisKasa(std::string _siparisOid);

};

#endif // CARIDIALOG_H
