#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QtGlobal>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

#include "../snkkey.h"
#include "mongoheaders.h"


using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_pushButton_Kapat_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::LoginDialog *ui;

    mongocxx::database* db;
};

#endif // LOGINDIALOG_H
