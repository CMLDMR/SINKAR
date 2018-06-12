#ifndef SIPARISDIALOG_H
#define SIPARISDIALOG_H

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
#include <QComboBox>

namespace Ui {
class SiparisDialog;
}

namespace Siparis {
    class ReceteDelegate;
}

class SiparisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SiparisDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~SiparisDialog();


signals:
    void selectedRecete(QString Receteoid,double miktar);

private slots:
    void listRecete(const QString &index);

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::SiparisDialog *ui;
    void initilize();


    mongocxx::database* db;

    Siparis::ReceteDelegate* receteDelegate;

    QStandardItemModel* receteModel;

};

#include <QStyledItemDelegate>
#include <QPainter>
#include <QSize>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QDebug>

namespace Siparis {
    class ReceteDelegate : public QStyledItemDelegate
    {
    public:
        ReceteDelegate(){}

        enum datarole{
            KategoriRole = Qt::UserRole + 1,
            Oid
        };

        void paint(QPainter*painter,const QStyleOptionViewItem &option,const QModelIndex &index) const;

        QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    private:
        const int padding= 5;
    };
}

#endif // SIPARISDIALOG_H
