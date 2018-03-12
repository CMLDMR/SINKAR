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

        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem;
            item->setText(doc[SNKKey::Kategoriler::adi].get_utf8().value.to_string().c_str());
            item->setData(doc[SNKKey::Kategoriler::oid].get_oid().value.to_string().c_str(),Qt::UserRole);
            kategoriModel->appendRow(item);
        }

    } catch (mongocxx::exception &e) {
        setmessage(e);
    }
}

void MalzemeKalemiDialog::on_pushButton_NewMalzeme_clicked()
{

    std::cout << ui->listView_kategori->currentIndex().row() << std::endl;

    std::cout << ui->listView_kategori->currentIndex().data(Qt::UserRole).toString().toStdString() << std::endl;

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
    std::cout << "INDEX: " << index.data(Qt::UserRole).toString().toStdString() << std::endl;


    QtBsonObject filter;

    filter.append(SNKKey::Malzeme::kategorioid,QtBsonObject::oid(index.data(Qt::UserRole).toString().toStdString().c_str()));


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
//                item->setData(doc[SNKKey::Malzeme::birimi].get_utf8().value.to_string().c_str(),MalzemeDelegate::Kategori);

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

                }


            } catch (bsoncxx::exception &e) {
                item->setData(e.what(),MalzemeDelegate::Kategori);
            }

            try {
                item->setData(doc[SNKKey::Malzeme::kategorioid].get_oid().value.to_string().c_str(),MalzemeDelegate::KategoriOid);
                item->setData(doc[SNKKey::Malzeme::oid].get_oid().value.to_string().c_str(),MalzemeDelegate::Oid);

            } catch (bsoncxx::exception &e) {
//                item->setData(e.what(),MalzemeDelegate::HeaderRole);
                setmessage(e);
            }

            malzemeModel->appendRow(item);

        }


    } catch (mongocxx::exception &e) {
        setmessage(e);
    }

}
