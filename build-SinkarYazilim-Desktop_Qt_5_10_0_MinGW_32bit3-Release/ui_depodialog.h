/********************************************************************************
** Form generated from reading UI file 'depodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPODIALOG_H
#define UI_DEPODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DepoDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_yenile;
    QPushButton *pushButton_ekle;
    QPushButton *pushButton_close;

    void setupUi(QDialog *DepoDialog)
    {
        if (DepoDialog->objectName().isEmpty())
            DepoDialog->setObjectName(QStringLiteral("DepoDialog"));
        DepoDialog->resize(277, 367);
        verticalLayout_2 = new QVBoxLayout(DepoDialog);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        groupBox = new QGroupBox(DepoDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(270, 16777215));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setDragEnabled(true);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_delete = new QPushButton(groupBox);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        horizontalLayout->addWidget(pushButton_delete);

        pushButton_yenile = new QPushButton(groupBox);
        pushButton_yenile->setObjectName(QStringLiteral("pushButton_yenile"));

        horizontalLayout->addWidget(pushButton_yenile);

        pushButton_ekle = new QPushButton(groupBox);
        pushButton_ekle->setObjectName(QStringLiteral("pushButton_ekle"));

        horizontalLayout->addWidget(pushButton_ekle);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_close = new QPushButton(groupBox);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

        verticalLayout->addWidget(pushButton_close);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(DepoDialog);

        QMetaObject::connectSlotsByName(DepoDialog);
    } // setupUi

    void retranslateUi(QDialog *DepoDialog)
    {
        DepoDialog->setWindowTitle(QApplication::translate("DepoDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("DepoDialog", "Depolar", nullptr));
        pushButton_delete->setText(QApplication::translate("DepoDialog", "Sil", nullptr));
        pushButton_yenile->setText(QApplication::translate("DepoDialog", "Yenile", nullptr));
        pushButton_ekle->setText(QApplication::translate("DepoDialog", "Yeni Ekle", nullptr));
        pushButton_close->setText(QApplication::translate("DepoDialog", "Kapat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepoDialog: public Ui_DepoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPODIALOG_H
