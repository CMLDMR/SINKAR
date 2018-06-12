#include "stokdialog.h"
#include "ui_stokdialog.h"
#include "malzemegirdialog.h"
#include "malzemecikdialog.h"

StokDialog::StokDialog(mongocxx::database* _db , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StokDialog),
    db(_db)
{

    ui->setupUi(this);


    model = new QStandardItemModel;

    ui->listView_MalzemeStok->setModel(model);

    mItemDelegate = new StokItemDeletegate;

    ui->listView_MalzemeStok->setItemDelegate(mItemDelegate);


    this->setWindowFlag(Qt::FramelessWindowHint);

    this->setStyleSheet("QDialog{border:1px solid black;}");

    this->initDepoList();

    this->initMalzemeList();

    connect(ui->comboBox_depo,&QComboBox::currentTextChanged,this,&StokDialog::initMalzemeList);


}

StokDialog::~StokDialog()
{
    delete ui;
}

void StokDialog::on_pushButton_malzemeGirisi_clicked()
{
    MalzemeGirDialog* mDialog = new MalzemeGirDialog(db);
    mDialog->exec();
    this->initMalzemeList(ui->comboBox_depo->currentText());
    mDialog->deleteLater();
}

void StokDialog::on_pushButton_malzemeCikisi_clicked()
{
    MalzemeCikDialog* mDialog = new MalzemeCikDialog(db);
    mDialog->exec();
    mDialog->deleteLater();
}

void StokDialog::setmessage(QString msg)
{
    ui->label_status->setText(msg);
}

void StokDialog::setmessage(QString msg, mongocxx::exception &e)
{
    ui->label_status->setText(QString("%1 - %2").arg(msg).arg(e.what()));
}


void StokDialog::setmessage(QString msg, bsoncxx::exception &e)
{

    ui->label_status->setText(QString("%1 - %2").arg(msg).arg(e.what()));

}

void StokDialog::initDepoList()
{

    auto filter = document{};

    try {

        auto cursor = db->collection(SNKKey::Depo::collection).find(filter.view());

        ui->comboBox_depo->clear();
        ui->comboBox_depo->addItem("Hepsi");
        for( auto doc : cursor )
        {
            ui->comboBox_depo->addItem(doc[SNKKey::Depo::depoAdi].get_utf8().value.to_string().c_str());
        }
    } catch (mongocxx::exception &e) {
        this->setmessage("Error",e);
    }

}

void StokDialog::initMalzemeList(QString depo)
{

    auto filter = document{};

    if( depo != "Hepsi" )
    {
        try {
            filter.append(kvp(SNKKey::StokMiktar::depo,depo.toStdString().c_str()));
        } catch (bsoncxx::exception &e) {
            setmessage("Error",e);
            return;
        }
    }



    try {
        auto cursor = db->collection(SNKKey::StokMiktar::collection).find(filter.view());

        model->removeRows(0,model->rowCount());

        for( auto doc : cursor )
        {

            QStandardItem *item = new QStandardItem;
            item->setData(doc[SNKKey::StokMiktar::adi].get_utf8().value.to_string().c_str(),Qt::DisplayRole);
            item->setData(doc[SNKKey::StokMiktar::miktar].get_double().value,StokItemDeletegate::MiktarRole);
            item->setData(doc[SNKKey::StokMiktar::birim].get_utf8().value.to_string().c_str(),StokItemDeletegate::BirimRole);
            item->setData(doc[SNKKey::StokMiktar::depo].get_utf8().value.to_string().c_str(),StokItemDeletegate::DepoRole);
            item->setData(doc[SNKKey::oid].get_oid().value.to_string().c_str(),StokItemDeletegate::OidRole);
            model->appendRow(item);

        }


    } catch (mongocxx::exception &e) {
        setmessage("Error",e);
    }



    std::cout << "Depo: " << bsoncxx::to_json(filter.view()) << std::endl;




}

StokItemDeletegate::StokItemDeletegate()
{



}

void StokItemDeletegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if( !index.isValid() )
    {
        return;
    }


    painter->save();

    if (option.state & QStyle::State_Selected)
    {
        painter->setPen(Qt::white);
        painter->fillRect(option.rect, option.palette.highlight());
    }

    painter->setPen(Qt::black);

    QString malzemeAdi = index.data(Qt::DisplayRole).toString();

    QString miktar = QString("Miktar: %1 %2").arg(index.data(MiktarRole).toDouble()).arg(index.data(BirimRole).toString());


    QFont font = QApplication::font();
    font.setBold(true);
    QFontMetrics FontMetrics(font);


    QFont fontMiktar = QApplication::font();
    QFontMetrics FontMetricsMiktar(fontMiktar);

    QRect titleRect = FontMetrics.boundingRect(option.rect.left(),option.rect.top()+padding , option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap, malzemeAdi );

    QRect MiktarRect = FontMetrics.boundingRect(option.rect.left(),titleRect.bottom()+padding , option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap, miktar );


    QString depo = index.data(DepoRole).toString();


    QRect DepoRect = FontMetrics.boundingRect(option.rect.left(),MiktarRect.bottom()+padding , option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap, miktar );



    if (option.state & QStyle::State_Selected)
    {
        painter->setPen(Qt::white);
    }else{
        painter->setPen(Qt::black);
    }



    painter->setFont(font);
    painter->drawText(titleRect,malzemeAdi);


    if (option.state & QStyle::State_Selected)
    {
        painter->setPen(Qt::white);
    }else{
        painter->setPen(Qt::gray);
    }

    painter->setFont(fontMiktar);
    if( index.data(MiktarRole).toDouble() <= 0 )
    {
        painter->setPen(Qt::red);
    }
    painter->drawText(MiktarRect,miktar);

    if (option.state & QStyle::State_Selected)
    {
        painter->setPen(Qt::white);
    }else{
        painter->setPen(Qt::gray);
    }
    painter->setFont(fontMiktar);
    painter->drawText(DepoRect,depo);


    painter->restore();



}

QSize StokItemDeletegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{


    QString malzemeAdi = index.data(Qt::DisplayRole).toString();
    QString miktar = QString("Miktar: %1 %2").arg(index.data(MiktarRole).toDouble()).arg(index.data(BirimRole).toString());


    QFont font = QApplication::font();
    font.setBold(true);
    QFontMetrics FontMetrics(font);


    QFont fontMiktar = QApplication::font();
    QFontMetrics FontMetricsMiktar(fontMiktar);

    QRect titleRect = FontMetrics.boundingRect(option.rect.left(),option.rect.top()+padding , option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap, malzemeAdi );

    QRect MiktarRect = FontMetrics.boundingRect(option.rect.left(),titleRect.bottom()+padding , option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop | Qt::TextWordWrap , miktar );

    QString depo = index.data(DepoRole).toString();


    QRect DepoRect = FontMetrics.boundingRect(option.rect.left(),MiktarRect.bottom()+padding , option.rect.width() , 0 ,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap, depo );



    return QSize(option.rect.width(),
                 titleRect.height() +
                 MiktarRect.height() +
                 DepoRect.height() + padding*4);
}

void StokDialog::on_pushButton_close_clicked()
{
    this->close();
}
