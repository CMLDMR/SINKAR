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

class ReceteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceteDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~ReceteDialog();

private slots:
    void on_pushButton_addreceteKategori_clicked();

private:
    Ui::ReceteDialog *ui;

    mongocxx::database* db;


    void setmessage(QString e);
    void setmessage(mongocxx::exception &e);
    void setmessage(bsoncxx::exception &e);
};

#endif // RECETEDIALOG_H
