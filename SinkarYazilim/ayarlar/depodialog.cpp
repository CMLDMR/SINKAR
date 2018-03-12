#include "depodialog.h"
#include "ui_depodialog.h"

DepoDialog::DepoDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DepoDialog),
    db(_db)
{
    ui->setupUi(this);


    model = new QStandardItemModel;
    model->setHorizontalHeaderLabels(QStringList() << "Depo Adı");
    ui->tableView->setModel(model);

    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    setWindowFlag(Qt::FramelessWindowHint);
    setStyleSheet("QDialog{border:1px solid black;}");


    this->refreshList();
}

DepoDialog::~DepoDialog()
{
    delete ui;
}



void DepoDialog::on_pushButton_ekle_clicked()
{


    auto mDialog = std::make_unique<Dialog>();
    mDialog.get()->setWindowTitle("Yeni Depo Adını Giriniz");


    auto vLayout = mDialog.get()->addLayout<VLayout>();

    auto lineEdit = vLayout->addwidget<QLineEdit>();
    lineEdit->setPlaceholderText("Depo Adını Giriniz");



    auto hLayout = vLayout->addlayout<HLayout>();

    auto ok = hLayout->addwidget<QPushButton>("Tamam");

    connect(ok,&QPushButton::clicked,[&](){
        this->setNewDepo(lineEdit->text().toStdString().c_str());
        mDialog.get()->close();
    });


    mDialog.get()->exec();

}

void DepoDialog::refreshList()
{



    auto collection = db->collection(SNKKey::Depo::collection);

    try {
        auto cursor = collection.find(document{}.view());

        int row = 0;
        model->removeRows(0,model->rowCount());
        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem;
            item->setText(doc[SNKKey::Depo::depoAdi].get_utf8().value.to_string().c_str());
            item->setData(doc[SNKKey::Depo::oid].get_oid().value.to_string().c_str());
            model->setItem(row++,0,item);
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


}

void DepoDialog::setNewDepo(std::string newDepoName)
{

    auto doc = document{};

    try {
        doc.append(kvp(SNKKey::Depo::depoAdi,newDepoName));
    } catch (bsoncxx::exception &e) {
        std::cout << "Depo Adı Ekleme Hatalı: " << e.what() << std::endl;
    }


    auto collection = db->collection(SNKKey::Depo::collection);

    try {
        auto ins = collection.insert_one(doc.view());
        if( !ins )
        {
            std::cout << "Depo Girilemedi";
        }else{
//            std::cout << "Girilen Depo Sayısı " << ins.value().result().inserted_count() << std::endl;
            this->refreshList();
        }
    } catch (mongocxx::exception & e) {
        std::cout << "insert Error: " << e.what() << std::endl;
    }


}

void DepoDialog::deleteItem(std::string oid)
{


    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Depo::oid,bsoncxx::oid{oid.c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    auto collection = db->collection(SNKKey::Depo::collection);
    try {
        auto del = collection.delete_one(filter.view());
        if( !del )
        {

        }else{
            if( del.value().deleted_count() )
            {
                QMessageBox msg;
                msg.setText("Depo Silindi");
                msg.setWindowTitle("Bilgi");
                msg.setIcon(QMessageBox::Information);
                msg.exec();
                this->refreshList();
            }else{
                QMessageBox msg;
                msg.setText("Depo Silinemedi");
                msg.setWindowTitle("UYARI");
                msg.setIcon(QMessageBox::Warning);
                msg.exec();
            }

        }
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

}




void DepoDialog::on_pushButton_close_clicked()
{
    this->close();
}

void DepoDialog::on_pushButton_yenile_clicked()
{
    this->refreshList();
}

void DepoDialog::on_pushButton_delete_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();

    if( index.row() == -1 )
    {

        QMessageBox msg;
        msg.setText("Lütfen Bir Depo Seçiniz");
        msg.setWindowTitle("UYARI");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();

        return;
    }

    std::string oid = index.data(Qt::UserRole).toString().toStdString().c_str();

    this->deleteItem(oid);


}

void DepoDialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    std::string oid = index.data(Qt::UserRole).toString().toStdString().c_str();

    this->deleteItem(oid);
}
