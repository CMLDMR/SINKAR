/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_OpenKasa;
    QPushButton *pushButton_Stok;
    QPushButton *pushButton_Personel;
    QPushButton *pushButton_options;
    QPushButton *pushButton_Cari;
    QPushButton *pushButton_Close;
    QPushButton *pushButton_ExternalOutGoing;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(565, 304);
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_OpenKasa = new QPushButton(centralWidget);
        pushButton_OpenKasa->setObjectName(QStringLiteral("pushButton_OpenKasa"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_OpenKasa->sizePolicy().hasHeightForWidth());
        pushButton_OpenKasa->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_OpenKasa, 0, 0, 1, 1);

        pushButton_Stok = new QPushButton(centralWidget);
        pushButton_Stok->setObjectName(QStringLiteral("pushButton_Stok"));
        sizePolicy.setHeightForWidth(pushButton_Stok->sizePolicy().hasHeightForWidth());
        pushButton_Stok->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_Stok, 0, 3, 1, 1);

        pushButton_Personel = new QPushButton(centralWidget);
        pushButton_Personel->setObjectName(QStringLiteral("pushButton_Personel"));
        sizePolicy.setHeightForWidth(pushButton_Personel->sizePolicy().hasHeightForWidth());
        pushButton_Personel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_Personel, 0, 2, 1, 1);

        pushButton_options = new QPushButton(centralWidget);
        pushButton_options->setObjectName(QStringLiteral("pushButton_options"));
        sizePolicy.setHeightForWidth(pushButton_options->sizePolicy().hasHeightForWidth());
        pushButton_options->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_options, 0, 1, 1, 1);

        pushButton_Cari = new QPushButton(centralWidget);
        pushButton_Cari->setObjectName(QStringLiteral("pushButton_Cari"));
        sizePolicy.setHeightForWidth(pushButton_Cari->sizePolicy().hasHeightForWidth());
        pushButton_Cari->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_Cari, 0, 4, 1, 1);

        pushButton_Close = new QPushButton(centralWidget);
        pushButton_Close->setObjectName(QStringLiteral("pushButton_Close"));
        sizePolicy.setHeightForWidth(pushButton_Close->sizePolicy().hasHeightForWidth());
        pushButton_Close->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_Close, 1, 4, 1, 1);

        pushButton_ExternalOutGoing = new QPushButton(centralWidget);
        pushButton_ExternalOutGoing->setObjectName(QStringLiteral("pushButton_ExternalOutGoing"));
        sizePolicy.setHeightForWidth(pushButton_ExternalOutGoing->sizePolicy().hasHeightForWidth());
        pushButton_ExternalOutGoing->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_ExternalOutGoing, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 565, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Stok & Kasa", nullptr));
        pushButton_OpenKasa->setText(QApplication::translate("MainWindow", "Kasa", nullptr));
        pushButton_Stok->setText(QApplication::translate("MainWindow", "Stok", nullptr));
        pushButton_Personel->setText(QApplication::translate("MainWindow", "Personel\n"
"Y\303\266netimi", nullptr));
        pushButton_options->setText(QApplication::translate("MainWindow", "Ayarlar", nullptr));
        pushButton_Cari->setText(QApplication::translate("MainWindow", "Cari\n"
"ve\n"
"Kasa", nullptr));
        pushButton_Close->setText(QApplication::translate("MainWindow", "Kapat", nullptr));
        pushButton_ExternalOutGoing->setText(QApplication::translate("MainWindow", "Harici\n"
"Giderler", nullptr));
        label->setText(QApplication::translate("MainWindow", "Stok & Kasa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
