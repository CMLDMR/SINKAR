/********************************************************************************
** Form generated from reading UI file 'caridialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARIDIALOG_H
#define UI_CARIDIALOG_H

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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CariDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_ProxyFilter;
    QPushButton *pushButton_addKisi;
    QGridLayout *gridLayout;
    QLabel *label_ToplamMiktar;
    QRadioButton *radioButton_Normal;
    QLabel *label_ToplamMiktar_ind;
    QRadioButton *radioButton_indirimli;
    QListView *listView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_SelectKisi;
    QPushButton *pushButton_refereshList;
    QPushButton *pushButton_CloseDialog;

    void setupUi(QDialog *CariDialog)
    {
        if (CariDialog->objectName().isEmpty())
            CariDialog->setObjectName(QStringLiteral("CariDialog"));
        CariDialog->resize(353, 392);
        verticalLayout = new QVBoxLayout(CariDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(CariDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CariDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_ProxyFilter = new QLineEdit(CariDialog);
        lineEdit_ProxyFilter->setObjectName(QStringLiteral("lineEdit_ProxyFilter"));

        horizontalLayout->addWidget(lineEdit_ProxyFilter);

        pushButton_addKisi = new QPushButton(CariDialog);
        pushButton_addKisi->setObjectName(QStringLiteral("pushButton_addKisi"));
        pushButton_addKisi->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(pushButton_addKisi);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_ToplamMiktar = new QLabel(CariDialog);
        label_ToplamMiktar->setObjectName(QStringLiteral("label_ToplamMiktar"));

        gridLayout->addWidget(label_ToplamMiktar, 0, 0, 1, 1);

        radioButton_Normal = new QRadioButton(CariDialog);
        radioButton_Normal->setObjectName(QStringLiteral("radioButton_Normal"));

        gridLayout->addWidget(radioButton_Normal, 0, 1, 1, 1);

        label_ToplamMiktar_ind = new QLabel(CariDialog);
        label_ToplamMiktar_ind->setObjectName(QStringLiteral("label_ToplamMiktar_ind"));

        gridLayout->addWidget(label_ToplamMiktar_ind, 1, 0, 1, 1);

        radioButton_indirimli = new QRadioButton(CariDialog);
        radioButton_indirimli->setObjectName(QStringLiteral("radioButton_indirimli"));

        gridLayout->addWidget(radioButton_indirimli, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        listView = new QListView(CariDialog);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setAlternatingRowColors(true);
        listView->setSelectionRectVisible(true);

        verticalLayout->addWidget(listView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_SelectKisi = new QPushButton(CariDialog);
        pushButton_SelectKisi->setObjectName(QStringLiteral("pushButton_SelectKisi"));

        horizontalLayout_2->addWidget(pushButton_SelectKisi);

        pushButton_refereshList = new QPushButton(CariDialog);
        pushButton_refereshList->setObjectName(QStringLiteral("pushButton_refereshList"));

        horizontalLayout_2->addWidget(pushButton_refereshList);

        pushButton_CloseDialog = new QPushButton(CariDialog);
        pushButton_CloseDialog->setObjectName(QStringLiteral("pushButton_CloseDialog"));

        horizontalLayout_2->addWidget(pushButton_CloseDialog);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CariDialog);

        QMetaObject::connectSlotsByName(CariDialog);
    } // setupUi

    void retranslateUi(QDialog *CariDialog)
    {
        CariDialog->setWindowTitle(QApplication::translate("CariDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("CariDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Cari Hesaplar</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("CariDialog", "Filter", nullptr));
        pushButton_addKisi->setText(QApplication::translate("CariDialog", "+", nullptr));
        label_ToplamMiktar->setText(QApplication::translate("CariDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Toplam Miktar %1 TL</span></p></body></html>", nullptr));
        radioButton_Normal->setText(QApplication::translate("CariDialog", "Normal", nullptr));
        label_ToplamMiktar_ind->setText(QApplication::translate("CariDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Toplam Miktar %1 TL</span></p></body></html>", nullptr));
        radioButton_indirimli->setText(QApplication::translate("CariDialog", "\304\260ndirimli", nullptr));
        pushButton_SelectKisi->setText(QApplication::translate("CariDialog", "Se\303\247", nullptr));
        pushButton_refereshList->setText(QApplication::translate("CariDialog", "Yenile", nullptr));
        pushButton_CloseDialog->setText(QApplication::translate("CariDialog", "Kapat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CariDialog: public Ui_CariDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARIDIALOG_H
