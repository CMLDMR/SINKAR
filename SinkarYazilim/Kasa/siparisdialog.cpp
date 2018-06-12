#include "siparisdialog.h"
#include "ui_siparisdialog.h"


#include "src/quickwidget.h"

#include <QDoubleSpinBox>
#include <QLabel>

SiparisDialog::SiparisDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SiparisDialog),db(_db)
{
    ui->setupUi(this);
    this->initilize();
    this->setWindowTitle("Menü Seç");
}

SiparisDialog::~SiparisDialog()
{
    delete ui;
}

void SiparisDialog::initilize()
{


    receteDelegate = new Siparis::ReceteDelegate;

    ui->listView->setItemDelegate(std::move(receteDelegate));

    receteModel = new QStandardItemModel;

    ui->listView->setModel(receteModel);



    auto filter = document{};

    try {
        auto cursor = db->collection(SNKKey::Recete::Recete::collection).find(filter.view());

        receteModel->removeRows(0,receteModel->rowCount());
        int row = 0;
        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem;
            try {
                item->setText(doc[SNKKey::Recete::Recete::adi].get_utf8().value.to_string().c_str());
            } catch (bsoncxx::exception &e) {
                item->setText(e.what());
            }
            try {
                item->setData(doc[SNKKey::Recete::Recete::kategori].get_utf8().value.to_string().c_str(),Siparis::ReceteDelegate::KategoriRole);
            } catch (bsoncxx::exception &e) {
                item->setData(e.what(),Siparis::ReceteDelegate::KategoriRole);
            }
            try {
                item->setData(doc[SNKKey::Recete::Recete::oid].get_oid().value.to_string().c_str(),Siparis::ReceteDelegate::Oid);
            } catch (bsoncxx::exception &e) {
                item->setData(e.what(),Siparis::ReceteDelegate::Oid);
            }
            receteModel->appendRow(item);
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Errro: " << e.what() << std::endl;
    }



    filter.clear();


    ui->comboBox_katFilter->clear();
    ui->comboBox_katFilter->addItem("Hepsi");
    try {
        auto cursor = db->collection(SNKKey::Recete::Kategori::collection).find(filter.view());

        for( auto doc : cursor )
        {
            ui->comboBox_katFilter->addItem(doc[SNKKey::Recete::Kategori::adi].get_utf8().value.to_string().c_str(),Qt::UserRole+1);
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }


    connect(ui->comboBox_katFilter,&QComboBox::currentTextChanged,this,&SiparisDialog::listRecete);

}

void SiparisDialog::listRecete(const QString &index)
{
    auto filter = document{};

    if( index != "Hepsi" )
    {
        try {
            filter.append(kvp(SNKKey::Recete::Recete::kategori,index.toStdString().c_str()));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            return;
        }
    }


    try {
        auto cursor = db->collection(SNKKey::Recete::Recete::collection).find(filter.view());

        receteModel->removeRows(0,receteModel->rowCount());
        int row = 0;
        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem;
            try {
                item->setText(doc[SNKKey::Recete::Recete::adi].get_utf8().value.to_string().c_str());
            } catch (bsoncxx::exception &e) {
                item->setText(e.what());
            }
            try {
                item->setData(doc[SNKKey::Recete::Recete::kategori].get_utf8().value.to_string().c_str(),Siparis::ReceteDelegate::KategoriRole);
            } catch (bsoncxx::exception &e) {
                item->setData(e.what(),Siparis::ReceteDelegate::KategoriRole);
            }
            try {
                item->setData(doc[SNKKey::Recete::Recete::oid].get_oid().value.to_string().c_str(),Siparis::ReceteDelegate::Oid);
            } catch (bsoncxx::exception &e) {
                item->setData(e.what(),Siparis::ReceteDelegate::Oid);
            }
            receteModel->appendRow(item);
        }

    } catch (mongocxx::exception &e) {
        std::cout << "Errro: " << e.what() << std::endl;
    }
}

void Siparis::ReceteDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
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

QSize Siparis::ReceteDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
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

void SiparisDialog::on_listView_doubleClicked(const QModelIndex &index)
{

    auto mDialog = new Dialog();

    auto layout = mDialog->addLayout<VLayout>();

    auto label = layout->addwidget<QLabel>("Miktar Seçiniz");

    auto miktar = layout->addwidget<QDoubleSpinBox>();
    miktar->setMaximum(100000);
    miktar->setMinimum(0);
    miktar->setValue(1);

    auto btn = layout->addwidget<QPushButton>("Ekle");

    connect(btn,&QPushButton::clicked,[=](){
        if( miktar->value() > 0.0 )
        {
            emit selectedRecete(index.data(Siparis::ReceteDelegate::Oid).toString(),miktar->value());
            mDialog->close();
        }
    });

    mDialog->exec();

}
