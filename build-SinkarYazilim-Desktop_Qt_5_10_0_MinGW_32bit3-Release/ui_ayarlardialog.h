/********************************************************************************
** Form generated from reading UI file 'ayarlardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AYARLARDIALOG_H
#define UI_AYARLARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AyarlarDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_malzeme;
    QPushButton *pushButton_depo;
    QPushButton *pushButton_recete;

    void setupUi(QDialog *AyarlarDialog)
    {
        if (AyarlarDialog->objectName().isEmpty())
            AyarlarDialog->setObjectName(QStringLiteral("AyarlarDialog"));
        AyarlarDialog->resize(334, 118);
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        AyarlarDialog->setFont(font);
        verticalLayout = new QVBoxLayout(AyarlarDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_malzeme = new QPushButton(AyarlarDialog);
        pushButton_malzeme->setObjectName(QStringLiteral("pushButton_malzeme"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_malzeme->sizePolicy().hasHeightForWidth());
        pushButton_malzeme->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_malzeme, 0, 1, 1, 1);

        pushButton_depo = new QPushButton(AyarlarDialog);
        pushButton_depo->setObjectName(QStringLiteral("pushButton_depo"));
        sizePolicy.setHeightForWidth(pushButton_depo->sizePolicy().hasHeightForWidth());
        pushButton_depo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_depo, 0, 0, 1, 1);

        pushButton_recete = new QPushButton(AyarlarDialog);
        pushButton_recete->setObjectName(QStringLiteral("pushButton_recete"));
        sizePolicy.setHeightForWidth(pushButton_recete->sizePolicy().hasHeightForWidth());
        pushButton_recete->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_recete, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(AyarlarDialog);

        QMetaObject::connectSlotsByName(AyarlarDialog);
    } // setupUi

    void retranslateUi(QDialog *AyarlarDialog)
    {
        AyarlarDialog->setWindowTitle(QApplication::translate("AyarlarDialog", "Dialog", nullptr));
        pushButton_malzeme->setText(QApplication::translate("AyarlarDialog", "Malzemeler", nullptr));
        pushButton_depo->setText(QApplication::translate("AyarlarDialog", "Depo Ayarlar\304\261", nullptr));
        pushButton_recete->setText(QApplication::translate("AyarlarDialog", "Re\303\247eteler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AyarlarDialog: public Ui_AyarlarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AYARLARDIALOG_H
