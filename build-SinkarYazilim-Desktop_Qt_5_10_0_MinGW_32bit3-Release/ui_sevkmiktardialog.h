/********************************************************************************
** Form generated from reading UI file 'sevkmiktardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEVKMIKTARDIALOG_H
#define UI_SEVKMIKTARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SevkMiktarDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_selected;
    QPushButton *pushButton_iptal;
    QPushButton *pushButton_tamam;

    void setupUi(QDialog *SevkMiktarDialog)
    {
        if (SevkMiktarDialog->objectName().isEmpty())
            SevkMiktarDialog->setObjectName(QStringLiteral("SevkMiktarDialog"));
        SevkMiktarDialog->resize(267, 106);
        gridLayout = new QGridLayout(SevkMiktarDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(SevkMiktarDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox_selected = new QDoubleSpinBox(SevkMiktarDialog);
        doubleSpinBox_selected->setObjectName(QStringLiteral("doubleSpinBox_selected"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox_selected->sizePolicy().hasHeightForWidth());
        doubleSpinBox_selected->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(14);
        doubleSpinBox_selected->setFont(font);

        gridLayout->addWidget(doubleSpinBox_selected, 0, 1, 1, 1);

        pushButton_iptal = new QPushButton(SevkMiktarDialog);
        pushButton_iptal->setObjectName(QStringLiteral("pushButton_iptal"));
        sizePolicy1.setHeightForWidth(pushButton_iptal->sizePolicy().hasHeightForWidth());
        pushButton_iptal->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(10);
        pushButton_iptal->setFont(font1);

        gridLayout->addWidget(pushButton_iptal, 1, 0, 1, 1);

        pushButton_tamam = new QPushButton(SevkMiktarDialog);
        pushButton_tamam->setObjectName(QStringLiteral("pushButton_tamam"));
        sizePolicy1.setHeightForWidth(pushButton_tamam->sizePolicy().hasHeightForWidth());
        pushButton_tamam->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_tamam->setFont(font2);

        gridLayout->addWidget(pushButton_tamam, 1, 1, 1, 1);


        retranslateUi(SevkMiktarDialog);

        QMetaObject::connectSlotsByName(SevkMiktarDialog);
    } // setupUi

    void retranslateUi(QDialog *SevkMiktarDialog)
    {
        SevkMiktarDialog->setWindowTitle(QApplication::translate("SevkMiktarDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("SevkMiktarDialog", "TextLabel", nullptr));
        pushButton_iptal->setText(QApplication::translate("SevkMiktarDialog", "\304\260ptal", nullptr));
        pushButton_tamam->setText(QApplication::translate("SevkMiktarDialog", "Tamam", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SevkMiktarDialog: public Ui_SevkMiktarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEVKMIKTARDIALOG_H
