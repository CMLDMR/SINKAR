#include "addcarihesapdialog.h"
#include "ui_addcarihesapdialog.h"

addCariHesapDialog::addCariHesapDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCariHesapDialog),
    db(_db)
{
    ui->setupUi(this);
    this->setWindowTitle("Cari Hesap Ekle");
    this->setAccepted(false);
}

addCariHesapDialog::~addCariHesapDialog()
{
    delete ui;
}

void addCariHesapDialog::on_pushButton_save_clicked()
{

#ifndef SINKAR
    auto doc = document{};

    try {
        doc.append(kvp(SNKKey::Cari::Kisiler::ad,ui->lineEdit_ad->text().toStdString()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Kisiler::adres,ui->lineEdit_adres->text().toStdString()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Kisiler::iletisim,ui->lineEdit_iletisim->text().toStdString()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        auto ins = db->collection(SNKKey::Cari::Kisiler::collection).insert_one(doc.view());
        if( ins )
        {
            if( ins.value().result().inserted_count() )
            {
                this->setAccepted(true);
                this->setName(ui->lineEdit_ad->text());
                this->close();
            }else{
                std::cout << "Error: No inserted" << std::endl;
            }
        }else{
            std::cout << "Errro: No Document Returned" << std::endl;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Errror: " << e.what() << std::endl;
    }

#endif
}

bool addCariHesapDialog::accepted() const
{
    return mAccepted;
}

void addCariHesapDialog::setAccepted(bool accepted)
{
    mAccepted = accepted;
}

QString addCariHesapDialog::name() const
{
    return mName;
}

void addCariHesapDialog::setName(QString name)
{
    mName = name;
}
