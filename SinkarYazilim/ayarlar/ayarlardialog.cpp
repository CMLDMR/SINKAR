#include "ayarlardialog.h"
#include "ui_ayarlardialog.h"


#include "depodialog.h"
#include "malzemekalemidialog.h"
#include "recetedialog.h"

AyarlarDialog::AyarlarDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AyarlarDialog),
    db(_db)
{
    ui->setupUi(this);
}

AyarlarDialog::~AyarlarDialog()
{
    delete ui;
}

void AyarlarDialog::on_pushButton_depo_clicked()
{
    DepoDialog* mDialog = new DepoDialog(db);
    mDialog->exec();
    mDialog->deleteLater();
}

void AyarlarDialog::on_pushButton_malzeme_clicked()
{
    MalzemeKalemiDialog* mDialog = new MalzemeKalemiDialog(db);
    mDialog->exec();
    mDialog->deleteLater();
}

void AyarlarDialog::on_pushButton_recete_clicked()
{
    ReceteDialog* mDialog = new ReceteDialog(db);
    mDialog->exec();
    mDialog->deleteLater();
}
