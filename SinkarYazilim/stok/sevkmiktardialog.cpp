#include "sevkmiktardialog.h"
#include "ui_sevkmiktardialog.h"

SevkMiktarDialog::SevkMiktarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SevkMiktarDialog)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("QDialog{border:1px solid black;}");

    setAccepted(false);
}

SevkMiktarDialog::~SevkMiktarDialog()
{
    delete ui;
}

void SevkMiktarDialog::on_pushButton_tamam_clicked()
{

    setMiktar(ui->doubleSpinBox_selected->value());
    setAccepted(true);
    this->close();
}

double SevkMiktarDialog::getMaxMiktar() const
{
    return maxMiktar;
}

void SevkMiktarDialog::setMaxMiktar(double value)
{
    maxMiktar = value;
    ui->doubleSpinBox_selected->setMaximum(maxMiktar);
}

double SevkMiktarDialog::getMiktar() const
{
    return Miktar;
}

void SevkMiktarDialog::setMiktar(double value)
{
    Miktar = value;
}

bool SevkMiktarDialog::getAccepted() const
{
    return mAccepted;
}

void SevkMiktarDialog::setAccepted(bool accepted)
{
    mAccepted = accepted;
}

void SevkMiktarDialog::on_pushButton_iptal_clicked()
{
    this->close();
}
