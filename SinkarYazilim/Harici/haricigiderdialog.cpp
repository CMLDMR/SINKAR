#include "haricigiderdialog.h"
#include "ui_haricigiderdialog.h"


#include "src/quickwidget.h"

HariciGiderDialog::HariciGiderDialog(mongocxx::database *_db, bsoncxx::document::value *_user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HariciGiderDialog),
    DBUser (_db,_user)
{

    ui->setupUi(this);

    this->setWindowTitle("Harici Gider Ekle");

    model = new QStandardItemModel;

    ui->listView->setModel(model);

    delegate = new Delegate::KisiDelegate;

    ui->listView->setItemDelegate(delegate);

    this->listKategoriList();

    ui->dateEdit->setDate(QDate::currentDate());

    this->setSelectedIndex(false);

    this->listCompleter();
}

HariciGiderDialog::~HariciGiderDialog()
{
    delete ui;
}

void HariciGiderDialog::on_pushButton_ekle_clicked()
{
    if( ui->doubleSpinBox_Miktar->value() <= 0 )
    {
        QMessageBox msg;
        msg.setButtonText(QMessageBox::StandardButton::Ok,"Tamam");
        msg.setText("Miktar Girmediniz!");
        msg.setWindowTitle("UYARI");
        msg.exec();
        return;
    }


    if( !selectedIndex() )
    {
        QMessageBox msg;
        msg.setButtonText(QMessageBox::StandardButton::Ok,"Tamam");
        msg.setText("Kategori Seçmediniz!");
        msg.setWindowTitle("UYARI");
        msg.exec();
        return;
    }


    auto doc = document{};


    try {
        doc.append(kvp(SNKKey::HariciGider::Gider::adi,ui->lineEdit_GiderAdi->text().toStdString().c_str()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    try {
        doc.append(kvp(SNKKey::HariciGider::Gider::julianDate,ui->dateEdit->date().toJulianDay()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    try {
        doc.append(kvp(SNKKey::HariciGider::Gider::miktar,ui->doubleSpinBox_Miktar->value()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    std::string oid = ui->listView->currentIndex().data(Delegate::KisiDelegate::Oid).toString().toStdString();

    try {
        doc.append(kvp(SNKKey::HariciGider::Gider::kategorioid,bsoncxx::oid{oid}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    try {
        auto ins = this->collection(SNKKey::HariciGider::Gider::collection).insert_one(doc.view());
        if( ins )
        {
            if( ins.value().result().inserted_count() )
            {
                std::cout << "INSERT SUCCESSFULLY" << std::endl;
                ui->doubleSpinBox_Miktar->setValue(0);
                ui->lineEdit_GiderAdi->setText("");
            }else{
                std::cout << "No Document Inserted" << std::endl;
            }
        }else{
            std::cout << "No Document Inserted" << std::endl;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "DB Error " << e.what() << std::endl;
    }



}

void HariciGiderDialog::listKategoriList()
{
    try {
        auto cursor = this->collection(SNKKey::HariciGider::Kategori::collection).find(document{}.view());
        model->removeRows(0,model->rowCount());
        for( auto doc : cursor )
        {
            {
                QStandardItem* item = new QStandardItem;
                item->setText(doc[SNKKey::HariciGider::Kategori::kategoriName].get_utf8().value.to_string().c_str());
                item->setData(doc[SNKKey::oid].get_oid().value.to_string().c_str(),Delegate::KisiDelegate::Oid);
                model->appendRow(item);
            }
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void HariciGiderDialog::listCompleter()
{


    try {

        auto cursor = this->collection(SNKKey::HariciGider::Gider::collection).find(document{}.view());


        QStringList strList;

        for( auto doc : cursor )
        {
            strList.append(doc[SNKKey::HariciGider::Gider::adi].get_utf8().value.to_string().c_str());
        }

        strList.removeDuplicates();

        QCompleter* completer = new QCompleter(strList);

        ui->lineEdit_GiderAdi->setCompleter(completer);

    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }





}

void HariciGiderDialog::insertGiderDoc(std::string adi,qint64 julienDate , double miktar , std::string kategoriOid)
{

    auto doc = document{};


    try {
        doc.append(kvp(SNKKey::HariciGider::Gider::adi,adi));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    try {
        doc.append(kvp(SNKKey::HariciGider::Gider::julianDate,julienDate));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    try {
        doc.append(kvp(SNKKey::HariciGider::Gider::miktar,miktar));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    std::string oid = ui->listView->currentIndex().data(Delegate::KisiDelegate::Oid).toString().toStdString();

    try {
        doc.append(kvp(SNKKey::HariciGider::Gider::kategorioid,bsoncxx::oid{kategoriOid}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    try {
        auto ins = this->collection(SNKKey::HariciGider::Gider::collection).insert_one(doc.view());
        if( ins )
        {
            if( ins.value().result().inserted_count() )
            {
                std::cout << "INSERT SUCCESSFULLY" << std::endl;
                ui->doubleSpinBox_Miktar->setValue(0);
                ui->lineEdit_GiderAdi->setText("");
            }else{
                std::cout << "No Document Inserted" << std::endl;
            }
        }else{
            std::cout << "No Document Inserted" << std::endl;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "DB Error " << e.what() << std::endl;
    }

}

bool HariciGiderDialog::selectedIndex() const
{
    return mSelectedIndex;
}

void HariciGiderDialog::setSelectedIndex(bool selectedIndex)
{
    mSelectedIndex = selectedIndex;
}

void HariciGiderDialog::on_listView_clicked(const QModelIndex &index)
{
    this->setSelectedIndex(true);
}

void HariciGiderDialog::on_listView_doubleClicked(const QModelIndex &index)
{

    auto filter = document{};


    try {
        filter.append(kvp(SNKKey::HariciGider::Gider::kategorioid,bsoncxx::oid{index.data(Delegate::KisiDelegate::Oid).toString().toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    QStringList strList;

    try {
        auto cursor = this->collection(SNKKey::HariciGider::Gider::collection).find(filter.view());
        for( auto doc : cursor )
        {
            strList.append(doc[SNKKey::HariciGider::Gider::adi].get_utf8().value.to_string().c_str());
        }
        strList.removeDuplicates();
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    auto mDialog = std::make_unique<Dialog>();

    auto layout = mDialog->addLayout<VLayout>();

    auto label = layout->addwidget<QLabel>("<h3>Daha Öndeki Gider Adları</h3>");

    auto listWidget = layout->addwidget<QListView>();

    auto modelList = std::make_unique<QStandardItemModel>();

    for( QString str : strList )
    {
        QStandardItem* item = new QStandardItem;
        item->setText(str);
        modelList->appendRow(item);
    }

    listWidget->setModel(modelList.get());

    auto itemDelegate = std::make_unique<Delegate::KisiDelegate>();

    listWidget->setItemDelegate(itemDelegate.get());
    listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    bool listWidetItemSelected = false;

    connect(listWidget,&QListView::clicked,[&listWidetItemSelected](const QModelIndex &_index){
        listWidetItemSelected = true;
    });


    auto doubleSpinBox = layout->addwidget<QDoubleSpinBox>();
    doubleSpinBox->setMaximum(1000000);


    auto date = layout->addwidget<QDateEdit>();
    date->setDate(QDate::currentDate());


    auto btn = layout->addwidget<QPushButton>("Kaydet");


    connect(listWidget,&QListView::doubleClicked,[&mDialog,&listWidetItemSelected,this,&index,&doubleSpinBox,&date,&listWidget](const QModelIndex &_index){

        if( !listWidetItemSelected )
        {
            QMessageBox msg;
            msg.setText("Gider Adı Seçmediniz");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("UYARI");
            msg.setWindowFlag(Qt::FramelessWindowHint);
            msg.setStyleSheet("QDialog{border:1px solid black;}");
            msg.exec();
            return;
        }

        if( doubleSpinBox->value() <= 0.0 )
        {
            QMessageBox msg;
            msg.setText("Miktar Seçmediniz!");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("UYARI");
            msg.setWindowFlag(Qt::FramelessWindowHint);
            msg.setStyleSheet("QDialog{border:1px solid black;}");
            msg.exec();
            return;
        }


        std::string oid = index.data(Delegate::KisiDelegate::Oid).toString().toStdString();

        std::string adi = listWidget->currentIndex().data(Qt::DisplayRole).toString().toStdString();

        this->insertGiderDoc(adi,date->date().toJulianDay(),doubleSpinBox->value(),oid);

        mDialog.get()->close();
    });

    connect(btn,&QPushButton::clicked,[&mDialog,&listWidetItemSelected,this,&index,&doubleSpinBox,&date,&listWidget](){

        if( !listWidetItemSelected )
        {
            QMessageBox msg;
            msg.setText("Gider Adı Seçmediniz");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("UYARI");
            msg.setWindowFlag(Qt::FramelessWindowHint);
            msg.setStyleSheet("QDialog{border:1px solid black;}");
            msg.exec();
            return;
        }

        if( doubleSpinBox->value() <= 0.0 )
        {
            QMessageBox msg;
            msg.setText("Miktar Seçmediniz!");
            msg.setIcon(QMessageBox::Warning);
            msg.setWindowTitle("UYARI");
            msg.setWindowFlag(Qt::FramelessWindowHint);
            msg.setStyleSheet("QDialog{border:1px solid black;}");
            msg.exec();
            return;
        }


        std::string oid = index.data(Delegate::KisiDelegate::Oid).toString().toStdString();

        std::string adi = listWidget->currentIndex().data(Qt::DisplayRole).toString().toStdString();

        this->insertGiderDoc(adi,date->date().toJulianDay(),doubleSpinBox->value(),oid);

        mDialog.get()->close();
    });




    mDialog->exec();



}
