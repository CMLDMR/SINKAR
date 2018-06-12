#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(mongocxx::database* _db , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),
    db(_db)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QDialog{border:1px solid black;}");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_Kapat_clicked()
{
    emit applicationQuit();
    this->close();

}

void LoginDialog::on_pushButton_login_clicked()
{

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Personel::username,ui->lineEdit_username->text().toStdString().c_str()));
        filter.append(kvp(SNKKey::Personel::pasword,ui->lineEdit_password->text().toStdString().c_str()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error Parse UserName Password: " << e.what() << std::endl;
    }


    try {
        auto collection = db->collection(SNKKey::Personel::collection);

        auto val = collection.find_one(filter.view());
        if( val )
        {
            auto view = val.value().view();
            if( !view.empty() )
            {
                std::string oid = view[SNKKey::Personel::oid].get_oid().value.to_string();
                emit signSuccessFully(oid);
                this->close();
            }else{
                std::cout << "Document Empty" << std::endl;
            }
        }else{
            std::cout << "No POinter" << std::endl;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


}
