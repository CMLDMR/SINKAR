#ifndef MALZEMEKALEMIDIALOG_H
#define MALZEMEKALEMIDIALOG_H

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



namespace Ui {
class MalzemeKalemiDialog;
}


class MalzemeDelegate;


class MalzemeKalemiDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MalzemeKalemiDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~MalzemeKalemiDialog();

private slots:
    void on_pushButton_NewKategori_clicked();

    void on_pushButton_NewMalzeme_clicked();

    void on_listView_kategori_clicked(const QModelIndex &index);

private:
    Ui::MalzemeKalemiDialog *ui;

    mongocxx::database* db;

    void setmessage(QString e);
    void setmessage(mongocxx::exception &e);
    void setmessage(bsoncxx::exception &e);

    void showmessage(QString mesage,QMessageBox::Icon icon = QMessageBox::Icon::Information);


    void refreshKategoriList();
    QStandardItemModel* kategoriModel;


    QStandardItemModel* malzemeModel;
    MalzemeDelegate* mMalzemeDelegate;
};



class MalzemeDelegate : public QStyledItemDelegate
{
public:
    MalzemeDelegate();
    ~MalzemeDelegate();

    enum datarole {
        HeaderRole = Qt::UserRole + 1,
        Kategori,
        KategoriOid,
        Oid
    };

    void paint(QPainter* painter, const QStyleOptionViewItem &option , const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option , const QModelIndex &index ) const;

private:

    const int padding = 5;

};



#endif // MALZEMEKALEMIDIALOG_H
