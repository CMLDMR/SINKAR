#ifndef SELECTFIRMADIALOG_H
#define SELECTFIRMADIALOG_H

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

#include <QStandardItemModel>
#include <QStandardItem>
#include <QSortFilterProxyModel>


namespace Ui {
class SelectFirmaDialog;
}

class SelectFirmaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectFirmaDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~SelectFirmaDialog();

    std::string getFirmaOid() const;
    void setFirmaOid(const std::string &value);

    bool getAccepted() const;
    void setAccepted(bool accepted);

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::SelectFirmaDialog *ui;

    mongocxx::database* db;

    void initFirmaList();

    std::string firmaOid;

    bool mAccepted;

    QStandardItemModel* model;

    QSortFilterProxyModel *proxyModel;
};

#endif // SELECTFIRMADIALOG_H
