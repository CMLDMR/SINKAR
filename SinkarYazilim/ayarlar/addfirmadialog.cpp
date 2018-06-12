#include "addfirmadialog.h"
#include "ui_addfirmadialog.h"

addFirmaDialog::addFirmaDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addFirmaDialog),
    db(_db)
{

    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QDialog{border:1px solid black;}");

    this->setSaveAccepted(false);

}

addFirmaDialog::~addFirmaDialog()
{
    delete ui;
}

void addFirmaDialog::on_pushButton_save_clicked()
{

    auto doc = document{};

    try {
        doc.append(kvp(SNKKey::Firma::adi,ui->lineEdit_FirmaAdi->text().toStdString().c_str()));
        doc.append(kvp(SNKKey::Firma::carikod,ui->lineEdit_CariKod->text().toStdString().c_str()));
    } catch (bsoncxx::exception &e) {
        return;
    }


    try {
        auto ins = db->collection(SNKKey::Firma::collection).insert_one(doc.view());
        if( ins )
        {
            if( ins.value().result().inserted_count() )
            {
                setSaveAccepted(true);
                setLastFirmaOid(ins.value().inserted_id().get_oid().value.to_string());
            }
        }
    } catch (mongocxx::exception &e) {

    }
    this->close();
}

bool addFirmaDialog::getSaveAccepted() const
{
    return mSaveAccepted;
}

void addFirmaDialog::setFirmaName(QString name)
{
    ui->lineEdit_FirmaAdi->setText(name);
}

bool addFirmaDialog::saveAccepted() const
{
    return mSaveAccepted;
}

void addFirmaDialog::setSaveAccepted(bool saveAccepted)
{
    mSaveAccepted = saveAccepted;
}

std::string addFirmaDialog::getLastFirmaOid() const
{
    return lastFirmaOid;
}

void addFirmaDialog::setLastFirmaOid(const std::string &value)
{
    lastFirmaOid = value;
}


void addFirmaDialog::on_pushButton_iptal_clicked()
{
    this->close();
}
