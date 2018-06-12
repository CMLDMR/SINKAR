#include "selectfirmadialog.h"
#include "ui_selectfirmadialog.h"

#include "ayarlar/addfirmadialog.h"

SelectFirmaDialog::SelectFirmaDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectFirmaDialog),
    db(_db)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QDialog{border:1px solid black;}");

    model = new QStandardItemModel;
    model->setHorizontalHeaderLabels(QStringList()<<"Firmalar");
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    ui->listView->setModel(proxyModel);
    this->initFirmaList();
    setAccepted(false);
}

SelectFirmaDialog::~SelectFirmaDialog()
{
    delete ui;
}

void SelectFirmaDialog::on_pushButton_clicked()
{
    addFirmaDialog* mDialog = new addFirmaDialog(db);
    mDialog->setFirmaName(ui->lineEdit->text());
    mDialog->exec();
    if( mDialog->getSaveAccepted() )
    {
        auto filter = document{};
        try {
            filter.append(kvp(SNKKey::Firma::oid,bsoncxx::oid{mDialog->getLastFirmaOid().c_str()}));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        try {
            auto val = db->collection(SNKKey::Firma::collection).find_one(filter.view());
            if( val )
            {
                if( !val.value().view().empty() )
                {
                    this->initFirmaList();
                    ui->lineEdit->setText(val.value().view()[SNKKey::Firma::adi].get_utf8().value.to_string().c_str());
                }
            }
        } catch (mongocxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    mDialog->deleteLater();
}

void SelectFirmaDialog::initFirmaList()
{
    try {
        auto cursor = db->collection(SNKKey::Firma::collection).find(document{}.view());
        model->removeRows(0,model->rowCount());
        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem;
            item->setText(doc[SNKKey::Firma::adi].get_utf8().value.to_string().c_str());
            item->setData(doc[SNKKey::Firma::oid].get_oid().value.to_string().c_str(),Qt::UserRole);
            model->appendRow(item);
        }
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

bool SelectFirmaDialog::getAccepted() const
{
    return mAccepted;
}

void SelectFirmaDialog::setAccepted(bool accepted)
{
    mAccepted = accepted;
}

std::string SelectFirmaDialog::getFirmaOid() const
{
    return firmaOid;
}

void SelectFirmaDialog::setFirmaOid(const std::string &value)
{
    firmaOid = value;
}

void SelectFirmaDialog::on_lineEdit_textChanged(const QString &arg1)
{
    proxyModel->setFilterRegExp(QRegExp(arg1));
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
}

void SelectFirmaDialog::on_listView_doubleClicked(const QModelIndex &index)
{
    setAccepted(true);
    this->setFirmaOid(index.data(Qt::UserRole).toString().toStdString());
    this->close();
}
