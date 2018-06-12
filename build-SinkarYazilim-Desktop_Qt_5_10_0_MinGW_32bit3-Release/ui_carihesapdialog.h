/********************************************************************************
** Form generated from reading UI file 'carihesapdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARIHESAPDIALOG_H
#define UI_CARIHESAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CariHesapDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_OdemeAl;
    QPushButton *pushButton_Hesaplar;
    QPushButton *pushButton_Kapat;

    void setupUi(QDialog *CariHesapDialog)
    {
        if (CariHesapDialog->objectName().isEmpty())
            CariHesapDialog->setObjectName(QStringLiteral("CariHesapDialog"));
        CariHesapDialog->resize(350, 126);
        horizontalLayout = new QHBoxLayout(CariHesapDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_OdemeAl = new QPushButton(CariHesapDialog);
        pushButton_OdemeAl->setObjectName(QStringLiteral("pushButton_OdemeAl"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_OdemeAl->sizePolicy().hasHeightForWidth());
        pushButton_OdemeAl->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_OdemeAl, 0, 0, 1, 1);

        pushButton_Hesaplar = new QPushButton(CariHesapDialog);
        pushButton_Hesaplar->setObjectName(QStringLiteral("pushButton_Hesaplar"));
        sizePolicy.setHeightForWidth(pushButton_Hesaplar->sizePolicy().hasHeightForWidth());
        pushButton_Hesaplar->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_Hesaplar, 0, 1, 1, 1);

        pushButton_Kapat = new QPushButton(CariHesapDialog);
        pushButton_Kapat->setObjectName(QStringLiteral("pushButton_Kapat"));
        sizePolicy.setHeightForWidth(pushButton_Kapat->sizePolicy().hasHeightForWidth());
        pushButton_Kapat->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_Kapat, 0, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(CariHesapDialog);
        QObject::connect(pushButton_Kapat, SIGNAL(clicked()), CariHesapDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(CariHesapDialog);
    } // setupUi

    void retranslateUi(QDialog *CariHesapDialog)
    {
        CariHesapDialog->setWindowTitle(QApplication::translate("CariHesapDialog", "Dialog", nullptr));
        pushButton_OdemeAl->setText(QApplication::translate("CariHesapDialog", "\303\226deme Al", nullptr));
        pushButton_Hesaplar->setText(QApplication::translate("CariHesapDialog", "Hesaplar", nullptr));
        pushButton_Kapat->setText(QApplication::translate("CariHesapDialog", "Kapat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CariHesapDialog: public Ui_CariHesapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARIHESAPDIALOG_H
