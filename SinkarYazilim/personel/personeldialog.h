#ifndef PERSONELDIALOG_H
#define PERSONELDIALOG_H


#include <QtGlobal>



#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

namespace Ui {
class PersonelDialog;
}

class PersonelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonelDialog(QWidget *parent = 0);
    ~PersonelDialog();

private slots:
    void on_pushButton_Save_clicked();

private:
    Ui::PersonelDialog *ui;
};

#endif // PERSONELDIALOG_H
