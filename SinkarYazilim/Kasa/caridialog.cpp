#include "caridialog.h"
#include "ui_caridialog.h"

#include "addcarihesapdialog.h"

CariDialog::CariDialog(mongocxx::database *_db, double _toplamMiktar, double _indirimliMiktar, std::string _siparisOid, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CariDialog),
    db(_db),
    ToplamMiktar(_toplamMiktar),
    ToplamMiktar_ind(_indirimliMiktar),
    siparisOid(_siparisOid)
{
    ui->setupUi(this);

    this->setWindowTitle("Cari Hesap");

    model = new QStandardItemModel;

    model->setHorizontalHeaderLabels(QStringList()<<"İsim & Soyisim");

    proxyModel = new QSortFilterProxyModel;

    proxyModel->setSourceModel(model);

    ui->listView->setModel(proxyModel);

    this->initKisiList();

    this->setSetHesap(false);

    ui->label_ToplamMiktar->setText(QString("<html><head/><body><p><span style=\" font-weight:600;\">Toplam Miktar %1 TL</span></p></body></html>").arg(ToplamMiktar));

    ui->label_ToplamMiktar_ind->setText(QString("<html><head/><body><p><span style=\" font-weight:600;\">Toplam İndirimli Miktar %1 TL</span></p></body></html>").arg(ToplamMiktar_ind));

    this->setSelectedKisi(false);
}

CariDialog::~CariDialog()
{
    delete ui;
}

void CariDialog::on_pushButton_CloseDialog_clicked()
{
    this->close();
}

void CariDialog::on_pushButton_addKisi_clicked()
{
    std::unique_ptr<addCariHesapDialog> mDialog = std::make_unique<addCariHesapDialog>(db);

    mDialog->exec();

    if( mDialog.get()->accepted() )
    {
        this->initKisiList();

        ui->lineEdit_ProxyFilter->setText(mDialog.get()->name());

    }
}

void CariDialog::initKisiList()
{
#ifndef SINKAR
    try {
        auto cursor = db->collection(SNKKey::Cari::Kisiler::collection).find(document{}.view());
        int row = 0;
        model->removeRows(0,model->rowCount());
        for( auto doc : cursor )
        {
            {
                QStandardItem* item = new QStandardItem;
                try {
                    item->setText(doc[SNKKey::Cari::Kisiler::ad].get_utf8().value.to_string().c_str());
                } catch (bsoncxx::exception &e) {
                    item->setText(e.what());
                }
                try {
                    item->setData(doc[SNKKey::oid].get_oid().value.to_string().c_str(),Qt::UserRole);
                } catch (bsoncxx::exception &e) {
                    item->setData("null",Qt::UserRole);
                }
                model->setItem(row,0,item);
            }
            row++;
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Errro: " << e.what() << std::endl;
    }
#endif


}

bool CariDialog::setHesap() const
{
    return mSetHesap;
}

void CariDialog::setSetHesap(bool setHesap)
{
    mSetHesap = setHesap;
}

bool CariDialog::selectedKisi() const
{
    return mSelectedKisi;
}

void CariDialog::setSelectedKisi(bool selectedKisi)
{
    mSelectedKisi = selectedKisi;
}

bsoncxx::array::value CariDialog::getSiparisArray(std::string _SiparisOid)
{

    auto arlist = array{};


    auto filter = document{};


    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{_SiparisOid}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return  arlist.extract();
    }

    mongocxx::options::find findOption;

    auto projectView = document{};

    try {
        projectView.append(kvp(SNKKey::Siparis::kasaoid,true));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return  arlist.extract();
    }

    try {
        projectView.append(kvp(SNKKey::Siparis::siparis,true));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return  arlist.extract();
    }

    findOption.projection(projectView.view());


    try {
        auto val = db->collection(SNKKey::Siparis::collection).find_one(filter.view(),findOption);
        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto ar = val.value().view()[SNKKey::Siparis::siparis].get_array().value;
                for( auto doc : ar )
                {
                    arlist.append(doc.get_document().value);
                }
                return arlist.extract();
            }else{
                std::cout << "Errror No Document" << std::endl;
                return arlist.extract();
            }
        }else{
            std::cout << "No Returned Document" << std::endl;
            return arlist.extract();
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return arlist.extract();
    }

}

std::string CariDialog::getSiparisKasa(std::string _siparisOid)
{

    auto filter = document{};

    std::string getoid{"null"};

    try {
        filter.append(kvp(SNKKey::oid,bsoncxx::oid{_siparisOid}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return getoid;
    }

    mongocxx::options::find findOption;

    auto projectView = document{};

    try {
        projectView.append(kvp(SNKKey::Siparis::kasaoid,true));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return getoid;
    }

    findOption.projection(projectView.view());


    try {
        auto val = db->collection(SNKKey::Siparis::collection).find_one(filter.view(),findOption);
        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto ar = val.value().view()[SNKKey::Siparis::kasaoid].get_oid().value;
                return ar.to_string();
            }else{
                std::cout << "Errror No Document" << std::endl;
                return getoid;
            }
        }else{
            return getoid;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return getoid;
    }

}

void CariDialog::on_lineEdit_ProxyFilter_textChanged(const QString &arg1)
{
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterRegExp(arg1);
}

void CariDialog::on_pushButton_refereshList_clicked()
{
    this->initKisiList();
}

void CariDialog::on_listView_doubleClicked(const QModelIndex &index)
{

    if( !ui->radioButton_Normal->isChecked() && !ui->radioButton_indirimli->isChecked() )
    {
        QMessageBox msg;
        msg.setText("Tutarı Seçmediniz");
        msg.setIcon(QMessageBox::Icon::Warning);
        msg.setWindowFlag(Qt::FramelessWindowHint);
        msg.setStyleSheet("QDialog{border:1px solid black;}");
        msg.exec();
        return;
    }

    auto siparisLis = this->getSiparisArray(this->siparisOid);

    auto kasaoid = this->getSiparisKasa(this->siparisOid);


    if( index.data(Qt::UserRole).toString() != "null" )
    {
        auto doc = document{};

        try {
            doc.append(kvp(SNKKey::Cari::Hesap::odeme,SNKKey::Cari::Hesap::Odeme::odenmedi));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::odeme <<" Error: " << e.what() << std::endl;
            return;
        }

        try {
            doc.append(kvp(SNKKey::Cari::Hesap::siparisList,siparisLis));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::odeme <<" Error: " << e.what() << std::endl;
            return;
        }

        if( kasaoid != "null" )
        {
            try {
                doc.append(kvp(SNKKey::Cari::Hesap::kasaoid,bsoncxx::oid{kasaoid}));
            } catch (bsoncxx::exception &e) {
                std::cout << SNKKey::Cari::Hesap::odeme <<" Error: " << e.what() << std::endl;
                return;
            }
        }


        try {
            doc.append(kvp(SNKKey::Cari::Hesap::kisioid,bsoncxx::oid{index.data(Qt::UserRole).toString().toStdString()}));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::kisioid <<" Error: " << e.what() << std::endl;
            return;
        }

        if( ui->radioButton_Normal->isChecked() )
        {
            try {
                doc.append(kvp(SNKKey::Cari::Hesap::miktar,bsoncxx::types::b_double{ToplamMiktar}));
            } catch (bsoncxx::exception &e) {
                std::cout << SNKKey::Cari::Hesap::miktar <<" Error: " << e.what() << std::endl;
                return;
            }

            try {
                doc.append(kvp(SNKKey::Cari::Hesap::indirim,SNKKey::Cari::Hesap::INDIRIM::yok));
            } catch (bsoncxx::exception &e) {
                std::cout << SNKKey::Cari::Hesap::indirim <<" Error: " << e.what() << std::endl;
                return;
            }
        }else{
            try {
                doc.append(kvp(SNKKey::Cari::Hesap::miktar,bsoncxx::types::b_double{ToplamMiktar_ind}));
            } catch (bsoncxx::exception &e) {
                std::cout << SNKKey::Cari::Hesap::miktar <<" Error: " << e.what() << std::endl;
                return;
            }
            try {
                doc.append(kvp(SNKKey::Cari::Hesap::indirim,SNKKey::Cari::Hesap::INDIRIM::var));
            } catch (bsoncxx::exception &e) {
                std::cout << SNKKey::Cari::Hesap::indirim <<" Error: " << e.what() << std::endl;
                return;
            }
        }


        try {
            doc.append(kvp(SNKKey::Cari::Hesap::julianDate,QDate::currentDate().toJulianDay()));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::julianDate <<" Error: " << e.what() << std::endl;
            return;
        }

        try {
            doc.append(kvp(SNKKey::Cari::Hesap::saat,QTime::currentTime().toString("hh:mm").toStdString()));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::saat <<" Error: " << e.what() << std::endl;
            return;
        }

        try {
            doc.append(kvp(SNKKey::Cari::Hesap::saat,QTime::currentTime().toString("hh:mm").toStdString()));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::saat <<" Error: " << e.what() << std::endl;
            return;
        }

        try {
            auto ins = db->collection(SNKKey::Cari::Hesap::collection).insert_one(doc.view());
            if( ins )
            {
                if( ins.value().result().inserted_count() )
                {
                    this->setSetHesap(true);
                    this->close();
                }else{
                    this->setSetHesap(false);
                    std::cout << "No Document Inserted " << std::endl;
                }
            }else{
                this->setSetHesap(false);
                std::cout << "No Document Returned" << std::endl;
            }
        } catch (mongocxx::exception &e) {
            this->setSetHesap(false);
            std::cout << "Errror: " << e.what() << std::endl;
        }
    }

}

void CariDialog::on_pushButton_SelectKisi_clicked()
{


#ifndef SINKAR

    if( !selectedKisi() )
    {
        QMessageBox msg;
        msg.setText("Hesap Seçmediniz");
        msg.setInformativeText("Lütfen Hesap Seçiniz");
        msg.setIcon(QMessageBox::Icon::Warning);
        msg.setWindowFlag(Qt::FramelessWindowHint);
        msg.setStyleSheet("QDialog{border:1px solid black;}");
        msg.exec();
        return;
    }


    QModelIndex index = ui->listView->currentIndex();


    if( !ui->radioButton_Normal->isChecked() && !ui->radioButton_indirimli->isChecked() )
    {
        QMessageBox msg;
        msg.setText("Tutarı Seçmediniz");
        msg.setIcon(QMessageBox::Icon::Warning);
        msg.setWindowFlag(Qt::FramelessWindowHint);
        msg.setStyleSheet("QDialog{border:1px solid black;}");
        msg.exec();
        return;
    }

    if( index.data(Qt::UserRole).toString() != "null" )
    {
        auto doc = document{};

        try {
            doc.append(kvp(SNKKey::Cari::Hesap::odeme,SNKKey::Cari::Hesap::Odeme::odenmedi));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::odeme <<" Error: " << e.what() << std::endl;
            return;
        }

        try {
            doc.append(kvp(SNKKey::Cari::Hesap::kisioid,bsoncxx::oid{index.data(Qt::UserRole).toString().toStdString()}));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::kisioid <<" Error: " << e.what() << std::endl;
            return;
        }

        if( ui->radioButton_Normal->isChecked() )
        {
            try {
                doc.append(kvp(SNKKey::Cari::Hesap::miktar,bsoncxx::types::b_double{ToplamMiktar}));
            } catch (bsoncxx::exception &e) {
                std::cout << SNKKey::Cari::Hesap::miktar <<" Error: " << e.what() << std::endl;
                return;
            }

            try {
                doc.append(kvp(SNKKey::Cari::Hesap::indirim,SNKKey::Cari::Hesap::INDIRIM::yok));
            } catch (bsoncxx::exception &e) {
                std::cout << SNKKey::Cari::Hesap::indirim <<" Error: " << e.what() << std::endl;
                return;
            }
        }else{
            try {
                doc.append(kvp(SNKKey::Cari::Hesap::miktar,bsoncxx::types::b_double{ToplamMiktar_ind}));
            } catch (bsoncxx::exception &e) {
                std::cout << SNKKey::Cari::Hesap::miktar <<" Error: " << e.what() << std::endl;
                return;
            }
            try {
                doc.append(kvp(SNKKey::Cari::Hesap::indirim,SNKKey::Cari::Hesap::INDIRIM::var));
            } catch (bsoncxx::exception &e) {
                std::cout << SNKKey::Cari::Hesap::indirim <<" Error: " << e.what() << std::endl;
                return;
            }
        }


        try {
            doc.append(kvp(SNKKey::Cari::Hesap::julianDate,QDate::currentDate().toJulianDay()));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::julianDate <<" Error: " << e.what() << std::endl;
            return;
        }

        try {
            doc.append(kvp(SNKKey::Cari::Hesap::saat,QTime::currentTime().toString("hh:mm").toStdString()));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::saat <<" Error: " << e.what() << std::endl;
            return;
        }

        try {
            doc.append(kvp(SNKKey::Cari::Hesap::saat,QTime::currentTime().toString("hh:mm").toStdString()));
        } catch (bsoncxx::exception &e) {
            std::cout << SNKKey::Cari::Hesap::saat <<" Error: " << e.what() << std::endl;
            return;
        }

        try {
            auto ins = db->collection(SNKKey::Cari::Hesap::collection).insert_one(doc.view());
            if( ins )
            {
                if( ins.value().result().inserted_count() )
                {
                    this->setSetHesap(true);
                    this->close();
                }else{
                    this->setSetHesap(false);
                    std::cout << "No Document Inserted " << std::endl;
                }
            }else{
                this->setSetHesap(false);
                std::cout << "No Document Returned" << std::endl;
            }
        } catch (mongocxx::exception &e) {
            this->setSetHesap(false);
            std::cout << "Errror: " << e.what() << std::endl;
        }
    }


#endif
}

void CariDialog::on_listView_clicked(const QModelIndex &index)
{
    this->setSelectedKisi(true);
}
