#include "hesabikapatdialog.h"
#include "ui_hesabikapatdialog.h"

HesabiKapatDialog::HesabiKapatDialog(mongocxx::database *_db , double toplamMiktar , double _indirimliMiktar, std::string siparisOid, std::string depo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HesabiKapatDialog),
    db(_db),
    ToplamMiktar(toplamMiktar),
    SiparisOid(siparisOid),
    CurrentDepo(depo),
    IndirimliMiktar(_indirimliMiktar)
{
    ui->setupUi(this);
    ui->label_ToplamMiktar->setText(QString("%1 TL").arg(ToplamMiktar));
    ui->label_ToplamMiktarIND->setText(QString("%1 TL").arg(IndirimliMiktar));
    this->setOdendi(false);
    this->setWindowTitle("Hesabı Kapat?");



}

HesabiKapatDialog::~HesabiKapatDialog()
{
    delete ui;
}

void HesabiKapatDialog::on_pushButton_masayiKapat_clicked()
{

    if( ToplamMiktar-ui->doubleSpinBox_KrediKarti->value()-ui->doubleSpinBox_Nakit->value() > 0 )
    {
        QMessageBox msg;
        msg.setText("Ödeme Miktarı Yetersiz");
        msg.exec();
        return;
    }

    if( ToplamMiktar-ui->doubleSpinBox_KrediKarti->value()-ui->doubleSpinBox_Nakit->value() < 0 )
    {
        QMessageBox::StandardButton btn = QMessageBox::question(this,"Soru","Ödeme Fazla Gibi\nDevam Edilsin mi?",QMessageBox::StandardButton::Yes|QMessageBox::StandardButton::No);
        if( btn != QMessageBox::StandardButton::Yes )
        {
            return;
        }
    }

    auto doc = document{};

    try {
        doc.append(kvp(SNKKey::Siparis::Odeme::nakit,ui->doubleSpinBox_Nakit->value()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        doc.append(kvp(SNKKey::Siparis::Odeme::kredikarti,ui->doubleSpinBox_KrediKarti->value()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        doc.append(kvp(SNKKey::Siparis::Odeme::odenen,ui->doubleSpinBox_Odenen->value()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        doc.append(kvp(SNKKey::Siparis::Odeme::odemeTarih,QDate::currentDate().toJulianDay()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        doc.append(kvp(SNKKey::Siparis::Odeme::odemeSaat,QTime::currentTime().toString("hh:mm").toStdString()));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        doc.append(kvp(SNKKey::Siparis::hesap,SNKKey::Siparis::Hesap::kapali));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    auto setDoc = document{};
    try {
        setDoc.append(kvp("$set",doc));
    } catch (bsoncxx::exception &e) {
        std::cout << "Errro: " << e.what() << std::endl;
    }



    auto filter = document{};
    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{SiparisOid.c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    try {
        auto ins = db->collection(SNKKey::Siparis::collection).update_one(filter.view(),setDoc.view());
        if( ins )
        {
            if( ins.value().modified_count() )
            {
                this->setOdendi(true);
            }else{
                std::cout << "No Updated" << std::endl;
            }
        }else{
            std::cout << "No Pointer Returned" << std::endl;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }



    if( this->odendi() )
    {
        this->UpdateStock(SiparisOid);
    }


}

void HesabiKapatDialog::on_doubleSpinBox_Nakit_valueChanged(double arg1)
{
    ui->doubleSpinBox_Odenen->setValue(ui->doubleSpinBox_KrediKarti->value()+ui->doubleSpinBox_Nakit->value());
    ui->label_KalanMiktar->setText(QString("%1 TL").arg(ToplamMiktar-ui->doubleSpinBox_KrediKarti->value()-ui->doubleSpinBox_Nakit->value()));
}

void HesabiKapatDialog::on_doubleSpinBox_KrediKarti_valueChanged(double arg1)
{
    ui->doubleSpinBox_Odenen->setValue(ui->doubleSpinBox_KrediKarti->value()+ui->doubleSpinBox_Nakit->value());
    ui->label_KalanMiktar->setText(QString("%1 TL").arg(ToplamMiktar-ui->doubleSpinBox_KrediKarti->value()-ui->doubleSpinBox_Nakit->value()));
}

void HesabiKapatDialog::on_pushButton_TamamiNakit_clicked()
{
    ui->doubleSpinBox_Nakit->setValue(ToplamMiktar);
    ui->doubleSpinBox_KrediKarti->setValue(0);
}

void HesabiKapatDialog::on_pushButton_TamamiKrediKarti_clicked()
{
    ui->doubleSpinBox_Nakit->setValue(0);
    ui->doubleSpinBox_KrediKarti->setValue(ToplamMiktar);
}

void HesabiKapatDialog::UpdateStock(std::string siparisoid)
{


    auto filter = document{};
    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{siparisoid.c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }



    QMap<QString,double> ReceteList;

    try {

        auto val = db->collection(SNKKey::Siparis::collection).find_one(filter.view());

        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto arlist = val.value().view()[SNKKey::Siparis::siparis].get_array().value;
                for( auto _doc : arlist )
                {
                    auto doc = _doc.get_document().value;
                    if( ReceteList.contains(doc[SNKKey::Siparis::siparisList::receteoid].get_oid().value.to_string().c_str()) )
                    {
                        ReceteList[doc[SNKKey::Siparis::siparisList::receteoid].get_oid().value.to_string().c_str()] += doc[SNKKey::Siparis::siparisList::miktar].get_double().value;
                    }else{
                        ReceteList[doc[SNKKey::Siparis::siparisList::receteoid].get_oid().value.to_string().c_str()] = doc[SNKKey::Siparis::siparisList::miktar].get_double().value;
                    }
                }
            }
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Errror: " << e.what() << std::endl;
    }

    QMap<QString,double> MalzemeList;


    QMapIterator<QString, double> i(ReceteList);

    while (i.hasNext()) {
        i.next();

        auto filter_ = document{};

        try {
            filter_.append(kvp(SNKKey::oid,bsoncxx::oid{i.key().toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            std::cout << "Errror: " << e.what() << std::endl;
        }

        std::cout << "Recete Filter: " << bsoncxx::to_json(filter_) << std::endl;


        try {
            auto receteval = db->collection(SNKKey::Recete::Recete::collection).find_one(filter_.view());

            if( receteval )
            {
                if( !receteval.value().view().empty() )
                {
                    auto arlist = receteval.value().view()[SNKKey::Recete::Recete::malzeme].get_array().value;
                    for( auto _doc : arlist )
                    {
                        auto doc = _doc.get_document().value;
                        if( MalzemeList.contains(doc[SNKKey::Recete::Recete::Malzemeler::oid].get_oid().value.to_string().c_str()) )
                        {
                            MalzemeList[doc[SNKKey::Recete::Recete::Malzemeler::oid].get_oid().value.to_string().c_str()] += doc[SNKKey::Recete::Recete::Malzemeler::miktar].get_double().value*i.value();
                        }else{
                            MalzemeList[doc[SNKKey::Recete::Recete::Malzemeler::oid].get_oid().value.to_string().c_str()] = doc[SNKKey::Recete::Recete::Malzemeler::miktar].get_double().value*i.value();
                        }
                    }
                }
            }

        } catch (mongocxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }



    QMapIterator<QString, double> Malzeme(MalzemeList);

    while ( Malzeme.hasNext() ) {
        Malzeme.next();

        auto filter_ = document{};

        try {
            filter_.append(kvp(SNKKey::StokMiktar::malzemeoid,bsoncxx::oid{Malzeme.key().toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error : " << e.what() << std::endl;
        }

        try {
            filter_.append(kvp(SNKKey::StokMiktar::depo,CurrentDepo.c_str()));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error : " << e.what() << std::endl;
        }

        auto incDoc = document{};
        try {
            auto dec = Malzeme.value() * ( -1.0 );
            incDoc.append(kvp("$inc",make_document(kvp(SNKKey::StokMiktar::miktar,dec))));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error: "<< e.what() << std::endl;
        }

        std::cout << "Filter: " << bsoncxx::to_json(filter_) << std::endl;
        std::cout << "INC: " << bsoncxx::to_json(incDoc) << std::endl;

        try {
            auto upt = db->collection(SNKKey::StokMiktar::collection).update_one(filter_.view(),incDoc.view());
            if( upt )
            {
                if( upt.value().modified_count() )
                {
                    std::cout << "Modified Count : "<<  upt.value().modified_count() << std::endl;
                }else{
                    std::cout << "No Modified" << std::endl;
                }
            }else{
                std::cout << "No POinter Returned" << std::endl;
            }
        } catch (mongocxx::exception &e) {
            std::cout << "Errror: " << e.what() << std::endl;
        }
    }


    this->close();


}

bool HesabiKapatDialog::odendi() const
{
    return mOdendi;
}

void HesabiKapatDialog::setOdendi(bool odendi)
{
    mOdendi = odendi;
}

void HesabiKapatDialog::on_pushButton_CariHesabaAt_clicked()
{
    std::unique_ptr<CariDialog> mDialog = std::make_unique<CariDialog>(db,ToplamMiktar,IndirimliMiktar,SiparisOid);

    mDialog->exec();

    if( mDialog->setHesap() )
    {
        this->setOdendi(true);
        this->UpdateStock(SiparisOid);
        auto filter = document{};
        try {
            filter.append(kvp(SNKKey::oid,bsoncxx::oid{SiparisOid.c_str()}));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        try {
            auto del = db->collection(SNKKey::Siparis::collection).delete_one(filter.view());
            if( del )
            {
                if( del.value().deleted_count() )
                {
                    this->close();
                }else{
                    std::cout << "Siparis Silinemedi" << std::endl;
                }
            }else{
                std::cout << "Siparis Silinemedi" << std::endl;
            }
        } catch (mongocxx::exception &e) {
            std::cout << "Siparis Silinemedi , Errror: " << e.what() << std::endl;
        }
    }
}

void HesabiKapatDialog::on_pushButton_OdemeIptal_clicked()
{
    this->close();
}
