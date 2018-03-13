/********************************************************************************
** Form generated from reading UI file 'recetedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECETEDIALOG_H
#define UI_RECETEDIALOG_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReceteDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_delRecete;
    QPushButton *pushButton_refreshRecete;
    QPushButton *pushButton_addNew;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_karmarji;
    QDoubleSpinBox *doubleSpinBox_newFiyat;
    QLineEdit *lineEdit_receteAdi;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *lineEdit_receteid;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_recete_kdv;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_ReceteKat;
    QPushButton *pushButton_addreceteKategori;
    QLineEdit *lineEdit_receteBirimi;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_Maliyet;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListView *listView_MalzemeList;
    QPushButton *pushButton_addMalzeme;
    QPushButton *pushButton_receteSave;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_status;
    QPushButton *pushButton_kapat;

    void setupUi(QDialog *ReceteDialog)
    {
        if (ReceteDialog->objectName().isEmpty())
            ReceteDialog->setObjectName(QStringLiteral("ReceteDialog"));
        ReceteDialog->resize(878, 656);
        verticalLayout_4 = new QVBoxLayout(ReceteDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(ReceteDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(250, 16777215));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listView = new QListView(groupBox);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_delRecete = new QPushButton(groupBox);
        pushButton_delRecete->setObjectName(QStringLiteral("pushButton_delRecete"));

        horizontalLayout->addWidget(pushButton_delRecete);

        pushButton_refreshRecete = new QPushButton(groupBox);
        pushButton_refreshRecete->setObjectName(QStringLiteral("pushButton_refreshRecete"));

        horizontalLayout->addWidget(pushButton_refreshRecete);

        pushButton_addNew = new QPushButton(groupBox);
        pushButton_addNew->setObjectName(QStringLiteral("pushButton_addNew"));

        horizontalLayout->addWidget(pushButton_addNew);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addWidget(groupBox);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(ReceteDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_8 = new QLabel(ReceteDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        doubleSpinBox_karmarji = new QDoubleSpinBox(ReceteDialog);
        doubleSpinBox_karmarji->setObjectName(QStringLiteral("doubleSpinBox_karmarji"));

        gridLayout->addWidget(doubleSpinBox_karmarji, 6, 1, 1, 1);

        doubleSpinBox_newFiyat = new QDoubleSpinBox(ReceteDialog);
        doubleSpinBox_newFiyat->setObjectName(QStringLiteral("doubleSpinBox_newFiyat"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        doubleSpinBox_newFiyat->setFont(font);
        doubleSpinBox_newFiyat->setReadOnly(true);
        doubleSpinBox_newFiyat->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_newFiyat->setMaximum(1e+9);

        gridLayout->addWidget(doubleSpinBox_newFiyat, 7, 1, 1, 1);

        lineEdit_receteAdi = new QLineEdit(ReceteDialog);
        lineEdit_receteAdi->setObjectName(QStringLiteral("lineEdit_receteAdi"));

        gridLayout->addWidget(lineEdit_receteAdi, 2, 1, 1, 1);

        label_2 = new QLabel(ReceteDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(ReceteDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_4 = new QLabel(ReceteDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_receteid = new QLineEdit(ReceteDialog);
        lineEdit_receteid->setObjectName(QStringLiteral("lineEdit_receteid"));
        lineEdit_receteid->setEnabled(false);

        gridLayout->addWidget(lineEdit_receteid, 1, 1, 1, 1);

        label_6 = new QLabel(ReceteDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        label_7 = new QLabel(ReceteDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        doubleSpinBox_recete_kdv = new QDoubleSpinBox(ReceteDialog);
        doubleSpinBox_recete_kdv->setObjectName(QStringLiteral("doubleSpinBox_recete_kdv"));

        gridLayout->addWidget(doubleSpinBox_recete_kdv, 5, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox_ReceteKat = new QComboBox(ReceteDialog);
        comboBox_ReceteKat->setObjectName(QStringLiteral("comboBox_ReceteKat"));

        horizontalLayout_2->addWidget(comboBox_ReceteKat);

        pushButton_addreceteKategori = new QPushButton(ReceteDialog);
        pushButton_addreceteKategori->setObjectName(QStringLiteral("pushButton_addreceteKategori"));
        pushButton_addreceteKategori->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(pushButton_addreceteKategori);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        lineEdit_receteBirimi = new QLineEdit(ReceteDialog);
        lineEdit_receteBirimi->setObjectName(QStringLiteral("lineEdit_receteBirimi"));

        gridLayout->addWidget(lineEdit_receteBirimi, 3, 1, 1, 1);

        label_9 = new QLabel(ReceteDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        doubleSpinBox_Maliyet = new QDoubleSpinBox(ReceteDialog);
        doubleSpinBox_Maliyet->setObjectName(QStringLiteral("doubleSpinBox_Maliyet"));
        doubleSpinBox_Maliyet->setReadOnly(true);
        doubleSpinBox_Maliyet->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_Maliyet->setMaximum(1e+13);

        gridLayout->addWidget(doubleSpinBox_Maliyet, 4, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(ReceteDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        listView_MalzemeList = new QListView(ReceteDialog);
        listView_MalzemeList->setObjectName(QStringLiteral("listView_MalzemeList"));
        listView_MalzemeList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_MalzemeList->setAlternatingRowColors(true);
        listView_MalzemeList->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(listView_MalzemeList);

        pushButton_addMalzeme = new QPushButton(ReceteDialog);
        pushButton_addMalzeme->setObjectName(QStringLiteral("pushButton_addMalzeme"));

        verticalLayout_2->addWidget(pushButton_addMalzeme);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton_receteSave = new QPushButton(ReceteDialog);
        pushButton_receteSave->setObjectName(QStringLiteral("pushButton_receteSave"));

        verticalLayout_3->addWidget(pushButton_receteSave);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_status = new QLabel(ReceteDialog);
        label_status->setObjectName(QStringLiteral("label_status"));

        horizontalLayout_4->addWidget(label_status);

        pushButton_kapat = new QPushButton(ReceteDialog);
        pushButton_kapat->setObjectName(QStringLiteral("pushButton_kapat"));
        pushButton_kapat->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(pushButton_kapat);


        verticalLayout_4->addLayout(horizontalLayout_4);


        retranslateUi(ReceteDialog);

        QMetaObject::connectSlotsByName(ReceteDialog);
    } // setupUi

    void retranslateUi(QDialog *ReceteDialog)
    {
        ReceteDialog->setWindowTitle(QApplication::translate("ReceteDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("ReceteDialog", "Re\303\247eteler", nullptr));
        pushButton_delRecete->setText(QApplication::translate("ReceteDialog", "Sil", nullptr));
        pushButton_refreshRecete->setText(QApplication::translate("ReceteDialog", "Yenile", nullptr));
        pushButton_addNew->setText(QApplication::translate("ReceteDialog", "Yeni Ekle", nullptr));
        label_5->setText(QApplication::translate("ReceteDialog", "KDV", nullptr));
        label_8->setText(QApplication::translate("ReceteDialog", "Toplam Fiyat", nullptr));
        label_2->setText(QApplication::translate("ReceteDialog", "Re\303\247ete Ad\304\261", nullptr));
        label->setText(QApplication::translate("ReceteDialog", "Re\303\247ete id", nullptr));
        label_4->setText(QApplication::translate("ReceteDialog", "Re\303\247ete Kategorisi", nullptr));
        label_6->setText(QApplication::translate("ReceteDialog", "Maliyet", nullptr));
        label_7->setText(QApplication::translate("ReceteDialog", "Kar %", nullptr));
        pushButton_addreceteKategori->setText(QApplication::translate("ReceteDialog", "+", nullptr));
        label_9->setText(QApplication::translate("ReceteDialog", "Birimi", nullptr));
        label_3->setText(QApplication::translate("ReceteDialog", "Malzemeler", nullptr));
        pushButton_addMalzeme->setText(QApplication::translate("ReceteDialog", "Yeni Malzeme Ekle", nullptr));
        pushButton_receteSave->setText(QApplication::translate("ReceteDialog", "Kaydet", nullptr));
        label_status->setText(QApplication::translate("ReceteDialog", "status", nullptr));
        pushButton_kapat->setText(QApplication::translate("ReceteDialog", "Kapat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReceteDialog: public Ui_ReceteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECETEDIALOG_H
