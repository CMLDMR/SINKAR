#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    ui->statusBar->showMessage("Durum:");
    try {
        Client = new mongocxx::client(mongocxx::uri(SNKKey::dburl));
    } catch (mongocxx::exception& e) {
        setMessage(QString("Error: %1").arg(e.what()).toStdString().c_str());
        return;
    }




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

}
