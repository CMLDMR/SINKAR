/********************************************************************************
** Form generated from reading UI file 'siparisdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIPARISDIALOG_H
#define UI_SIPARISDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SiparisDialog
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_katFilter;
    QListView *listView;
    QPushButton *pushButton_close;

    void setupUi(QDialog *SiparisDialog)
    {
        if (SiparisDialog->objectName().isEmpty())
            SiparisDialog->setObjectName(QStringLiteral("SiparisDialog"));
        SiparisDialog->resize(295, 312);
        verticalLayout = new QVBoxLayout(SiparisDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox_katFilter = new QComboBox(SiparisDialog);
        comboBox_katFilter->setObjectName(QStringLiteral("comboBox_katFilter"));

        verticalLayout->addWidget(comboBox_katFilter);

        listView = new QListView(SiparisDialog);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(listView);

        pushButton_close = new QPushButton(SiparisDialog);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

        verticalLayout->addWidget(pushButton_close);


        retranslateUi(SiparisDialog);
        QObject::connect(pushButton_close, SIGNAL(clicked()), SiparisDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(SiparisDialog);
    } // setupUi

    void retranslateUi(QDialog *SiparisDialog)
    {
        SiparisDialog->setWindowTitle(QApplication::translate("SiparisDialog", "Dialog", nullptr));
        pushButton_close->setText(QApplication::translate("SiparisDialog", "Kapat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SiparisDialog: public Ui_SiparisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIPARISDIALOG_H
