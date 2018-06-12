#include "malzemeselectdialog.h"
#include "ui_malzemeselectdialog.h"

MalzemeSelectDialog::MalzemeSelectDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MalzemeSelectDialog),
    db(_db),
    mMalzemeOid(bsoncxx::types::b_oid{bsoncxx::oid{}})

{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QDialog{border:1px solid black;}");

    model = new QStandardItemModel;
    ui->listView->setModel(model);
    model->setHorizontalHeaderLabels(QStringList()<<"Malzemeler");

    try {
        auto cursor = db->collection(SNKKey::Kategoriler::collection).find(document{}.view());

        ui->comboBox_KategoriFilter->addItem("Hepsi");
        ui->comboBox_KategoriFilter->blockSignals(true);
        if( ui->comboBox_KategoriFilter->signalsBlocked() )
        {
            for( auto doc : cursor )
            {
                ui->comboBox_KategoriFilter->addItem(doc[SNKKey::Kategoriler::adi].get_utf8().value.to_string().c_str(),
                        QVariant(doc[SNKKey::Kategoriler::oid].get_oid().value.to_string().c_str()));
            }
        }

        if( !ui->comboBox_KategoriFilter->blockSignals(false) )
        {
            showMessage("Can Not unblock Signal");
        }

    } catch (mongocxx::exception &e) {
        this->showMessage("Kategoriler Çekilemedi");
    }


}

MalzemeSelectDialog::~MalzemeSelectDialog()
{
    delete ui;
}


void MalzemeSelectDialog::on_comboBox_KategoriFilter_currentIndexChanged(const QString &arg1)
{

    auto filter = document{};

    if( arg1 == "Hepsi" )
    {

    }else{
        try {
            filter.append(kvp(SNKKey::Malzeme::kategorioid,bsoncxx::oid{ui->comboBox_KategoriFilter->currentData(Qt::UserRole).toString().toStdString().c_str()}));
        } catch (bsoncxx::exception &e) {
            showMessage(QString("Document Error: %1 ").arg(e.what()));
        }
    }


    try {
        auto collectin = db->collection(SNKKey::Malzeme::collection);
        auto cursor = collectin.find(filter.view());
        model->removeRows(0,model->rowCount());
        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem();
            item->setText(doc[SNKKey::Malzeme::adi].get_utf8().value.to_string().c_str());
            item->setData(doc[SNKKey::Malzeme::oid].get_oid().value.to_string().c_str(),Qt::UserRole);
            model->appendRow(item);
        }
    } catch (mongocxx::exception &e) {
        showMessage(QString("DB Error: %1").arg(e.what()),QMessageBox::Icon::Critical);
    }
}

void MalzemeSelectDialog::showMessage(QString mesaj, QMessageBox::Icon icon)
{
    QMessageBox msg;
    msg.setText(mesaj);
    msg.setIcon(icon);
    msg.setWindowFlag(Qt::FramelessWindowHint);
    msg.setStyleSheet("QDialog{border: 1px solid black;}");
    msg.exec();
}

bool MalzemeSelectDialog::clickAccepted() const
{
    return mClickAccepted;
}

void MalzemeSelectDialog::setClickAccepted(bool clickAccepted)
{
    mClickAccepted = clickAccepted;
}

bsoncxx::types::value MalzemeSelectDialog::malzemeOid() const
{
    return mMalzemeOid;
}

void MalzemeSelectDialog::setKategori(const QString &kategoriName)
{
    ui->comboBox_KategoriFilter->setCurrentText(kategoriName);
}

void MalzemeSelectDialog::setMalzemeOid(const bsoncxx::types::value &malzemeOid)
{
    mMalzemeOid = malzemeOid;
}

void MalzemeSelectDialog::on_listView_doubleClicked(const QModelIndex &index)
{
    bsoncxx::types::value val(bsoncxx::types::b_oid{bsoncxx::oid{index.data(Qt::UserRole).toString().toStdString().c_str()}});
    setMalzemeOid(val);
    setClickAccepted(true);
    this->close();
}

void MalzemeSelectDialog::on_pushButton_iptal_clicked()
{

    setClickAccepted(false);
    this->close();
}
