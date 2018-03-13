#include "recetedialog.h"
#include "ui_recetedialog.h"


#include "addmalzemedialog.h"

ReceteDialog::ReceteDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceteDialog),
    db(_db)
{

    ui->setupUi(this);

    malzemeModel = new QStandardItemModel;

    ui->listView_MalzemeList->setModel(malzemeModel);

    malzemeDelegate = new MalzemeItemDelegate;

    ui->listView_MalzemeList->setItemDelegate(malzemeDelegate);


    receteModel = new QStandardItemModel;

    ui->listView->setModel(receteModel);

    receteDelegate = new ReceteDelegate;

    ui->listView->setItemDelegate(receteDelegate);


    this->resetKategoriList();

    this->reinitReceteList();


}

ReceteDialog::~ReceteDialog()
{
    delete ui;
}

void ReceteDialog::on_pushButton_addreceteKategori_clicked()
{

    auto mDialog = new Dialog;

    auto mainLayout = mDialog->addLayout<VLayout>();

    auto text = mainLayout->addwidget<QLabel>("<b>Yeni Kategori</b2>");

    auto lineEditKategoriName = mainLayout->addwidget<QLineEdit>();
    lineEditKategoriName->setPlaceholderText("Kategori Adını Giriniz");

    auto save = mainLayout->addwidget<QPushButton>("Kaydet");


    connect(save,&QPushButton::clicked,[=](){


        QtBsonObject obj;

        obj.append(Recete::Kategori::adi,lineEditKategoriName->text());

        try {
            auto ins = db->collection(Recete::Kategori::collection).insert_one(obj.view());

            if( ins )
            {
                if( ins.value().result().inserted_count() )
                {
                    setmessage("Kategori Eklendi");
                    this->resetKategoriList();
                    ui->comboBox_ReceteKat->setCurrentText(lineEditKategoriName->text());
                }else{
                    setmessage(" ! Kategori Eklenemedi");
                }
            }else{
                setmessage(" ! Kategori Eklenemedi");
            }


        } catch (mongocxx::exception &e) {
            setmessage(e);
        }



        mDialog->close();
    });


    mDialog->exec();
    mDialog->deleteLater();


}


void ReceteDialog::setmessage(QString e)
{
    ui->label_status->setText(e);
}

void ReceteDialog::setmessage(bsoncxx::exception &e)
{
    setmessage(QString("builder Error: %1").arg(e.what()));
}


void ReceteDialog::setmessage(mongocxx::exception &e)
{
    setmessage(QString("db Error: %1").arg(e.what()));
}

bool ReceteDialog::insert(QString collection, QtBsonObject &obj)
{
    bool returnType = false;
    try {
        auto ins = db->collection(collection.toStdString().c_str()).insert_one(obj.view());
        if( ins )
        {
            if( ins.value().result().inserted_count() )
            {
                setmessage("Döküman Kayıt Edildi");
                returnType = true;
            }else{
                setmessage(" ! Döküman Kayıt Edilemedi");
            }
        }else{
            setmessage(" ! Döküman Kayıt Edilemedi");
        }
    } catch (mongocxx::exception &e) {
        setmessage(e);
    }

    return returnType;

}

void ReceteDialog::CalcFiyat()
{
    double fiyat = ui->doubleSpinBox_Maliyet->value();

    double kdvRate = ui->doubleSpinBox_recete_kdv->value();

    double karRate = ui->doubleSpinBox_karmarji->value();

    double kar = 0;
    double kdv = 0;

    kdv = fiyat*kdvRate/100;

    kar = fiyat*karRate/100;

    ui->doubleSpinBox_newFiyat->setValue(kdv+kar+fiyat);

}

void ReceteDialog::resetKategoriList()
{


    ui->comboBox_ReceteKat->clear();

    QtBsonObject filter;

    try {
        auto cursor = db->collection(Recete::Kategori::collection).find(filter.view());

        for( auto doc : cursor )
        {
            ui->comboBox_ReceteKat->addItem(doc[Recete::Kategori::adi].get_utf8().value.to_string().c_str());
        }
    } catch (mongocxx::exception &e) {
        setmessage(e);
        return;
    }

}

void ReceteDialog::reinitReceteList()
{



    QtBsonObject filter;

    try {
        auto cursor = db->collection(SNKKey::Recete::Recete::collection).find(filter.view());

        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem;
            item->setText(doc[Recete::Recete::adi].get_utf8().value.to_string().c_str());
            item->setData(doc[Recete::Recete::kategori].get_utf8().value.to_string().c_str(),ReceteDelegate::KategoriRole);
            item->setData(doc[Recete::Recete::oid].get_oid().value.to_string().c_str(),ReceteDelegate::Oid);
            receteModel->appendRow(item);
        }


    } catch (mongocxx::exception &e) {
        setmessage(e);
    }


}

void ReceteDialog::on_pushButton_addNew_clicked()
{


    this->resetKategoriList();

    ui->lineEdit_receteAdi->setText("");
    ui->doubleSpinBox_Maliyet->setValue(0);
    ui->lineEdit_receteid->setText("");
    ui->doubleSpinBox_karmarji->setValue(0);
    ui->doubleSpinBox_newFiyat->setValue(0);
    ui->doubleSpinBox_recete_kdv->setValue(0);

}

void ReceteDialog::save_new()
{

    if( ui->comboBox_ReceteKat->currentText().isEmpty() )
    {
        this->showmessage("Kategori Seçmediniz");
        return;
    }



    QtBsonObject obj;

    obj.append(Recete::Recete::adi,ui->lineEdit_receteAdi->text());
    obj.append(Recete::Recete::birimi,ui->lineEdit_receteBirimi->text());
    obj.append(Recete::Recete::kdv,ui->doubleSpinBox_recete_kdv->value());
    obj.append(Recete::Recete::kar,ui->doubleSpinBox_karmarji->value());
    obj.append(Recete::Recete::kategori,ui->comboBox_ReceteKat->currentText());



    // Check Malzeme List
    {
        auto arList = array{};
        for( int i = 0 ; i < malzemeModel->rowCount() ; i++ )
        {
            QStandardItem* item = malzemeModel->item(i,0);
            auto _obj = document{};
            _obj.append(kvp(Recete::Recete::Malzemeler::miktar,item->data(MalzemeItemDelegate::Miktar).toDouble()));
            _obj.append(kvp(Recete::Recete::Malzemeler::oid,bsoncxx::oid{item->data(MalzemeItemDelegate::Oid).toString().toStdString().c_str()}));
            arList.append(_obj);
        }

        obj.append(Recete::Recete::malzeme,arList);

//        std::cout << "BSON: " << bsoncxx::to_json(obj.view()) << std::endl;

    }




    this->insert(Recete::Recete::collection.c_str(),obj);



}

void ReceteDialog::on_pushButton_receteSave_clicked()
{
    if( ui->lineEdit_receteid->text().isEmpty() )
    {
        this->save_new();
    }
}

void ReceteDialog::on_pushButton_addMalzeme_clicked()
{


    addMalzemeDialog* mDialog = new addMalzemeDialog(db);

    mDialog->exec();

    if( mDialog->Accepted() )
    {
        QModelIndex index = mDialog->getCurrentIndex();


        QtBsonObject filter;

        filter.append(SNKKey::Malzeme::oid,QtBsonObject::oid(index.data(Qt::UserRole).toString()));

        try {

            auto val = db->collection(SNKKey::Malzeme::collection).find_one(filter.view());
            if( val )
            {
                auto view = val.value().view();

                QStandardItem* item = new QStandardItem;
                item->setData(view[Malzeme::adi].get_utf8().value.to_string().c_str(),MalzemeItemDelegate::HeaderRole);

                {
                    QtBsonObject kFilter;
                    kFilter.append(Kategoriler::oid,QtBsonObject::oid(index.data(Qt::UserRole+1).toString()));
                    auto _val = db->collection(Kategoriler::collection).find_one(kFilter.view());
                    if( _val )
                    {
                        item->setData(_val.value().view()[Kategoriler::adi].get_utf8().value.to_string().c_str(),MalzemeItemDelegate::Kategori);
                    }
                }


                item->setData(view[Malzeme::fiyat].get_double().value,MalzemeItemDelegate::Fiyat);
                item->setData(mDialog->getSelectedValue(),MalzemeItemDelegate::Miktar);
                item->setData(mDialog->getSelectedValueType(),MalzemeItemDelegate::MiktarType);
                item->setData(index.data(Qt::UserRole+1).toString(),MalzemeItemDelegate::KategoriOid);
                item->setData(index.data(Qt::UserRole).toString(),MalzemeItemDelegate::Oid);
                malzemeModel->appendRow(item);

                {
                    double toplam = 0;
                    for( int i = 0 ; i < malzemeModel->rowCount() ; i++ )
                    {
                        QStandardItem* item = malzemeModel->item(i,0);
                        toplam += item->data(MalzemeItemDelegate::Fiyat).toDouble() * item->data(MalzemeItemDelegate::Miktar).toDouble();

                    }

                    ui->doubleSpinBox_Maliyet->setValue(toplam);
                    this->CalcFiyat();
                }


            }


        } catch (mongocxx::exception &e) {
            setmessage(e);
        }
    }


    mDialog->deleteLater();

}

MalzemeItemDelegate::MalzemeItemDelegate()
{





}

void MalzemeItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
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
        double fiyat = index.data(Fiyat).toDouble();
        QString str_fiyat = QString("Fiyat: %1 TL").arg(fiyat);

        double miktar = index.data(Miktar).toDouble();
        QString str_Miktar = QString("Miktar: %1 %2 Toplam: %3 TL").arg(miktar).arg(index.data(MiktarType).toString()).arg(miktar*fiyat);


        QFont headerFont = QApplication::font();
        headerFont.setBold(true);
        QFontMetrics headerMetrics(headerFont);

        QFont kategoriFont = QApplication::font();
        QFontMetrics kategoriMetrics(kategoriFont);


        QRect headerrect = headerMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,adi);


        QRect kategoriRect = kategoriMetrics.boundingRect(option.rect.left(),headerrect.bottom()+padding,option.rect.width(), 0 , Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);

        QRect fiyatRect = kategoriMetrics.boundingRect(option.rect.left(),kategoriRect.bottom()+padding,option.rect.width(), 0 , Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,str_fiyat);

        QRect miktarRect = kategoriMetrics.boundingRect(option.rect.left(),fiyatRect.bottom()+padding,option.rect.width(), 0 , Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,str_Miktar);



        painter->setFont(headerFont);
        painter->drawText(headerrect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,adi);

        painter->setFont(kategoriFont);
        painter->drawText(kategoriRect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);

        painter->setFont(kategoriFont);
        painter->drawText(fiyatRect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,str_fiyat);

        painter->setFont(kategoriFont);
        painter->drawText(miktarRect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,str_Miktar);

        painter->restore();



}

QSize MalzemeItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if(!index.isValid())
        return QSize();

    QString adi = index.data(HeaderRole).toString();
    QString kategori = index.data(Kategori).toString();
    double fiyat = index.data(Fiyat).toDouble();
    QString str_fiyat = QString("Fiyat: %1 TL").arg(fiyat);

    double miktar = index.data(Miktar).toDouble();
    QString str_Miktar = QString("Miktar: %1 GR").arg(miktar);

    QFont headerFont = QApplication::font();
    headerFont.setBold(true);
    QFontMetrics headerMetrics(headerFont);

    QFont kategoriFont = QApplication::font();
    QFontMetrics kategoriMetrics(kategoriFont);

    QRect headerrect = headerMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,adi);

    QRect kategoriRect = kategoriMetrics.boundingRect(option.rect.left(),headerrect.bottom()+padding,option.rect.width(), 0 , Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);

    QRect fiyatRect = kategoriMetrics.boundingRect(option.rect.left(),kategoriRect.bottom()+padding,option.rect.width(), 0 , Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,str_fiyat);

    QRect miktarRect = kategoriMetrics.boundingRect(option.rect.left(),kategoriRect.bottom()+padding,option.rect.width(), 0 , Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,str_Miktar);

    QSize size( option.rect.width() , headerrect.height() +
                kategoriRect.height()  +
                fiyatRect.height()  +
                miktarRect.height()  +
                4 * padding );

    return size;

}

void ReceteDialog::on_listView_MalzemeList_doubleClicked(const QModelIndex &index)
{
    QMessageBox::StandardButton btn = QMessageBox::question(this,"Soru","Silmek İstediğinize Eminmisiniz?",QMessageBox::StandardButton::Ok|QMessageBox::StandardButton::Cancel);

    if( btn == QMessageBox::StandardButton::Ok )
    {
        malzemeModel->removeRow(index.row());
        this->CalcFiyat();
    }
}

void ReceteDialog::on_doubleSpinBox_recete_kdv_valueChanged(double arg1)
{
    this->CalcFiyat();
}

void ReceteDialog::on_doubleSpinBox_karmarji_valueChanged(double arg1)
{
    this->CalcFiyat();
}

void ReceteDialog::showmessage(QString mesage, QMessageBox::Icon icon)
{
    QMessageBox msg;
    msg.setWindowFlag(Qt::FramelessWindowHint);
    msg.setStyleSheet("QDialog{border:1px solid black;}");
    msg.setIcon(icon);
    msg.setText(mesage);
    msg.exec();
}

void ReceteDialog::on_pushButton_refreshRecete_clicked()
{
    this->reinitReceteList();
}

ReceteDelegate::ReceteDelegate()
{

}

void ReceteDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( !index.isValid() )
    {
        return;
    }

    QString title = index.data(Qt::DisplayRole).toString();
    QString kategori = index.data(KategoriRole).toString();

    QFont font = QApplication::font();

    font.setBold(true);
    QFontMetrics titleMetrics(font);

    QFont subFont = QApplication::font();
    QFontMetrics subMetrics(subFont);

    QRect titleRect = titleMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,title);
    QRect KategoriRect = subMetrics.boundingRect(option.rect.left(),titleRect.bottom()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);







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

    painter->restore();

}

QSize ReceteDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( !index.isValid() )
    {
        return QSize();
    }



    QString title = index.data(Qt::DisplayRole).toString();
    QString kategori = index.data(KategoriRole).toString();



    QFont font = QApplication::font();
    font.setBold(true);
    QFontMetrics titleMetrics(font);

    QFont subFont = QApplication::font();
    QFontMetrics subMetrics(subFont);


    QRect titleRect = titleMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,title);

    QRect KategoriRect = subMetrics.boundingRect(option.rect.left(),titleRect.bottom()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,kategori);


    return  QSize(option.rect.width(),
                  titleRect.height()+
                  KategoriRect.height()+
                  2*padding+padding);


}

void ReceteDialog::on_listView_clicked(const QModelIndex &index)
{


    QtBsonObject filter;

    filter.appendOid(index.data(ReceteDelegate::Oid).toString());


    try {
        auto val = db->collection(Recete::Recete::collection).find_one(filter.view());

        if( val )
        {
            auto view = val.value().view();

            if( !view.empty() )
            {
                ui->lineEdit_receteAdi->setText(view[Recete::Recete::adi].get_utf8().value.to_string().c_str());
                ui->lineEdit_receteid->setText(view[Recete::Recete::oid].get_oid().value.to_string().c_str());
                ui->lineEdit_receteBirimi->setText(view[Recete::Recete::birimi].get_utf8().value.to_string().c_str());
                ui->comboBox_ReceteKat->setCurrentText(view[Recete::Recete::kategori].get_utf8().value.to_string().c_str());


                auto arList = view[Recete::Recete::malzeme].get_array().value;

                malzemeModel->removeRows(0,malzemeModel->rowCount());

                for( auto element : arList )
                {
                    QtBsonObject _filter;

                    try {
                        _filter.append(SNKKey::Malzeme::oid,QtBsonObject::oid(element[Recete::Recete::Malzemeler::oid].get_oid().value.to_string().c_str()));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "Error: " << e.what() << std::endl;
                    }

                    try {
                        auto _val = db->collection(SNKKey::Malzeme::collection).find_one(_filter.view());
                        if( _val )
                        {
                            auto _view = _val.value().view();
                            QStandardItem* item = new QStandardItem;
                            item->setData(_view[Malzeme::adi].get_utf8().value.to_string().c_str(),MalzemeItemDelegate::HeaderRole);

                            {
                                QtBsonObject kFilter;
                                kFilter.append(Kategoriler::oid,QtBsonObject::oid(_view[Malzeme::kategorioid].get_oid().value.to_string().c_str()));
                                auto _val = db->collection(Kategoriler::collection).find_one(kFilter.view());
                                if( _val )
                                {
                                    item->setData(_val.value().view()[Kategoriler::adi].get_utf8().value.to_string().c_str(),MalzemeItemDelegate::Kategori);
                                }
                            }

                            item->setData(_view[Malzeme::fiyat].get_double().value,MalzemeItemDelegate::Fiyat);
                            item->setData(element[Recete::Recete::Malzemeler::miktar].get_double().value,MalzemeItemDelegate::Miktar);
                            item->setData("Litre",MalzemeItemDelegate::MiktarType);
                            item->setData(_view[Malzeme::kategorioid].get_oid().value.to_string().c_str(),MalzemeItemDelegate::KategoriOid);
                            item->setData(_view[Malzeme::oid].get_oid().value.to_string().c_str(),MalzemeItemDelegate::Oid);
                            malzemeModel->appendRow(item);

                        }

                    } catch (mongocxx::exception &e) {
                        setmessage(e);
                    }
                }

                {
                    double toplam = 0;
                    for( int i = 0 ; i < malzemeModel->rowCount() ; i++ )
                    {
                        QStandardItem* item = malzemeModel->item(i,0);
                        toplam += item->data(MalzemeItemDelegate::Fiyat).toDouble() * item->data(MalzemeItemDelegate::Miktar).toDouble();
                    }
                    ui->doubleSpinBox_Maliyet->setValue(toplam);
                    this->CalcFiyat();
                }




            }
        }

    } catch (mongocxx::exception &e) {
        setmessage(e);
    }



}

void ReceteDialog::on_pushButton_kapat_clicked()
{
    this->close();
}
