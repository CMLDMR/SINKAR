#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(mongocxx::database* _db , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    db(_db)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_Kapat_clicked()
{
    qApp->quit();
}

void LoginDialog::on_pushButton_login_clicked()
{

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Personel::username,ui->lineEdit_username->text().toStdString().c_str()));
        filter.append(kvp(SNKKey::Personel::pasword,ui->lineEdit_password->text().toStdString().c_str()));
    } catch (bsoncxx::exception &e) {

    }


    try {
        auto collection = db->collection(SNKKey::Personel::collection);

        auto val = collection.find_one(filter.view());
        if( val )
        {
            auto view = val.value().view();
            if( !view.empty() )
            {
                this->close();
            }
        }
    } catch (mongocxx::exception &e) {

    }


}
