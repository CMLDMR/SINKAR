/********************************************************************************
** Form generated from reading UI file 'addfirmadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFIRMADIALOG_H
#define UI_ADDFIRMADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addFirmaDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_FirmaAdi;
    QLineEdit *lineEdit_CariKod;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_iptal;
    QPushButton *pushButton_save;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *addFirmaDialog)
    {
        if (addFirmaDialog->objectName().isEmpty())
            addFirmaDialog->setObjectName(QStringLiteral("addFirmaDialog"));
        addFirmaDialog->resize(256, 125);
        verticalLayout = new QVBoxLayout(addFirmaDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(addFirmaDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(addFirmaDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_FirmaAdi = new QLineEdit(addFirmaDialog);
        lineEdit_FirmaAdi->setObjectName(QStringLiteral("lineEdit_FirmaAdi"));

        gridLayout->addWidget(lineEdit_FirmaAdi, 1, 1, 1, 1);

        lineEdit_CariKod = new QLineEdit(addFirmaDialog);
        lineEdit_CariKod->setObjectName(QStringLiteral("lineEdit_CariKod"));

        gridLayout->addWidget(lineEdit_CariKod, 2, 1, 1, 1);

        label = new QLabel(addFirmaDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_iptal = new QPushButton(addFirmaDialog);
        pushButton_iptal->setObjectName(QStringLiteral("pushButton_iptal"));

        horizontalLayout->addWidget(pushButton_iptal);

        pushButton_save = new QPushButton(addFirmaDialog);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(addFirmaDialog);

        QMetaObject::connectSlotsByName(addFirmaDialog);
    } // setupUi

    void retranslateUi(QDialog *addFirmaDialog)
    {
        addFirmaDialog->setWindowTitle(QApplication::translate("addFirmaDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("addFirmaDialog", "Firma Ad\304\261", nullptr));
        label_3->setText(QApplication::translate("addFirmaDialog", "Cari Kodu", nullptr));
        label->setText(QApplication::translate("addFirmaDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Firma Olu\305\237tur</span></p></body></html>", nullptr));
        pushButton_iptal->setText(QApplication::translate("addFirmaDialog", "\304\260ptal", nullptr));
        pushButton_save->setText(QApplication::translate("addFirmaDialog", "Kaydet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addFirmaDialog: public Ui_addFirmaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFIRMADIALOG_H
