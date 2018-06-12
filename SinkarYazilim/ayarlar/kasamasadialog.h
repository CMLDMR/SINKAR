#ifndef KASAMASADIALOG_H
#define KASAMASADIALOG_H

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
#include <QStyledItemDelegate>
#include <QPainter>

namespace Ui {
class KasaMasaDialog;
}

namespace KasaStyle {
class ItemDelegate;
}

namespace MasaStyle {
class ItemDelegate;
}

class KasaMasaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KasaMasaDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~KasaMasaDialog();

private slots:
    void on_pushButton_addNewKasa_clicked();

private:
    Ui::KasaMasaDialog *ui;

    mongocxx::database* db;

    void initConnection();

    void initDepo();

    mongocxx::cursor find(const std::string collection, const bsoncxx::document::view &view);

    mongocxx::stdx::optional<mongocxx::result::insert_one> insert_one(const std::string collection, const bsoncxx::document::view &view);

    void ShowMessage( QString msg , QMessageBox::Icon icon = QMessageBox::Icon::Information );
    void ShowMessage(bsoncxx::exception &e , QString Message , QMessageBox::Icon icon = QMessageBox::Icon::Warning );
    void ShowMessage(mongocxx::exception &e , QString Message , QMessageBox::Icon icon = QMessageBox::Icon::Warning );

    QStandardItemModel* kasaModel;
    KasaStyle::ItemDelegate* kasaDelegate;
    void initKasalar();

    QStandardItemModel* masaModel;
    MasaStyle::ItemDelegate* masaDelegate;
    void addMasa();
    void initMasalar();
};

namespace KasaStyle {


class ItemDelegate : public QStyledItemDelegate
{
public:
    ItemDelegate() {}

    void paint(QPainter* painter , const QStyleOptionViewItem &option , const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option , const QModelIndex &index) const;


    const int padding = 5;
};

}

namespace MasaStyle {


class ItemDelegate : public QStyledItemDelegate
{
public:
    ItemDelegate() {}

    void paint(QPainter* painter , const QStyleOptionViewItem &option , const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option , const QModelIndex &index) const;


    const int padding = 5;
};

}


#endif // KASAMASADIALOG_H
