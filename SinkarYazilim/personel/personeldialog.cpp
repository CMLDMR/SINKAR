#include "personeldialog.h"
#include "ui_personeldialog.h"

PersonelDialog::PersonelDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonelDialog),
    db(_db)
{
    ui->setupUi(this);

    mModel = new QStandardItemModel;
    mModel->setHorizontalHeaderLabels(QStringList()<<"Ad"<<"Soyad");

    ui->tableView->setModel(mModel);

    this->refreshList();
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


    this->refreshList();

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

void PersonelDialog::removeRows()
{
    mModel->removeRows(0,mModel->rowCount());

}

void PersonelDialog::refreshList()
{

    auto filter = document{};

    mongocxx::options::find findOption;


    try {
        auto collection = db->collection(SNKKey::Personel::collection);

        auto cursor = collection.find(filter.view(),findOption);


        this->removeRows();
        int row = 0;
        for( auto doc : cursor )
        {
            {
                QStandardItem* item = new QStandardItem;
                item->setData(doc[SNKKey::Personel::oid].get_oid().value.to_string().c_str(),Qt::UserRole);
                item->setText(doc[SNKKey::Personel::ad].get_utf8().value.to_string().c_str());
                mModel->setItem(row,0,item);
            }
            {
                QStandardItem* item = new QStandardItem;
                item->setData(doc[SNKKey::Personel::oid].get_oid().value.to_string().c_str(),Qt::UserRole);
                item->setText(doc[SNKKey::Personel::soyad].get_utf8().value.to_string().c_str());
                mModel->setItem(row,1,item);
            }


            row++;
        }

    } catch (mongocxx::exception &e) {
        setstatus(e);
    }

}

void PersonelDialog::on_pushButton_Refresh_clicked()
{
    this->refreshList();
}

void PersonelDialog::on_tableView_clicked(const QModelIndex &index)
{
    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Personel::oid,bsoncxx::oid{index.data(Qt::UserRole).toString().toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        setstatus(e);
    }

    try {
        auto collection = db->collection(SNKKey::Personel::collection);

        auto val = collection.find_one(filter.view());

        if( val )
        {
            auto view = val.value().view();

            ui->lineEdit_name->setText(view[SNKKey::Personel::ad].get_utf8().value.to_string().c_str());
            ui->lineEdit_oid->setText(view[SNKKey::Personel::oid].get_oid().value.to_string().c_str());
            ui->lineEdit_surname->setText(view[SNKKey::Personel::soyad].get_utf8().value.to_string().c_str());
            ui->lineEdit_username->setText(view[SNKKey::Personel::username].get_utf8().value.to_string().c_str());
        }

    } catch (mongocxx::exception &e) {
        setstatus(e);
    }
}

void PersonelDialog::on_pushButton_addNew_clicked()
{
    ui->lineEdit_oid->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_surname->setText("");
    ui->lineEdit_username->setText("");
}

void PersonelDialog::on_pushButton_delete_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();

    if( index.row() == -1 )
    {
        setstatus("Lütfen Listeden Personel Seçiniz");
        return;
    }


    std::string oid = index.data(Qt::UserRole).toString().toStdString();

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Personel::oid,bsoncxx::oid{oid}));
    } catch (bsoncxx::exception &e) {
        setstatus(e);
    }

    try {
        auto collection = db->collection(SNKKey::Personel::collection);

        auto del = collection.delete_one(filter.view());

        if( del )
        {
            setstatus(QString("Silinen Personel Sayısı: %1").arg(del.value().deleted_count()));
        }

    } catch (mongocxx::exception &e) {
        setstatus(e);
    }



}
