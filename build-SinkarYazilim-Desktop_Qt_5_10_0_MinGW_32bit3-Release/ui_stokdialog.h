/********************************************************************************
** Form generated from reading UI file 'stokdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOKDIALOG_H
#define UI_STOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StokDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_malzemeCikisi;
    QPushButton *pushButton_malzemeGirisi;
    QPushButton *pushButton_sevkler;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QComboBox *comboBox_depo;
    QLabel *label_2;
    QListView *listView_MalzemeStok;
    QHBoxLayout *horizontalLayout;
    QLabel *label_status;
    QPushButton *pushButton_close;

    void setupUi(QDialog *StokDialog)
    {
        if (StokDialog->objectName().isEmpty())
            StokDialog->setObjectName(QStringLiteral("StokDialog"));
        StokDialog->resize(558, 510);
        verticalLayout_2 = new QVBoxLayout(StokDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_malzemeCikisi = new QPushButton(StokDialog);
        pushButton_malzemeCikisi->setObjectName(QStringLiteral("pushButton_malzemeCikisi"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_malzemeCikisi->sizePolicy().hasHeightForWidth());
        pushButton_malzemeCikisi->setSizePolicy(sizePolicy);
        pushButton_malzemeCikisi->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pushButton_malzemeCikisi, 0, 1, 1, 1);

        pushButton_malzemeGirisi = new QPushButton(StokDialog);
        pushButton_malzemeGirisi->setObjectName(QStringLiteral("pushButton_malzemeGirisi"));
        sizePolicy.setHeightForWidth(pushButton_malzemeGirisi->sizePolicy().hasHeightForWidth());
        pushButton_malzemeGirisi->setSizePolicy(sizePolicy);
        pushButton_malzemeGirisi->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pushButton_malzemeGirisi, 0, 0, 1, 1);

        pushButton_sevkler = new QPushButton(StokDialog);
        pushButton_sevkler->setObjectName(QStringLiteral("pushButton_sevkler"));
        sizePolicy.setHeightForWidth(pushButton_sevkler->sizePolicy().hasHeightForWidth());
        pushButton_sevkler->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton_sevkler, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        groupBox = new QGroupBox(StokDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox_depo = new QComboBox(groupBox);
        comboBox_depo->setObjectName(QStringLiteral("comboBox_depo"));

        gridLayout->addWidget(comboBox_depo, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        listView_MalzemeStok = new QListView(groupBox);
        listView_MalzemeStok->setObjectName(QStringLiteral("listView_MalzemeStok"));

        verticalLayout->addWidget(listView_MalzemeStok);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_status = new QLabel(StokDialog);
        label_status->setObjectName(QStringLiteral("label_status"));

        horizontalLayout->addWidget(label_status);

        pushButton_close = new QPushButton(StokDialog);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_close->sizePolicy().hasHeightForWidth());
        pushButton_close->setSizePolicy(sizePolicy2);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_close->setFont(font);

        horizontalLayout->addWidget(pushButton_close);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(StokDialog);

        QMetaObject::connectSlotsByName(StokDialog);
    } // setupUi

    void retranslateUi(QDialog *StokDialog)
    {
        StokDialog->setWindowTitle(QApplication::translate("StokDialog", "Dialog", nullptr));
        pushButton_malzemeCikisi->setText(QApplication::translate("StokDialog", "Depo Sevk", nullptr));
        pushButton_malzemeGirisi->setText(QApplication::translate("StokDialog", "Malzeme Giri\305\237i", nullptr));
        pushButton_sevkler->setText(QApplication::translate("StokDialog", "Sevkler", nullptr));
        groupBox->setTitle(QApplication::translate("StokDialog", "Malzemeler", nullptr));
        label_2->setText(QApplication::translate("StokDialog", "Depo", nullptr));
        label_status->setText(QApplication::translate("StokDialog", "status", nullptr));
        pushButton_close->setText(QApplication::translate("StokDialog", "Kapat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StokDialog: public Ui_StokDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOKDIALOG_H
