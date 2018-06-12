/********************************************************************************
** Form generated from reading UI file 'malzemegirdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MALZEMEGIRDIALOG_H
#define UI_MALZEMEGIRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MalzemeGirDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *doubleSpinBox_birimFiyati;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_MalzemeAdi;
    QPushButton *pushButton_SelectMalzeme;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_Kategori;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_miktar;
    QComboBox *comboBox_selectDepo;
    QLabel *label_15;
    QLabel *label_14;
    QLineEdit *lineEdit_birimi;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_ToplamTutar;
    QLabel *label;
    QLineEdit *lineEdit_malzemeKodu;
    QLabel *label_11;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBox_indirimMiktari;
    QDoubleSpinBox *doubleSpinBox_KDV;
    QLabel *label_17;
    QLabel *label_19;
    QLineEdit *lineEdit_kategoriKodu;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_faturaSeri;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_faturaNO;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_CariKodu;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_7;
    QComboBox *comboBox_faturaTipi;
    QDateEdit *dateEdit_faturaTarihi;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_9;
    QLineEdit *lineEdit_FirmaAdi;
    QLineEdit *lineEdit_FirmaAdi_oid;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_save;
    QLabel *label_status;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *MalzemeGirDialog)
    {
        if (MalzemeGirDialog->objectName().isEmpty())
            MalzemeGirDialog->setObjectName(QStringLiteral("MalzemeGirDialog"));
        MalzemeGirDialog->resize(334, 592);
        verticalLayout_4 = new QVBoxLayout(MalzemeGirDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_18 = new QLabel(MalzemeGirDialog);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_4->addWidget(label_18);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(MalzemeGirDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        doubleSpinBox_birimFiyati = new QDoubleSpinBox(groupBox);
        doubleSpinBox_birimFiyati->setObjectName(QStringLiteral("doubleSpinBox_birimFiyati"));
        doubleSpinBox_birimFiyati->setEnabled(false);
        doubleSpinBox_birimFiyati->setMaximum(1e+8);

        gridLayout_2->addWidget(doubleSpinBox_birimFiyati, 7, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lineEdit_MalzemeAdi = new QLineEdit(groupBox);
        lineEdit_MalzemeAdi->setObjectName(QStringLiteral("lineEdit_MalzemeAdi"));

        horizontalLayout_7->addWidget(lineEdit_MalzemeAdi);

        pushButton_SelectMalzeme = new QPushButton(groupBox);
        pushButton_SelectMalzeme->setObjectName(QStringLiteral("pushButton_SelectMalzeme"));

        horizontalLayout_7->addWidget(pushButton_SelectMalzeme);


        gridLayout_2->addLayout(horizontalLayout_7, 3, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lineEdit_Kategori = new QLineEdit(groupBox);
        lineEdit_Kategori->setObjectName(QStringLiteral("lineEdit_Kategori"));

        horizontalLayout_6->addWidget(lineEdit_Kategori);


        gridLayout_2->addLayout(horizontalLayout_6, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 5, 0, 1, 1);

        doubleSpinBox_miktar = new QDoubleSpinBox(groupBox);
        doubleSpinBox_miktar->setObjectName(QStringLiteral("doubleSpinBox_miktar"));
        doubleSpinBox_miktar->setMaximum(1e+8);

        gridLayout_2->addWidget(doubleSpinBox_miktar, 5, 1, 1, 1);

        comboBox_selectDepo = new QComboBox(groupBox);
        comboBox_selectDepo->setObjectName(QStringLiteral("comboBox_selectDepo"));

        gridLayout_2->addWidget(comboBox_selectDepo, 4, 1, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_2->addWidget(label_15, 8, 0, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 7, 0, 1, 1);

        lineEdit_birimi = new QLineEdit(groupBox);
        lineEdit_birimi->setObjectName(QStringLiteral("lineEdit_birimi"));
        lineEdit_birimi->setEnabled(false);

        gridLayout_2->addWidget(lineEdit_birimi, 6, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 6, 0, 1, 1);

        doubleSpinBox_ToplamTutar = new QDoubleSpinBox(groupBox);
        doubleSpinBox_ToplamTutar->setObjectName(QStringLiteral("doubleSpinBox_ToplamTutar"));
        doubleSpinBox_ToplamTutar->setMaximum(1e+17);

        gridLayout_2->addWidget(doubleSpinBox_ToplamTutar, 8, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit_malzemeKodu = new QLineEdit(groupBox);
        lineEdit_malzemeKodu->setObjectName(QStringLiteral("lineEdit_malzemeKodu"));
        lineEdit_malzemeKodu->setEnabled(false);

        gridLayout_2->addWidget(lineEdit_malzemeKodu, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 4, 0, 1, 1);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_2->addWidget(label_16, 9, 0, 1, 1);

        doubleSpinBox_indirimMiktari = new QDoubleSpinBox(groupBox);
        doubleSpinBox_indirimMiktari->setObjectName(QStringLiteral("doubleSpinBox_indirimMiktari"));
        doubleSpinBox_indirimMiktari->setMaximum(1e+14);

        gridLayout_2->addWidget(doubleSpinBox_indirimMiktari, 9, 1, 1, 1);

        doubleSpinBox_KDV = new QDoubleSpinBox(groupBox);
        doubleSpinBox_KDV->setObjectName(QStringLiteral("doubleSpinBox_KDV"));
        doubleSpinBox_KDV->setEnabled(false);
        QFont font;
        font.setKerning(true);
        doubleSpinBox_KDV->setFont(font);
        doubleSpinBox_KDV->setMaximum(1e+13);

        gridLayout_2->addWidget(doubleSpinBox_KDV, 10, 1, 1, 1);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 10, 0, 1, 1);

        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 1, 0, 1, 1);

        lineEdit_kategoriKodu = new QLineEdit(groupBox);
        lineEdit_kategoriKodu->setObjectName(QStringLiteral("lineEdit_kategoriKodu"));
        lineEdit_kategoriKodu->setEnabled(false);

        gridLayout_2->addWidget(lineEdit_kategoriKodu, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MalzemeGirDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        lineEdit_faturaSeri = new QLineEdit(groupBox_2);
        lineEdit_faturaSeri->setObjectName(QStringLiteral("lineEdit_faturaSeri"));

        horizontalLayout->addWidget(lineEdit_faturaSeri);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_faturaNO = new QLineEdit(groupBox_2);
        lineEdit_faturaNO->setObjectName(QStringLiteral("lineEdit_faturaNO"));

        horizontalLayout_2->addWidget(lineEdit_faturaNO);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 3, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit_CariKodu = new QLineEdit(groupBox_2);
        lineEdit_CariKodu->setObjectName(QStringLiteral("lineEdit_CariKodu"));
        lineEdit_CariKodu->setEnabled(false);

        horizontalLayout_4->addWidget(lineEdit_CariKodu);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_4, 6, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        comboBox_faturaTipi = new QComboBox(groupBox_2);
        comboBox_faturaTipi->addItem(QString());
        comboBox_faturaTipi->addItem(QString());
        comboBox_faturaTipi->setObjectName(QStringLiteral("comboBox_faturaTipi"));

        gridLayout->addWidget(comboBox_faturaTipi, 5, 1, 1, 1);

        dateEdit_faturaTarihi = new QDateEdit(groupBox_2);
        dateEdit_faturaTarihi->setObjectName(QStringLiteral("dateEdit_faturaTarihi"));
        dateEdit_faturaTarihi->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_faturaTarihi, 4, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 6, 0, 1, 1);

        lineEdit_FirmaAdi = new QLineEdit(groupBox_2);
        lineEdit_FirmaAdi->setObjectName(QStringLiteral("lineEdit_FirmaAdi"));
        lineEdit_FirmaAdi->setEnabled(false);

        gridLayout->addWidget(lineEdit_FirmaAdi, 7, 1, 1, 1);

        lineEdit_FirmaAdi_oid = new QLineEdit(groupBox_2);
        lineEdit_FirmaAdi_oid->setObjectName(QStringLiteral("lineEdit_FirmaAdi_oid"));
        lineEdit_FirmaAdi_oid->setEnabled(false);

        gridLayout->addWidget(lineEdit_FirmaAdi_oid, 8, 1, 1, 1);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout->addWidget(label_20, 8, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_cancel = new QPushButton(MalzemeGirDialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"font: 75 10pt \"Tahoma\";\n"
"text-decoration: underline;"));

        horizontalLayout_5->addWidget(pushButton_cancel);

        pushButton_save = new QPushButton(MalzemeGirDialog);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setStyleSheet(QLatin1String("font: 75 10pt \"Tahoma\";\n"
"text-decoration: underline;\n"
"color: rgb(85, 200, 127);"));

        horizontalLayout_5->addWidget(pushButton_save);


        verticalLayout_4->addLayout(horizontalLayout_5);

        label_status = new QLabel(MalzemeGirDialog);
        label_status->setObjectName(QStringLiteral("label_status"));

        verticalLayout_4->addWidget(label_status);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        retranslateUi(MalzemeGirDialog);

        QMetaObject::connectSlotsByName(MalzemeGirDialog);
    } // setupUi

    void retranslateUi(QDialog *MalzemeGirDialog)
    {
        MalzemeGirDialog->setWindowTitle(QApplication::translate("MalzemeGirDialog", "Dialog", nullptr));
        label_18->setText(QApplication::translate("MalzemeGirDialog", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Malzeme Giri\305\237i</span></p></body></html>", nullptr));
        groupBox->setTitle(QApplication::translate("MalzemeGirDialog", "Malzeme Bilgiler", nullptr));
        pushButton_SelectMalzeme->setText(QApplication::translate("MalzemeGirDialog", "+", nullptr));
        label_2->setText(QApplication::translate("MalzemeGirDialog", "Kategori", nullptr));
        label_3->setText(QApplication::translate("MalzemeGirDialog", "Malzeme Ad\304\261", nullptr));
        label_12->setText(QApplication::translate("MalzemeGirDialog", "Miktar", nullptr));
        label_15->setText(QApplication::translate("MalzemeGirDialog", "Toplam Tutar", nullptr));
        label_14->setText(QApplication::translate("MalzemeGirDialog", "Birim Fiyat\304\261", nullptr));
        label_13->setText(QApplication::translate("MalzemeGirDialog", "Birimi", nullptr));
        label->setText(QApplication::translate("MalzemeGirDialog", "Malzeme Kodu", nullptr));
        label_11->setText(QApplication::translate("MalzemeGirDialog", "Depo", nullptr));
        label_16->setText(QApplication::translate("MalzemeGirDialog", "\304\260skonto  indirimi", nullptr));
        label_17->setText(QApplication::translate("MalzemeGirDialog", "KDV", nullptr));
        label_19->setText(QApplication::translate("MalzemeGirDialog", "Kategori Kodu", nullptr));
        groupBox_2->setTitle(QApplication::translate("MalzemeGirDialog", "Fatura Bilgileri", nullptr));
        label_5->setText(QApplication::translate("MalzemeGirDialog", "Seri", nullptr));
        label_6->setText(QApplication::translate("MalzemeGirDialog", "No", nullptr));
        pushButton->setText(QApplication::translate("MalzemeGirDialog", "+", nullptr));
        label_4->setText(QApplication::translate("MalzemeGirDialog", "Fatura No", nullptr));
        label_7->setText(QApplication::translate("MalzemeGirDialog", "Fatura Tarihi", nullptr));
        comboBox_faturaTipi->setItemText(0, QApplication::translate("MalzemeGirDialog", "iade", nullptr));
        comboBox_faturaTipi->setItemText(1, QApplication::translate("MalzemeGirDialog", "Normal", nullptr));

        label_8->setText(QApplication::translate("MalzemeGirDialog", "Fatura Tipi", nullptr));
        label_10->setText(QApplication::translate("MalzemeGirDialog", "Firman\304\261n Ad\304\261", nullptr));
        label_9->setText(QApplication::translate("MalzemeGirDialog", "Firman\304\261n Cari Kodu", nullptr));
        label_20->setText(QApplication::translate("MalzemeGirDialog", "Firman\304\261n Oid", nullptr));
        pushButton_cancel->setText(QApplication::translate("MalzemeGirDialog", "\304\260ptal", nullptr));
        pushButton_save->setText(QApplication::translate("MalzemeGirDialog", "Kaydet", nullptr));
        label_status->setText(QApplication::translate("MalzemeGirDialog", "status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MalzemeGirDialog: public Ui_MalzemeGirDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MALZEMEGIRDIALOG_H
