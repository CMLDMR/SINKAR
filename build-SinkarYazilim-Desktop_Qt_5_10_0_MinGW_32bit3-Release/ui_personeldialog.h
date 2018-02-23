/********************************************************************************
** Form generated from reading UI file 'personeldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONELDIALOG_H
#define UI_PERSONELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PersonelDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_Refresh;
    QPushButton *pushButton_addNew;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_surname;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_5;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Save;

    void setupUi(QDialog *PersonelDialog)
    {
        if (PersonelDialog->objectName().isEmpty())
            PersonelDialog->setObjectName(QStringLiteral("PersonelDialog"));
        PersonelDialog->resize(1156, 607);
        horizontalLayout_2 = new QHBoxLayout(PersonelDialog);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(PersonelDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(270, 16777215));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_delete = new QPushButton(groupBox);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        horizontalLayout->addWidget(pushButton_delete);

        pushButton_Refresh = new QPushButton(groupBox);
        pushButton_Refresh->setObjectName(QStringLiteral("pushButton_Refresh"));

        horizontalLayout->addWidget(pushButton_Refresh);

        pushButton_addNew = new QPushButton(groupBox);
        pushButton_addNew->setObjectName(QStringLiteral("pushButton_addNew"));

        horizontalLayout->addWidget(pushButton_addNew);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PersonelDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(groupBox_2);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_surname = new QLineEdit(groupBox_2);
        lineEdit_surname->setObjectName(QStringLiteral("lineEdit_surname"));

        gridLayout->addWidget(lineEdit_surname, 1, 1, 1, 1);

        lineEdit_username = new QLineEdit(groupBox_2);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        gridLayout->addWidget(lineEdit_username, 2, 1, 1, 1);

        lineEdit_password = new QLineEdit(groupBox_2);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(lineEdit_password, 3, 1, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setEnabled(false);
        lineEdit_5->setReadOnly(true);

        gridLayout->addWidget(lineEdit_5, 4, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_Save = new QPushButton(groupBox_2);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));

        verticalLayout_2->addWidget(pushButton_Save);


        horizontalLayout_2->addWidget(groupBox_2);


        retranslateUi(PersonelDialog);

        QMetaObject::connectSlotsByName(PersonelDialog);
    } // setupUi

    void retranslateUi(QDialog *PersonelDialog)
    {
        PersonelDialog->setWindowTitle(QApplication::translate("PersonelDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("PersonelDialog", "Personel Listesi", nullptr));
        pushButton_delete->setText(QApplication::translate("PersonelDialog", "Sil", nullptr));
        pushButton_Refresh->setText(QApplication::translate("PersonelDialog", "Yenile", nullptr));
        pushButton_addNew->setText(QApplication::translate("PersonelDialog", "Ekle", nullptr));
        groupBox_2->setTitle(QApplication::translate("PersonelDialog", "Detaylar", nullptr));
        label->setText(QApplication::translate("PersonelDialog", "Ad", nullptr));
        label_2->setText(QApplication::translate("PersonelDialog", "Soyad", nullptr));
        label_3->setText(QApplication::translate("PersonelDialog", "Kullan\304\261c\304\261 Ad\304\261", nullptr));
        label_4->setText(QApplication::translate("PersonelDialog", "\305\236ifre", nullptr));
        label_5->setText(QApplication::translate("PersonelDialog", "oid", nullptr));
        pushButton_Save->setText(QApplication::translate("PersonelDialog", "Kaydet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PersonelDialog: public Ui_PersonelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONELDIALOG_H
