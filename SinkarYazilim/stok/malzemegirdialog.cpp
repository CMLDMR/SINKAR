#include "malzemegirdialog.h"
#include "ui_malzemegirdialog.h"

#include "src/quickwidget.h"
#include "malzemeselectdialog.h"
#include "selectfirmadialog.h"


#include <QStringListModel>

MalzemeGirDialog::MalzemeGirDialog(mongocxx::database* _db , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MalzemeGirDialog),
    db(_db)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QDialog{border:1px solid black;}");


    this->initKategoriList();
    this->initDepo();
    this->initFirmalar();

    ui->dateEdit_faturaTarihi->setDate(QDate::currentDate());

}

MalzemeGirDialog::~MalzemeGirDialog()
{
    delete ui;
}

void MalzemeGirDialog::on_pushButton_cancel_clicked()
{
    this->close();
}

void MalzemeGirDialog::setmessage(bsoncxx::exception &e)
{
    setmessage(QString("Document Error: %1").arg(e.what()));
}

void MalzemeGirDialog::setmessage(mongocxx::exception &e)
{
    setmessage(QString("DB Error: %1").arg(e.what()));
}

void MalzemeGirDialog::setmessage(QString e)
{
    ui->label_status->setText(e);
}

void MalzemeGirDialog::setmessage(bsoncxx::exception &e, QString mesaj)
{
    setmessage(QString("Document Error: %1 -> %2").arg(e.what()).arg(mesaj));
}

void MalzemeGirDialog::setmessage(mongocxx::exception &e, QString mesaj)
{
    setmessage(QString("DB Error: %1 -> %2").arg(e.what()).arg(mesaj));
}

void MalzemeGirDialog::showMessage(QString mesaj, QMessageBox::Icon icon)
{

    QMessageBox msg;
    msg.setText(mesaj);
    msg.setIcon(icon);
    msg.setWindowFlag(Qt::FramelessWindowHint);
    msg.setStyleSheet("QDialog{border:1px solid black;}");
    msg.exec();

}

void MalzemeGirDialog::initKategoriList()
{
    auto collection = db->collection(SNKKey::Kategoriler::collection);

    try {
        auto cursor = collection.find(document{}.view());
        KategoriList.clear();
        KategoriListOid.clear();
        for( auto doc : cursor )
        {
            KategoriList.append(doc[SNKKey::Kategoriler::adi].get_utf8().value.to_string().c_str());
            KategoriListOid.append(doc[SNKKey::Kategoriler::oid].get_oid().value.to_string().c_str());
        }
        mKategoriCompleter = new QCompleter(KategoriList);
        connect(mKategoriCompleter,SIGNAL(activated(QString)),this,SLOT(selectedKategori(QString)));
        ui->lineEdit_Kategori->setCompleter(mKategoriCompleter);
    } catch (mongocxx::exception &e) {
        setmessage(e,"Kategori Completer");
    }
}

void MalzemeGirDialog::initMalzemeList()
{

    ui->lineEdit_malzemeKodu->setText("");
    ui->lineEdit_MalzemeAdi->setText("");
    ui->lineEdit_birimi->setText("");
    ui->doubleSpinBox_KDV->setValue(0);
    ui->doubleSpinBox_birimFiyati->setValue(0);


    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Malzeme::kategorioid,bsoncxx::oid{ui->lineEdit_kategoriKodu->text().toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        setmessage(e,"Malzeme List Filter append kategori Oid");
    }



    try {
        auto cursor = db->collection(SNKKey::Malzeme::collection).find(filter.view());
        MalzemeList.clear();
        MalzemeListOid.clear();
        for( auto doc : cursor )
        {
            MalzemeList.append(doc[SNKKey::Malzeme::adi].get_utf8().value.to_string().c_str());
            MalzemeListOid.append(doc[SNKKey::Malzeme::oid].get_oid().value.to_string().c_str());
        }

        mMalzemeListCompleter = new QCompleter(MalzemeList);
        ui->lineEdit_MalzemeAdi->setCompleter(mMalzemeListCompleter);
        connect(mMalzemeListCompleter,SIGNAL(activated(QString)),this,SLOT(selectedMalzeme(QString)));

    } catch (mongocxx::exception &e) {
        setmessage(e,"Malzeme Listesi Query Error");
    }
}

void MalzemeGirDialog::setMalzemeOid(const char *oid)
{


    auto filter = document{};
    try {
        filter.append(kvp(SNKKey::Malzeme::oid,bsoncxx::oid{oid}));
    } catch (bsoncxx::exception &e) {
        setmessage(e," Malzeme oid Append Edilemedi");
        return;
    }
    try {
        auto collection = db->collection(SNKKey::Malzeme::collection);
        auto val = collection.find_one(filter.view());
        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto view = val.value().view();
                ui->lineEdit_malzemeKodu->setText(view[SNKKey::Malzeme::oid].get_oid().value.to_string().c_str());
                ui->lineEdit_MalzemeAdi->setText(view[SNKKey::Malzeme::adi].get_utf8().value.to_string().c_str());
                ui->lineEdit_birimi->setText(view[SNKKey::Malzeme::birimi].get_utf8().value.to_string().c_str());
                ui->lineEdit_kategoriKodu->setText(view[SNKKey::Malzeme::kategorioid].get_oid().value.to_string().c_str());
                ui->doubleSpinBox_KDV->setValue(view[SNKKey::Malzeme::kdv].get_double().value);
                ui->doubleSpinBox_birimFiyati->setValue(view[SNKKey::Malzeme::fiyat].get_double().value);
            }
        }
    } catch (mongocxx::exception &e) {
        setmessage(e,"DB Query Malzeme Oid");
    }


    filter.clear();

    try {
        filter.append(kvp(SNKKey::Kategoriler::oid,bsoncxx::oid{ui->lineEdit_kategoriKodu->text().toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        setmessage(e,"kategori oid building error");
    }

    try {
        auto collection = db->collection(SNKKey::Kategoriler::collection);
        auto val = collection.find_one(filter.view());
        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto view = val.value().view();
                ui->lineEdit_Kategori->setText(view[SNKKey::Kategoriler::adi].get_utf8().value.to_string().c_str());
                ui->lineEdit_kategoriKodu->setText(view[SNKKey::Kategoriler::oid].get_oid().value.to_string().c_str());
            }
        }

    } catch (mongocxx::exception &e) {
        setmessage(e,"kategori query error");
    }


}

void MalzemeGirDialog::initDepo()
{

    auto cursor = this->find(SNKKey::Depo::collection,document{});

    ui->comboBox_selectDepo->clear();

    for( auto doc : cursor )
    {
        ui->comboBox_selectDepo->addItem(doc[SNKKey::Depo::depoAdi].get_utf8().value.to_string().c_str());
    }

}

mongocxx::cursor MalzemeGirDialog::find(std::string collection, bsoncxx::builder::basic::document filter)
{
    try {
        auto cursor = db->collection(collection).find(filter.view());
        return cursor;
    } catch (mongocxx::exception &e) {
        setmessage(e,QString(" find error : %1").arg(collection.c_str()));
    }
}

auto MalzemeGirDialog::find_one(std::string collection, bsoncxx::builder::basic::document filter)
{
    try {
        auto val = db->collection(collection).find_one(filter.view());
        return val;
    } catch (mongocxx::exception &e) {
        setmessage(e,"DB find one error");
    }
}

auto MalzemeGirDialog::insert(std::string collection, const bsoncxx::builder::basic::document &insertDoc)
{
    try {
        auto ins = db->collection(collection).insert_one(insertDoc.view());
        return ins;
    } catch (mongocxx::exception &e) {
        setmessage(e,"insert doc error");
    }
}

void MalzemeGirDialog::setToplamTutar()
{

    double birimFiyat = ui->doubleSpinBox_birimFiyati->value();

    double miktar = ui->doubleSpinBox_miktar->value();

    ui->doubleSpinBox_ToplamTutar->setValue(miktar*birimFiyat);

}

void MalzemeGirDialog::initFirmalar()
{




}

void MalzemeGirDialog::selectedKategori(const QString &kategoriName)
{
    int index = KategoriList.indexOf(kategoriName);
    if( index != -1 )
    {
        QString oid = KategoriListOid.at(index);
        ui->lineEdit_kategoriKodu->setText(oid);
        this->initMalzemeList();

    }
}

void MalzemeGirDialog::selectedMalzeme(const QString &malzemeName)
{

    int index = MalzemeList.indexOf(malzemeName);
    if( index != -1 )
    {
        QString oid = MalzemeListOid.at(index);
        this->setMalzemeOid(oid.toStdString().c_str());
    }

}

void MalzemeGirDialog::on_pushButton_SelectMalzeme_clicked()
{

    MalzemeSelectDialog* mDialog = new MalzemeSelectDialog(db);

    if( ui->lineEdit_Kategori->text().isEmpty() )
    {

    }else{
        mDialog->setKategori(ui->lineEdit_Kategori->text());
    }

    mDialog->exec();

    if( mDialog->clickAccepted() )
    {
        this->setMalzemeOid(mDialog->malzemeOid().get_oid().value.to_string().c_str());
    }

    mDialog->deleteLater();
}

void MalzemeGirDialog::on_doubleSpinBox_miktar_valueChanged(double arg1)
{
    this->setToplamTutar();
}

void MalzemeGirDialog::on_doubleSpinBox_birimFiyati_valueChanged(double arg1)
{
    this->setToplamTutar();
}

void MalzemeGirDialog::on_pushButton_clicked()
{
    SelectFirmaDialog* mDialog = new SelectFirmaDialog(db);

    mDialog->exec();

    if( mDialog->getAccepted() )
    {

        auto filter = document{};

        try {
            filter.append(kvp(SNKKey::Firma::oid,bsoncxx::oid{mDialog->getFirmaOid().c_str()}));
        } catch (bsoncxx::exception &e) {
            setmessage(e);
        }

        auto val = this->find_one(SNKKey::Firma::collection,std::move(filter));

        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto view = val.value().view();

                ui->lineEdit_CariKodu->setText(view[SNKKey::Firma::carikod].get_utf8().value.to_string().c_str());
                ui->lineEdit_FirmaAdi->setText(view[SNKKey::Firma::adi].get_utf8().value.to_string().c_str());
                ui->lineEdit_FirmaAdi_oid->setText(view[SNKKey::Firma::oid].get_oid().value.to_string().c_str());
            }
        }
    }

    mDialog->deleteLater();
}

void MalzemeGirDialog::on_pushButton_save_clicked()
{

    auto doc = document{};

    auto firmaDoc = document{};

    try {
        firmaDoc.append(kvp(SNKKey::MGirisi::Fatura::seri,ui->lineEdit_faturaSeri->text().toStdString().c_str()));
        firmaDoc.append(kvp(SNKKey::MGirisi::Fatura::no,ui->lineEdit_faturaNO->text().toStdString().c_str()));
        firmaDoc.append(kvp(SNKKey::MGirisi::Fatura::tarih,ui->dateEdit_faturaTarihi->date().toJulianDay()));
        firmaDoc.append(kvp(SNKKey::MGirisi::Fatura::tipi,ui->comboBox_faturaTipi->currentText().toStdString().c_str()));
        firmaDoc.append(kvp(SNKKey::MGirisi::Fatura::firmaCarikod,ui->lineEdit_CariKodu->text().toStdString().c_str()));
        firmaDoc.append(kvp(SNKKey::MGirisi::Fatura::firmaadi,ui->lineEdit_FirmaAdi->text().toStdString().c_str()));
        firmaDoc.append(kvp(SNKKey::MGirisi::Fatura::firmaoid,bsoncxx::oid{ui->lineEdit_FirmaAdi_oid->text().toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        setmessage(e);
    }

    try {
        doc.append(kvp(SNKKey::MGirisi::malzemeoid,bsoncxx::oid{ui->lineEdit_malzemeKodu->text().toStdString().c_str()}));
        doc.append(kvp(SNKKey::MGirisi::kategroiOid,bsoncxx::oid{ui->lineEdit_kategoriKodu->text().toStdString().c_str()}));
        doc.append(kvp(SNKKey::MGirisi::kategori,ui->lineEdit_Kategori->text().toStdString().c_str()));
        doc.append(kvp(SNKKey::MGirisi::malzemeadi,ui->lineEdit_MalzemeAdi->text().toStdString().c_str()));
        doc.append(kvp(SNKKey::MGirisi::depo,ui->comboBox_selectDepo->currentText().toStdString().c_str()));
        doc.append(kvp(SNKKey::MGirisi::miktar,ui->doubleSpinBox_miktar->value()));
        doc.append(kvp(SNKKey::MGirisi::birimi,ui->lineEdit_birimi->text().toStdString().c_str()));
        doc.append(kvp(SNKKey::MGirisi::birimFiyat,ui->doubleSpinBox_birimFiyati->value()));
        doc.append(kvp(SNKKey::MGirisi::iskontoindirim,ui->doubleSpinBox_indirimMiktari->value()));
        doc.append(kvp(SNKKey::MGirisi::kdv,ui->doubleSpinBox_KDV->value()));
        doc.append(kvp(SNKKey::MGirisi::girisTipi,SNKKey::MGirisi::GirisTipi::malzemeGirisi.c_str()));
        doc.append(kvp(SNKKey::MGirisi::fatura,firmaDoc));
        doc.append(kvp(SNKKey::MGirisi::julianDate,QDate::currentDate().toJulianDay()));
    } catch (bsoncxx::exception &e) {
        setmessage(e);
    }


    bool mKayitBasarili = false;
    auto ins = this->insert(SNKKey::MGirisi::collection,doc);
    if( ins )
    {
        if( ins.value().result().inserted_count() )
        {
            ui->label_status->setText("<h2><span color=\"green\";>Kayıt Başarılı</span></h2>");
            mKayitBasarili = true;

        }else{
            ui->label_status->setText("<h2><span color=\"red\";>Kayıt Yapılamadı</span></h2>");
        }
    }else{
        ui->label_status->setText("<h2><span color=\"red\";>Kayıt Yapılamadı</span></h2>");
    }

    if( mKayitBasarili ){
        auto filter = document{};

        try {
            filter.append(kvp(SNKKey::StokMiktar::depo,ui->comboBox_selectDepo->currentText().toStdString().c_str()));
            filter.append(kvp(SNKKey::StokMiktar::malzemeoid,bsoncxx::oid{ui->lineEdit_malzemeKodu->text().toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            setmessage(e,"insDoc filter error");
            return;
        }

        auto updateDoc = document{};

        try {
            updateDoc.append(kvp("$inc",make_document(kvp(SNKKey::StokMiktar::miktar,ui->doubleSpinBox_miktar->value()))));
        } catch (bsoncxx::exception &e) {
            setmessage(e,"insDoc Error");
            return;
        }


        mongocxx::options::find_one_and_update findUpdateOption;

        findUpdateOption.return_document(mongocxx::options::return_document::k_after);

        try {
            auto upt = db->collection(SNKKey::StokMiktar::collection).find_one_and_update(filter.view(),updateDoc.view(),findUpdateOption);

            if( upt )
            {
                if( !upt.value().view().empty() )
                {
                    auto view = upt.value().view();

                    QString str = QString("%1 Malzeme Miktarı %2 %3 Oldu").arg(view[SNKKey::StokMiktar::adi].get_utf8().value.to_string().c_str())
                            .arg(view[SNKKey::StokMiktar::miktar].get_double().value)
                            .arg(view[SNKKey::StokMiktar::birim].get_utf8().value.to_string().c_str());
                    this->showMessage(str);
                    this->close();
                }else{
                    this->showMessage("Stok Güncellenemedi, Lütfen Elle Güncelleyiniz",QMessageBox::Icon::Critical);
                }
            }else{
                this->showMessage("Stok Güncellenemedi, Lütfen Elle Güncelleyiniz",QMessageBox::Icon::Critical);
            }

        } catch (mongocxx::exception &e) {
            setmessage(e,"Update Error");
        }
    }





}
