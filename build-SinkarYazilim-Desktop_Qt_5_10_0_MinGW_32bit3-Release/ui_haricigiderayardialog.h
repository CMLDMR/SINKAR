/********************************************************************************
** Form generated from reading UI file 'haricigiderayardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HARICIGIDERAYARDIALOG_H
#define UI_HARICIGIDERAYARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HariciGiderAyarDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *listView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_change;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_addNew;
    QPushButton *pushButton_close;

    void setupUi(QDialog *HariciGiderAyarDialog)
    {
        if (HariciGiderAyarDialog->objectName().isEmpty())
            HariciGiderAyarDialog->setObjectName(QStringLiteral("HariciGiderAyarDialog"));
        HariciGiderAyarDialog->resize(333, 436);
        verticalLayout = new QVBoxLayout(HariciGiderAyarDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(HariciGiderAyarDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        listView = new QListView(HariciGiderAyarDialog);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setAlternatingRowColors(true);
        listView->setSelectionBehavior(QAbstractItemView::SelectRows);
        listView->setSelectionRectVisible(true);

        verticalLayout->addWidget(listView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_delete = new QPushButton(HariciGiderAyarDialog);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        horizontalLayout_2->addWidget(pushButton_delete);

        pushButton_change = new QPushButton(HariciGiderAyarDialog);
        pushButton_change->setObjectName(QStringLiteral("pushButton_change"));

        horizontalLayout_2->addWidget(pushButton_change);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_addNew = new QPushButton(HariciGiderAyarDialog);
        pushButton_addNew->setObjectName(QStringLiteral("pushButton_addNew"));

        horizontalLayout->addWidget(pushButton_addNew);

        pushButton_close = new QPushButton(HariciGiderAyarDialog);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setCheckable(false);
        pushButton_close->setAutoExclusive(false);
        pushButton_close->setFlat(false);

        horizontalLayout->addWidget(pushButton_close);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(HariciGiderAyarDialog);
        QObject::connect(pushButton_close, SIGNAL(clicked()), HariciGiderAyarDialog, SLOT(close()));

        pushButton_close->setDefault(true);


        QMetaObject::connectSlotsByName(HariciGiderAyarDialog);
    } // setupUi

    void retranslateUi(QDialog *HariciGiderAyarDialog)
    {
        HariciGiderAyarDialog->setWindowTitle(QApplication::translate("HariciGiderAyarDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("HariciGiderAyarDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Harici Gider Kategorileri</span></p></body></html>", nullptr));
        pushButton_delete->setText(QApplication::translate("HariciGiderAyarDialog", "Sil", nullptr));
        pushButton_change->setText(QApplication::translate("HariciGiderAyarDialog", "De\304\237i\305\237tir", nullptr));
        pushButton_addNew->setText(QApplication::translate("HariciGiderAyarDialog", "Yeni Ekle", nullptr));
        pushButton_close->setText(QApplication::translate("HariciGiderAyarDialog", "\304\260ptal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HariciGiderAyarDialog: public Ui_HariciGiderAyarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARICIGIDERAYARDIALOG_H
