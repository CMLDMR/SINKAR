/********************************************************************************
** Form generated from reading UI file 'malzemecikdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MALZEMECIKDIALOG_H
#define UI_MALZEMECIKDIALOG_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MalzemeCikDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QComboBox *comboBox_source;
    QLabel *label;
    QLineEdit *lineEdit_filter;
    QLabel *label_3;
    QListView *listView_currentStock;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QListView *listView_selectedStock;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox_destination;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *MalzemeCikDialog)
    {
        if (MalzemeCikDialog->objectName().isEmpty())
            MalzemeCikDialog->setObjectName(QStringLiteral("MalzemeCikDialog"));
        MalzemeCikDialog->resize(449, 600);
        verticalLayout_3 = new QVBoxLayout(MalzemeCikDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(MalzemeCikDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox_source = new QComboBox(groupBox);
        comboBox_source->setObjectName(QStringLiteral("comboBox_source"));

        gridLayout->addWidget(comboBox_source, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_filter = new QLineEdit(groupBox);
        lineEdit_filter->setObjectName(QStringLiteral("lineEdit_filter"));

        gridLayout->addWidget(lineEdit_filter, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        listView_currentStock = new QListView(groupBox);
        listView_currentStock->setObjectName(QStringLiteral("listView_currentStock"));
        listView_currentStock->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_currentStock->setAlternatingRowColors(true);
        listView_currentStock->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_4->addWidget(listView_currentStock);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        listView_selectedStock = new QListView(groupBox);
        listView_selectedStock->setObjectName(QStringLiteral("listView_selectedStock"));
        listView_selectedStock->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_selectedStock->setAlternatingRowColors(true);
        listView_selectedStock->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(listView_selectedStock);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MalzemeCikDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        comboBox_destination = new QComboBox(groupBox_2);
        comboBox_destination->setObjectName(QStringLiteral("comboBox_destination"));

        verticalLayout_2->addWidget(comboBox_destination);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_cancel = new QPushButton(MalzemeCikDialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);

        pushButton_ok = new QPushButton(MalzemeCikDialog);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout_3->addWidget(pushButton_ok);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(MalzemeCikDialog);

        QMetaObject::connectSlotsByName(MalzemeCikDialog);
    } // setupUi

    void retranslateUi(QDialog *MalzemeCikDialog)
    {
        MalzemeCikDialog->setWindowTitle(QApplication::translate("MalzemeCikDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("MalzemeCikDialog", "Kaynak", nullptr));
        label->setText(QApplication::translate("MalzemeCikDialog", "Kaynak", nullptr));
        label_3->setText(QApplication::translate("MalzemeCikDialog", "Malzeme", nullptr));
        label_4->setText(QApplication::translate("MalzemeCikDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Sevk Edilecek Malzemeler</span></p></body></html>", nullptr));
        groupBox_2->setTitle(QApplication::translate("MalzemeCikDialog", "Hedef", nullptr));
        pushButton_cancel->setText(QApplication::translate("MalzemeCikDialog", "\304\260ptal", nullptr));
        pushButton_ok->setText(QApplication::translate("MalzemeCikDialog", "Tamamla", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MalzemeCikDialog: public Ui_MalzemeCikDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MALZEMECIKDIALOG_H
