#ifndef SEVKMIKTARDIALOG_H
#define SEVKMIKTARDIALOG_H

#include <QtGlobal>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

namespace Ui {
class SevkMiktarDialog;
}

class SevkMiktarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SevkMiktarDialog(QWidget *parent = 0);
    ~SevkMiktarDialog();

    bool getAccepted() const;
    void setAccepted(bool accepted);

    double getMiktar() const;
    void setMiktar(double value);

    double getMaxMiktar() const;
    void setMaxMiktar(double value);

private slots:
    void on_pushButton_tamam_clicked();

    void on_pushButton_iptal_clicked();

private:
    Ui::SevkMiktarDialog *ui;

    bool mAccepted;

    double Miktar;

    double maxMiktar;
};

#endif // SEVKMIKTARDIALOG_H
