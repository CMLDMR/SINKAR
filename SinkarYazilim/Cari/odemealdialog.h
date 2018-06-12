#ifndef ODEMEALDIALOG_H
#define ODEMEALDIALOG_H

#include <QtGlobal>

#include "../snkkey.h"
#include "mongoheaders.h"


#include <chrono>
#include <thread>

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
#include <QItemDelegate>


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
class OdemeAlDialog;
}

#include <QApplication>

namespace OdemealDialog {
class KisiDelegate;
}



class OdemeAlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OdemeAlDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~OdemeAlDialog();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_toogleMaximize_clicked();

    void on_pushButton_minimize_clicked();

    void on_lineEdit_filter_textChanged(const QString &arg1);

    void on_listView_KisiList_clicked(const QModelIndex &index);

    void on_pushButton_OdemeAl_clicked();

    void on_pushButton_OdemeListesiniCikar_clicked();

    void on_pushButton_NakitTamami_clicked();

    void on_pushButton_KrediOdeme_clicked();

private:
    Ui::OdemeAlDialog *ui;

    mongocxx::database* db;

    void initialize();

    void initKisiList();

    QStandardItemModel* modelKisi;
    QSortFilterProxyModel* proxyKisi;
    OdemealDialog::KisiDelegate* itemDelegate;

    QStandardItemModel* modelHesaplar;
    enum HesapRole {
        Bakiye = Qt::UserRole,
        Oid
    };

    bool NakitOde(std::string oid,double miktar );
    bool KrediKartiOde(std::string oid,double miktar );
    bool KarisikOde(std::string oid,double nakitMiktar,double krediKartiMiktar );

    void initBorcList();

};


#include <QPainter>


namespace OdemealDialog {


class KisiDelegate : public QStyledItemDelegate
{
public:
    KisiDelegate() {}

    void paint(QPainter* painter,const QStyleOptionViewItem &option , const QModelIndex &index) const
    {
        QString isim = index.data(Qt::DisplayRole).toString();

        QFont font = QApplication::font();

        QFontMetrics fontMetrics(font);

        QRect textRect = fontMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,isim);



        painter->save();

        if( option.state & QStyle::StateFlag::State_Selected )
        {
            painter->fillRect(option.rect,option.palette.highlight());
            painter->setPen(Qt::white);
        }else{
            painter->setPen(Qt::black);
        }

        painter->setFont(font);

        painter->drawText(textRect,isim);

        painter->restore();

    }

    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const
    {
        QString isim = index.data(Qt::DisplayRole).toString();

        QFont font = QApplication::font();

        QFontMetrics fontMetrics(font);

        QRect textRect = fontMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,isim);

        return QSize(option.rect.width(),textRect.height() + 2 * padding);
    }

private:
    const int padding = 5;

};



}






#endif // ODEMEALDIALOG_H
