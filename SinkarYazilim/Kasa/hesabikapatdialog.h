#ifndef HESABIKAPATDIALOG_H
#define HESABIKAPATDIALOG_H

#include <QtGlobal>

#include "../snkkey.h"
#include "mongoheaders.h"


#include <QMessageBox>
#include <QDate>
#include <QTime>
#include <QMap>
#include <QMapIterator>
#include <utility>


using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;


#ifndef SINKAR
#include "caridialog.h"
#endif



#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif



namespace Ui {
class HesabiKapatDialog;
}

class HesabiKapatDialog : public QDialog
{
    Q_OBJECT

public:

    explicit HesabiKapatDialog(mongocxx::database* _db , double toplamMiktar, double _indirimliMiktar , std::string siparisOid, std::string depo , QWidget *parent = 0);

    ~HesabiKapatDialog();

    bool odendi() const;

    void setOdendi(bool odendi);

private slots:
    void on_pushButton_masayiKapat_clicked();

    void on_doubleSpinBox_Nakit_valueChanged(double arg1);

    void on_doubleSpinBox_KrediKarti_valueChanged(double arg1);

    void on_pushButton_TamamiNakit_clicked();

    void on_pushButton_TamamiKrediKarti_clicked();

    void on_pushButton_CariHesabaAt_clicked();

    void on_pushButton_OdemeIptal_clicked();

private:
    Ui::HesabiKapatDialog *ui;

    mongocxx::database* db;

    double ToplamMiktar;
    double IndirimliMiktar;

    std::string SiparisOid;

    std::string CurrentDepo;

    bool mOdendi;

    void UpdateStock(std::string siparisoid);
};

#endif // HESABIKAPATDIALOG_H
