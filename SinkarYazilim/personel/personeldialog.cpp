#include "personeldialog.h"
#include "ui_personeldialog.h"

PersonelDialog::PersonelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonelDialog)
{
    ui->setupUi(this);
}

PersonelDialog::~PersonelDialog()
{
    delete ui;
}

void PersonelDialog::on_pushButton_Save_clicked()
{

}
