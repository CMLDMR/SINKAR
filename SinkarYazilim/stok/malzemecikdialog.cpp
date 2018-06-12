#include "malzemecikdialog.h"
#include "ui_malzemecikdialog.h"

#include "sevkmiktardialog.h"

MalzemeCikDialog::MalzemeCikDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MalzemeCikDialog),
    db(_db)
{
    ui->setupUi(this);

    this->initDepolar();

    connect(ui->comboBox_source,SIGNAL(activated(int)),this,SLOT(setDestinationDepo(int)));

    model = new QStandardItemModel;

    filterModel = new QSortFilterProxyModel;
    filterModel->setSourceModel(model);
    filterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    ui->listView_currentStock->setModel(filterModel);

    itemDelegate = new ItemDelegate;
    ui->listView_currentStock->setItemDelegate(itemDelegate);


    selectedmodel = new QStandardItemModel;

    ui->listView_selectedStock->setModel(selectedmodel);
    ui->listView_selectedStock->setItemDelegate(itemDelegate);

    this->initMalzemeList();
}

MalzemeCikDialog::~MalzemeCikDialog()
{
    delete ui;
}

void MalzemeCikDialog::initDepolar()
{
    try {
        auto cursor = db->collection(SNKKey::Depo::collection).find(document{}.view());


        ui->comboBox_source->clear();
        ui->comboBox_destination->clear();

        int i = 0;
        for( auto doc : cursor )
        {
            if( i != 0 )
            {
                ui->comboBox_destination->addItem(doc[SNKKey::Depo::depoAdi].get_utf8().value.to_string().c_str(),doc[SNKKey::Depo::oid].get_oid().value.to_string().c_str());
            }
            ui->comboBox_source->addItem(doc[SNKKey::Depo::depoAdi].get_utf8().value.to_string().c_str(),doc[SNKKey::Depo::oid].get_oid().value.to_string().c_str());
            i++;
        }
    } catch (mongocxx::exception &e) {
        this->ShowMessage("Depolar Listelenemedi",e,QMessageBox::Icon::Critical);
    }
}

void MalzemeCikDialog::ShowMessage(QString mesaj, bsoncxx::exception &e, QMessageBox::Icon icon)
{
    QMessageBox msg;
    msg.setText(mesaj);
    msg.setInformativeText(e.what());
    msg.setWindowFlag(Qt::FramelessWindowHint);
    msg.setIcon(icon);
    msg.setStyleSheet("QDialog{border:1px solid black;}");
    msg.exec();
}

void MalzemeCikDialog::ShowMessage(QString mesaj, mongocxx::exception &e, QMessageBox::Icon icon)
{
    QMessageBox msg;
    msg.setText(mesaj);
    msg.setInformativeText(e.what());
    msg.setWindowFlag(Qt::FramelessWindowHint);
    msg.setIcon(icon);
    msg.setStyleSheet("QDialog{border:1px solid black;}");
    msg.exec();
}

void MalzemeCikDialog::ShowMessage(QString mesaj, QMessageBox::Icon icon)
{
    QMessageBox msg;
    msg.setText(mesaj);
    msg.setWindowFlag(Qt::FramelessWindowHint);
    msg.setIcon(icon);
    msg.setStyleSheet("QDialog{border:1px solid black;}");
    msg.exec();
}

void MalzemeCikDialog::initMalzemeList()
{

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::StokMiktar::depo,ui->comboBox_source->currentText().toStdString().c_str()));
    } catch (bsoncxx::exception &e) {
        this->ShowMessage("Filter Oluşturulamadı",e,QMessageBox::Icon::Critical);
        return;
    }


    try {

        auto cursor = db->collection(SNKKey::StokMiktar::collection).find(filter.view());

        model->removeRows(0,model->rowCount());

        int row = 0;
        for( auto doc : cursor )
        {
            QStandardItem* item = new QStandardItem;
            item->setData(doc[SNKKey::StokMiktar::adi].get_utf8().value.to_string().c_str(),ItemDelegate::title);
            item->setData(doc[SNKKey::StokMiktar::miktar].get_double().value,ItemDelegate::miktar);
            item->setData(doc[SNKKey::StokMiktar::birim].get_utf8().value.to_string().c_str(),ItemDelegate::birim);
            item->setData(doc[SNKKey::StokMiktar::malzemeoid].get_oid().value.to_string().c_str(),ItemDelegate::malzemeoid);
            model->setItem(row++,item);
        }

    } catch (mongocxx::exception &e) {
        this->ShowMessage("Malzemeler Çekilemedi",e,QMessageBox::Icon::Critical);
    }



}

void MalzemeCikDialog::PrintSevk(std::string oid)
{

    auto filter = document{};

    try {
        filter.append(kvp(SNKKey::SevkFisi::oid,bsoncxx::oid{oid.c_str()}));
    } catch (bsoncxx::exception &e) {
        ShowMessage("Error For Printer Filter",e,QMessageBox::Icon::Critical);
        return;
    }

    try {


        auto collection = db->collection(SNKKey::SevkFisi::collection);

        auto val = collection.find_one(filter.view());

        if( val )
        {
            if( !val.value().view().empty() )
            {

                auto view = val.value().view();

                // Create a report
                KDReports::Report report;

                // Add a text element for the title
                KDReports::TextElement titleElement( QObject::tr( "Depo Sevk Fişi" ) );
                titleElement.setPointSize( 18 );
                report.addElement( titleElement, Qt::AlignHCenter );

                // add 20 mm of vertical space:
                report.addVerticalSpacing( 20 );

                {
                    // add some more text
                    KDReports::TextElement textElement( QObject::tr( "Çıkış Deposu" ) );
                    report.addElement( textElement, Qt::AlignLeft );
                }
                {
                    KDReports::TextElement textElement( QObject::tr(view[SNKKey::SevkFisi::kaynakDepo].get_utf8().value.to_string().c_str()));
                    report.addElement( textElement, Qt::AlignLeft );
                }

                {
                    // add some more text
                    KDReports::TextElement textElement( QObject::tr( "Giriş Deposu" ) );
                    report.addElement( textElement, Qt::AlignLeft );
                }
                {
                    KDReports::TextElement textElement( QObject::tr(view[SNKKey::SevkFisi::hedefDepo].get_utf8().value.to_string().c_str()));
                    report.addElement( textElement, Qt::AlignLeft );
                }

                // show a print preview
                KDReports::PreviewDialog preview( &report );
                preview.setWindowFlag(Qt::FramelessWindowHint);
                preview.setStyleSheet("QDialog{border:1px solid black;}");
                preview.exec();

            }
        }
    } catch (mongocxx::exception &e) {
        ShowMessage("Error Query : ", e , QMessageBox::Icon::Critical );
    }

}

void MalzemeCikDialog::setDestinationDepo(int index)
{

    ui->comboBox_destination->clear();
    selectedmodel->removeRows(0,selectedmodel->rowCount());
    for( int i = 0 ; i < ui->comboBox_source->count() ; i++ )
    {
        if( index != i )
        {
            ui->comboBox_destination->addItem(ui->comboBox_source->itemText(i),ui->comboBox_source->itemData(i,Qt::UserRole).toString().toStdString().c_str());
        }
    }

    this->initMalzemeList();


}

void MalzemeCikDialog::on_lineEdit_filter_textChanged(const QString &arg1)
{

    filterModel->setFilterRegExp(arg1);
}

ItemDelegate::ItemDelegate()
{

}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
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


    QString mTitle = index.data(title).toString();
    QString mMiktar = QString("Miktar: %1 %2").arg(index.data(miktar).toDouble()).arg(index.data(birim).toString());


    QFont titlefont = QApplication::font();
    titlefont.setBold(true);

    QFont subtitlesFont = QApplication::font();


    QFontMetrics titleFontMetrics(titlefont);
    QFontMetrics subtitleFontMetrics(subtitlesFont);



    QRect titleRect = titleFontMetrics.boundingRect(option.rect.left(),option.rect.top()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,mTitle);
    QRect subTitle1Rect = subtitleFontMetrics.boundingRect(option.rect.left(),titleRect.bottom()+padding,option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,mMiktar);



    painter->setFont(titlefont);

    if( index.data(miktar).toDouble() == 0 )
    {
        painter->setPen(Qt::red);
    }

    painter->drawText(titleRect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,mTitle);

    painter->setFont(subtitlesFont);

    if( option.state & QStyle::State_Selected )
    {

        painter->setPen(Qt::white);


    }else{
        painter->setPen(Qt::gray);
    }

    if( index.data(miktar).toDouble() )
    {
        painter->setPen(Qt::black);
    }


    painter->drawText(subTitle1Rect,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,mMiktar);

    painter->restore();

}

QSize ItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( !index.isValid() )
    {
        return QSize();
    }



    QString mTitle = index.data(title).toString();
    QString mMiktar = QString("%1").arg(index.data(miktar).toDouble());


    QFont titlefont = QApplication::font();
    titlefont.setBold(true);

    QFont subtitlesFont = QApplication::font();


    QFontMetrics titleFontMetrics(titlefont);
    QFontMetrics subtitleFontMetrics(subtitlesFont);



    QRect titleRect = titleFontMetrics.boundingRect(option.rect.left(),option.rect.top(),option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,mTitle);
    QRect subTitle1Rect = subtitleFontMetrics.boundingRect(option.rect.left(),titleRect.bottom(),option.rect.width(),0,Qt::AlignLeft|Qt::AlignTop|Qt::TextWordWrap,mMiktar);


    return QSize(option.rect.width(),titleRect.height() +
                 subTitle1Rect.height()+2*padding);
}

void MalzemeCikDialog::on_listView_currentStock_doubleClicked(const QModelIndex &index)
{
    if( index.data(ItemDelegate::miktar).toDouble() == 0 )
    {
        this->ShowMessage("Bu Depoda Bu Malzemeden Bulunmamaktadır");
        return;
    }else{
        SevkMiktarDialog* mDialog = new SevkMiktarDialog();
        mDialog->setMaxMiktar(index.data(ItemDelegate::miktar).toDouble());
        mDialog->exec();
        if( mDialog->getAccepted() && mDialog->getMiktar() )
        {
            {
                bool exist = false;
                bool existIndex = -1;
                double existMiktar = 0;
                for( int i = 0 ; i < selectedmodel->rowCount() ; i++ )
                {
                    if( selectedmodel->item(i,0)->data(ItemDelegate::title).toString() == index.data(ItemDelegate::title).toString() )
                    {
                        exist = true;
                        existIndex = i;
                        existMiktar = selectedmodel->item(i,0)->data(ItemDelegate::miktar).toDouble();
                        break;
                    }
                }
                if( exist )
                {
                    QStandardItem* item = new QStandardItem;
                    item->setData(index.data(ItemDelegate::title).toString(),ItemDelegate::title);
                    item->setData(mDialog->getMiktar()+existMiktar,ItemDelegate::miktar);
                    item->setData(index.data(ItemDelegate::birim).toString(),ItemDelegate::birim);
                    item->setData(index.data(ItemDelegate::malzemeoid).toString(),ItemDelegate::malzemeoid);
                    selectedmodel->setItem(existIndex,item);
                }else{
                    QStandardItem* item = new QStandardItem;
                    item->setData(index.data(ItemDelegate::title).toString(),ItemDelegate::title);
                    item->setData(mDialog->getMiktar(),ItemDelegate::miktar);
                    item->setData(index.data(ItemDelegate::birim).toString(),ItemDelegate::birim);
                    item->setData(index.data(ItemDelegate::malzemeoid).toString(),ItemDelegate::malzemeoid);
                    selectedmodel->appendRow(item);
                }

            }

            {
                QStandardItem* item = new QStandardItem;
                item->setData(index.data(ItemDelegate::title).toString(),ItemDelegate::title);
                item->setData(index.data(ItemDelegate::miktar).toDouble() - mDialog->getMiktar(),ItemDelegate::miktar);
                item->setData(index.data(ItemDelegate::birim).toString(),ItemDelegate::birim);
                item->setData(index.data(ItemDelegate::malzemeoid).toString(),ItemDelegate::malzemeoid);
                model->setItem(index.row(),item);
            }

            if( selectedmodel->rowCount() )
            {
                ui->comboBox_source->setEnabled(false);
            }else{
                ui->comboBox_source->setEnabled(true);
            }

        }
        mDialog->deleteLater();
    }
}

void MalzemeCikDialog::on_listView_selectedStock_doubleClicked(const QModelIndex &index)
{
    for( int i = 0 ; i < model->rowCount() ; i++ )
    {
        if( index.data(ItemDelegate::title).toString() == model->index(i,0).data(ItemDelegate::title).toString() )
        {
            {
                double miktar = index.data(ItemDelegate::miktar).toDouble();
                QStandardItem* item = new QStandardItem;
                item->setData(index.data(ItemDelegate::title).toString(),ItemDelegate::title);
                item->setData(model->index(i,0).data(ItemDelegate::miktar).toDouble() + miktar ,ItemDelegate::miktar);
                item->setData(index.data(ItemDelegate::birim).toString(),ItemDelegate::birim);
                model->setItem(i,item);
                selectedmodel->removeRow(index.row());

                if( selectedmodel->rowCount() )
                {
                    ui->comboBox_source->setEnabled(false);
                }else{
                    ui->comboBox_source->setEnabled(true);
                }
            }
            break;
        }
    }
}

void MalzemeCikDialog::on_pushButton_cancel_clicked()
{
    this->close();
}

void MalzemeCikDialog::on_pushButton_ok_clicked()
{




    bool breakDown = false;




    if( !ui->comboBox_destination->count() )
    {
        QMessageBox msg;
        msg.setText("Hata");
        msg.setInformativeText("Hedef Depo Bulunmamakta");
        msg.setWindowFlag(Qt::FramelessWindowHint);
        msg.setStyleSheet("QDialog{border:1px solid black;}");
        msg.exec();
        return;
    }

    std::vector<MalzemeStruct> list;

    for( int i = 0 ; i < selectedmodel->rowCount() ; i++ )
    {



        // Destionation increment
        {

            QModelIndex index = selectedmodel->index(i,0);
            auto filter = document{};

            {
                MalzemeStruct item;
                item.adi = index.data(ItemDelegate::title).toString().toStdString();
                item.birim = index.data(ItemDelegate::birim).toString().toStdString();
                item.miktar = index.data(ItemDelegate::miktar).toDouble();
                item.oid = index.data(ItemDelegate::malzemeoid).toString().toStdString();
                list.push_back(item);
            }


            try {
                filter.append(kvp(SNKKey::StokMiktar::adi,index.data(ItemDelegate::title).toString().toStdString().c_str()));
                filter.append(kvp(SNKKey::StokMiktar::depo,ui->comboBox_destination->currentText().toStdString().c_str()));
            } catch (bsoncxx::exception &e) {
                this->ShowMessage("Hedef için Filtre Oluşturulamadı",e,QMessageBox::Icon::Critical);
                breakDown = true;
                break;
            }

            auto updateDoc = document{};

            if( !breakDown )
            {
                try {
                    updateDoc.append(kvp("$inc",make_document(kvp(SNKKey::StokMiktar::miktar,index.data(ItemDelegate::miktar).toDouble()))));
                } catch (bsoncxx::exception &e) {
                    this->ShowMessage("updateDoc Oluşturulamadı",e,QMessageBox::Icon::Critical);
                    breakDown = true;
                    break;
                }
            }

            if( !breakDown )
            {
                try {
                    auto collection = db->collection(SNKKey::StokMiktar::collection);

                    auto upt = collection.update_one(filter.view(),updateDoc.view());
                    if( upt )
                    {
                        if( !upt.value().modified_count() )
                        {
                            ShowMessage("DB update Yapılamadı",QMessageBox::Icon::Critical);
                            breakDown = true;
                            break;
                        }
                    }else{
                        ShowMessage("DB update Yapılamadı",QMessageBox::Icon::Critical);
                        breakDown = true;
                        break;
                    }
                } catch (mongocxx::exception &e) {
                    ShowMessage("DB update Yapılamadı",e,QMessageBox::Icon::Critical);
                    breakDown = true;
                    break;
                }
            }
        }



        // Source decrement
        {

            QModelIndex index = selectedmodel->index(i,0);
            auto filter = document{};

            try {
                filter.append(kvp(SNKKey::StokMiktar::adi,index.data(ItemDelegate::title).toString().toStdString().c_str()));
                filter.append(kvp(SNKKey::StokMiktar::depo,ui->comboBox_source->currentText().toStdString().c_str()));
            } catch (bsoncxx::exception &e) {
                this->ShowMessage("Hedef için Filtre Oluşturulamadı",e,QMessageBox::Icon::Critical);
                breakDown = true;
                break;
            }

            auto updateDoc = document{};

            if( !breakDown )
            {
                try {
                    updateDoc.append(kvp("$inc",make_document(kvp(SNKKey::StokMiktar::miktar,(-1)*index.data(ItemDelegate::miktar).toDouble()))));
                } catch (bsoncxx::exception &e) {
                    this->ShowMessage("updateDoc Oluşturulamadı",e,QMessageBox::Icon::Critical);
                    breakDown = true;
                    break;
                }
            }

            if( !breakDown )
            {
                try {
                    auto collection = db->collection(SNKKey::StokMiktar::collection);

                    auto upt = collection.update_one(filter.view(),updateDoc.view());
                    if( upt )
                    {
                        if( !upt.value().modified_count() )
                        {
                            ShowMessage("DB update Yapılamadı",QMessageBox::Icon::Critical);
                            breakDown = true;
                            break;
                        }
                    }else{
                        ShowMessage("DB update Yapılamadı",QMessageBox::Icon::Critical);
                        breakDown = true;
                        break;
                    }
                } catch (mongocxx::exception &e) {
                    ShowMessage("DB update Yapılamadı",e,QMessageBox::Icon::Critical);
                    breakDown = true;
                    break;
                }
            }
        }
    }


    {


        auto malzemeList = array{};

        for( auto item : list )
        {

            auto malDoc = document{};

            {
                auto filter = document{};
                try {
                    filter.append(kvp(SNKKey::Malzeme::oid,bsoncxx::oid{item.oid.c_str()}));
                    try {
                        auto val = db->collection(SNKKey::Malzeme::collection).find_one(filter.view());
                        if( val )
                        {
                            if( !val.value().view().empty() )
                            {
                                auto view = val.value().view();
                                malDoc.append(kvp(SNKKey::SevkFisi::Malzeme::fiyat,view[SNKKey::Malzeme::fiyat].get_double().value));
                            }
                        }
                    } catch (mongocxx::exception &e) {
                        ShowMessage("DB Query Error",e,QMessageBox::Icon::Critical);
                    }
                } catch (bsoncxx::exception &e) {
                    ShowMessage("filter oluşturalamadı",e,QMessageBox::Icon::Critical);
                }
            }

            try {
                malDoc.append(kvp(SNKKey::SevkFisi::Malzeme::adi,item.adi));
                malDoc.append(kvp(SNKKey::SevkFisi::Malzeme::birim,item.birim));
                malDoc.append(kvp(SNKKey::SevkFisi::Malzeme::miktar,item.miktar));
                malzemeList.append(malDoc);
            } catch (bsoncxx::exception &e) {
                ShowMessage("Error BSON Document",e);
            }

        }


        auto doc = document{};

        try {
            doc.append(kvp(SNKKey::SevkFisi::hedefDepo,ui->comboBox_destination->currentText().toStdString().c_str()));
            doc.append(kvp(SNKKey::SevkFisi::kaynakDepo,ui->comboBox_source->currentText().toStdString().c_str()));
            doc.append(kvp(SNKKey::SevkFisi::tarih,QDate::currentDate().toJulianDay()));
            doc.append(kvp(SNKKey::SevkFisi::malzemeler,malzemeList));
        } catch (bsoncxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }


        bool thisClose = true;
        std::string oid;
        try {
            auto collection = db->collection(SNKKey::SevkFisi::collection);

            auto ins = collection.insert_one(doc.view());

            if( ins )
            {
                if( ins.value().result().inserted_count() )
                {

                    QMessageBox::StandardButton btn = QMessageBox::question(this,"Soru","Sevk Fişi Çıkartmak İstemisiniz?",QMessageBox::StandardButton::Ok|QMessageBox::StandardButton::Cancel);

                    if( btn == QMessageBox::StandardButton::Ok )
                    {
                        oid = ins.value().inserted_id().get_oid().value.to_string();
                        thisClose = false;
                    }
                }
            }
        } catch (mongocxx::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        if( thisClose )
        {
            this->close();
        }else{

            this->PrintSevk(oid);

            this->close();

        }


    }





}
