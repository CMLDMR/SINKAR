#include "malzemekalemidialog.h"
#include "ui_malzemekalemidialog.h"

#include "src/quickwidget.h"

MalzemeKalemiDialog::MalzemeKalemiDialog(mongocxx::database* _db , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MalzemeKalemiDialog),
    db(_db)
{
    ui->setupUi(this);


    kategoriModel = new QStandardItemModel;

    kategoriModel->setHorizontalHeaderLabels(QStringList()<<"Kategoriler");

    ui->listView_kategori->setModel(kategoriModel);


    malzemeModel = new QStandardItemModel;

    ui->listView_malzeme->setModel(malzemeModel);

    mMalzemeDelegate = new MalzemeDelegate;

    ui->listView_malzeme->setItemDelegate(mMalzemeDelegate);



    this->refreshKategoriList();


    this->setStyleSheet("QDialog{border:1px solid black;}");
    this->setWindowFlag(Qt::FramelessWindowHint);
}

MalzemeKalemiDialog::~MalzemeKalemiDialog()
{
    delete ui;
}

void MalzemeKalemiDialog::on_pushButton_NewKategori_clicked()
{

    auto mDialog = new Dialog();


    auto vLayout = mDialog->addLayout<VLayout>();

    auto label = vLayout->addwidget<QLabel>("Kategori Adını Giriniz");

    auto lineEdit = vLayout->addwidget<QLineEdit>();
    lineEdit->setPlaceholderText("Kategori Adını Giriniz");

    auto save = vLayout->addwidget<QPushButton>("Kaydet");

    connect(save,&QPushButton::clicked,[=](){


        auto collection = db->collection(SNKKey::Kategoriler::collection);

        QtBsonObject obj;

        obj.append(SNKKey::Kategoriler::adi,lineEdit->text());


        try {
            auto ins = collection.insert_one(obj.view());

            if( ins )
            {
                if( ins.value().result().inserted_count() )
                {
                    this->setmessage("kategori oluşturuldu");
                    this->refreshKategoriList();
                }else{
                    this->setmessage("kategori oluşturulamadı");
                }
            }else{
                this->setmessage("kategori oluşturulamadı");
            }
        } catch (mongocxx::exception &e) {
            this->setmessage(e);
        }

        mDialog->close();
    });




    mDialog->exec();


}

void MalzemeKalemiDialog::setmessage(QString e)
{
    ui->label_status->setText(e);
}

void MalzemeKalemiDialog::setmessage(bsoncxx::exception &e)
{
    setmessage(QString("builder Error: %1").arg(e.what()));
}


void MalzemeKalemiDialog::setmessage(mongocxx::exception &e)
{
    setmessage(QString("db Error: %1").arg(e.what()));
}

void MalzemeKalemiDialog::showmessage(QString mesage, QMessageBox::Icon icon)
{

    QMessageBox msg;
    msg.setWindowFlag(Qt::FramelessWindowHint);
    msg.setStyleSheet("QDialog{border:1px solid black;}");
    msg.setIcon(icon);
    msg.setText(mesage);
    msg.exec();


}

void MalzemeKalemiDialog::refreshKategoriList()
{

    kategoriModel->removeRows(0,kategoriModel->rowCount());

    QtBsonObject filter;

    try {
        auto cursor = db->collection(SNKKey::Kategoriler::collection).find(filter.view());

        ui->comboBox_MalzemeKategori->clear();
        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem;
            item->setText(doc[SNKKey::Kategoriler::adi].get_utf8().value.to_string().c_str());
            item->setData(doc[SNKKey::Kategoriler::oid].get_oid().value.to_string().c_str(),Qt::UserRole);
            kategoriModel->appendRow(item);
            ui->comboBox_MalzemeKategori->addItem(doc[SNKKey::Kategoriler::adi].get_utf8().value.to_string().c_str());
        }

    } catch (mongocxx::exception &e) {
        setmessage(e);
    }
}

void MalzemeKalemiDialog::on_pushButton_NewMalzeme_clicked()
{


    if( ui->listView_kategori->currentIndex().row() == -1 )
    {
        this->showmessage("Kategori Seçmediniz Lütfen Listeden Kategori Seçiniz",QMessageBox::Warning);
        return;
    }


    auto mDialog = new Dialog();

    auto layout = mDialog->addLayout<VLayout>();

    auto label = layout->addwidget<QLabel>("<b>Kategori: " + ui->listView_kategori->currentIndex().data(Qt::DisplayRole).toString()+"</b>");

    auto lineEdit_malzeme = layout->addwidget<QLineEdit>();
    lineEdit_malzeme->setPlaceholderText("Malzeme Adı Giriniz");

    auto lineEdit_birim = layout->addwidget<QLineEdit>();
    lineEdit_birim->setPlaceholderText("Malzeme Birimini Giriniz");


    auto kdv = layout->addwidget<QDoubleSpinBox>();

    auto save = layout->addwidget<QPushButton>("Kaydet");

    connect(save,&QPushButton::clicked,[=](){

        QtBsonObject obj;

        obj.append(SNKKey::Malzeme::adi,lineEdit_malzeme->text());
        obj.append(SNKKey::Malzeme::birimi,lineEdit_birim->text());
        obj.append(SNKKey::Malzeme::kdv,kdv->value());
        obj.append(SNKKey::Malzeme::kategorioid,QtBsonObject::oid(ui->listView_kategori->currentIndex().data(Qt::UserRole).toString()));


        try {
            auto ins = db->collection(SNKKey::Malzeme::collection).insert_one(obj.view());
            if( !ins )
            {
                this->showmessage("Malzeme Kayıt Edilemedi");
            }else{
                if( !ins.value().result().inserted_count() )
                {
                    this->showmessage("Malzeme Kayıt Edilemedi");
                }else{
                    this->setmessage("kayıt başarılı");
                    this->on_pushButton_refreshMalzeme_clicked();
                }
            }

        } catch (mongocxx::exception &e) {
            this->setmessage(e);
        }


        mDialog->close();
    });


    mDialog->exec();
}

MalzemeDelegate::MalzemeDelegate()
{

}

MalzemeDelegate::~MalzemeDelegate()
{

}

void MalzemeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

//    std::cout << "PAINT " << std::endl;
    if( !index.isValid() )
    {
        return;
    }

    painter->save();

    if( option.state & QStyle::State_Selected )
    {
        painter->fillRect(option.rect,option.palette.highlight());
        painter->setPen(Qt::white);

    }else{
        painter->setPen(Qt::black);

    }


    QString adi = index.data(HeaderRole).toString();
    QString kategori = index.data(Kategori).toString();


    QFont headerFont = QApplication::font();
    headerFont.setBold(true);
    QFontMetrics headerMetrics(headerFont);

    QFont kategoriFont = QApplication::font();
    QFontMetrics kategoriMetrics(kategoriFont);


    QRect headerrect = headerMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,adi);


    QRect kategoriRect = kategoriMetrics.boundingRect(option.rect.left(),headerrect.bottom()+padding,option.rect.width(), 0 , Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);



    painter->setFont(headerFont);
    painter->drawText(headerrect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,adi);

    painter->setFont(kategoriFont);
    painter->drawText(kategoriRect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);

    painter->restore();
}

QSize MalzemeDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//    std::cout << "SizeHINT" << std::endl;
    if(!index.isValid())
        return QSize();


    QString adi = index.data(HeaderRole).toString();
    QString kategori = index.data(Kategori).toString();


    QFont headerFont = QApplication::font();
    headerFont.setBold(true);
    QFontMetrics headerMetrics(headerFont);

    QFont kategoriFont = QApplication::font();
    QFontMetrics kategoriMetrics(kategoriFont);


    QRect headerrect = headerMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,adi);


    QRect kategoriRect = kategoriMetrics.boundingRect(option.rect.left(),headerrect.bottom()+padding,option.rect.width(), 0 , Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);


    QSize size(option.rect.width(), headerrect.height() +
               kategoriRect.height()  +
               3*padding);


    return size;



}

void MalzemeKalemiDialog::on_listView_kategori_clicked(const QModelIndex &index)
{

    QtBsonObject filter;

    filter.append(SNKKey::Malzeme::kategorioid,QtBsonObject::oid(index.data(Qt::UserRole).toString().toStdString().c_str()));

    this->refreshMalzemeList(filter);

}

void MalzemeKalemiDialog::refreshMalzemeList(QtBsonObject &filter)
{


    auto collection = db->collection(SNKKey::Malzeme::collection);



    try {
        auto cursor = collection.find(filter.view());


        malzemeModel->removeRows(0,malzemeModel->rowCount());
        for( auto doc : cursor )
        {

            QStandardItem* item = new QStandardItem;
            try {
                item->setData(doc[SNKKey::Malzeme::adi].get_utf8().value.to_string().c_str(),MalzemeDelegate::HeaderRole);
            } catch (bsoncxx::exception &e) {
                item->setData(e.what(),MalzemeDelegate::HeaderRole);
            }
            try {
                item->setData(doc[SNKKey::Malzeme::birimi].get_utf8().value.to_string().c_str(),MalzemeDelegate::Birimi);
            } catch (bsoncxx::exception &e) {
                setmessage(e);
            }
            try {
                item->setData(doc[SNKKey::Malzeme::kdv].get_double().value,MalzemeDelegate::Kdv);
            } catch (bsoncxx::exception &e) {
                setmessage(e);
            }
            try {
                QtBsonObject newFilter;
                newFilter.append(SNKKey::Kategoriler::oid,QtBsonObject::oid(doc[SNKKey::Malzeme::kategorioid].get_oid().value.to_string().c_str()));

                try {

                    auto _collection = db->collection(SNKKey::Kategoriler::collection);

                    auto val = _collection.find_one(newFilter.view());

                    if( val )
                    {
                        if( !val.value().view().empty() )
                        {
                            auto view = val.value().view();

                            item->setData(view[SNKKey::Kategoriler::adi].get_utf8().value.to_string().c_str(),MalzemeDelegate::Kategori);
                        }
                    }
                } catch (mongocxx::exception &e) {
                    item->setData(doc[SNKKey::Malzeme::birimi].get_utf8().value.to_string().c_str(),MalzemeDelegate::Kategori);
                }
            } catch (bsoncxx::exception &e) {
                item->setData(e.what(),MalzemeDelegate::Kategori);
            }

            try {
                item->setData(doc[SNKKey::Malzeme::kategorioid].get_oid().value.to_string().c_str(),MalzemeDelegate::KategoriOid);
                item->setData(doc[SNKKey::Malzeme::oid].get_oid().value.to_string().c_str(),MalzemeDelegate::Oid);

            } catch (bsoncxx::exception &e) {
                setmessage(e);
            }

            malzemeModel->appendRow(item);

        }


    } catch (mongocxx::exception &e) {
        setmessage(e);
    }

}

void MalzemeKalemiDialog::on_listView_malzeme_clicked(const QModelIndex &index)
{

    ui->lineEdit_MalzemeOid->setText(index.data(MalzemeDelegate::Oid).toString());

    ui->comboBox_MalzemeKategori->setCurrentText(index.data(MalzemeDelegate::Kategori).toString());

    ui->lineEdit_MalzemeName->setText(index.data(MalzemeDelegate::HeaderRole).toString());

    ui->lineEdit_MalzemeBirimi->setText(index.data(MalzemeDelegate::Birimi).toString());

    ui->doubleSpinBox_MalzemeComboBox->setValue(index.data(MalzemeDelegate::Kdv).toDouble());

    ui->lineEdit_KategoriOid->setText(index.data(MalzemeDelegate::KategoriOid).toString());


}

void MalzemeKalemiDialog::on_pushButton_SaveMalzeme_clicked()
{

    QtBsonObject obj;

    obj.append(SNKKey::Malzeme::adi,ui->lineEdit_MalzemeName->text());

    obj.append(SNKKey::Malzeme::birimi,ui->lineEdit_MalzemeBirimi->text());

    obj.append(SNKKey::Malzeme::kategorioid,QtBsonObject::oid(ui->lineEdit_KategoriOid->text()));

    obj.append(SNKKey::Malzeme::kdv,ui->doubleSpinBox_MalzemeComboBox->value());

    obj.append("$set",obj);

    QtBsonObject filter;

    filter.append(SNKKey::Malzeme::oid,QtBsonObject::oid(ui->lineEdit_MalzemeOid->text()));

    try {
        auto ins = db->collection(SNKKey::Malzeme::collection).update_one(filter.view(),obj.view());
        if( ins )
        {
            if( ins.value().modified_count() )
            {
                setmessage("Doküman Güncellendi");
                QtBsonObject _filter;
                _filter.append(SNKKey::Malzeme::kategorioid,QtBsonObject::oid(ui->listView_kategori->currentIndex().data(Qt::UserRole).toString()));

                this->refreshMalzemeList(_filter);

            }else{
                setmessage(" ! Doküman Güncellenemedi");
            }
        }else{
            setmessage(" ! Doküman Güncellenemedi");
        }
    } catch (mongocxx::exception &e) {
        setmessage(e);
    }
}

void MalzemeKalemiDialog::on_comboBox_MalzemeKategori_currentIndexChanged(const QString &arg1)
{
    {

        QtBsonObject kfilter;

        kfilter.append(SNKKey::Kategoriler::adi,arg1);

        auto val = db->collection(SNKKey::Kategoriler::collection).find_one(kfilter.view());

        if( val )
        {
            if( !val.value().view().empty() )
            {
                auto view = val.value().view();

                ui->lineEdit_KategoriOid->setText(view[SNKKey::Kategoriler::oid].get_oid().value.to_string().c_str());
            }
        }
    }
}

void MalzemeKalemiDialog::on_pushButton_deleteKategori_clicked()
{

    bool existMalzeme = false;

    {
        QtBsonObject filter;
        filter.append(SNKKey::Malzeme::kategorioid,QtBsonObject::oid(ui->listView_kategori->currentIndex().data(Qt::UserRole).toString()));

        auto val = db->collection(SNKKey::Malzeme::collection).find(filter.view());
        if( std::distance(val.begin(),val.end()) )
        {
            existMalzeme = true;
        }
    }


    if( existMalzeme )
    {
        showmessage("Bu Kategoriye Ait Malzemeler Var. Bu Kategoriyi Silmek için Önce Malzeme Listesini\nBu Kategoriden Çıkarın yada Silin!",QMessageBox::Icon::Critical);
        return;
    }else{
        QMessageBox::StandardButton btn = QMessageBox::question(this,"SORU","Bu Kategoriyi Silmek İstediğinize Emin misiniz?",QMessageBox::StandardButton::Ok|QMessageBox::StandardButton::Cancel);

        if( btn == QMessageBox::StandardButton::Ok )
        {
            QtBsonObject filter;
            filter.append(SNKKey::Kategoriler::oid,QtBsonObject::oid(ui->listView_kategori->currentIndex().data(Qt::UserRole).toString()));

            auto del = db->collection(SNKKey::Kategoriler::collection).delete_one(filter.view());
            if( del )
            {
                if( del.value().deleted_count() )
                {
                    setmessage("Kategori Silindi");
                    this->refreshKategoriList();
                }else{
                    setmessage(" ! Kategori Silinemedi");
                }
            }else{
                setmessage(" ! Kategori Silinemedi");
            }
        }
    }

}

void MalzemeKalemiDialog::on_pushButton_refreshKategori_clicked()
{
    this->refreshKategoriList();
}

void MalzemeKalemiDialog::on_pushButton_deleteMalzeme_clicked()
{

    if( ui->lineEdit_MalzemeOid->text().isEmpty() )
    {
        this->showmessage("Malzeme Seçmediniz");
        return;
    }


    QMessageBox::StandardButton btn = QMessageBox::question(this,"SORU","Bu Malzemeyi Silmek İstediğinize Emin misiniz?",QMessageBox::StandardButton::Ok|QMessageBox::StandardButton::Cancel);

    if( btn == QMessageBox::StandardButton::Ok )
    {
        QtBsonObject filter;
        filter.append(SNKKey::Malzeme::oid,QtBsonObject::oid(ui->lineEdit_MalzemeOid->text()));

        auto del = db->collection(SNKKey::Malzeme::collection).delete_one(filter.view());
        if( del )
        {
            if( del.value().deleted_count() )
            {
                setmessage("Malzeme Silindi");
                this->on_pushButton_refreshMalzeme_clicked();
            }else{
                setmessage(" ! Malzeme Silinemedi");
            }
        }else{
            setmessage(" ! Malzeme Silinemedi");
        }
    }
}

void MalzemeKalemiDialog::on_pushButton_refreshMalzeme_clicked()
{

    QtBsonObject filter;

    filter.append(SNKKey::Malzeme::kategorioid,QtBsonObject::oid(ui->listView_kategori->currentIndex().data(Qt::UserRole).toString()));
    this->refreshMalzemeList(filter);
}
