/********************************************************************************
** Form generated from reading UI file 'malzemekalemidialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MALZEMEKALEMIDIALOG_H
#define UI_MALZEMEKALEMIDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_MalzemeKalemiDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QListView *listView_kategori;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_deleteKategori;
    QPushButton *pushButton_refreshKategori;
    QPushButton *pushButton_NewKategori;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QListView *listView_malzeme;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_refreshMalzeme;
    QPushButton *pushButton_NewMalzeme;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEdit_MalzemeOid;
    QLabel *label_5;
    QLineEdit *lineEdit_MalzemeName;
    QLineEdit *lineEdit_MalzemeBirimi;
    QLabel *label_3;
    QLabel *label;
    QComboBox *comboBox_MalzemeKategori;
    QDoubleSpinBox *doubleSpinBox_MalzemeComboBox;
    QLineEdit *lineEdit_KategoriOid;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_fiyat;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_SaveMalzeme;
    QPushButton *pushButton_deleteMalzeme;
    QPushButton *pushButtoClose;
    QLabel *label_status;

    void setupUi(QDialog *MalzemeKalemiDialog)
    {
        if (MalzemeKalemiDialog->objectName().isEmpty())
            MalzemeKalemiDialog->setObjectName(QStringLiteral("MalzemeKalemiDialog"));
        MalzemeKalemiDialog->resize(766, 375);
        verticalLayout_4 = new QVBoxLayout(MalzemeKalemiDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(MalzemeKalemiDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listView_kategori = new QListView(groupBox_2);
        listView_kategori->setObjectName(QStringLiteral("listView_kategori"));

        verticalLayout_2->addWidget(listView_kategori);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_deleteKategori = new QPushButton(groupBox_2);
        pushButton_deleteKategori->setObjectName(QStringLiteral("pushButton_deleteKategori"));

        horizontalLayout->addWidget(pushButton_deleteKategori);

        pushButton_refreshKategori = new QPushButton(groupBox_2);
        pushButton_refreshKategori->setObjectName(QStringLiteral("pushButton_refreshKategori"));

        horizontalLayout->addWidget(pushButton_refreshKategori);

        pushButton_NewKategori = new QPushButton(groupBox_2);
        pushButton_NewKategori->setObjectName(QStringLiteral("pushButton_NewKategori"));

        horizontalLayout->addWidget(pushButton_NewKategori);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(MalzemeKalemiDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        listView_malzeme = new QListView(groupBox_3);
        listView_malzeme->setObjectName(QStringLiteral("listView_malzeme"));

        verticalLayout_3->addWidget(listView_malzeme);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_refreshMalzeme = new QPushButton(groupBox_3);
        pushButton_refreshMalzeme->setObjectName(QStringLiteral("pushButton_refreshMalzeme"));

        horizontalLayout_2->addWidget(pushButton_refreshMalzeme);

        pushButton_NewMalzeme = new QPushButton(groupBox_3);
        pushButton_NewMalzeme->setObjectName(QStringLiteral("pushButton_NewMalzeme"));

        horizontalLayout_2->addWidget(pushButton_NewMalzeme);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(groupBox_3);

        groupBox = new QGroupBox(MalzemeKalemiDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_MalzemeOid = new QLineEdit(groupBox);
        lineEdit_MalzemeOid->setObjectName(QStringLiteral("lineEdit_MalzemeOid"));
        lineEdit_MalzemeOid->setEnabled(false);

        gridLayout->addWidget(lineEdit_MalzemeOid, 0, 1, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        lineEdit_MalzemeName = new QLineEdit(groupBox);
        lineEdit_MalzemeName->setObjectName(QStringLiteral("lineEdit_MalzemeName"));

        gridLayout->addWidget(lineEdit_MalzemeName, 3, 1, 1, 2);

        lineEdit_MalzemeBirimi = new QLineEdit(groupBox);
        lineEdit_MalzemeBirimi->setObjectName(QStringLiteral("lineEdit_MalzemeBirimi"));

        gridLayout->addWidget(lineEdit_MalzemeBirimi, 4, 1, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_MalzemeKategori = new QComboBox(groupBox);
        comboBox_MalzemeKategori->setObjectName(QStringLiteral("comboBox_MalzemeKategori"));

        gridLayout->addWidget(comboBox_MalzemeKategori, 1, 1, 1, 2);

        doubleSpinBox_MalzemeComboBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox_MalzemeComboBox->setObjectName(QStringLiteral("doubleSpinBox_MalzemeComboBox"));

        gridLayout->addWidget(doubleSpinBox_MalzemeComboBox, 5, 1, 1, 2);

        lineEdit_KategoriOid = new QLineEdit(groupBox);
        lineEdit_KategoriOid->setObjectName(QStringLiteral("lineEdit_KategoriOid"));
        lineEdit_KategoriOid->setEnabled(false);

        gridLayout->addWidget(lineEdit_KategoriOid, 2, 1, 1, 2);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        doubleSpinBox_fiyat = new QDoubleSpinBox(groupBox);
        doubleSpinBox_fiyat->setObjectName(QStringLiteral("doubleSpinBox_fiyat"));

        gridLayout->addWidget(doubleSpinBox_fiyat, 6, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_SaveMalzeme = new QPushButton(groupBox);
        pushButton_SaveMalzeme->setObjectName(QStringLiteral("pushButton_SaveMalzeme"));

        verticalLayout->addWidget(pushButton_SaveMalzeme);

        pushButton_deleteMalzeme = new QPushButton(groupBox);
        pushButton_deleteMalzeme->setObjectName(QStringLiteral("pushButton_deleteMalzeme"));

        verticalLayout->addWidget(pushButton_deleteMalzeme);

        pushButtoClose = new QPushButton(groupBox);
        pushButtoClose->setObjectName(QStringLiteral("pushButtoClose"));

        verticalLayout->addWidget(pushButtoClose);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout_4->addLayout(horizontalLayout_3);

        label_status = new QLabel(MalzemeKalemiDialog);
        label_status->setObjectName(QStringLiteral("label_status"));

        verticalLayout_4->addWidget(label_status);


        retranslateUi(MalzemeKalemiDialog);
        QObject::connect(pushButtoClose, SIGNAL(clicked()), MalzemeKalemiDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(MalzemeKalemiDialog);
    } // setupUi

    void retranslateUi(QDialog *MalzemeKalemiDialog)
    {
        MalzemeKalemiDialog->setWindowTitle(QApplication::translate("MalzemeKalemiDialog", "Dialog", nullptr));
        groupBox_2->setTitle(QApplication::translate("MalzemeKalemiDialog", "Kategoriler", nullptr));
        pushButton_deleteKategori->setText(QApplication::translate("MalzemeKalemiDialog", "Sil", nullptr));
        pushButton_refreshKategori->setText(QApplication::translate("MalzemeKalemiDialog", "Yenile", nullptr));
        pushButton_NewKategori->setText(QApplication::translate("MalzemeKalemiDialog", "Yeni Kategori", nullptr));
        groupBox_3->setTitle(QApplication::translate("MalzemeKalemiDialog", "Malzemeler", nullptr));
        pushButton_refreshMalzeme->setText(QApplication::translate("MalzemeKalemiDialog", "Yenile", nullptr));
        pushButton_NewMalzeme->setText(QApplication::translate("MalzemeKalemiDialog", "Yeni Malzeme", nullptr));
        groupBox->setTitle(QApplication::translate("MalzemeKalemiDialog", "Malzeme Detaylar\304\261", nullptr));
        label_4->setText(QApplication::translate("MalzemeKalemiDialog", "Birimi", nullptr));
        label_2->setText(QApplication::translate("MalzemeKalemiDialog", "Kategori", nullptr));
        label_5->setText(QApplication::translate("MalzemeKalemiDialog", "KDV", nullptr));
        label_3->setText(QApplication::translate("MalzemeKalemiDialog", "Ad\304\261", nullptr));
        label->setText(QApplication::translate("MalzemeKalemiDialog", "Kodu", nullptr));
        label_6->setText(QApplication::translate("MalzemeKalemiDialog", "Kategori Kodu", nullptr));
        label_7->setText(QApplication::translate("MalzemeKalemiDialog", "Fiyat", nullptr));
        pushButton_SaveMalzeme->setText(QApplication::translate("MalzemeKalemiDialog", "Kaydet", nullptr));
        pushButton_deleteMalzeme->setText(QApplication::translate("MalzemeKalemiDialog", "Sil", nullptr));
        pushButtoClose->setText(QApplication::translate("MalzemeKalemiDialog", "Kapat", nullptr));
        label_status->setText(QApplication::translate("MalzemeKalemiDialog", "status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MalzemeKalemiDialog: public Ui_MalzemeKalemiDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MALZEMEKALEMIDIALOG_H
