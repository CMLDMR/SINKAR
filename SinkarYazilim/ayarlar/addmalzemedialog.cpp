#include "addmalzemedialog.h"
#include "ui_addmalzemedialog.h"


#include "src/quickwidget.h"

addMalzemeDialog::addMalzemeDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMalzemeDialog),
    db(_db)
{

    ui->setupUi(this);

    setAccepted(false);

    model = new QStandardItemModel;

    ui->listView->setModel(model);

    model->setHorizontalHeaderLabels(QStringList()<<"Malzemeler");

    this->refreshKategori();

}

addMalzemeDialog::~addMalzemeDialog()
{
    delete ui;
}

bool addMalzemeDialog::Accepted() const
{
    return m_Accepted;
}

QModelIndex addMalzemeDialog::getCurrentIndex() const
{
    return CurrentIndex;
}

void addMalzemeDialog::setCurrentIndex(const QModelIndex &value)
{
    CurrentIndex = value;
}

std::string addMalzemeDialog::getOid() const
{
    return m_oid;
}

void addMalzemeDialog::setOid(const std::string &oid)
{
    m_oid = oid;
}

double addMalzemeDialog::getSelectedValue() const
{
    return mSelectedValue;
}

void addMalzemeDialog::setSelectedValue(double selectedValue)
{
    mSelectedValue = selectedValue;
}

QString addMalzemeDialog::getSelectedValueType() const
{
    return mSelectedValueType;
}

void addMalzemeDialog::setSelectedValueType(const QString &selectedValueType)
{
    mSelectedValueType = selectedValueType;
}

void addMalzemeDialog::setAccepted(bool Accepted)
{
    m_Accepted = Accepted;
}

void addMalzemeDialog::refreshKategori()
{
    QtBsonObject filter;
    try {
        auto cursor = db->collection(SNKKey::Kategoriler::collection).find(filter.view());
        ui->comboBox->clear();
        ui->comboBox->addItem("Hepsi");
        for( auto doc : cursor )
        {
            ui->comboBox->addItem(doc[SNKKey::Kategoriler::adi].get_utf8().value.to_string().c_str(),doc[SNKKey::Kategoriler::oid].get_oid().value.to_string().c_str());
        }
    } catch (mongocxx::exception &e) {
        ui->comboBox->clear();
        ui->comboBox->addItem("Kategoriler Çekilemedi");
        setmessage(e);
    }
}

void addMalzemeDialog::setmessage(QString e)
{
    ui->label_status->setText(e);
}

void addMalzemeDialog::setmessage(bsoncxx::exception &e)
{
    setmessage(QString("builder Error: %1").arg(e.what()));
}


void addMalzemeDialog::setmessage(mongocxx::exception &e)
{
    setmessage(QString("db Error: %1").arg(e.what()));
}

void addMalzemeDialog::refreshList(QString val)
{

    QtBsonObject filter;
    if( !val.isEmpty() )
    {
        filter.append(SNKKey::Malzeme::kategorioid,QtBsonObject::oid(val));
    }


    try {
        auto cursor = db->collection(SNKKey::Malzeme::collection).find(filter.view());

        model->removeRows(0,model->rowCount());
        for( auto doc : cursor )
        {
            QStandardItem *item = new QStandardItem();
            item->setText(doc[SNKKey::Malzeme::adi].get_utf8().value.to_string().c_str());
            item->setData(doc[SNKKey::Malzeme::oid].get_oid().value.to_string().c_str(),Qt::UserRole);
            item->setData(doc[SNKKey::Malzeme::kategorioid].get_oid().value.to_string().c_str(),Qt::UserRole+1);
            model->appendRow(item);
        }

    } catch (mongocxx::exception &e) {
        setmessage(e);
    }



}




void addMalzemeDialog::on_comboBox_currentIndexChanged(int index)
{
    if( ui->comboBox->itemText(index) != "Hepsi" )
    {
        QString oid = ui->comboBox->itemData(index,Qt::UserRole).toString();

        this->refreshList(oid);
    }else{
        this->refreshList("");
    }


}

void addMalzemeDialog::on_listView_doubleClicked(const QModelIndex &index)
{

    if( ui->doubleSpinBox_Miktar->value() == 0.0 )
    {

        auto mDialog = new Dialog();

        auto layout = mDialog->addLayout<VLayout>();

        layout->addwidget<QLabel>("Miktar Giriniz");

        auto val = layout->addwidget<QDoubleSpinBox>();

        val->setMaximum(99999);
        val->setValue(0);

        auto ok = layout->addwidget<QPushButton>("Tamam");

        double miktar = 0;

        connect(ok,&QPushButton::clicked,[&miktar,&val,&mDialog](){
            miktar = val->value();
            mDialog->close();
        });

        mDialog->exec();


        this->setSelectedValueType(ui->comboBox_miktarType->currentText());
        this->setCurrentIndex(index);
        this->setSelectedValue(miktar);
        setAccepted(true);
        this->close();

        return;
    }else{
        this->setSelectedValue(ui->doubleSpinBox_Miktar->value());
        this->setSelectedValueType(ui->comboBox_miktarType->currentText());
        this->setCurrentIndex(index);
        setAccepted(true);
        this->close();
    }



}
