#ifndef RECETEDIALOG_H
#define RECETEDIALOG_H


#include <QtGlobal>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif


#include "../snkkey.h"
#include "qtbsonobject.h"

#include <QStandardItem>
#include <QStandardItemModel>


#include "src/quickwidget.h"

#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


#include <QStyledItemDelegate>
#include <QPainter>


using namespace SNKKey;

namespace Ui {
class ReceteDialog;
}



class MalzemeItemDelegate;
class ReceteDelegate;




class ReceteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceteDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~ReceteDialog();

private slots:
    void on_pushButton_addreceteKategori_clicked();

    void on_pushButton_addNew_clicked();

    void save_new();

    void on_pushButton_receteSave_clicked();

    void on_pushButton_addMalzeme_clicked();

    void on_listView_MalzemeList_doubleClicked(const QModelIndex &index);

    void on_doubleSpinBox_recete_kdv_valueChanged(double arg1);

    void on_doubleSpinBox_karmarji_valueChanged(double arg1);



    void on_pushButton_refreshRecete_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_kapat_clicked();

private:
    Ui::ReceteDialog *ui;

    mongocxx::database* db;

    void showmessage(QString mesage,QMessageBox::Icon icon = QMessageBox::Icon::Information);

    void setmessage(QString e);
    void setmessage(mongocxx::exception &e);
    void setmessage(bsoncxx::exception &e);


    QStandardItemModel* malzemeModel;
    MalzemeItemDelegate* malzemeDelegate;


    QStandardItemModel* receteModel;
    ReceteDelegate* receteDelegate;


    bool insert(QString collection , QtBsonObject &obj);

    void CalcFiyat();

    void resetKategoriList();

    void reinitReceteList();
};



class ReceteDelegate : public QStyledItemDelegate
{
public:
    ReceteDelegate();

    enum datarole{
        KategoriRole = Qt::UserRole + 1,
        Oid
    };

    void paint(QPainter*painter,const QStyleOptionViewItem &option,const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    const int padding= 5;
};





class MalzemeItemDelegate : public QStyledItemDelegate
{
public:
    MalzemeItemDelegate();

    enum datarole {
        HeaderRole = Qt::UserRole + 1,
        Kategori,
        KategoriOid,
        Oid,
        Birimi,
        Kdv,
        Fiyat,
        Miktar,
        MiktarType
    };

    void paint(QPainter* painter,const QStyleOptionViewItem &option,const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const;


private:
    const int padding= 5;
};



#endif // RECETEDIALOG_H
