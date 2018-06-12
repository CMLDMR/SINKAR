/********************************************************************************
** Form generated from reading UI file 'malzemeselectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MALZEMESELECTDIALOG_H
#define UI_MALZEMESELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MalzemeSelectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox_KategoriFilter;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_iptal;

    void setupUi(QDialog *MalzemeSelectDialog)
    {
        if (MalzemeSelectDialog->objectName().isEmpty())
            MalzemeSelectDialog->setObjectName(QStringLiteral("MalzemeSelectDialog"));
        MalzemeSelectDialog->resize(281, 412);
        verticalLayout = new QVBoxLayout(MalzemeSelectDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MalzemeSelectDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        comboBox_KategoriFilter = new QComboBox(MalzemeSelectDialog);
        comboBox_KategoriFilter->setObjectName(QStringLiteral("comboBox_KategoriFilter"));

        verticalLayout->addWidget(comboBox_KategoriFilter);

        listView = new QListView(MalzemeSelectDialog);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_iptal = new QPushButton(MalzemeSelectDialog);
        pushButton_iptal->setObjectName(QStringLiteral("pushButton_iptal"));

        horizontalLayout->addWidget(pushButton_iptal);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MalzemeSelectDialog);

        QMetaObject::connectSlotsByName(MalzemeSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *MalzemeSelectDialog)
    {
        MalzemeSelectDialog->setWindowTitle(QApplication::translate("MalzemeSelectDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("MalzemeSelectDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Malzeme Se\303\247</span></p></body></html>", nullptr));
        pushButton_iptal->setText(QApplication::translate("MalzemeSelectDialog", "\304\260ptal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MalzemeSelectDialog: public Ui_MalzemeSelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MALZEMESELECTDIALOG_H
