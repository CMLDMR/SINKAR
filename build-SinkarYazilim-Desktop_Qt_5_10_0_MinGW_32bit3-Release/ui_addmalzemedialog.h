/********************************************************************************
** Form generated from reading UI file 'addmalzemedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMALZEMEDIALOG_H
#define UI_ADDMALZEMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addMalzemeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_Miktar;
    QComboBox *comboBox_miktarType;
    QListView *listView;
    QPushButton *pushButton_kapat;
    QLabel *label_status;

    void setupUi(QDialog *addMalzemeDialog)
    {
        if (addMalzemeDialog->objectName().isEmpty())
            addMalzemeDialog->setObjectName(QStringLiteral("addMalzemeDialog"));
        addMalzemeDialog->resize(349, 467);
        verticalLayout = new QVBoxLayout(addMalzemeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(addMalzemeDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(addMalzemeDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(addMalzemeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_Miktar = new QDoubleSpinBox(addMalzemeDialog);
        doubleSpinBox_Miktar->setObjectName(QStringLiteral("doubleSpinBox_Miktar"));
        doubleSpinBox_Miktar->setMaximum(1e+7);

        horizontalLayout_2->addWidget(doubleSpinBox_Miktar);

        comboBox_miktarType = new QComboBox(addMalzemeDialog);
        comboBox_miktarType->addItem(QString());
        comboBox_miktarType->addItem(QString());
        comboBox_miktarType->addItem(QString());
        comboBox_miktarType->addItem(QString());
        comboBox_miktarType->setObjectName(QStringLiteral("comboBox_miktarType"));

        horizontalLayout_2->addWidget(comboBox_miktarType);


        verticalLayout->addLayout(horizontalLayout_2);

        listView = new QListView(addMalzemeDialog);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setAlternatingRowColors(true);
        listView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(listView);

        pushButton_kapat = new QPushButton(addMalzemeDialog);
        pushButton_kapat->setObjectName(QStringLiteral("pushButton_kapat"));

        verticalLayout->addWidget(pushButton_kapat);

        label_status = new QLabel(addMalzemeDialog);
        label_status->setObjectName(QStringLiteral("label_status"));

        verticalLayout->addWidget(label_status);


        retranslateUi(addMalzemeDialog);
        QObject::connect(pushButton_kapat, SIGNAL(clicked()), addMalzemeDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(addMalzemeDialog);
    } // setupUi

    void retranslateUi(QDialog *addMalzemeDialog)
    {
        addMalzemeDialog->setWindowTitle(QApplication::translate("addMalzemeDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("addMalzemeDialog", "Kategoriler", nullptr));
        label_2->setText(QApplication::translate("addMalzemeDialog", "Miktar", nullptr));
        comboBox_miktarType->setItemText(0, QApplication::translate("addMalzemeDialog", "Litre", nullptr));
        comboBox_miktarType->setItemText(1, QApplication::translate("addMalzemeDialog", "Adet", nullptr));
        comboBox_miktarType->setItemText(2, QApplication::translate("addMalzemeDialog", "Gram", nullptr));
        comboBox_miktarType->setItemText(3, QApplication::translate("addMalzemeDialog", "KiloGram", nullptr));

        pushButton_kapat->setText(QApplication::translate("addMalzemeDialog", "Kapat", nullptr));
        label_status->setText(QApplication::translate("addMalzemeDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addMalzemeDialog: public Ui_addMalzemeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMALZEMEDIALOG_H
