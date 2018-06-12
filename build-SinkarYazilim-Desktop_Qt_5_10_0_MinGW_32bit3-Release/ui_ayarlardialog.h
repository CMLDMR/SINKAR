/********************************************************************************
** Form generated from reading UI file 'ayarlardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AYARLARDIALOG_H
#define UI_AYARLARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AyarlarDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QPushButton *pushButton_depo;
    QPushButton *pushButton_malzeme;
    QPushButton *pushButton;
    QPushButton *pushButton_recete;
    QPushButton *pushButton_KasaMasa;
    QPushButton *pushButton_HariciGiderler;

    void setupUi(QDialog *AyarlarDialog)
    {
        if (AyarlarDialog->objectName().isEmpty())
            AyarlarDialog->setObjectName(QStringLiteral("AyarlarDialog"));
        AyarlarDialog->resize(565, 126);
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        AyarlarDialog->setFont(font);
        verticalLayout = new QVBoxLayout(AyarlarDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(AyarlarDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_depo = new QPushButton(AyarlarDialog);
        pushButton_depo->setObjectName(QStringLiteral("pushButton_depo"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_depo->sizePolicy().hasHeightForWidth());
        pushButton_depo->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_depo, 0, 0, 1, 1);

        pushButton_malzeme = new QPushButton(AyarlarDialog);
        pushButton_malzeme->setObjectName(QStringLiteral("pushButton_malzeme"));
        sizePolicy1.setHeightForWidth(pushButton_malzeme->sizePolicy().hasHeightForWidth());
        pushButton_malzeme->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_malzeme, 0, 1, 1, 1);

        pushButton = new QPushButton(AyarlarDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(9);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("color: rgb(255, 0, 4);\n"
"text-decoration: underline;\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));

        gridLayout->addWidget(pushButton, 0, 5, 1, 1);

        pushButton_recete = new QPushButton(AyarlarDialog);
        pushButton_recete->setObjectName(QStringLiteral("pushButton_recete"));
        sizePolicy1.setHeightForWidth(pushButton_recete->sizePolicy().hasHeightForWidth());
        pushButton_recete->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_recete, 0, 2, 1, 1);

        pushButton_KasaMasa = new QPushButton(AyarlarDialog);
        pushButton_KasaMasa->setObjectName(QStringLiteral("pushButton_KasaMasa"));
        sizePolicy1.setHeightForWidth(pushButton_KasaMasa->sizePolicy().hasHeightForWidth());
        pushButton_KasaMasa->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_KasaMasa, 0, 3, 1, 1);

        pushButton_HariciGiderler = new QPushButton(AyarlarDialog);
        pushButton_HariciGiderler->setObjectName(QStringLiteral("pushButton_HariciGiderler"));
        sizePolicy1.setHeightForWidth(pushButton_HariciGiderler->sizePolicy().hasHeightForWidth());
        pushButton_HariciGiderler->setSizePolicy(sizePolicy1);
        pushButton_HariciGiderler->setFlat(false);

        gridLayout->addWidget(pushButton_HariciGiderler, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(AyarlarDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), AyarlarDialog, SLOT(close()));

        pushButton_HariciGiderler->setDefault(false);


        QMetaObject::connectSlotsByName(AyarlarDialog);
    } // setupUi

    void retranslateUi(QDialog *AyarlarDialog)
    {
        AyarlarDialog->setWindowTitle(QApplication::translate("AyarlarDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("AyarlarDialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Ayarlar</span></p></body></html>", nullptr));
        pushButton_depo->setText(QApplication::translate("AyarlarDialog", "Depo\n"
"Ayarlar\304\261", nullptr));
        pushButton_malzeme->setText(QApplication::translate("AyarlarDialog", "Malzemeler", nullptr));
        pushButton->setText(QApplication::translate("AyarlarDialog", "Kapat", nullptr));
        pushButton_recete->setText(QApplication::translate("AyarlarDialog", "Re\303\247eteler", nullptr));
        pushButton_KasaMasa->setText(QApplication::translate("AyarlarDialog", "Kasa\n"
"Masalar", nullptr));
        pushButton_HariciGiderler->setText(QApplication::translate("AyarlarDialog", "Harici\n"
"Giderler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AyarlarDialog: public Ui_AyarlarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AYARLARDIALOG_H
