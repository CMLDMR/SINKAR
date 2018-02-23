#include "personeldialog.h"
#include "ui_personeldialog.h"

PersonelDialog::PersonelDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonelDialog),
    db(_db)
{
    ui->setupUi(this);
}

PersonelDialog::~PersonelDialog()
{
    delete ui;
}

void PersonelDialog::on_pushButton_Save_clicked()
{

    if( ui->lineEdit_oid->text().isEmpty() )
    {
        this->saveNew();
    }


}

void PersonelDialog::setstatus(bsoncxx::exception &e)
{

    ui->label_status->setText(QString("Doc Error: %1").arg(e.what()));

}

void PersonelDialog::setstatus(mongocxx::exception &e)
{

    ui->label_status->setText(QString("DB Error: %1").arg(e.what()));

}

void PersonelDialog::setstatus(QString e)
{

    ui->label_status->setText("Bilgi: " + e);

}

void PersonelDialog::saveNew()
{

    auto doc = document{};

    try {
        doc.append(kvp(SNKKey::Personel::ad,ui->lineEdit_name->text().toStdString()));
        doc.append(kvp(SNKKey::Personel::soyad,ui->lineEdit_surname->text().toStdString()));
        doc.append(kvp(SNKKey::Personel::pasword,ui->lineEdit_password->text().toStdString()));
        doc.append(kvp(SNKKey::Personel::username,ui->lineEdit_username->text().toStdString()));
    } catch (bsoncxx::exception &e) {
        setstatus(e);
    }

    try {
        auto collection = db->collection(SNKKey::Personel::collection);
        auto ins = collection.insert_one(doc.view());
        if( ins )
        {
            setstatus(QString("inserted: %1").arg(ins.value().result().inserted_count()).toStdString().c_str());
        }else{
            setstatus("No Document inserted");
        }
    } catch (mongocxx::exception &e) {
        setstatus(e);
    }



}
