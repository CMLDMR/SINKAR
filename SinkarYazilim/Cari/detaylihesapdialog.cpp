#include "detaylihesapdialog.h"
#include "ui_detaylihesapdialog.h"

#include "gelirgidersceneitem.h"

DetayliHesapDialog::DetayliHesapDialog(mongocxx::database *_db, bsoncxx::document::value *_user, QWidget *parent) :
    DBUser (_db,_user),
    QDialog(parent),
    ui(new Ui::DetayliHesapDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Detaylı Hesap Kontrol - ") + this->getPersonelFullName());

    this->initCariControl();

    ui->tabWidget->setCurrentIndex(0);

    setMinitMalzemeGider(false);

    connect(ui->tabWidget,&QTabWidget::currentChanged,this,&DetayliHesapDialog::mCurrentTabIndex);

}

DetayliHesapDialog::~DetayliHesapDialog()
{
    delete ui;
}

void DetayliHesapDialog::initCariControl()
{
    modelCariControlKisiList = new QStandardItemModel;
    modelCariControlKisiList->setHorizontalHeaderLabels(QStringList()<<"Kişi Adı");
    proxyCariControlKisiList = new QSortFilterProxyModel;
    proxyCariControlKisiList->setSourceModel(modelCariControlKisiList);
    proxyCariControlKisiList->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->listView_CariiControlKisiList->setModel(proxyCariControlKisiList);
    mCariKontrolKisiDelegate = new Delegate::KisiDelegate;
    ui->listView_CariiControlKisiList->setItemDelegate(mCariKontrolKisiDelegate);
    this->initCariKisiList();
}

void DetayliHesapDialog::initCariKisiList()
{

    try {
        auto cursor = this->collection(SNKKey::Cari::Kisiler::collection).find(document{}.view());
        modelCariControlKisiList->removeRows(0,modelCariControlKisiList->rowCount());
        for( auto doc : cursor )
        {
            auto item = new QStandardItem;
            item->setText(doc[SNKKey::Cari::Kisiler::ad].get_utf8().value.to_string().c_str());
            item->setData(doc[SNKKey::oid].get_oid().value.to_string().c_str(),Delegate::KisiDelegate::Oid);
            modelCariControlKisiList->appendRow(item);
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

}

bool DetayliHesapDialog::getMinitMalzemeGider() const
{
    return minitMalzemeGider;
}

void DetayliHesapDialog::setMinitMalzemeGider(bool value)
{
    minitMalzemeGider = value;
}

void DetayliHesapDialog::initMalzemeGider()
{
    if( !this->getMinitMalzemeGider() )
    {
        mMalzemeGiderScene = new QGraphicsScene();
        ui->graphicsView_MalzemeGider->setScene(mMalzemeGiderScene);
        connect(ui->pushButton_MalzemeGiderExport,&QPushButton::clicked,this,&DetayliHesapDialog::exportMalzemeGider);
        this->setMinitMalzemeGider(true);
        ui->dateEdit_MalzemeGiderSetDate->setDate(QDate::currentDate());
    }
}

void DetayliHesapDialog::exportMalzemeGider()
{

    using namespace std;


    auto filter = document{};

    QVector<bsoncxx::document::view> viewList;
    QStringList strList;


    try {
        auto cursor = this->collection(SNKKey::Cari::Hesap::collection).find(filter.view());
        for( auto doc : cursor )
        {
            viewList.append(doc);
            strList.append(QString::number(doc[SNKKey::Cari::Hesap::julianDate].get_int64().value));
        }
    } catch (mongocxx::exception &e) {
        cout << "Error: " << e.what() << std::endl;
    }

    strList.removeDuplicates();

    for( QString tarih_ : strList )
    {
        double gelir = 0;
        double gider = 0;
        int64_t tarih = tarih_.toLongLong();
        for( auto doc : viewList )
        {
            try {
                if( tarih == doc[SNKKey::Cari::Hesap::odemeJulianDate].get_int64().value )
                {
                    try {
                        gelir += doc[SNKKey::Cari::Hesap::odemeMiktari].get_double().value;
                    } catch (bsoncxx::exception &e) {
                    }
                }
            } catch (bsoncxx::exception &e) {
            }

            try {
                auto sipList = doc[SNKKey::Cari::Hesap::siparisList].get_array().value;
                for( auto receteDoc : sipList )
                {
                    gider += this->getReceteGider(receteDoc.get_document().view()[SNKKey::Cari::Hesap::SIPARISLIST::receteoid].get_oid().value.to_string(),receteDoc.get_document().view()[SNKKey::Cari::Hesap::SIPARISLIST::miktar].get_double().value);
                }
            } catch (bsoncxx::exception &e) {

            }
        }
        cout << tarih << " - " << gelir << " - " << gider << endl;
        this->addGunBarMalzemeGiderScene(tarih,gelir,gider);
    }
     mMalzemeGiderScene->update(ui->graphicsView_MalzemeGider->rect());
     ui->graphicsView_MalzemeGider->updateSceneRect(mMalzemeGiderScene->itemsBoundingRect());
}

void DetayliHesapDialog::ClearMalzemeGiderScene()
{
    mMalzemeGiderScene->clear();
}

bool DetayliHesapDialog::addGunBarMalzemeGiderScene(qint64 date, double gelir, double gider)
{

    qreal ypos = mMalzemeGiderScene->itemsBoundingRect().height();
    if( ypos != 0.0 ) ypos += barPadding;


    qreal xpos = 0.0;



    GelirGiderSceneItem* item = new GelirGiderSceneItem(date,gelir,gider);

    mMalzemeGiderScene->addItem(item);
    item->setPos(xpos,mMalzemeGiderScene->itemsBoundingRect().bottom()+5);

}

bool DetayliHesapDialog::addAyBartoBottomGunBar(QString ay, double gelir, double gider)
{
    const double ciroStep =  ui->doubleSpinBox_MalzemeGiderMaxCiro->value();

    qreal ypos = mMalzemeGiderScene->itemsBoundingRect().bottom();
    qreal xpos = 0.0;


    auto text = mMalzemeGiderScene->addText("<h2>"+ay + " Net : " + QString( "%1" ).arg(gelir-gider)+"</h2>");
    text->setHtml("<h2>"+ay + " Net : " + QString( "%1" ).arg(gelir-gider)+" TL </h2>");
    text->setPos(xpos,ypos);

    auto gelirItem = mMalzemeGiderScene->addRect( xpos , ypos+25 , gelir/ciroStep*10 , 20 , QPen(Qt::green),QBrush(Qt::GlobalColor::green));
    auto gelirText = mMalzemeGiderScene->addText(QString("%1 TL").arg(gelir));
    gelirText->setPos(xpos+20,ypos+25);

    auto giderItem = mMalzemeGiderScene->addRect( xpos , ypos+25+25 ,gider/ciroStep*10 , 20, QPen(Qt::red),QBrush(Qt::GlobalColor::red));
    auto giderText = mMalzemeGiderScene->addText(QString("%1 TL").arg(gider));
    giderText->setPos(xpos+20,ypos+25+25);


}

double DetayliHesapDialog::getReceteGider(std::string receteoid, double receteMiktar)
{

    double gider = 0.0;

    auto receteFilter = document{};

    try {
        receteFilter.append(kvp(SNKKey::oid,bsoncxx::oid{receteoid}));
    } catch (bsoncxx::exception &e) {
        return 0.0;
    }

    bsoncxx::document::value Receteval = bsoncxx::document::value(document{}.view());

    try {
        auto val_ = this->collection(SNKKey::Recete::Recete::collection).find_one(receteFilter.view());
        if( val_ )
        {
            if( !val_.value().view().empty() )
            {
                Receteval = val_.value();
            }else{
                return 0.0;
            }
        }else{
            return 0.0;
        }

    } catch (mongocxx::exception &e) {
        return 0.0;
    }

    try {

        std::cout << "\nRECETE: " << Receteval.view()[SNKKey::Recete::Recete::adi].get_utf8().value.to_string() << std::endl;
    } catch (bsoncxx::exception &e) {

    }



    QVector<bsoncxx::document::view> malList;
    try {
        auto malListViewList = Receteval.view()[SNKKey::Recete::Recete::malzeme].get_array().value;
        for( auto doc : malListViewList )
        {
            malList.append(doc.get_document().view());
        }
    } catch (bsoncxx::exception &e) {
        return 0.0;
    }

    if( !malList.count() )
    {
        return 0.0;
    }


    for( auto mal : malList )
    {

        auto malFilter = document{};

        try {
            malFilter.append(kvp(SNKKey::Malzeme::oid,mal[SNKKey::Recete::Recete::Malzemeler::oid].get_oid().value));
        } catch (bsoncxx::exception &e) {

        }

        try {

            auto malVal = this->collection(SNKKey::Malzeme::collection).find_one(malFilter.view());

            if( malVal )
            {
                if( !malVal.value().view().empty() )
                {
                    auto view = malVal.value().view();

                    gider += view[SNKKey::Malzeme::fiyat].get_double().value * (view[SNKKey::Malzeme::kdv].get_double().value + 100.0) / 100.0 * mal[SNKKey::Recete::Recete::Malzemeler::miktar].get_double().value;

                    try {
                        std::string malzeme = view[SNKKey::Malzeme::adi].get_utf8().value.to_string();
                        std::cout << "Malzeme: " << malzeme << " " << gider << std::endl;
                    } catch (bsoncxx::exception &e) {

                    }
                }
            }


        } catch (mongocxx::exception &e) {

        }



    }

    gider = gider * receteMiktar;

    std::cout << "RECETEGIDER: " << gider << std::endl;

    return gider;


}

void DetayliHesapDialog::on_lineEdit_CariControlFilter_textChanged(const QString &arg1)
{
    this->proxyCariControlKisiList->setFilterRegExp(arg1);
}

void DetayliHesapDialog::on_listView_CariiControlKisiList_clicked(const QModelIndex &index)
{

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Cari::Hesap::kisioid,bsoncxx::oid{index.data(Delegate::KisiDelegate::Oid).toString().toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    try {
        auto cursor = this->collection(SNKKey::Cari::Hesap::collection).find(filter.view());

        double toplamBorc = 0;
        double toplamOdeme = 0;
        double toplamNakitOdeme = 0;
        double toplamKrediOdeme = 0;

        for( auto doc : cursor )
        {

            bool odeme = SNKKey::Cari::Hesap::Odeme::odenmedi;
            try {
                odeme = doc[SNKKey::Cari::Hesap::odeme].get_bool().value;
            } catch (bsoncxx::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
            }

            try {
                toplamBorc += doc[SNKKey::Cari::Hesap::miktar].get_double().value;
            } catch (bsoncxx::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
            }

            if( odeme == SNKKey::Cari::Hesap::Odeme::odendi )
            {
                try {
                    toplamOdeme += doc[SNKKey::Cari::Hesap::odemeMiktari].get_double().value;
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }

                try {
                    toplamNakitOdeme += doc[SNKKey::Cari::Hesap::odemeMiktariNakit].get_double().value;
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }

                try {
                    toplamKrediOdeme += doc[SNKKey::Cari::Hesap::odemeMiktariKredi].get_double().value;
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
            }
        }

        ui->doubleSpinBox_CariControlToplamBorc->setValue(toplamBorc);
        ui->doubleSpinBox_CariControlToplamNakitOdeme->setValue(toplamNakitOdeme);
        ui->doubleSpinBox_CariControlKrediOdeme->setValue(toplamKrediOdeme);
        ui->doubleSpinBox_CariControlToplamOdeme->setValue(toplamOdeme);
        ui->doubleSpinBox_CariControlKalanBorc->setValue(toplamBorc-toplamOdeme);

    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

}

void DetayliHesapDialog::mCurrentTabIndex(int index)
{

    if( index == 1 )
    {
        this->initMalzemeGider();
    }

}

void DetayliHesapDialog::on_pushButton_toggleFullScreen_clicked()
{
    if( this->isMaximized() )
    {
        this->showNormal();
    }else{
        this->showMaximized();
    }
}

void DetayliHesapDialog::on_pushButton_Minimize_clicked()
{
    this->showMinimized();
}

void DetayliHesapDialog::on_pushButton_Close_clicked()
{
    this->close();
}

void DetayliHesapDialog::on_pushButton_MalzemeGiderCreateTestEntry_clicked()
{

    return;

    QDate begindate;
    begindate.setDate(2018,1,1);
    QDate endDate;
    endDate.setDate(2018,12,31);

    qsrand(QTime::currentTime().msec());

    // Recece Birim Fiyat
    const double birimFiyat = 10.0;

    int count = 0;




    for( auto i = begindate.toJulianDay() ; i < /*endDate.toJulianDay()*/begindate.toJulianDay()+75 ; i++ )
    {



        int random = qrand() % 5 ;


        for( int j = 0  ; j < random ; j++ )
        {
            auto doc = document{};

            // ODEME
            bool odeme;
            {

                auto odemeRand = qrand()%2;
                if( odemeRand == 0 ) odeme = true; else odeme = false;

                try {
                    doc.append(kvp("odeme",odeme));
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error odeme: " << e.what() << std::endl;
                }
            }


            // SiparisList
            double giderMiktar = 0.0;
            {
                auto siparisList = array{};

                auto siparis = document{};



                double _pre = qrand()%3+1;
                double _app = qrand()%10;
                double miktar = _pre + _app/10.0;
                giderMiktar = miktar;
                std::cout << "giderMiktar : " << giderMiktar << std::endl;

                try {
                    siparis.append(kvp("miktar",bsoncxx::types::b_double{giderMiktar}));
                } catch (bsoncxx::exception &e) {
                    std::cout << "siparis Append Error: " << e.what() << std::endl;
                }

                try {
                    auto cursor = this->collection(SNKKey::Recete::Recete::collection).find(document{}.view());

                    QStringList oidList;
                    for( auto doc : cursor )
                    {
                        try {
                            oidList.append(doc[SNKKey::oid].get_oid().value.to_string().c_str());
                        } catch (bsoncxx::exception &e) {
                            std::cout << "Error ReceteOid List: " << e.what() << std::endl;
                        }
                    }

                    int randomRecete = qrand()%5;
                    try {
                        siparis.append(kvp("receteoid",bsoncxx::oid{oidList.at(randomRecete).toStdString().c_str()}));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "siparis Append Error: " << e.what() << std::endl;
                    }
                } catch (mongocxx::exception &e) {

                }


                siparisList.append(siparis);

                try {
                    doc.append(kvp("siparisList",siparisList));
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error siparisList: " << e.what() << std::endl;
                }
            }

            // KASA OID
            {
                try {
                    doc.append(kvp("kasaoid",bsoncxx::oid{"5ad5b7b0ae94be3cd4001883"}));
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error kasaoid: " << e.what() << std::endl;
                }
            }

            // KISIOID
            {
                try {
                    doc.append(kvp("kisiOid",bsoncxx::oid{"5ad5da6cae94be3e24000863"}));
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error kisiOid: " << e.what() << std::endl;
                }
            }

            // MIKTAR
            double gelir = 0.0;
            {
                double _pre = qrand()%3;
                double _app = qrand()%10;
                double miktar = _pre + _app/10.0;
                miktar = giderMiktar *double(qrand()%3+2);
                gelir = miktar;
                try {
                    doc.append(kvp("miktar",bsoncxx::types::b_double{miktar}));
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error miktar: " << e.what() << std::endl;
                }
            }

            // INDIRIM
            {
                bool odeme;
                auto odemeRand = qrand()%2;
                if( odemeRand == 0 ) odeme = true; else odeme = false;

                try {
                    doc.append(kvp("indirim",odeme));
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error odeme: " << e.what() << std::endl;
                }
            }


            // JULIANDATE
            {
                try {
                    doc.append(kvp("julianDate",i));
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error odeme: " << e.what() << std::endl;
                }
            }

            // ODEME SAATI
            {
                try {
                    doc.append(kvp("saat","11:09"));
                } catch (bsoncxx::exception &e) {
                    std::cout << "Error saat: " << e.what() << std::endl;
                }
            }



            if( odeme )
            {
                // ODEME TARIHI
                {
                    auto odemeTarihi = i + qrand() % 20 ;
                    try {
                        doc.append(kvp("odemejulianDate",odemeTarihi));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "Error odeme: " << e.what() << std::endl;
                    }
                }

                // ODEME SAATI
                {
                    try {
                        doc.append(kvp("odemeSaat","11:09"));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "Error odeme: " << e.what() << std::endl;
                    }
                }


                // ODEME MİKTARI
                std::cout << "Odeme Miktar : " << gelir << std::endl;
                {
                    try {
                        doc.append(kvp("odemeMiktari",gelir));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "Error odeme: " << e.what() << std::endl;
                    }
                }

                // ODEME MİKTARI
                {
                    int _gelir = static_cast<int>(gelir);
                    int fark = 0;

                    if( _gelir != 0 )
                    {
                        fark = qrand()%_gelir;
                    }
                    double nakit = static_cast<double>(fark);
                    double kredi = gelir - nakit;
                    try {
                        doc.append(kvp("odemeMiktariNakit",nakit));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "Error odeme: " << e.what() << std::endl;
                    }
                    try {
                        doc.append(kvp("odemeMiktariKredi",kredi));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "Error odeme: " << e.what() << std::endl;
                    }
                }

                // ODEME TIPI
                {
                    try {
                        doc.append(kvp("odemeTipi","Karisik"));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "Error odeme: " << e.what() << std::endl;
                    }
                }

            }


            try {
                auto ins = this->collection(SNKKey::Cari::Hesap::collection).insert_one(doc.view());
                if( ins )
                {
                    if( ins.value().result().inserted_count() )
                    {
                        std::cout << "INserted" << std::endl;
                    }else{
                        std::cout << "NO INserted" << std::endl;
                    }
                }else{
                    std::cout << "NO Returned Document" << std::endl;
                }
            } catch (mongocxx::exception &e) {
                std::cout << "DB Insert Error: " << e.what() << std::endl;
            }

            std::cout << count++ << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(100));

        }

    }






}

