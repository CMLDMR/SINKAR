#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "personel/personeldialog.h"
#include "src/quickwidget.h"

#include "ayarlar/ayarlardialog.h"
#include "stok/stokdialog.h"
#include "Kasa/kasadialog.h"
#include "Cari/carihesapdialog.h"
#include "Harici/haricigiderdialog.h"

#include <QComboBox>

MainWindow::MainWindow(mongocxx::database *_db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    db(_db),
    User(document{}.view())
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Durum:");
    this->setWindowFlag(Qt::CustomizeWindowHint);
    this->setStyleSheet("QMainWindow{border:1px solid black;}");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMainWindow(std::string personelOid)
{
    auto filter = document{};
    try {
        filter.append(kvp(SNKKey::Personel::oid,bsoncxx::oid{personelOid}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Signin ERrror: " << e.what() << std::endl;
        return;
    }
    try {
        auto val = db->collection(SNKKey::Personel::collection).find_one(filter.view());
        if( val )
        {
            if( !val.value().view().empty() )
            {
                this->User = val.value();
                this->show();
            }else{
                std::cout << "Error No Document: " << std::endl;
                return;
            }
        }else{
            std::cout << "No Document Returned" << std::endl;
            return;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "DB Query Error: " <<e.what() << std::endl;
        return;
    }
}

void MainWindow::setMessage(const char *message)
{
    ui->statusBar->showMessage(message);
}

void MainWindow::on_pushButton_Personel_clicked()
{
    PersonelDialog* mDialog = new PersonelDialog(db);
    mDialog->exec();
    mDialog->deleteLater();
}

void MainWindow::on_pushButton_options_clicked()
{
    AyarlarDialog* mAyarlar = new AyarlarDialog(db,&User);
    mAyarlar->exec();
    mAyarlar->deleteLater();
}

void MainWindow::applicationQuit()
{
    qApp->exit(-1);
}

void MainWindow::on_pushButton_Stok_clicked()
{
    StokDialog* mDialog = new StokDialog(db);
    mDialog->exec();
    mDialog->deleteLater();
}

void MainWindow::on_pushButton_OpenKasa_clicked()
{

    struct item
    {
        std::string ad;
        std::string oid;
    };

    std::vector<item> kasaList;

    try {
        auto cursor = db->collection(SNKKey::Kasa::collection).find(document{}.view());

        for( auto doc : cursor )
        {
            item _item;
            _item.ad = doc[SNKKey::Kasa::ad].get_utf8().value.to_string();
            _item.oid = doc[SNKKey::Kasa::oid].get_oid().value.to_string();
            kasaList.push_back(_item);
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::string kasa = "null";

    if( kasaList.size() > 0 )
    {
        auto sDialog_ = std::make_unique<Dialog>();

        auto sDialog = sDialog_.get();

        auto layout = sDialog->addLayout<VLayout>();

        auto label = layout->addwidget<QLabel>("Kasa Seç");

        auto comboBox = layout->addwidget<QComboBox>();

        for( auto item : kasaList )
        {
            comboBox->addItem(item.ad.c_str(),item.oid.c_str());
        }

        auto sec = layout->addwidget<QPushButton>("Tamam");

        connect(sec,&QPushButton::clicked,[&kasa,&comboBox,&sDialog](){
            kasa = comboBox->currentText().toStdString();
            sDialog->close();
        });
        sDialog->exec();
    }



    if( kasa != "null" )
    {
        auto mDialog = new KasaDialog(kasa,db);
        mDialog->exec();
        mDialog->deleteLater();
    }

}

void MainWindow::on_pushButton_Close_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_Cari_clicked()
{
    auto mDialog = std::make_unique<CariHesapDialog>(db,&User);
    mDialog->exec();
}

void MainWindow::on_pushButton_ExternalOutGoing_clicked()
{
    auto mDialog = std::make_unique<HariciGiderDialog>(db,&User);
    mDialog->exec();
}
