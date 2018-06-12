#ifndef ADDCARIHESAPDIALOG_H
#define ADDCARIHESAPDIALOG_H

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

namespace Ui {
class addCariHesapDialog;
}

class addCariHesapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addCariHesapDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~addCariHesapDialog();

    QString name() const;

    bool accepted() const;

private slots:
    void on_pushButton_save_clicked();

private:
    Ui::addCariHesapDialog *ui;

    mongocxx::database* db;

    bool mAccepted;
    QString mName;
    void setName(QString name);
    void setAccepted(bool accepted);

};

#endif // ADDCARIHESAPDIALOG_H
