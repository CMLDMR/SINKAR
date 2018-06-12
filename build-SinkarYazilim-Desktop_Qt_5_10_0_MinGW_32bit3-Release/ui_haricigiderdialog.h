/********************************************************************************
** Form generated from reading UI file 'haricigiderdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HARICIGIDERDIALOG_H
#define UI_HARICIGIDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HariciGiderDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *listView;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_GiderAdi;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_Miktar;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_ekle;

    void setupUi(QDialog *HariciGiderDialog)
    {
        if (HariciGiderDialog->objectName().isEmpty())
            HariciGiderDialog->setObjectName(QStringLiteral("HariciGiderDialog"));
        HariciGiderDialog->resize(292, 400);
        verticalLayout = new QVBoxLayout(HariciGiderDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(HariciGiderDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        listView = new QListView(HariciGiderDialog);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setAlternatingRowColors(true);

        verticalLayout->addWidget(listView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(HariciGiderDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_GiderAdi = new QLineEdit(HariciGiderDialog);
        lineEdit_GiderAdi->setObjectName(QStringLiteral("lineEdit_GiderAdi"));

        gridLayout->addWidget(lineEdit_GiderAdi, 0, 1, 1, 1);

        label_2 = new QLabel(HariciGiderDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        doubleSpinBox_Miktar = new QDoubleSpinBox(HariciGiderDialog);
        doubleSpinBox_Miktar->setObjectName(QStringLiteral("doubleSpinBox_Miktar"));
        doubleSpinBox_Miktar->setMaximum(1e+11);

        gridLayout->addWidget(doubleSpinBox_Miktar, 1, 1, 1, 1);

        label_3 = new QLabel(HariciGiderDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        dateEdit = new QDateEdit(HariciGiderDialog);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(HariciGiderDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_ekle = new QPushButton(HariciGiderDialog);
        pushButton_ekle->setObjectName(QStringLiteral("pushButton_ekle"));

        horizontalLayout_2->addWidget(pushButton_ekle);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(HariciGiderDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), HariciGiderDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(HariciGiderDialog);
    } // setupUi

    void retranslateUi(QDialog *HariciGiderDialog)
    {
        HariciGiderDialog->setWindowTitle(QApplication::translate("HariciGiderDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("HariciGiderDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Kategori Se\303\247</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("HariciGiderDialog", "Gider", nullptr));
        label_2->setText(QApplication::translate("HariciGiderDialog", "Miktar", nullptr));
        label_3->setText(QApplication::translate("HariciGiderDialog", "Tarih", nullptr));
        pushButton->setText(QApplication::translate("HariciGiderDialog", "\304\260ptal", nullptr));
        pushButton_ekle->setText(QApplication::translate("HariciGiderDialog", "Ekle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HariciGiderDialog: public Ui_HariciGiderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARICIGIDERDIALOG_H
