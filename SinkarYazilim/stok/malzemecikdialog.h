#ifndef MALZEMECIKDIALOG_H
#define MALZEMECIKDIALOG_H


#include <QtGlobal>
#include "../snkkey.h"
#include "mongoheaders.h"
#include <ctime>
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */


#include <KDReports/KDReportsReport.h>
#include <KDReports/KDReportsTextElement.h>
#include <KDReports/KDReportsPreviewDialog.h>
#include <QPrintDialog>


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
#include <QSortFilterProxyModel>
#include <QPainter>
#include <QDateTime>

namespace Ui {
class MalzemeCikDialog;
}

class ItemDelegate;

class MalzemeCikDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MalzemeCikDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~MalzemeCikDialog();

private:
    Ui::MalzemeCikDialog *ui;

    mongocxx::database* db;

    void initDepolar();

    void ShowMessage(QString mesaj , bsoncxx::exception &e , QMessageBox::Icon icon = QMessageBox::Icon::Information);
    void ShowMessage(QString mesaj , mongocxx::exception &e , QMessageBox::Icon icon = QMessageBox::Icon::Information);
    void ShowMessage(QString mesaj , QMessageBox::Icon icon = QMessageBox::Icon::Information);


    QStandardItemModel* model;
    QSortFilterProxyModel* filterModel;
    ItemDelegate* itemDelegate;

    QStandardItemModel* selectedmodel;

    void initMalzemeList();


    struct MalzemeStruct
    {
        std::string oid;
        double miktar;
        std::string birim;
        std::string adi;
    };


    void PrintSevk(std::string oid);

private slots:
    void setDestinationDepo(int index);

    void on_lineEdit_filter_textChanged(const QString &arg1);
    void on_listView_currentStock_doubleClicked(const QModelIndex &index);
    void on_listView_selectedStock_doubleClicked(const QModelIndex &index);
    void on_pushButton_cancel_clicked();
    void on_pushButton_ok_clicked();
};



class ItemDelegate : public QStyledItemDelegate
{
public:
    ItemDelegate();

    enum Role{
        title = Qt::UserRole+1,
        miktar,
        birim,
        malzemeoid
    };


    void paint(QPainter* painter , const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option , const QModelIndex &index) const;

private:
    const int padding = 5;
};


#endif // MALZEMECIKDIALOG_H
