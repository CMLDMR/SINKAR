#include "carihesapdialog.h"
#include "ui_carihesapdialog.h"

#include "odemealdialog.h"
#include "detaylihesapdialog.h"


CariHesapDialog::CariHesapDialog(mongocxx::database *_db, bsoncxx::document::value *_user, QWidget *parent) :
    DBUser (_db,_user),
    QDialog(parent),
    ui(new Ui::CariHesapDialog),
    db(_db)

{
    ui->setupUi(this);

    this->setWindowTitle("Cari Hesap Kontrol");
}

CariHesapDialog::~CariHesapDialog()
{
    delete ui;
}

void CariHesapDialog::on_pushButton_OdemeAl_clicked()
{
    auto mDialog = std::make_unique<OdemeAlDialog>(db);

    mDialog->exec();
}

void CariHesapDialog::on_pushButton_Hesaplar_clicked()
{
    auto mDialog = std::make_unique<DetayliHesapDialog>(this->getDb(),this->getUser());

    mDialog->exec();
}
