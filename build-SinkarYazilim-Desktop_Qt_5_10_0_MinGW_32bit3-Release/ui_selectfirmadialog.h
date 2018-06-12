/********************************************************************************
** Form generated from reading UI file 'selectfirmadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTFIRMADIALOG_H
#define UI_SELECTFIRMADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelectFirmaDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListView *listView;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SelectFirmaDialog)
    {
        if (SelectFirmaDialog->objectName().isEmpty())
            SelectFirmaDialog->setObjectName(QStringLiteral("SelectFirmaDialog"));
        SelectFirmaDialog->resize(317, 451);
        verticalLayout = new QVBoxLayout(SelectFirmaDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(SelectFirmaDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SelectFirmaDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(SelectFirmaDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(SelectFirmaDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setToolTipDuration(5);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        listView = new QListView(SelectFirmaDialog);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);

        pushButton_2 = new QPushButton(SelectFirmaDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(SelectFirmaDialog);

        QMetaObject::connectSlotsByName(SelectFirmaDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectFirmaDialog)
    {
        SelectFirmaDialog->setWindowTitle(QApplication::translate("SelectFirmaDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("SelectFirmaDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Firma Se\303\247</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("SelectFirmaDialog", "Filtre", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("SelectFirmaDialog", "Yeni Firma Olu\305\237tur", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("SelectFirmaDialog", "Firma Olu\305\237tur", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("SelectFirmaDialog", "+", nullptr));
        pushButton_2->setText(QApplication::translate("SelectFirmaDialog", "\304\260ptal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectFirmaDialog: public Ui_SelectFirmaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTFIRMADIALOG_H
