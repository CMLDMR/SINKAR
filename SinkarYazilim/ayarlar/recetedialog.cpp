#include "recetedialog.h"
#include "ui_recetedialog.h"

ReceteDialog::ReceteDialog(mongocxx::database *_db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceteDialog),
    db(_db)
{
    ui->setupUi(this);
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
                    ui->comboBox_ReceteKat->addItem(lineEditKategoriName->text());
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
