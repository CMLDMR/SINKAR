/********************************************************************************
** Form generated from reading UI file 'kasadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KASADIALOG_H
#define UI_KASADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KasaDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_minimize;
    QPushButton *pushButton_ToggleScreen;
    QPushButton *pushButton_close;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Kasa;
    QLineEdit *lineEdikasaOid;
    QLabel *label_Depo;
    QListView *listView_Masalar;
    QLabel *label_AcikMasa;
    QLabel *label_KapaliMasa;
    QLabel *label_Masainfo;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_selectedMasaOid;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_siparisOid;
    QListView *listView_siparisList;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_kasaToplami;
    QDoubleSpinBox *doubleSpinBox_toplamMiktar;
    QLabel *label_kasaToplami_2;
    QDoubleSpinBox *doubleSpinBox_toplamMiktar_ind;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_siparis_al;
    QPushButton *pushButton_masayiKapat;

    void setupUi(QDialog *KasaDialog)
    {
        if (KasaDialog->objectName().isEmpty())
            KasaDialog->setObjectName(QStringLiteral("KasaDialog"));
        KasaDialog->resize(1060, 573);
        verticalLayout_3 = new QVBoxLayout(KasaDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton_minimize = new QPushButton(KasaDialog);
        pushButton_minimize->setObjectName(QStringLiteral("pushButton_minimize"));
        pushButton_minimize->setMinimumSize(QSize(0, 30));
        pushButton_minimize->setMaximumSize(QSize(30, 16777215));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_minimize->setFont(font);

        horizontalLayout_4->addWidget(pushButton_minimize);

        pushButton_ToggleScreen = new QPushButton(KasaDialog);
        pushButton_ToggleScreen->setObjectName(QStringLiteral("pushButton_ToggleScreen"));
        pushButton_ToggleScreen->setMinimumSize(QSize(0, 30));
        pushButton_ToggleScreen->setMaximumSize(QSize(30, 16777215));
        pushButton_ToggleScreen->setFont(font);

        horizontalLayout_4->addWidget(pushButton_ToggleScreen);

        pushButton_close = new QPushButton(KasaDialog);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(0, 30));
        pushButton_close->setMaximumSize(QSize(30, 16777215));
        pushButton_close->setFont(font);

        horizontalLayout_4->addWidget(pushButton_close);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(KasaDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(350, 16777215));
        QFont font1;
        font1.setPointSize(10);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Kasa = new QLabel(groupBox);
        label_Kasa->setObjectName(QStringLiteral("label_Kasa"));

        horizontalLayout->addWidget(label_Kasa);

        lineEdikasaOid = new QLineEdit(groupBox);
        lineEdikasaOid->setObjectName(QStringLiteral("lineEdikasaOid"));
        lineEdikasaOid->setEnabled(false);

        horizontalLayout->addWidget(lineEdikasaOid);


        verticalLayout->addLayout(horizontalLayout);

        label_Depo = new QLabel(groupBox);
        label_Depo->setObjectName(QStringLiteral("label_Depo"));

        verticalLayout->addWidget(label_Depo);

        listView_Masalar = new QListView(groupBox);
        listView_Masalar->setObjectName(QStringLiteral("listView_Masalar"));
        listView_Masalar->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(listView_Masalar);

        label_AcikMasa = new QLabel(groupBox);
        label_AcikMasa->setObjectName(QStringLiteral("label_AcikMasa"));

        verticalLayout->addWidget(label_AcikMasa);

        label_KapaliMasa = new QLabel(groupBox);
        label_KapaliMasa->setObjectName(QStringLiteral("label_KapaliMasa"));

        verticalLayout->addWidget(label_KapaliMasa);

        label_Masainfo = new QLabel(groupBox);
        label_Masainfo->setObjectName(QStringLiteral("label_Masainfo"));

        verticalLayout->addWidget(label_Masainfo);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(KasaDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font1);
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_selectedMasaOid = new QLineEdit(groupBox_2);
        lineEdit_selectedMasaOid->setObjectName(QStringLiteral("lineEdit_selectedMasaOid"));
        lineEdit_selectedMasaOid->setEnabled(false);

        gridLayout->addWidget(lineEdit_selectedMasaOid, 0, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_siparisOid = new QLineEdit(groupBox_2);
        lineEdit_siparisOid->setObjectName(QStringLiteral("lineEdit_siparisOid"));
        lineEdit_siparisOid->setEnabled(false);

        gridLayout->addWidget(lineEdit_siparisOid, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        listView_siparisList = new QListView(groupBox_2);
        listView_siparisList->setObjectName(QStringLiteral("listView_siparisList"));
        listView_siparisList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_siparisList->setAlternatingRowColors(true);

        verticalLayout_2->addWidget(listView_siparisList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_kasaToplami = new QLabel(groupBox_2);
        label_kasaToplami->setObjectName(QStringLiteral("label_kasaToplami"));

        horizontalLayout_2->addWidget(label_kasaToplami);

        doubleSpinBox_toplamMiktar = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_toplamMiktar->setObjectName(QStringLiteral("doubleSpinBox_toplamMiktar"));
        doubleSpinBox_toplamMiktar->setEnabled(false);
        doubleSpinBox_toplamMiktar->setFont(font);
        doubleSpinBox_toplamMiktar->setMaximum(1e+11);

        horizontalLayout_2->addWidget(doubleSpinBox_toplamMiktar);

        label_kasaToplami_2 = new QLabel(groupBox_2);
        label_kasaToplami_2->setObjectName(QStringLiteral("label_kasaToplami_2"));

        horizontalLayout_2->addWidget(label_kasaToplami_2);

        doubleSpinBox_toplamMiktar_ind = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_toplamMiktar_ind->setObjectName(QStringLiteral("doubleSpinBox_toplamMiktar_ind"));
        doubleSpinBox_toplamMiktar_ind->setEnabled(false);
        doubleSpinBox_toplamMiktar_ind->setFont(font);
        doubleSpinBox_toplamMiktar_ind->setMaximum(1e+11);

        horizontalLayout_2->addWidget(doubleSpinBox_toplamMiktar_ind);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_siparis_al = new QPushButton(groupBox_2);
        pushButton_siparis_al->setObjectName(QStringLiteral("pushButton_siparis_al"));

        horizontalLayout_2->addWidget(pushButton_siparis_al);

        pushButton_masayiKapat = new QPushButton(groupBox_2);
        pushButton_masayiKapat->setObjectName(QStringLiteral("pushButton_masayiKapat"));

        horizontalLayout_2->addWidget(pushButton_masayiKapat);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(KasaDialog);

        QMetaObject::connectSlotsByName(KasaDialog);
    } // setupUi

    void retranslateUi(QDialog *KasaDialog)
    {
        KasaDialog->setWindowTitle(QApplication::translate("KasaDialog", "Dialog", nullptr));
        pushButton_minimize->setText(QApplication::translate("KasaDialog", "_", nullptr));
        pushButton_ToggleScreen->setText(QApplication::translate("KasaDialog", "O", nullptr));
        pushButton_close->setText(QApplication::translate("KasaDialog", "X", nullptr));
        groupBox->setTitle(QApplication::translate("KasaDialog", "Masalar", nullptr));
        label_Kasa->setText(QApplication::translate("KasaDialog", "Kasa", nullptr));
        label_Depo->setText(QApplication::translate("KasaDialog", "TextLabel", nullptr));
        label_AcikMasa->setText(QApplication::translate("KasaDialog", "A\303\247\304\261k Masa", nullptr));
        label_KapaliMasa->setText(QApplication::translate("KasaDialog", "Kapal\304\261 Masa", nullptr));
        label_Masainfo->setText(QApplication::translate("KasaDialog", "<html><head/><body><p><span style=\" font-weight:600;\"></span></p></body></html>", nullptr));
        groupBox_2->setTitle(QApplication::translate("KasaDialog", "Durum", nullptr));
        label->setText(QApplication::translate("KasaDialog", "MasaOid", nullptr));
        label_2->setText(QApplication::translate("KasaDialog", "Sipari\305\237Oid", nullptr));
        label_kasaToplami->setText(QApplication::translate("KasaDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Kasa Toplam\304\261</span></p></body></html>", nullptr));
        label_kasaToplami_2->setText(QApplication::translate("KasaDialog", "<html><head/><body><p><span style=\" font-weight:600;\">\304\260ND Toplam\304\261</span></p></body></html>", nullptr));
        pushButton_siparis_al->setText(QApplication::translate("KasaDialog", "Sipari\305\237 Al/Ekle", nullptr));
        pushButton_masayiKapat->setText(QApplication::translate("KasaDialog", "Hesab\304\261/Masay\304\261 Kapat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KasaDialog: public Ui_KasaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KASADIALOG_H
