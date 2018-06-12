#ifndef KASADIALOG_H
#define KASADIALOG_H

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
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDate>
#include <QTime>
#include <QSysInfo>



namespace ItemDelegate {
class Delegate;
}


namespace Ui {
class KasaDialog;
}

class KasaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KasaDialog(std::string kasa , mongocxx::database* _db , QWidget *parent = 0);
    ~KasaDialog();

    bool getSelectedMasa() const;
    void setSelectedMasa(bool value);

private slots:
    void on_pushButton_siparis_al_clicked();

private:
    Ui::KasaDialog *ui;


    void initMasa(std::string kasa);
    void refreshMasaList();
    std::string CurrentKasa;
    bool SelectedMasa;
    QStandardItemModel* masaModel;
    ItemDelegate::Delegate* masaDelegate;

    QStandardItemModel* siparisModel;



    void listMasaSiparisi(std::string siparisoid);

    bool setMasaSiparis(std::string masaoid,std::string siparisoid);

    struct ReceteMalzemesi
    {
        std::string oid;
        double miktar;
    };
    double getReceteFiyati(bsoncxx::oid receteoid, double receteMiktar);
    double getReceteIndFiyati(bsoncxx::oid receteoid, double receteMiktar);

    bool masayiKapat(bsoncxx::oid masaoid);

    bool deleteSiparis(bsoncxx::oid siparisOid);

private slots:
    void addSelectedRecete(QString oid, double miktar);





    void on_listView_Masalar_clicked(const QModelIndex &index);

    void on_listView_Masalar_doubleClicked(const QModelIndex &index);

    void on_pushButton_masayiKapat_clicked();

    void on_listView_siparisList_doubleClicked(const QModelIndex &index);

    void on_pushButton_minimize_clicked();

    void on_pushButton_ToggleScreen_clicked();

    void on_pushButton_close_clicked();

private:
    mongocxx::database* db;
    bsoncxx::oid kasaoid;
    void showMsg( QString msg , QMessageBox::Icon icon = QMessageBox::Icon::Information );
    void showMsg( bsoncxx::exception &e, std::string key , QMessageBox::Icon icon = QMessageBox::Warning );
    void showMsg( mongocxx::exception &e, std::string key , QMessageBox::Icon icon = QMessageBox::Warning );
    mongocxx::stdx::optional<bsoncxx::document::value> find_one( const std::string collection , const bsoncxx::document::view &filter , const mongocxx::options::find &findOption = mongocxx::options::find() );
    mongocxx::cursor find( const std::string collection , const bsoncxx::document::view &filter , const mongocxx::options::find &findOption = mongocxx::options::find() );
    mongocxx::stdx::optional<mongocxx::result::insert_one> insert(const std::string collection , const bsoncxx::document::view &doc);

};



#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include <QStyleOptionViewItem>
#include <QModelIndex>


namespace ItemDelegate {

class Delegate : public QStyledItemDelegate
{
public:
    Delegate(){
        mPixmapLoaded = pixmap.load(":/icon/icon/tableFree.png");
        mPixmapLoaded = AcikPixmap.load(":/icon/icon/tableSet.png");
    }

    void paint(QPainter* painter , const QStyleOptionViewItem &option , const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option , const QModelIndex &index) const;

    enum Role
    {
        MasaDurumu = Qt::UserRole + 1,
        MasaOid
    };

private:
    const int padding = 5;
    QPixmap pixmap;
    QPixmap AcikPixmap;
    bool mPixmapLoaded;


};


class ReceteDelegate : public QStyledItemDelegate
{
public:
    ReceteDelegate(){}

    enum datarole{
        KategoriRole = Qt::UserRole + 1,
        Oid,
        Miktar,
        fiyat
    };

    void paint(QPainter*painter,const QStyleOptionViewItem &option,const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    const int padding= 5;
};

}

#endif // KASADIALOG_H
