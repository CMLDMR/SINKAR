#include "odemealdialog.h"
#include "ui_odemealdialog.h"


OdemeAlDialog::OdemeAlDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OdemeAlDialog),
    db(_db)
{
    ui->setupUi(this);
    this->setWindowTitle("Ödeme Al");
//    this->setWindowFlag(Qt::SplashScreen);
//    this->setStyleSheet("QDialog{border:1px solid black;}");

    this->initialize();

}

OdemeAlDialog::~OdemeAlDialog()
{
    delete ui;
}

void OdemeAlDialog::on_pushButton_close_clicked()
{
    this->close();
}

void OdemeAlDialog::on_pushButton_toogleMaximize_clicked()
{
    if( this->isMaximized() )
    {
        this->showNormal();
    }else{
        this->showMaximized();
    }
}

void OdemeAlDialog::on_pushButton_minimize_clicked()
{
    this->showMinimized();
}

void OdemeAlDialog::initialize()
{

    modelKisi = new QStandardItemModel;

    proxyKisi = new QSortFilterProxyModel;

    proxyKisi->setSourceModel(modelKisi);

    proxyKisi->setFilterCaseSensitivity(Qt::CaseInsensitive);

    ui->listView_KisiList->setModel(proxyKisi);

    itemDelegate = new OdemealDialog::KisiDelegate();

    ui->listView_KisiList->setItemDelegate(itemDelegate);


    this->initKisiList();


    modelHesaplar = new QStandardItemModel;

    modelHesaplar->setHorizontalHeaderLabels(QStringList()<<"Ücret"<<"Durum"<<"Ödeme");

    ui->tableView_HesapList->setModel(modelHesaplar);


}

void OdemeAlDialog::initKisiList()
{


    try {
        auto cursor = db->collection(SNKKey::Cari::Kisiler::collection).find(document{}.view());

        int row = 0;
        modelKisi->removeRows(0,modelKisi->rowCount());
        for( auto doc : cursor )
        {
            {
                QStandardItem* item = new QStandardItem;
                item->setText(doc[SNKKey::Cari::Kisiler::ad].get_utf8().value.to_string().c_str());
                item->setData(doc[SNKKey::oid].get_oid().value.to_string().c_str(),Qt::UserRole);
                modelKisi->appendRow(item);
            }
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

}

bool OdemeAlDialog::NakitOde(std::string oid, double miktar)
{


    auto doc = document{};

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odeme,SNKKey::Cari::Hesap::Odeme::odendi));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odeme << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeJulianDate,QDate::currentDate().toJulianDay()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeJulianDate << " <" << e.what() << std::endl;
        return false;
    }


    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeSaat,QTime::currentTime().toString("hh:mm").toStdString().c_str()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeSaat << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeMiktari,miktar));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeMiktari << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeMiktariNakit,miktar));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeMiktariNakit << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeMiktariKredi,bsoncxx::types::b_double{0}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeMiktariKredi << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeTipi,SNKKey::Cari::Hesap::ODEMETIPI::nakit));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeTipi << " <" << e.what() << std::endl;
        return false;
    }


    auto setDoc = document{};

    try {
        setDoc.append(kvp("$set",doc));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: << $set "  << " <" << e.what() << std::endl;
        return false;
    }

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{oid.c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: << oid "  << " <" << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = db->collection(SNKKey::Cari::Hesap::collection).update_one(filter.view(),setDoc.view());
        if( upt )
        {
            if( upt.value().modified_count() )
            {
                std::cout << "Ödendi" << std::endl;
                return true;
            }else{
                std::cout << "!Ödeme Olmadı" << std::endl;
                return false;
            }
        }else{
            std::cout << "!Ödeme Olmadı" << std::endl;
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "DB Error: " << e.what() << std::endl;
        return false;
    }


}

bool OdemeAlDialog::KrediKartiOde(std::string oid, double miktar)
{
    auto doc = document{};

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odeme,SNKKey::Cari::Hesap::Odeme::odendi));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odeme << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeJulianDate,QDate::currentDate().toJulianDay()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeJulianDate << " <" << e.what() << std::endl;
        return false;
    }


    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeSaat,QTime::currentTime().toString("hh:mm").toStdString().c_str()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeSaat << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeMiktari,miktar));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeMiktari << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeMiktariNakit,bsoncxx::types::b_double{0}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeMiktariNakit << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeMiktariKredi,miktar));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeMiktariKredi << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeTipi,SNKKey::Cari::Hesap::ODEMETIPI::krediKarti));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeTipi << " <" << e.what() << std::endl;
        return false;
    }


    auto setDoc = document{};

    try {
        setDoc.append(kvp("$set",doc));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: << $set "  << " <" << e.what() << std::endl;
        return false;
    }

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{oid.c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: << oid "  << " <" << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = db->collection(SNKKey::Cari::Hesap::collection).update_one(filter.view(),setDoc.view());
        if( upt )
        {
            if( upt.value().modified_count() )
            {
                std::cout << "Ödendi" << std::endl;
                return true;
            }else{
                std::cout << "!Ödeme Olmadı" << std::endl;
                return false;
            }
        }else{
            std::cout << "!Ödeme Olmadı" << std::endl;
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "DB Error: " << e.what() << std::endl;
        return false;
    }

}

bool OdemeAlDialog::KarisikOde(std::string oid, double nakitMiktar, double krediKartiMiktar)
{
    auto doc = document{};

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odeme,SNKKey::Cari::Hesap::Odeme::odendi));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odeme << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeJulianDate,QDate::currentDate().toJulianDay()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeJulianDate << " <" << e.what() << std::endl;
        return false;
    }


    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeSaat,QTime::currentTime().toString("hh:mm").toStdString().c_str()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeSaat << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeMiktari,nakitMiktar+krediKartiMiktar));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeMiktari << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeMiktariNakit,nakitMiktar));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeMiktariNakit << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeMiktariKredi,krediKartiMiktar));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeMiktariKredi << " <" << e.what() << std::endl;
        return false;
    }

    try {
        doc.append(kvp(SNKKey::Cari::Hesap::odemeTipi,SNKKey::Cari::Hesap::ODEMETIPI::karisik));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << SNKKey::Cari::Hesap::odemeTipi << " <" << e.what() << std::endl;
        return false;
    }


    auto setDoc = document{};

    try {
        setDoc.append(kvp("$set",doc));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: << $set "  << " <" << e.what() << std::endl;
        return false;
    }

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{oid.c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: << oid "  << " <" << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = db->collection(SNKKey::Cari::Hesap::collection).update_one(filter.view(),setDoc.view());
        if( upt )
        {
            if( upt.value().modified_count() )
            {
                std::cout << "Ödendi" << std::endl;
                return true;
            }else{
                std::cout << "!Ödeme Olmadı" << std::endl;
                return false;
            }
        }else{
            std::cout << "!Ödeme Olmadı" << std::endl;
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "DB Error: " << e.what() << std::endl;
        return false;
    }
}

void OdemeAlDialog::initBorcList()
{



    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Cari::Hesap::kisioid,bsoncxx::oid{ui->lineEdit_Oid->text().toStdString()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }

    try {
        filter.append(kvp(SNKKey::Cari::Hesap::odeme,SNKKey::Cari::Hesap::Odeme::odenmedi));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return;
    }



    try {
        auto cursor = db->collection(SNKKey::Cari::Hesap::collection).find(filter.view());

        modelHesaplar->removeRows(0,modelHesaplar->rowCount());
        double toplamBorc = 0;
        int row = 0;
        for( auto doc : cursor )
        {
            {
                QStandardItem* item = new QStandardItem;
                toplamBorc += doc[SNKKey::Cari::Hesap::miktar].get_double().value;
                item->setText(QString::number(doc[SNKKey::Cari::Hesap::miktar].get_double().value));
                item->setData(doc[SNKKey::Cari::Hesap::miktar].get_double().value,Bakiye);
                item->setData(doc[SNKKey::oid].get_oid().value.to_string().c_str(),Oid);
                modelHesaplar->setItem(row , 0 , item);
            }

            {
                QStandardItem* item = new QStandardItem;
                if( doc[SNKKey::Cari::Hesap::odeme].get_bool().value == SNKKey::Cari::Hesap::Odeme::odenmedi )
                {
                    item->setText("Ödenmedi");
                }else{
                    item->setText("Ödendi");
                }
                modelHesaplar->setItem(row , 1 , item);
            }
            row++;
        }
        ui->doubleSpinBox_ToplamBorc->setValue(toplamBorc);

    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    ui->doubleSpinBox_KrediKartiOde->setValue(0);
    ui->doubleSpinBox_NakitOde->setValue(0);
    ui->doubleSpinBox_OdeneBilecekRakam->setValue(0);
    ui->label_iade->setText(QString("iade : 0 TL"));
}

void OdemeAlDialog::on_lineEdit_filter_textChanged(const QString &arg1)
{
    proxyKisi->setFilterRegExp(arg1);
}

void OdemeAlDialog::on_listView_KisiList_clicked(const QModelIndex &index)
{
    ui->lineEdit_isim->setText(index.data(Qt::DisplayRole).toString());
    ui->lineEdit_Oid->setText(index.data(Qt::UserRole).toString());

    this->initBorcList();
}



void OdemeAlDialog::on_pushButton_OdemeAl_clicked()
{

    if( ui->doubleSpinBox_OdeneBilecekRakam->value() == 0.0 )
    {
        QMessageBox msg;
        msg.setText("Ödeme Yapılabilecek Miktar Mevcut Değil");
        msg.setIcon(QMessageBox::Warning);
        msg.setWindowFlag(Qt::FramelessWindowHint);
        msg.setStyleSheet("QDialog{border:1px solid black;}");
        msg.exec();
        return;
    }

    double varNakit = ui->doubleSpinBox_NakitOde->value();
    double varKredi = ui->doubleSpinBox_KrediKartiOde->value();

    double OdenenToplam = 0.0;

    for( int i = 0 ; i < modelHesaplar->rowCount() ; i++ )
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if( modelHesaplar->item(i,2)->text() == "Ödenebilir" )
        {
            auto miktar = modelHesaplar->item(i,0)->data(Bakiye).toDouble();

            if( varNakit >= miktar && varNakit != 0.0 )
            {
                OdenenToplam += miktar;
                varNakit -= miktar;
//                std::cout << miktar << " Nakit Odendi" << std::endl;


                if( !this->NakitOde(modelHesaplar->item(i,0)->data(Oid).toString().toStdString(),miktar) )
                {
                    std::cout << "Nakit Odeme Gerceklesmedi" << std::endl;
                    break;
                }else{
                    std::cout << "Nakit Odeme Gerceklesti" << std::endl;
                }




            }else if (varNakit < miktar  && varNakit != 0.0 ) {

//                std::cout << varNakit << " Nakit , " << miktar - varNakit << " Kredi ile Odendi"<<std::endl;

                if( !this->KarisikOde(modelHesaplar->item(i,0)->data(Oid).toString().toStdString(),varNakit,miktar - varNakit) )
                {
                    std::cout << "Karisik Odeme Gerceklesmedi" << std::endl;
                    break;
                }else{
                    std::cout << "Karisik Odeme Gerceklesti" << std::endl;
                }

                double kalanborck = miktar - varNakit;
                OdenenToplam += varNakit;
                OdenenToplam += kalanborck;
                varKredi -= kalanborck;
                varNakit = 0.0;


            }else if (varKredi > 0.0 ) {
                varKredi -= miktar;
                OdenenToplam += miktar;
//                std::cout << miktar << " Kredi ile Odendi" << std::endl;

                if( !this->KrediKartiOde(modelHesaplar->item(i,0)->data(Oid).toString().toStdString(),miktar) )
                {
                    std::cout << "KRedi Odeme Gerceklesmedi" << std::endl;
                    break;
                }else{
                    std::cout << "KRedi Odeme Gerceklesti" << std::endl;
                }
            }

//            std::cout << "Odenen: " << OdenenToplam << " varNakit: " << varNakit << " " << " varKredi: " << varKredi << std::endl;
        }
    }

    this->initBorcList();
}

void OdemeAlDialog::on_pushButton_OdemeListesiniCikar_clicked()
{
    double CurrentCash = ui->doubleSpinBox_NakitOde->value()+ui->doubleSpinBox_KrediKartiOde->value();

    double yeterliCash = 0 ;


    std::vector<int> list;


    for( int i = 0 ; i < modelHesaplar->rowCount() ; i++ )
    {
        auto value = modelHesaplar->item(i,0)->data(Bakiye).toDouble();
        if( value + yeterliCash <= CurrentCash )
        {
            list.push_back(i);
            yeterliCash += value;
        }else{

        }
        {
            QStandardItem* item = new QStandardItem;
            item->setText("Yetersiz Ödeme Miktarı");
            modelHesaplar->setItem(i,2,item);
        }
    }


    for( auto i : list )
    {
        QStandardItem* item = new QStandardItem;
        item->setText("Ödenebilir");
        modelHesaplar->setItem(i,2,item);
    }

    ui->doubleSpinBox_OdeneBilecekRakam->setValue(yeterliCash);

    ui->label_iade->setText(QString("iade : %1 TL").arg(CurrentCash-yeterliCash));

}

void OdemeAlDialog::on_pushButton_NakitTamami_clicked()
{
    ui->doubleSpinBox_NakitOde->setValue(ui->doubleSpinBox_ToplamBorc->value());
    ui->doubleSpinBox_KrediKartiOde->setValue(0);
}

void OdemeAlDialog::on_pushButton_KrediOdeme_clicked()
{
    ui->doubleSpinBox_KrediKartiOde->setValue(ui->doubleSpinBox_ToplamBorc->value()-ui->doubleSpinBox_NakitOde->value());
}
