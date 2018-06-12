#ifndef ADDFIRMADIALOG_H
#define ADDFIRMADIALOG_H

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
class addFirmaDialog;
}

class addFirmaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addFirmaDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~addFirmaDialog();

    bool saveAccepted() const;

    std::string getLastFirmaOid() const;

    bool getSaveAccepted() const;

    void setFirmaName(QString name);

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_iptal_clicked();

private:
    Ui::addFirmaDialog *ui;

    mongocxx::database* db;

    bool mSaveAccepted;
    void setSaveAccepted(bool saveAccepted);

    std::string lastFirmaOid;
    void setLastFirmaOid(const std::string &value);




};

#endif // ADDFIRMADIALOG_H
