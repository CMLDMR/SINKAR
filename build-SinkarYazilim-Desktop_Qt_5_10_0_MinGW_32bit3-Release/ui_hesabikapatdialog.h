/********************************************************************************
** Form generated from reading UI file 'hesabikapatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HESABIKAPATDIALOG_H
#define UI_HESABIKAPATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HesabiKapatDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_Nakit;
    QPushButton *pushButton_TamamiNakit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_KrediKarti;
    QPushButton *pushButton_TamamiKrediKarti;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_Odenen;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *label_ToplamMiktar;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLabel *label_ToplamMiktarIND;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLabel *label_KalanMiktar;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_CariHesabaAt;
    QPushButton *pushButton_masayiKapat;
    QPushButton *pushButton_OdemeIptal;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *HesabiKapatDialog)
    {
        if (HesabiKapatDialog->objectName().isEmpty())
            HesabiKapatDialog->setObjectName(QStringLiteral("HesabiKapatDialog"));
        HesabiKapatDialog->resize(347, 217);
        verticalLayout_3 = new QVBoxLayout(HesabiKapatDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(HesabiKapatDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBox_Nakit = new QDoubleSpinBox(groupBox);
        doubleSpinBox_Nakit->setObjectName(QStringLiteral("doubleSpinBox_Nakit"));
        doubleSpinBox_Nakit->setMaximum(1e+16);

        horizontalLayout->addWidget(doubleSpinBox_Nakit);

        pushButton_TamamiNakit = new QPushButton(groupBox);
        pushButton_TamamiNakit->setObjectName(QStringLiteral("pushButton_TamamiNakit"));

        horizontalLayout->addWidget(pushButton_TamamiNakit);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(HesabiKapatDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_KrediKarti = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_KrediKarti->setObjectName(QStringLiteral("doubleSpinBox_KrediKarti"));
        doubleSpinBox_KrediKarti->setMaximum(1e+16);

        horizontalLayout_2->addWidget(doubleSpinBox_KrediKarti);

        pushButton_TamamiKrediKarti = new QPushButton(groupBox_2);
        pushButton_TamamiKrediKarti->setObjectName(QStringLiteral("pushButton_TamamiKrediKarti"));

        horizontalLayout_2->addWidget(pushButton_TamamiKrediKarti);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(HesabiKapatDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        doubleSpinBox_Odenen = new QDoubleSpinBox(HesabiKapatDialog);
        doubleSpinBox_Odenen->setObjectName(QStringLiteral("doubleSpinBox_Odenen"));
        doubleSpinBox_Odenen->setMaximum(1e+16);

        horizontalLayout_4->addWidget(doubleSpinBox_Odenen);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(HesabiKapatDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        label_ToplamMiktar = new QLabel(HesabiKapatDialog);
        label_ToplamMiktar->setObjectName(QStringLiteral("label_ToplamMiktar"));

        horizontalLayout_5->addWidget(label_ToplamMiktar);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(HesabiKapatDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_8->addWidget(label_7);

        label_ToplamMiktarIND = new QLabel(HesabiKapatDialog);
        label_ToplamMiktarIND->setObjectName(QStringLiteral("label_ToplamMiktarIND"));

        horizontalLayout_8->addWidget(label_ToplamMiktarIND);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(HesabiKapatDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        label_KalanMiktar = new QLabel(HesabiKapatDialog);
        label_KalanMiktar->setObjectName(QStringLiteral("label_KalanMiktar"));

        horizontalLayout_6->addWidget(label_KalanMiktar);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_CariHesabaAt = new QPushButton(HesabiKapatDialog);
        pushButton_CariHesabaAt->setObjectName(QStringLiteral("pushButton_CariHesabaAt"));

        horizontalLayout_3->addWidget(pushButton_CariHesabaAt);

        pushButton_masayiKapat = new QPushButton(HesabiKapatDialog);
        pushButton_masayiKapat->setObjectName(QStringLiteral("pushButton_masayiKapat"));

        horizontalLayout_3->addWidget(pushButton_masayiKapat);

        pushButton_OdemeIptal = new QPushButton(HesabiKapatDialog);
        pushButton_OdemeIptal->setObjectName(QStringLiteral("pushButton_OdemeIptal"));

        horizontalLayout_3->addWidget(pushButton_OdemeIptal);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(HesabiKapatDialog);

        QMetaObject::connectSlotsByName(HesabiKapatDialog);
    } // setupUi

    void retranslateUi(QDialog *HesabiKapatDialog)
    {
        HesabiKapatDialog->setWindowTitle(QApplication::translate("HesabiKapatDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("HesabiKapatDialog", "Nakit", nullptr));
        label->setText(QApplication::translate("HesabiKapatDialog", "Nakit Miktar", nullptr));
        pushButton_TamamiNakit->setText(QApplication::translate("HesabiKapatDialog", "Tamam\304\261 Nakit", nullptr));
        groupBox_2->setTitle(QApplication::translate("HesabiKapatDialog", "Kredi Kart\304\261", nullptr));
        label_2->setText(QApplication::translate("HesabiKapatDialog", "Kredi Kart\304\261", nullptr));
        pushButton_TamamiKrediKarti->setText(QApplication::translate("HesabiKapatDialog", "Tamam\304\261 Kredi Kart\304\261", nullptr));
        label_4->setText(QApplication::translate("HesabiKapatDialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">\303\226denen</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("HesabiKapatDialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Toplam Miktar</span></p></body></html>", nullptr));
        label_ToplamMiktar->setText(QApplication::translate("HesabiKapatDialog", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("HesabiKapatDialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">IND Miktar</span></p></body></html>", nullptr));
        label_ToplamMiktarIND->setText(QApplication::translate("HesabiKapatDialog", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("HesabiKapatDialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Kalan Miktar</span></p></body></html>", nullptr));
        label_KalanMiktar->setText(QApplication::translate("HesabiKapatDialog", "0", nullptr));
        pushButton_CariHesabaAt->setText(QApplication::translate("HesabiKapatDialog", "Cari Hesaba At", nullptr));
        pushButton_masayiKapat->setText(QApplication::translate("HesabiKapatDialog", "Hesab\304\261 Kapat", nullptr));
        pushButton_OdemeIptal->setText(QApplication::translate("HesabiKapatDialog", "\304\260ptal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HesabiKapatDialog: public Ui_HesabiKapatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HESABIKAPATDIALOG_H
