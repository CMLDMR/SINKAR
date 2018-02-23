#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "personel/personeldialog.h"
#include "personel/logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    ui->statusBar->showMessage("Durum:");
    try {
        Client = new mongocxx::client(mongocxx::uri(SNKKey::dburl.c_str()));
    } catch (mongocxx::exception& e) {
        setMessage(QString("Error: %1").arg(e.what()).toStdString().c_str());
        return;
    }



    db = Client->database(SNKKey::db.c_str());



    LoginDialog* mLoginDialog = new LoginDialog(&db);
    mLoginDialog->exec();
    mLoginDialog->deleteLater();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMessage(const char *message)
{

    ui->statusBar->showMessage(message);

}

void MainWindow::on_pushButton_Personel_clicked()
{


    PersonelDialog* mDialog = new PersonelDialog(&db);

//    connect(mDialog,&PersonelDialog::status,this,&MainWindow::setMessage);

    mDialog->exec();
    mDialog->deleteLater();


}

void MainWindow::on_pushButton_options_clicked()
{

}
