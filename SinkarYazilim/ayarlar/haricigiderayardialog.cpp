#include "haricigiderayardialog.h"
#include "ui_haricigiderayardialog.h"
#include "src/quickwidget.h"

#include <QLineEdit>
#include <QMessageBox>

HariciGiderAyarDialog::HariciGiderAyarDialog(mongocxx::database *_db, bsoncxx::document::value *_user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HariciGiderAyarDialog),
    DBUser (_db,_user)
{
    ui->setupUi(this);


    this->setWindowTitle("Gider Kategorileri");

    model = new QStandardItemModel;

    ui->listView->setModel(model);

    delegate = new Delegate::KisiDelegate;

    ui->listView->setItemDelegate(delegate);

    this->listKategori();

    this->setSelectedKategori(false);

}

HariciGiderAyarDialog::~HariciGiderAyarDialog()
{
    delete ui;
}

void HariciGiderAyarDialog::on_pushButton_addNew_clicked()
{

    auto mDialog = std::make_unique<Dialog>();

    auto layout = mDialog->addLayout<VLayout>();

    auto label = layout->addwidget<QLabel>("Yeni Gider Tipi");

    auto lineEdit = layout->addwidget<QLineEdit>();
    lineEdit->setPlaceholderText("Gider Tipini Giriniz");

    auto hLayout = layout->addlayout<HLayout>();

    auto okBtn = hLayout->addwidget<QPushButton>("Ekle");

    auto cancelBtn = hLayout->addwidget<QPushButton>("İptal");

    connect(cancelBtn,&QPushButton::clicked,mDialog.get(),&Dialog::close);

    connect(okBtn,&QPushButton::clicked,[&mDialog,&lineEdit,this](){

        auto doc = document{};


        try {
            doc.append(kvp(SNKKey::HariciGider::Kategori::kategoriName,lineEdit->text().toStdString().c_str()));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        try {

            auto ins = this->collection(SNKKey::HariciGider::Kategori::collection).insert_one(doc.view());

            if( ins )
            {
                if( ins.value().result().inserted_count() )
                {
                    std::cout << "Succesfully Added" << std::endl;
                }else{
                    std::cout << "No Document İnserted" << std::endl;
                }
            }else{
                std::cout << "No Document İnserted" << std::endl;
            }

        } catch (mongocxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }


        mDialog.get()->close();
        this->listKategori();
    });


    mDialog.get()->exec();

}

void HariciGiderAyarDialog::listKategori()
{
    try {
        auto cursor = this->collection(SNKKey::HariciGider::Kategori::collection).find(document{}.view());

        model->removeRows(0,model->rowCount());
        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem;
            item->setText(doc[SNKKey::HariciGider::Kategori::kategoriName].get_utf8().value.to_string().c_str());
            item->setData(doc[SNKKey::oid].get_oid().value.to_string().c_str(),Delegate::KisiDelegate::Oid);
            model->appendRow(item);
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Error  " << e.what() << std::endl;
    }



}

void HariciGiderAyarDialog::changeKategirName(std::string oid)
{

    auto mDialog = std::make_unique<Dialog>();

    auto layout = mDialog.get()->addLayout<VLayout>();

    auto lineEdit = layout->addwidget<QLineEdit>();
    lineEdit->setPlaceholderText("Lütfen Yeni Kategori Adını Giriniz");

    auto btn = layout->addwidget<QPushButton>("Kaydet");

    connect(btn,&QPushButton::clicked,[&lineEdit,&oid,this,&mDialog](){

        auto filter = document{};

        try {
            filter.append(kvp(SNKKey::oid,bsoncxx::oid{oid.c_str()}));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error. " << e.what() << std::endl;
            return;
        }

        auto setDoc = document{};

        try {
            setDoc.append(kvp("$set",make_document(kvp(SNKKey::HariciGider::Kategori::kategoriName,lineEdit->text().toStdString()))));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            return;
        }


        try {
            auto upt = this->collection(SNKKey::HariciGider::Kategori::collection).update_one(filter.view(),setDoc.view());

            if( upt )
            {
                if( !upt.value().modified_count() )
                {
                    std::cout << "No Modified Document: " << std::endl;
                }else{
                    std::cout << "Change Successfully" << std::endl;
                }
            }else{
                std::cout << "No Document Successfully" << std::endl;
            }
        } catch (mongocxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        this->listKategori();
        mDialog->close();
    });

    mDialog->exec();
}

void HariciGiderAyarDialog::deleteKategori(std::string oid)
{

    QMessageBox::StandardButton btn = QMessageBox::question(this,"Sil?","Silmek İstediğinize Eminmisiniz?",QMessageBox::StandardButton::Yes|QMessageBox::StandardButton::No);

    if( btn == QMessageBox::StandardButton::No )
    {
        return;
    }


    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{oid.c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error. " << e.what() << std::endl;
        return;
    }


    try {
        auto del = this->collection(SNKKey::HariciGider::Kategori::collection).delete_one(filter.view());
        if( del )
        {
            if( del.value().deleted_count() )
            {
                std::cout << "Deleted Successfully" << std::endl;
                this->listKategori();
            }else{
                std::cout << "No Deleted Function" << std::endl;
            }
        }else{
            std::cout << "No Deleted DOcument" << std::endl;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

}

bool HariciGiderAyarDialog::selectedKategori() const
{
    return mSelectedKategori;
}

void HariciGiderAyarDialog::setSelectedKategori(bool selectedKategori)
{
    mSelectedKategori = selectedKategori;
}

void HariciGiderAyarDialog::on_listView_doubleClicked(const QModelIndex &index)
{

    this->setSelectedKategori(true);

    std::string oid = index.data(Delegate::KisiDelegate::Oid).toString().toStdString();

    auto mDialog = std::make_unique<Dialog>();

    auto layout = mDialog->addLayout<VLayout>();

    auto degistirbtn = layout->addwidget<QPushButton>("Değiştir");

    auto silbtn = layout->addwidget<QPushButton>("Sil");

    auto newbtn = layout->addwidget<QPushButton>("Yeni Ekle");


    connect(degistirbtn,&QPushButton::clicked,[=,&mDialog,&oid](){
        this->changeKategirName(oid);
        mDialog.get()->close();
    });

    connect(silbtn,&QPushButton::clicked,[=,&mDialog,&oid](){
        this->deleteKategori(oid);
        mDialog->close();
    });

    connect(newbtn,&QPushButton::clicked,[this,&mDialog](){
        mDialog->close();
        this->on_pushButton_addNew_clicked();
    });

    mDialog->exec();


}

void HariciGiderAyarDialog::on_listView_clicked(const QModelIndex &index)
{
    this->setSelectedKategori(true);
}

void HariciGiderAyarDialog::on_pushButton_change_clicked()
{
    if( selectedKategori() )
    {
        std::string oid = ui->listView->currentIndex().data(Delegate::KisiDelegate::Oid).toString().toStdString();
        this->changeKategirName(oid);
    }
}

void HariciGiderAyarDialog::on_pushButton_delete_clicked()
{
    if( selectedKategori() )
    {
        std::string oid = ui->listView->currentIndex().data(Delegate::KisiDelegate::Oid).toString().toStdString();
        this->deleteKategori(oid);
    }
}
