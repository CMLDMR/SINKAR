/********************************************************************************
** Form generated from reading UI file 'kasamasadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KASAMASADIALOG_H
#define UI_KASAMASADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KasaMasaDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_BagliDepo;
    QListView *listView_kasaList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_deleteKasa;
    QPushButton *pushButton_refreshKasaList;
    QPushButton *pushButton_addNewKasa;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QListView *listView_MasaList;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_deleteMasa;
    QPushButton *pushButton_refreshMasaList;
    QPushButton *pushButton_addNewMasa;
    QPushButton *pushButton_Kapat;

    void setupUi(QDialog *KasaMasaDialog)
    {
        if (KasaMasaDialog->objectName().isEmpty())
            KasaMasaDialog->setObjectName(QStringLiteral("KasaMasaDialog"));
        KasaMasaDialog->resize(566, 462);
        verticalLayout_3 = new QVBoxLayout(KasaMasaDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox = new QGroupBox(KasaMasaDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_BagliDepo = new QComboBox(groupBox);
        comboBox_BagliDepo->setObjectName(QStringLiteral("comboBox_BagliDepo"));

        horizontalLayout->addWidget(comboBox_BagliDepo);


        verticalLayout->addLayout(horizontalLayout);

        listView_kasaList = new QListView(groupBox);
        listView_kasaList->setObjectName(QStringLiteral("listView_kasaList"));

        verticalLayout->addWidget(listView_kasaList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_deleteKasa = new QPushButton(groupBox);
        pushButton_deleteKasa->setObjectName(QStringLiteral("pushButton_deleteKasa"));
        QFont font1;
        font1.setPointSize(12);
        pushButton_deleteKasa->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_deleteKasa);

        pushButton_refreshKasaList = new QPushButton(groupBox);
        pushButton_refreshKasaList->setObjectName(QStringLiteral("pushButton_refreshKasaList"));
        pushButton_refreshKasaList->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_refreshKasaList);

        pushButton_addNewKasa = new QPushButton(groupBox);
        pushButton_addNewKasa->setObjectName(QStringLiteral("pushButton_addNewKasa"));
        pushButton_addNewKasa->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_addNewKasa);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(KasaMasaDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listView_MasaList = new QListView(groupBox_2);
        listView_MasaList->setObjectName(QStringLiteral("listView_MasaList"));

        verticalLayout_2->addWidget(listView_MasaList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_deleteMasa = new QPushButton(groupBox_2);
        pushButton_deleteMasa->setObjectName(QStringLiteral("pushButton_deleteMasa"));

        horizontalLayout_3->addWidget(pushButton_deleteMasa);

        pushButton_refreshMasaList = new QPushButton(groupBox_2);
        pushButton_refreshMasaList->setObjectName(QStringLiteral("pushButton_refreshMasaList"));

        horizontalLayout_3->addWidget(pushButton_refreshMasaList);

        pushButton_addNewMasa = new QPushButton(groupBox_2);
        pushButton_addNewMasa->setObjectName(QStringLiteral("pushButton_addNewMasa"));

        horizontalLayout_3->addWidget(pushButton_addNewMasa);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        pushButton_Kapat = new QPushButton(KasaMasaDialog);
        pushButton_Kapat->setObjectName(QStringLiteral("pushButton_Kapat"));

        verticalLayout_3->addWidget(pushButton_Kapat);


        retranslateUi(KasaMasaDialog);

        QMetaObject::connectSlotsByName(KasaMasaDialog);
    } // setupUi

    void retranslateUi(QDialog *KasaMasaDialog)
    {
        KasaMasaDialog->setWindowTitle(QApplication::translate("KasaMasaDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("KasaMasaDialog", "Kasalar", nullptr));
        label->setText(QApplication::translate("KasaMasaDialog", "Ba\304\237l\304\261 Depo", nullptr));
        pushButton_deleteKasa->setText(QApplication::translate("KasaMasaDialog", "Sil\342\235\214", nullptr));
        pushButton_refreshKasaList->setText(QApplication::translate("KasaMasaDialog", "\360\237\224\204", nullptr));
        pushButton_addNewKasa->setText(QApplication::translate("KasaMasaDialog", "Kasa\342\236\225", nullptr));
        groupBox_2->setTitle(QApplication::translate("KasaMasaDialog", "Masalar", nullptr));
        pushButton_deleteMasa->setText(QApplication::translate("KasaMasaDialog", "Sil\342\235\214", nullptr));
        pushButton_refreshMasaList->setText(QApplication::translate("KasaMasaDialog", "\360\237\224\204", nullptr));
        pushButton_addNewMasa->setText(QApplication::translate("KasaMasaDialog", "Masa\342\236\225", nullptr));
        pushButton_Kapat->setText(QApplication::translate("KasaMasaDialog", "Kapat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KasaMasaDialog: public Ui_KasaMasaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KASAMASADIALOG_H
