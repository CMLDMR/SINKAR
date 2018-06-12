/********************************************************************************
** Form generated from reading UI file 'addcarihesapdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCARIHESAPDIALOG_H
#define UI_ADDCARIHESAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addCariHesapDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_iletisim;
    QLabel *label_2;
    QLineEdit *lineEdit_ad;
    QLabel *label;
    QLineEdit *lineEdit_adres;
    QLabel *label_3;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *addCariHesapDialog)
    {
        if (addCariHesapDialog->objectName().isEmpty())
            addCariHesapDialog->setObjectName(QStringLiteral("addCariHesapDialog"));
        addCariHesapDialog->resize(400, 156);
        verticalLayout = new QVBoxLayout(addCariHesapDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_iletisim = new QLineEdit(addCariHesapDialog);
        lineEdit_iletisim->setObjectName(QStringLiteral("lineEdit_iletisim"));

        gridLayout->addWidget(lineEdit_iletisim, 1, 1, 1, 1);

        label_2 = new QLabel(addCariHesapDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_ad = new QLineEdit(addCariHesapDialog);
        lineEdit_ad->setObjectName(QStringLiteral("lineEdit_ad"));

        gridLayout->addWidget(lineEdit_ad, 0, 1, 1, 1);

        label = new QLabel(addCariHesapDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_adres = new QLineEdit(addCariHesapDialog);
        lineEdit_adres->setObjectName(QStringLiteral("lineEdit_adres"));

        gridLayout->addWidget(lineEdit_adres, 2, 1, 1, 1);

        label_3 = new QLabel(addCariHesapDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton_save = new QPushButton(addCariHesapDialog);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        verticalLayout->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(addCariHesapDialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        verticalLayout->addWidget(pushButton_cancel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QWidget::setTabOrder(lineEdit_ad, lineEdit_iletisim);
        QWidget::setTabOrder(lineEdit_iletisim, lineEdit_adres);
        QWidget::setTabOrder(lineEdit_adres, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_cancel);

        retranslateUi(addCariHesapDialog);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), addCariHesapDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(addCariHesapDialog);
    } // setupUi

    void retranslateUi(QDialog *addCariHesapDialog)
    {
        addCariHesapDialog->setWindowTitle(QApplication::translate("addCariHesapDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("addCariHesapDialog", "\304\260leti\305\237im", nullptr));
        label->setText(QApplication::translate("addCariHesapDialog", "Ad Soyad", nullptr));
        label_3->setText(QApplication::translate("addCariHesapDialog", "Adres", nullptr));
        pushButton_save->setText(QApplication::translate("addCariHesapDialog", "Kaydet", nullptr));
        pushButton_cancel->setText(QApplication::translate("addCariHesapDialog", "iptal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addCariHesapDialog: public Ui_addCariHesapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCARIHESAPDIALOG_H
