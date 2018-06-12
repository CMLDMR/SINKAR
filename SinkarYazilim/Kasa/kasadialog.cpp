#include "kasadialog.h"
#include "ui_kasadialog.h"

#include "siparisdialog.h"
#include "hesabikapatdialog.h"

KasaDialog::KasaDialog(std::string kasa, mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KasaDialog),db(_db),CurrentKasa(kasa)
{
    ui->setupUi(this);

    this->initMasa(kasa);

    this->setSelectedMasa(false);

    this->setWindowFlag(Qt::FramelessWindowHint);

    this->setStyleSheet("QDialog{border:1px solid black;}");


#ifndef SINKAR
    ui->doubleSpinBox_toplamMiktar_ind->setHidden(false);
#else
    ui->doubleSpinBox_toplamMiktar_ind->setHidden(true);
#endif

}

KasaDialog::~KasaDialog()
{
    delete ui;
}

void KasaDialog::initMasa(std::string kasa)
{

    masaModel = new QStandardItemModel;
    ui->listView_Masalar->setModel(masaModel);
    masaDelegate = new ItemDelegate::Delegate;
    ui->listView_Masalar->setItemDelegate(masaDelegate);

    this->refreshMasaList();

    ui->label_Depo->setText("null");

    {
        auto filter = document{};

        try {
            filter.append(kvp(SNKKey::Kasa::ad,kasa.c_str()));
        } catch (bsoncxx::exception &e) {
            std::cout << "Errror: " << e.what() << std::endl;
        }

        std::string depooid = "null";
        try {
            auto val = db->collection(SNKKey::Kasa::collection).find_one(filter.view());
            if( val )
            {
                if( !val.value().view().empty() )
                {
                    depooid = val.value().view()[SNKKey::Kasa::depooid].get_oid().value.to_string();
                }
            }
        } catch (mongocxx::exception &e) {
            std::cout << "Errror: " << e.what() << std::endl;
        }

        if( depooid != "null" )
        {
            filter.clear();

            try {
                filter.append(kvp(SNKKey::oid,bsoncxx::oid{depooid.c_str()}));
            } catch (bsoncxx::exception &e) {
                std::cout << "Errror: " << e.what() << std::endl;
            }

            try {
                auto val = db->collection(SNKKey::Depo::collection).find_one(filter.view());
                if( val )
                {
                    if( !val.value().view().empty() )
                    {
                        ui->label_Depo->setText(val.value().view()[SNKKey::Depo::depoAdi].get_utf8().value.to_string().c_str());
                    }else{
                        ui->label_Depo->setText("null");
                    }
                }else{
                    ui->label_Depo->setText("null");
                }
            } catch (mongocxx::exception &e) {
                ui->label_Depo->setText("null");
            }
        }
    }

    siparisModel = new QStandardItemModel;

    ui->listView_siparisList->setModel(siparisModel);

    ItemDelegate::ReceteDelegate* siparisDeletage = new ItemDelegate::ReceteDelegate;
    ui->listView_siparisList->setItemDelegate(siparisDeletage);

}

void KasaDialog::refreshMasaList()
{

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Kasa::ad,CurrentKasa));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,SNKKey::Kasa::ad);
        return;
    }

    auto val = this->find_one(SNKKey::Kasa::collection,filter.view());

    try {
        ui->label_Kasa->setText(val.value().view()[SNKKey::Kasa::ad].get_utf8().value.to_string().c_str());
    } catch (bsoncxx::exception &e) {
        ui->label_Kasa->setText(e.what());
    }

    try {
        ui->lineEdikasaOid->setText(val.value().view()[SNKKey::oid].get_oid().value.to_string().c_str());
    } catch (bsoncxx::exception &e) {
        ui->label_Kasa->setText(e.what());
    }

    filter.clear();

    try {
        filter.append(kvp(SNKKey::Masa::kasaoid,val.value().view()[SNKKey::oid].get_oid().value));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,SNKKey::Masa::kasaoid);
        return;
    }

    auto cursor = this->find(SNKKey::Masa::collection,filter.view());

    masaModel->removeRows(0,masaModel->rowCount());
    int row = 0;
    int AcikMasa = 0;
    int KapaliMasa = 0;
    for( auto doc : cursor )
    {
        {
            QStandardItem* item = new QStandardItem;
            try {
                item->setText(doc[SNKKey::Masa::ad].get_utf8().value.to_string().c_str());
            } catch (bsoncxx::exception &e) {
                item->setText(e.what());
            }
            try {
                item->setData(doc[SNKKey::Masa::durum].get_utf8().value.to_string().c_str(),ItemDelegate::Delegate::MasaDurumu);
                if( doc[SNKKey::Masa::durum].get_utf8().value.to_string() == SNKKey::Masa::masaDurum::kullanimda )
                {
                    AcikMasa++;
                }else{
                    KapaliMasa++;
                }
            } catch (bsoncxx::exception &e) {
                item->setData(e.what(),ItemDelegate::Delegate::MasaDurumu);
            }
            try {
                item->setData(doc[SNKKey::Masa::oid].get_oid().value.to_string().c_str(),ItemDelegate::Delegate::MasaOid);
            } catch (bsoncxx::exception &e) {
                item->setData(e.what(),ItemDelegate::Delegate::MasaOid);
            }
            masaModel->setItem(row,0,item);
        }
        row++;
    }

    ui->label_AcikMasa->setText(QString("Açık Masa: %1").arg(AcikMasa));
    ui->label_KapaliMasa->setText(QString("Kapalı Masa: %1").arg(KapaliMasa));

}

void KasaDialog::listMasaSiparisi(std::string siparisoid)
{


    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{siparisoid}));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,"Siparis oid");
        return;
    }

    try {
        filter.append(kvp(SNKKey::Siparis::hesap,SNKKey::Siparis::Hesap::acik));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,"Siparis oid");
        return;
    }



    try {
        auto val = db->collection(SNKKey::Siparis::collection).find_one(filter.view());

        if( val )
        {
            if( !val.value().view().empty() )
            {
                double kasaFiyat = 0;
                double kasaIndFiyat = 0;
                siparisModel->removeRows(0,siparisModel->rowCount());
                try {
                    auto arlist = val.value().view()[SNKKey::Siparis::siparis].get_array().value;
                    for( auto doc : arlist )
                    {
                        QStandardItem* item = new QStandardItem;
                        filter.clear();
                        try {
                            filter.append(kvp(SNKKey::oid,doc[SNKKey::Siparis::siparisList::receteoid].get_oid().value));
                        } catch (bsoncxx::exception &e) {
                            this->showMsg(e,"Siparis oid");
                            return;
                        }
                        auto val = this->find_one(SNKKey::Recete::Recete::collection,filter.view());
                        if( val )
                        {
                            if( !val.value().view().empty() )
                            {
                                try {
                                    item->setText(val.value().view()[SNKKey::Recete::Recete::adi].get_utf8().value.to_string().c_str());
                                } catch (bsoncxx::exception &e) {
                                    item->setText(e.what());
                                }
                                try {
                                    double fiyat = this->getReceteFiyati(val.value().view()[SNKKey::Recete::Recete::oid].get_oid().value,doc[SNKKey::Siparis::siparisList::miktar].get_double().value);
                                    kasaFiyat += fiyat;
                                    double IndFiyat = this->getReceteIndFiyati(val.value().view()[SNKKey::Recete::Recete::oid].get_oid().value,doc[SNKKey::Siparis::siparisList::miktar].get_double().value);
                                    kasaIndFiyat += IndFiyat;
                                    item->setData(fiyat,ItemDelegate::ReceteDelegate::fiyat);
                                } catch (bsoncxx::exception &e) {
                                    item->setData(0,ItemDelegate::ReceteDelegate::fiyat);
                                }
                                try {
                                    item->setData(val.value().view()[SNKKey::Recete::Recete::kategori].get_utf8().value.to_string().c_str(),ItemDelegate::ReceteDelegate::KategoriRole);
                                } catch (bsoncxx::exception &e) {
                                    item->setData(e.what(),ItemDelegate::ReceteDelegate::KategoriRole);
                                }
                            }
                        }
                        try {
                            item->setData(doc[SNKKey::Siparis::siparisList::receteoid].get_oid().value.to_string().c_str(),ItemDelegate::ReceteDelegate::Oid);
                        } catch (bsoncxx::exception &e) {
                            item->setData(e.what(),ItemDelegate::ReceteDelegate::Oid);
                        }
                        try {
                            item->setData(doc[SNKKey::Siparis::siparisList::miktar].get_double().value,ItemDelegate::ReceteDelegate::Miktar);
                        } catch (bsoncxx::exception &e) {
                            item->setData(0,ItemDelegate::ReceteDelegate::Miktar);
                        }
                        siparisModel->appendRow(item);
                    }
                } catch (bsoncxx::exception &e) {
                    QStandardItem* item = new QStandardItem;
                    try {
                        item->setText(e.what());
                    } catch (bsoncxx::exception &e) {
                        item->setText(e.what());
                    }
                    siparisModel->appendRow(item);
                }
                ui->doubleSpinBox_toplamMiktar->setValue(kasaFiyat);
                ui->doubleSpinBox_toplamMiktar_ind->setValue(kasaIndFiyat);
            }else{
                ui->doubleSpinBox_toplamMiktar->setValue(0);
                ui->doubleSpinBox_toplamMiktar_ind->setValue(0);
            }
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Errror: " << e.what() << std::endl;
    }
}

bool KasaDialog::setMasaSiparis(std::string masaoid, std::string siparisoid)
{

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{masaoid}));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,"masaoid error");
        return false;
    }

    auto setDoc = document{};

    try {
        setDoc.append(kvp(SNKKey::Masa::siparisoid,bsoncxx::oid{siparisoid.c_str()}));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,"SNKKey::Masa::siparisoid");
    }

    try {
        setDoc.append(kvp(SNKKey::Masa::durum,SNKKey::Masa::masaDurum::kullanimda));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,"SNKKey::Masa::siparisoid");
    }

    auto updateDoc = document{};

    try {
        updateDoc.append(kvp("$set",setDoc));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,"SNKKey::Masa::siparisoid");
        return false;
    }


    try {
        auto upt = this->db->collection(SNKKey::Masa::collection).update_one(filter.view(),updateDoc.view());
        if( upt )
        {
            if( upt.value().modified_count() )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        this->showMsg(e,"update_one");
        return false;
    }


}

double KasaDialog::getReceteFiyati(bsoncxx::oid receteoid , double receteMiktar )
{

    double fiyat = 0.0;

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,receteoid));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error ReceteOID: " << e.what() << std::endl;
        return fiyat;
    }

    double recetekdv = 0.0;
    double recetekar = 0.0;


    std::vector<ReceteMalzemesi> malzemeoidList;


    try {

        auto val = db->collection(SNKKey::Recete::Recete::collection).find_one(filter.view());
        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto view = val.value().view();
                recetekdv = view[SNKKey::Recete::Recete::kdv].get_double().value;
                recetekar = view[SNKKey::Recete::Recete::kar].get_double().value;

                auto arlist = view[SNKKey::Recete::Recete::malzeme].get_array().value;

                for( auto doc : arlist )
                {
                    auto sip = doc.get_document().view();
                    ReceteMalzemesi malzeme;
                    malzeme.miktar = sip[SNKKey::Recete::Recete::Malzemeler::miktar].get_double().value;
                    malzeme.oid = sip[SNKKey::Recete::Recete::Malzemeler::oid].get_oid().value.to_string();
                    malzemeoidList.push_back(malzeme);

                }
            }else{
                std::cout << "IND RECETE VIEW EMPTY" << std::endl;
                return fiyat;
            }
        }else{
            std::cout << "IND RECETE DOCUMENT EMPTY "<< std::endl;
            return fiyat;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "IND Recete QUERY ERROR: " << e.what() << std::endl;
        return fiyat;
    }


    filter.clear();


    auto arList = array{};

    for( auto doc : malzemeoidList )
    {
        arList.append(bsoncxx::oid{doc.oid});
    }

    try {
        filter.append(kvp(SNKKey::oid,make_document(kvp("$in",arList))));
    } catch (bsoncxx::exception &e) {
        std::cout << "IND malzeme $in build error: " << e.what() << std::endl;
        return fiyat;
    }


    try {

        auto cursor = db->collection(SNKKey::Malzeme::collection).find(filter.view());

        double malzemeTotalFiyat = 0;

        for( auto doc : cursor )
        {
            double malzemeMiktari = 0 ;
            for( auto mal : malzemeoidList )
            {
                if( doc[SNKKey::oid].get_oid().value.to_string() == mal.oid )
                {
                    malzemeMiktari = mal.miktar;
                    break;
                }
            }
            malzemeTotalFiyat += malzemeMiktari*doc[SNKKey::Malzeme::fiyat].get_double().value * ( doc[SNKKey::Malzeme::kdv].get_double().value + 100.0 ) / 100.0;
        }

        fiyat = malzemeTotalFiyat*receteMiktar*(recetekdv+100.0)/100.0*(recetekar+100.0)/100.0;

        std::cout << "IND MalzemeTotalFiyat: " << malzemeTotalFiyat << std::endl;
        std::cout << "IND receteMiktar: " << receteMiktar << std::endl;
        std::cout << "IND recetekdv: " << recetekdv << std::endl;
        std::cout << "IND recetekar: " << recetekar << std::endl;
        std::cout << "IND fiyat: " << fiyat << std::endl;

    } catch (mongocxx::exception &e) {
        std::cout << "IND Malzeme Oid QUERY ERROR: " << e.what() << std::endl;
        return fiyat;
    }


    return fiyat;
}

double KasaDialog::getReceteIndFiyati(bsoncxx::oid receteoid, double receteMiktar)
{
    double fiyat = 0.0;

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,receteoid));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error ReceteOID: " << e.what() << std::endl;
        return fiyat;
    }

    double recetekdv = 0.0;
    double recetekar = 0.0;


    std::vector<ReceteMalzemesi> malzemeoidList;


    try {

        auto val = db->collection(SNKKey::Recete::Recete::collection).find_one(filter.view());
        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto view = val.value().view();
                recetekdv = view[SNKKey::Recete::Recete::kdv].get_double().value;
                recetekar = view[SNKKey::Recete::Recete::indirimliKar].get_double().value;

                auto arlist = view[SNKKey::Recete::Recete::malzeme].get_array().value;

                for( auto doc : arlist )
                {
                    auto sip = doc.get_document().view();
                    ReceteMalzemesi malzeme;
                    malzeme.miktar = sip[SNKKey::Recete::Recete::Malzemeler::miktar].get_double().value;
                    malzeme.oid = sip[SNKKey::Recete::Recete::Malzemeler::oid].get_oid().value.to_string();
                    malzemeoidList.push_back(malzeme);

                }
            }else{
                std::cout << "RECETE VIEW EMPTY" << std::endl;
                return fiyat;
            }
        }else{
            std::cout << "RECETE DOCUMENT EMPTY "<< std::endl;
            return fiyat;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Recete QUERY ERROR: " << e.what() << std::endl;
        return fiyat;
    }


    filter.clear();


    auto arList = array{};

    for( auto doc : malzemeoidList )
    {
        arList.append(bsoncxx::oid{doc.oid});
    }

    try {
        filter.append(kvp(SNKKey::oid,make_document(kvp("$in",arList))));
    } catch (bsoncxx::exception &e) {
        std::cout << "malzeme $in build error: " << e.what() << std::endl;
        return fiyat;
    }


    try {

        auto cursor = db->collection(SNKKey::Malzeme::collection).find(filter.view());

        double malzemeTotalFiyat = 0;

        for( auto doc : cursor )
        {
            double malzemeMiktari = 0 ;
            for( auto mal : malzemeoidList )
            {
                if( doc[SNKKey::oid].get_oid().value.to_string() == mal.oid )
                {
                    malzemeMiktari = mal.miktar;
                    break;
                }
            }
            malzemeTotalFiyat += malzemeMiktari*doc[SNKKey::Malzeme::fiyat].get_double().value * ( doc[SNKKey::Malzeme::kdv].get_double().value + 100.0 ) / 100.0;
        }

        fiyat = malzemeTotalFiyat*receteMiktar*(recetekdv+100.0)/100.0*(recetekar+100.0)/100.0;

        std::cout << "MalzemeTotalFiyat: " << malzemeTotalFiyat << std::endl;
        std::cout << "receteMiktar: " << receteMiktar << std::endl;
        std::cout << "recetekdv: " << recetekdv << std::endl;
        std::cout << "recetekar: " << recetekar << std::endl;
        std::cout << "fiyat: " << fiyat << std::endl;

    } catch (mongocxx::exception &e) {
        std::cout << "Malzeme Oid QUERY ERROR: " << e.what() << std::endl;
        return fiyat;
    }


    return fiyat;
}

bool KasaDialog::masayiKapat(bsoncxx::oid masaoid)
{


    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,masaoid));
    } catch (bsoncxx::exception &e) {
        std::cout << "Errro: " << e.what() << std::endl;
        return false;
    }


    auto updateDoc = document{};

    try {
        updateDoc.append(kvp("$set",make_document(kvp(SNKKey::Masa::durum,SNKKey::Masa::masaDurum::kullanimdadegil))));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }



    try {
        updateDoc.append(kvp("$unset",make_document(kvp(SNKKey::Masa::siparisoid,/*bsoncxx::oid{ui->lineEdit_siparisOid->text().toStdString()}*/1))));
    } catch (bsoncxx::exception &e) {
        std::cout << "Errro: " << e.what() << std::endl;
        return false;
    }




    try {
        auto upt = db->collection(SNKKey::Masa::collection).update_one(filter.view(),updateDoc.view());

        if( upt )
        {
            if( upt.value().modified_count() )
            {
                std::cout << "Successfully" << std::endl;
                ui->lineEdit_siparisOid->setText("");
                siparisModel->removeRows(0,siparisModel->rowCount());
                this->refreshMasaList();
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }



}

bool KasaDialog::deleteSiparis(bsoncxx::oid siparisOid)
{

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,siparisOid));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }



    try {

        auto del = db->collection(SNKKey::Siparis::collection).delete_one(filter.view());

        if( del )
        {
            if( del.value().deleted_count() )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Errro: " << e.what() << std::endl;
        return false;
    }


}

bool KasaDialog::getSelectedMasa() const
{
    return SelectedMasa;
}

void KasaDialog::setSelectedMasa(bool value)
{
    SelectedMasa = value;
}

void KasaDialog::addSelectedRecete(QString oid,double miktar)
{

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Recete::Recete::oid,bsoncxx::oid{oid.toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,"Recete oid");
        return;
    }

    auto val = this->find_one(SNKKey::Recete::Recete::collection,filter.view());


    if( siparisModel->rowCount() )
    {

        auto filter = document{};

        try {
            filter.append(kvp(SNKKey::oid,bsoncxx::oid{ui->lineEdit_siparisOid->text().toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,"SNKKey::Masa::Siparis::oid");
            return;
        }

        auto malzemeDoc = document{};

        try {
            malzemeDoc.append(kvp(SNKKey::Siparis::siparisList::receteoid,bsoncxx::oid{oid.toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,"SNKKey::Masa::Siparis::receteoid");
            return;
        }
        try {
            malzemeDoc.append(kvp(SNKKey::Siparis::siparisList::miktar,bsoncxx::types::b_double{miktar}));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,"SNKKey::Masa::Siparis::miktar");
            return;
        }
        try {
            malzemeDoc.append(kvp(SNKKey::Siparis::siparisList::index,siparisModel->rowCount()));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,"SNKKey::Masa::Siparis::miktar");
            return;
        }

        auto doc = document{};

        try {
            doc.append(kvp("$push",make_document(kvp(SNKKey::Siparis::siparis,malzemeDoc))));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,"$push");
            return;
        }



        mongocxx::options::find_one_and_update updateOptions;



        updateOptions.return_document(mongocxx::options::return_document::k_after);



        try {
            auto upt = db->collection(SNKKey::Siparis::collection).find_one_and_update(filter.view(),doc.view(),updateOptions);
            if( upt )
            {
                if( !upt.value().view().empty() )
                {
                    this->listMasaSiparisi(upt.value().view()[SNKKey::oid].get_oid().value.to_string().c_str());
                }
            }
        } catch (mongocxx::exception &e) {
            this->showMsg(e,"find_one_and_update");
            return;
        }


    }else{

        auto doc = document{};
        try {
            doc.append(kvp(SNKKey::Siparis::masaoid,bsoncxx::oid{ui->listView_Masalar->currentIndex().data(ItemDelegate::Delegate::MasaOid).toString().toStdString()}));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,SNKKey::Siparis::masaoid.c_str());
            return;
        }

        try {
            doc.append(kvp(SNKKey::Siparis::tarih,QDate::currentDate().toJulianDay()));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,SNKKey::Siparis::masaoid.c_str());
            return;
        }

        try {
            doc.append(kvp(SNKKey::Siparis::saat,QTime::currentTime().toString("hh:mm").toStdString().c_str()));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,SNKKey::Siparis::masaoid.c_str());
            return;
        }

        try {
            doc.append(kvp(SNKKey::Siparis::host,QSysInfo::machineHostName().toStdString().c_str()));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,SNKKey::Siparis::masaoid.c_str());
            return;
        }

        try {
            doc.append(kvp(SNKKey::Siparis::hesap,SNKKey::Siparis::Hesap::acik));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,SNKKey::Siparis::masaoid.c_str());
            return;
        }





        try {
            doc.append(kvp(SNKKey::Siparis::kasaoid,bsoncxx::oid{ui->lineEdikasaOid->text().toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,SNKKey::Siparis::kasaoid.c_str());
            return;
        }

        auto malzemeDoc = document{};

        try {
            malzemeDoc.append(kvp(SNKKey::Siparis::siparisList::receteoid,bsoncxx::oid{oid.toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,"SNKKey::Masa::Siparis::receteoid");
            return;
        }
        try {
            malzemeDoc.append(kvp(SNKKey::Siparis::siparisList::miktar,bsoncxx::types::b_double{miktar}));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,"SNKKey::Masa::Siparis::miktar");
            return;
        }
        try {
            malzemeDoc.append(kvp(SNKKey::Siparis::siparisList::index,int(0)));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,"SNKKey::Masa::Siparis::miktar");
            return;
        }


        auto arList = array{};

        try {
            arList.append(malzemeDoc);
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,"SNKKey::Masa::Siparis");
            return;
        }

        try {
            doc.append(kvp(SNKKey::Siparis::siparis,arList));
        } catch (bsoncxx::exception &e) {
            this->showMsg(e,SNKKey::Siparis::siparis.c_str());
            return;
        }

        auto ins = this->insert(SNKKey::Siparis::collection,doc.view());

        ui->lineEdit_siparisOid->setText(ins.value().inserted_id().get_oid().value.to_string().c_str());

        this->setMasaSiparis(ui->lineEdit_selectedMasaOid->text().toStdString(),ins.value().inserted_id().get_oid().value.to_string());

        this->listMasaSiparisi(ins.value().inserted_id().get_oid().value.to_string().c_str());

    }

    this->refreshMasaList();

}

void KasaDialog::showMsg(QString msg, QMessageBox::Icon icon)
{

    QMessageBox mDialog;

    mDialog.setText(msg);

    mDialog.setIcon(icon);

    mDialog.setWindowFlag(Qt::FramelessWindowHint);

    mDialog.exec();

    mDialog.deleteLater();

}

void KasaDialog::showMsg(bsoncxx::exception &e, std::string key , QMessageBox::Icon icon)
{
    this->showMsg(QString("%1 - %2").arg(key.c_str()).arg(e.what()),icon);
}

void KasaDialog::showMsg(mongocxx::exception &e, std::string key , QMessageBox::Icon icon)
{
    this->showMsg(QString("%1 - %2").arg(key.c_str()).arg(e.what()),icon);
}

mongocxx::stdx::optional<bsoncxx::document::value> KasaDialog::find_one(const std::string collection, const bsoncxx::document::view &filter_view, const mongocxx::options::find &findOption)
{
    try {
        auto val = db->collection(collection).find_one(filter_view,findOption);
        return val;
    } catch (mongocxx::exception &e) {
        this->showMsg(e,"find_one");
    }
}

mongocxx::cursor KasaDialog::find(const std::string collection, const bsoncxx::document::view &filter, const mongocxx::options::find &findOption)
{
    try {
        auto cursor = db->collection(collection).find(filter,findOption);
        return cursor;
    } catch (mongocxx::exception &e) {
        this->showMsg(e,"find");
    }
}

mongocxx::stdx::optional<mongocxx::result::insert_one> KasaDialog::insert(const std::string collection, const bsoncxx::document::view &doc)
{
    try {
        auto ins = this->db->collection(collection).insert_one(doc);
        if( ins )
        {
            if( ins.value().result().inserted_count() )
            {
                return ins;
            }else{
                this->showMsg("No Document İNserted");
            }
        }else{
            this->showMsg("No Document İnserted");
        }
    } catch (mongocxx::exception &e) {
        this->showMsg(e,"insert Error");
    }
}

void ItemDelegate::Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if( !index.isValid() )
    {
        return;
    }

    QString masaText = index.data(Qt::DisplayRole).toString();

    QString masaDurumu = index.data(MasaDurumu).toString();


    QFont font  = QApplication::font();


    painter->save();

    if( option.state & QStyle::StateFlag::State_Selected )
    {
        painter->setPen(Qt::white);
        painter->fillRect(option.rect,option.palette.highlight());
        font.setBold(true);
    }else{
        painter->setPen(Qt::black);
    }
    painter->setFont(font);

    QFontMetrics fontMetrics(font);

    QRect masaRect = fontMetrics.boundingRect( option.rect.left() + 72 , option.rect.top() + padding , option.rect.width() , 0 , Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,masaText);

    QRect masaStateRect = fontMetrics.boundingRect( option.rect.left() + 72 , masaRect.bottom() + padding , option.rect.width() , 0 , Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,masaDurumu);

    painter->drawText( masaRect , masaText );

    painter->drawText( masaStateRect , masaDurumu );

    if( masaDurumu.toStdString() == SNKKey::Masa::masaDurum::kullanimda )
    {
        if( mPixmapLoaded )
        {
            painter->drawPixmap( QRectF( option.rect.left() , option.rect.top() + padding , AcikPixmap.width() , AcikPixmap.height() ) , AcikPixmap , QRectF( 0 , 0 , AcikPixmap.width() , AcikPixmap.height() ) );
        }
    }else{
        if( mPixmapLoaded )
        {
            painter->drawPixmap( QRectF( option.rect.left() , option.rect.top() + padding , pixmap.width() , pixmap.height() ) , pixmap , QRectF( 0 , 0 , pixmap.width() , pixmap.height() ) );
        }
    }



    painter->restore();
}

QSize ItemDelegate::Delegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( !index.isValid() )
    {
        return QSize();
    }
    return QSize(option.rect.width() , /*rect.height() + */pixmap.height() + 2 * padding );
}

void KasaDialog::on_pushButton_siparis_al_clicked()
{
    if( this->getSelectedMasa() )
    {
        auto mDialog = std::make_unique<SiparisDialog>(db);
        connect(mDialog.get(),&SiparisDialog::selectedRecete,this,&KasaDialog::addSelectedRecete);
        mDialog.get()->exec();

        disconnect(mDialog.get(),&SiparisDialog::selectedRecete,this,&KasaDialog::addSelectedRecete);
    }else{
        this->showMsg("Masa Seçmediniz");
    }
}

void KasaDialog::on_listView_Masalar_clicked(const QModelIndex &index)
{
    ui->lineEdit_selectedMasaOid->setText(index.data(ItemDelegate::Delegate::MasaOid).toString());

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{ui->lineEdit_selectedMasaOid->text().toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        this->showMsg(e,"SNKKey::Masa::oid");
        return;
    }


    try {
        auto val = db->collection(SNKKey::Masa::collection).find_one(filter.view());
        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto view = val.value().view();
                try {
                    try {
                        if( view[SNKKey::Masa::siparisoid].get_oid().value.to_string().size() )
                        {
                            this->listMasaSiparisi(view[SNKKey::Masa::siparisoid].get_oid().value.to_string());
                        }else{
                            siparisModel->removeRows(0,siparisModel->rowCount());
                        }
                    } catch (bsoncxx::exception &e) {
                        siparisModel->removeRows(0,siparisModel->rowCount());
                    }
                    try {
                        ui->lineEdit_siparisOid->setText(view[SNKKey::Masa::siparisoid].get_oid().value.to_string().c_str());
                    } catch (bsoncxx::exception &e) {
                        ui->lineEdit_siparisOid->setText("");
                    }
                    try {
                        ui->label_Masainfo->setText(QString("<html><head/><body><p><span style=\" font-weight:600;\">Masa Dolu</span></p></body></html>"));
                    } catch (bsoncxx::exception &e) {
                        ui->label_Masainfo->setText(e.what());
                    }
                } catch (bsoncxx::exception &e) {
                    ui->lineEdit_siparisOid->setText("");
                    siparisModel->removeRows(0,siparisModel->rowCount());
                    ui->label_Masainfo->setText(QString("<html><head/><body><p><span style=\" font-weight:600;\">Bu Masada Sipariş Yok</span></p></body></html>"));
                    ui->doubleSpinBox_toplamMiktar->setValue(0);
                }
            }
        }

    } catch (mongocxx::exception &e) {
        this->showMsg(e,"Error Query");
    }

    this->setSelectedMasa(true);
}

void ItemDelegate::ReceteDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( !index.isValid() )
    {
        return;
    }

    QString title = index.data(Qt::DisplayRole).toString();
    QString kategori = index.data(KategoriRole).toString();
    QString miktar = "Miktar: " + QString::number(index.data(Miktar).toDouble()) + " - Fiyat: " + QString::number(index.data(fiyat).toDouble()) +" TL";


    QFont font = QApplication::font();

    font.setBold(true);
    font.setPixelSize(16);
    QFontMetrics titleMetrics(font);

    QFont subFont = QApplication::font();
    QFontMetrics subMetrics(subFont);

    QRect titleRect = titleMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,title);
    QRect KategoriRect = subMetrics.boundingRect(option.rect.left(),titleRect.bottom()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);
    QRect miktarRect = subMetrics.boundingRect(option.rect.left(),KategoriRect.bottom()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,miktar);

    painter->save();

    if( option.state & QStyle::State_Selected )
    {
        painter->fillRect(option.rect,option.palette.highlight());
        painter->setPen(Qt::white);
    }else{
        painter->setPen(Qt::black);
    }

    painter->setFont(font);
    painter->drawText(titleRect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,title);

    painter->setFont(subFont);
    painter->setPen(Qt::gray);
    painter->drawText(KategoriRect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);

//    painter->setFont(font);
    if( option.state & QStyle::State_Selected )
    {
        painter->setPen(Qt::white);
    }else{
        painter->setPen(Qt::black);
    }

    painter->drawText(miktarRect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,miktar);
    if( option.state & QStyle::State_Selected )
    {
        painter->setPen(Qt::white);
    }else{
        painter->setPen(Qt::gray);
    }

    painter->drawLine(option.rect.left(),miktarRect.bottom(),option.rect.right(),miktarRect.bottom());

    painter->restore();
}

QSize ItemDelegate::ReceteDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( !index.isValid() )
    {
        return QSize();
    }

    QString title = index.data(Qt::DisplayRole).toString();
    QString kategori = index.data(KategoriRole).toString();
    QString miktar = "Miktar: " + QString::number(index.data(Miktar).toDouble()) + " - Fiyat: " + QString::number(index.data(fiyat).toDouble()) +" TL";




    QFont font = QApplication::font();
    font.setBold(true);
    font.setPixelSize(16);
    QFontMetrics titleMetrics(font);

    QFont subFont = QApplication::font();
    QFontMetrics subMetrics(subFont);

    QRect titleRect = titleMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,title);

    QRect KategoriRect = subMetrics.boundingRect(option.rect.left(),titleRect.bottom()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);

    QRect miktarRect = subMetrics.boundingRect(option.rect.left(),KategoriRect.bottom()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,miktar);


    return  QSize(option.rect.width(),
                  titleRect.height()+
                  KategoriRect.height()+
                  miktarRect.height()+
                  2*padding+padding);
}


void KasaDialog::on_listView_Masalar_doubleClicked(const QModelIndex &index)
{
    if( this->getSelectedMasa() )
    {
        auto mDialog = std::make_unique<SiparisDialog>(db);
        connect(mDialog.get(),&SiparisDialog::selectedRecete,this,&KasaDialog::addSelectedRecete);
        mDialog.get()->exec();
        disconnect(mDialog.get(),&SiparisDialog::selectedRecete,this,&KasaDialog::addSelectedRecete);
    }else{
        this->showMsg("Masa Seçmediniz");
    }
}

void KasaDialog::on_pushButton_masayiKapat_clicked()
{

    if( !ui->lineEdit_siparisOid->text().isEmpty() )
    {
        if( ui->label_Depo->text() == "null" )
        {
            QMessageBox msg;
            msg.setText("Bu Kasaya Ait Depo Bulunamadı");
            msg.setWindowFlag(Qt::FramelessWindowHint);
            msg.setButtonText(QMessageBox::StandardButton::Ok,"Tamam Anladık!");
            msg.setStyleSheet("QDialog{border:1px solid black;}");
            msg.exec();
        }else{
            auto mDialog = std::make_unique<HesabiKapatDialog>(db,ui->doubleSpinBox_toplamMiktar->value(),ui->doubleSpinBox_toplamMiktar_ind->value(),ui->lineEdit_siparisOid->text().toStdString(),ui->label_Depo->text().toStdString());
            mDialog.get()->exec();

            if( mDialog.get()->odendi() )
            {
                listMasaSiparisi(ui->lineEdit_selectedMasaOid->text().toStdString());
                this->masayiKapat(bsoncxx::oid{ui->lineEdit_selectedMasaOid->text().toStdString()});
            }
        }

    }else{
        QMessageBox msg;
        msg.setText("Bu Masada Kapatılacak Bir Hesap Bulunmamakta");
        msg.setWindowFlag(Qt::FramelessWindowHint);
        msg.setButtonText(QMessageBox::StandardButton::Ok,"Tamam Anladık!");
        msg.setStyleSheet("QDialog{border:1px solid black;}");
        msg.exec();
    }


}

void KasaDialog::on_listView_siparisList_doubleClicked(const QModelIndex &index)
{

    QMessageBox::StandardButton btn = QMessageBox::question(this,"Sil?","Silmek İstediğinize Emin misiniz?",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if( btn != QMessageBox::StandardButton::Yes )
    {
        return;
    }

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{ui->lineEdit_siparisOid->text().toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Selected Siparis Append Error: " << e.what() << std::endl;
        return;
    }

    auto unsetDoc = document{};

    try {
        unsetDoc.append(kvp("$unset",make_document(kvp(SNKKey::Siparis::siparis+"."+std::to_string(index.row()),1))));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: siparis index: "  << e.what() << std::endl;
    }

    std::cout << bsoncxx::to_json(unsetDoc.view()) << std::endl;

    bool updated = false;
    try {
        auto upt = db->collection(SNKKey::Siparis::collection).update_one(filter.view(),unsetDoc.view());
        if( upt )
        {
            if( upt.value().modified_count() )
            {
                std::cout << "Modified" << std::endl;
                updated = true;
            }else{
                std::cout << "No Modified: " << upt.value().result().modified_count() << std::endl;
            }
        }else{
            std::cout << "No Pointer Update" << std::endl;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "unsetDoc exec Error: " << e.what() << std::endl;
    }

    if( updated )
    {

        auto pullDoc = document{};

        try {
            pullDoc.append(kvp("$pull",make_document(kvp(SNKKey::Siparis::siparis,bsoncxx::types::b_null{}))));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error: siparis index: "  << e.what() << std::endl;
        }



        try {
            auto upt = db->collection(SNKKey::Siparis::collection).update_one(filter.view(),pullDoc.view());
            if( upt )
            {
                if( upt.value().modified_count() )
                {
                    updated = true;
                    std::string siparisoid =  ui->lineEdit_siparisOid->text().toStdString();
                    this->listMasaSiparisi(siparisoid);
                    if( !siparisModel->rowCount() )
                    {
                        if( this->masayiKapat(bsoncxx::oid{ui->lineEdit_selectedMasaOid->text().toStdString()}) )
                        {
                            if( this->deleteSiparis(bsoncxx::oid{siparisoid}) )
                            {
                                ui->lineEdit_siparisOid->setText("");
                            }
                        }

                    }
                }else{
                }
            }else{
            }
        } catch (mongocxx::exception &e) {
            std::cout << "pullDoc exec Error: " << e.what() << std::endl;
        }

    }


}

void KasaDialog::on_pushButton_minimize_clicked()
{
    this->showMinimized();
}

void KasaDialog::on_pushButton_ToggleScreen_clicked()
{
    if( this->isMaximized() )
    {
        this->showNormal();
    }else{
        this->showMaximized();
    }
}

void KasaDialog::on_pushButton_close_clicked()
{
    this->close();
}
