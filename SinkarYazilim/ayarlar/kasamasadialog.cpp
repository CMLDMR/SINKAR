#include "kasamasadialog.h"
#include "ui_kasamasadialog.h"

#include "src/quickwidget.h"


#include <QLineEdit>
#include <QMessageBox>

KasaMasaDialog::KasaMasaDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KasaMasaDialog),
    db(_db)
{
    ui->setupUi(this);
    this->initConnection();
    this->initDepo();


    kasaModel = new QStandardItemModel;
    kasaDelegate = new KasaStyle::ItemDelegate;
    ui->listView_kasaList->setItemDelegate(kasaDelegate);

    ui->listView_kasaList->setModel(kasaModel);
    this->initKasalar();


    masaModel = new QStandardItemModel;
    masaDelegate = new MasaStyle::ItemDelegate;
    ui->listView_MasaList->setItemDelegate(masaDelegate);
    ui->listView_MasaList->setModel(masaModel);


    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QDialog{border:1px solid black;}");

}

KasaMasaDialog::~KasaMasaDialog()
{
    delete ui;
}

void KasaMasaDialog::initConnection()
{

    connect(ui->pushButton_Kapat,&QPushButton::clicked,this,&KasaMasaDialog::close);
    connect(ui->pushButton_refreshKasaList,&QPushButton::clicked,this,&KasaMasaDialog::initKasalar);

    connect(ui->pushButton_addNewMasa,&QPushButton::clicked,this,&KasaMasaDialog::addMasa);

    connect(ui->listView_kasaList,&QListView::clicked,[=](const QModelIndex &index){
        this->initMasalar();
    });

}

void KasaMasaDialog::initDepo()
{

    auto filter = document{};

    auto cursor = this->find(SNKKey::Depo::collection,filter.view());

    ui->comboBox_BagliDepo->clear();
    ui->comboBox_BagliDepo->addItem("Hepsi");
    for( auto doc : cursor )
    {
        ui->comboBox_BagliDepo->addItem(doc[SNKKey::Depo::depoAdi].get_utf8().value.to_string().c_str(),doc[SNKKey::Depo::oid].get_oid().value.to_string().c_str());
    }


}

mongocxx::cursor KasaMasaDialog::find(const std::string collection , const bsoncxx::document::view &view)
{
    try {
        auto cursor = db->collection(collection).find(view);
        return cursor;
    } catch (mongocxx::exception &e) {
        this->ShowMessage(e,"Depo Collection");
    }
}

mongocxx::stdx::optional<mongocxx::result::insert_one> KasaMasaDialog::insert_one(const std::string collection , const bsoncxx::document::view &view)
{
    try {
        auto ins = db->collection(collection).insert_one(view);
        return ins;
    } catch (mongocxx::exception &e) {
        this->ShowMessage(e,collection.c_str());
    }
}

void KasaMasaDialog::ShowMessage(QString msg, QMessageBox::Icon icon)
{
    auto mDialog = std::make_unique<QMessageBox>();

    mDialog.get()->setStyleSheet("QDialog{border:1px solid black;}");
    mDialog->setWindowFlag(Qt::FramelessWindowHint);
    mDialog->setIcon(icon);
    mDialog->setText(msg);
    mDialog->exec();

}

void KasaMasaDialog::ShowMessage(bsoncxx::exception &e, QString Message, QMessageBox::Icon icon)
{
    this->ShowMessage(QString("%1 - %2").arg(Message).arg(e.what()),icon);
}

void KasaMasaDialog::ShowMessage(mongocxx::exception &e, QString Message, QMessageBox::Icon icon)
{
    this->ShowMessage(QString("%1 - %2").arg(Message).arg(e.what()),icon);
}

void KasaMasaDialog::initKasalar()
{

    auto cursor = this->find(SNKKey::Kasa::collection,document{}.view());
    kasaModel->removeRows(0,kasaModel->rowCount());
    int row = 0;
    for( auto doc : cursor )
    {
        {
            QStandardItem* item = new QStandardItem;
            try {
                item->setText(doc[SNKKey::Kasa::ad].get_utf8().value.to_string().c_str());
            } catch (bsoncxx::exception &e) {
                item->setText(e.what());
            }
            try {
                item->setData(doc[SNKKey::Kasa::oid].get_oid().value.to_string().c_str());
            } catch (bsoncxx::exception &e) {
                item->setData("null",Qt::UserRole+1);
            }
            kasaModel->setItem(row,0,item);
        }
    row++;
    }

}

void KasaMasaDialog::addMasa()
{

    if( ui->listView_kasaList->currentIndex().data(Qt::UserRole+1).toString().isEmpty() )
    {
        this->ShowMessage("Kasa Seçmediniz");
        return;
    }

    auto mDialog = std::make_unique<Dialog>();

    auto layout = mDialog->addLayout<VLayout>();

    auto lineEditKasaOid = layout->addwidget<QLineEdit>();
    lineEditKasaOid->setText(ui->listView_kasaList->currentIndex().data(Qt::UserRole+1).toString().toStdString().c_str());
    lineEditKasaOid->setEnabled(false);

    auto lineEditMasadi = layout->addwidget<QLineEdit>();
    lineEditMasadi->setPlaceholderText("Masa Adını Giriniz");


    auto okbtn = layout->addwidget<QPushButton>("Kaydet");

    connect(okbtn,&QPushButton::clicked,[&mDialog,&lineEditKasaOid,&lineEditMasadi,this](){

        auto doc = document{};

        try {
            doc.append(kvp(SNKKey::Masa::ad,lineEditMasadi->text().toStdString().c_str()));
        } catch (bsoncxx::exception &e) {
            this->ShowMessage(e,"Masa Ad");
            return;
        }

        try {
            doc.append(kvp(SNKKey::Masa::kasaoid,bsoncxx::oid{lineEditKasaOid->text().toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            this->ShowMessage(e,"Kasa oid");
            return;
        }

        auto ins = this->insert_one(SNKKey::Masa::collection,doc.view());
        if( ins )
        {
            if( !ins.value().result().inserted_count() )
            {
                this->ShowMessage("No Document İnserted");
                return;
            }else{
                mDialog->close();
            }
        }

    });

    mDialog.get()->exec();

}

void KasaMasaDialog::initMasalar()
{
    if( ui->listView_kasaList->currentIndex().data(Qt::UserRole+1).toString().isEmpty() )
    {
        this->ShowMessage("Kasa Seçmediniz");
        return;
    }

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::Masa::kasaoid,bsoncxx::oid{ui->listView_kasaList->currentIndex().data(Qt::UserRole+1).toString().toStdString().c_str()}));
    } catch (bsoncxx::exception &e) {
        this->ShowMessage(e,"Kasa kasaoid");
        return;
    }


    auto cursor = this->find(SNKKey::Masa::collection,filter.view());

    masaModel->removeRows(0,masaModel->rowCount());
    int row = 0;
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
                item->setData(doc[SNKKey::Masa::oid].get_oid().value.to_string().c_str());
            } catch (bsoncxx::exception &e) {
                item->setData("null");
            }
            masaModel->setItem(row,0,item);
        }
        row++;
    }
}

void KasaMasaDialog::on_pushButton_addNewKasa_clicked()
{

    auto mDialog = std::make_unique<Dialog>();

    auto layout = mDialog->addLayout<VLayout>();


    auto comboBox = layout->addwidget<QComboBox>();
    comboBox->addItem("Depolar");

    auto cursor = this->find(SNKKey::Depo::collection,document{}.view());


    comboBox->clear();
    for( auto doc : cursor )
    {
        comboBox->addItem(doc[SNKKey::Depo::depoAdi].get_utf8().value.to_string().c_str(),doc[SNKKey::Depo::oid].get_oid().value.to_string().c_str());
    }


    auto hLayout = layout->addlayout<HLayout>();

    auto lineEdit = hLayout->addwidget<QLineEdit>();
    lineEdit->setPlaceholderText("Yeni Kasa Adını Yazınız");

    auto okbtn = hLayout->addwidget<QPushButton>("Kaydet");


    connect(okbtn,&QPushButton::clicked,[&mDialog,&lineEdit,&comboBox,this](){


        auto doc = document{};

        try {
            doc.append(kvp(SNKKey::Kasa::ad,lineEdit->text().toStdString().c_str()));
        } catch (bsoncxx::exception &e) {
            this->ShowMessage(e,"Kasa Ad");
            return;
        }

        try {
            doc.append(kvp(SNKKey::Kasa::depooid,bsoncxx::oid{comboBox->currentData(Qt::UserRole).toString().toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            this->ShowMessage(e,"Depo Oid");
            return;
        }

        auto ins = this->insert_one(SNKKey::Kasa::collection,doc.view());
        if( ins )
        {
            if( !ins.value().result().inserted_count() )
            {
                this->ShowMessage("No Document İnserted");
                return;
            }
        }
        mDialog.get()->close();
    });



    mDialog.get()->exec();


}

void KasaStyle::ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{


    if( !index.isValid() ) return;

    painter->save();

    if( option.state & QStyle::State_Selected )
    {
        painter->fillRect(option.rect,option.palette.highlight());
    }

    QString title = index.data(Qt::DisplayRole).toString();


    QFont font = QApplication::font();

    QFontMetrics metric(font);


    QRect titleRect = metric.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,title);

    painter->setFont(font);

    if( option.state & QStyle::State_Selected )
    {
        painter->setPen(Qt::white);
    }else{
        painter->setPen(Qt::black);
    }

    painter->drawText(titleRect,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,title);

    painter->restore();


}

QSize KasaStyle::ItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if( !index.isValid() ) return QSize();


    QString title = index.data(Qt::DisplayRole).toString();


    QFont font = QApplication::font();

    QFontMetrics metric(font);


    QRect titleRect = metric.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,title);


    return QSize(option.rect.width(),titleRect.height()+2*padding);
}

void MasaStyle::ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( !index.isValid() ) return;

    painter->save();

    if( option.state & QStyle::State_Selected )
    {
        painter->fillRect(option.rect,option.palette.highlight());
    }

    QString title = index.data(Qt::DisplayRole).toString();


    QFont font = QApplication::font();

    QFontMetrics metric(font);


    QRect titleRect = metric.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,title);

    painter->setFont(font);

    if( option.state & QStyle::State_Selected )
    {
        painter->setPen(Qt::white);
    }else{
        painter->setPen(Qt::black);
    }

    painter->drawText(titleRect,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,title);

    painter->restore();
}

QSize MasaStyle::ItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( !index.isValid() ) return QSize();


    QString title = index.data(Qt::DisplayRole).toString();


    QFont font = QApplication::font();

    QFontMetrics metric(font);


    QRect titleRect = metric.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::TextWordWrap|Qt::AlignLeft|Qt::AlignTop,title);


    return QSize(option.rect.width(),titleRect.height()+2*padding);
}
