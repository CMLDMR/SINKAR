#include "ayarlardialog.h"
#include "ui_ayarlardialog.h"


#include "depodialog.h"
#include "malzemekalemidialog.h"
#include "recetedialog.h"
#include "kasamasadialog.h"
#include "haricigiderayardialog.h"

AyarlarDialog::AyarlarDialog(mongocxx::database *_db, bsoncxx::document::value *_user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AyarlarDialog),
    DBUser (_db,_user)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);

    this->setStyleSheet("QDialog{border:1px solid black;}");
}

AyarlarDialog::~AyarlarDialog()
{
    delete ui;
}

void AyarlarDialog::on_pushButton_depo_clicked()
{
    DepoDialog* mDialog = new DepoDialog(this->getDb());
    mDialog->exec();
    mDialog->deleteLater();
}

void AyarlarDialog::on_pushButton_malzeme_clicked()
{
    MalzemeKalemiDialog* mDialog = new MalzemeKalemiDialog(this->getDb());
    mDialog->exec();
    mDialog->deleteLater();
}

void AyarlarDialog::on_pushButton_recete_clicked()
{
    ReceteDialog* mDialog = new ReceteDialog(this->getDb());
    mDialog->exec();
    mDialog->deleteLater();
}

void AyarlarDialog::on_pushButton_KasaMasa_clicked()
{

    auto mDialog = new KasaMasaDialog(this->getDb());
    mDialog->exec();
    mDialog->deleteLater();

}

void AyarlarDialog::on_pushButton_HariciGiderler_clicked()
{
    auto mDialog = std::make_unique<HariciGiderAyarDialog>(this->getDb(),this->getUser());
    mDialog->exec();
}
