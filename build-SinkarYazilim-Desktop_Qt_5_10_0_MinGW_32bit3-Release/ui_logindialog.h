/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_username;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton_login;
    QPushButton *pushButton_Kapat;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(428, 150);
        LoginDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_username = new QLineEdit(LoginDialog);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        gridLayout->addWidget(lineEdit_username, 1, 1, 1, 1);

        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_password = new QLineEdit(LoginDialog);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_password, 2, 1, 1, 1);

        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 2, Qt::AlignHCenter);


        verticalLayout->addLayout(gridLayout);

        pushButton_login = new QPushButton(LoginDialog);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));

        verticalLayout->addWidget(pushButton_login);

        pushButton_Kapat = new QPushButton(LoginDialog);
        pushButton_Kapat->setObjectName(QStringLiteral("pushButton_Kapat"));

        verticalLayout->addWidget(pushButton_Kapat);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-weight:600;\">\305\236ifre</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-weight:600;\">Kullan\304\261c\304\261 Ad\304\261</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("LoginDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Giri\305\237 Yap</span></p></body></html>", nullptr));
        pushButton_login->setText(QApplication::translate("LoginDialog", "Giri\305\237", nullptr));
        pushButton_Kapat->setText(QApplication::translate("LoginDialog", "Kapat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
