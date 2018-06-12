/********************************************************************************
** Form generated from reading UI file 'detaylihesapdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAYLIHESAPDIALOG_H
#define UI_DETAYLIHESAPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetayliHesapDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Minimize;
    QPushButton *pushButton_toggleFullScreen;
    QPushButton *pushButton_Close;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_CariControlFilter;
    QListView *listView_CariiControlKisiList;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_CariControlToplamOdeme;
    QDoubleSpinBox *doubleSpinBox_CariControlToplamBorc;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_CariControlToplamNakitOdeme;
    QDoubleSpinBox *doubleSpinBox_CariControlKrediOdeme;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_CariControlKalanBorc;
    QSpacerItem *verticalSpacer;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QDateEdit *dateEdit_MalzemeGiderSetDate;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_MalzemeGiderMaxCiro;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_MalzemeGiderCreateTestEntry;
    QPushButton *pushButton_MalzemeGiderExport;
    QGraphicsView *graphicsView_MalzemeGider;
    QWidget *tab_4;
    QWidget *tab_2;
    QWidget *tab_5;

    void setupUi(QDialog *DetayliHesapDialog)
    {
        if (DetayliHesapDialog->objectName().isEmpty())
            DetayliHesapDialog->setObjectName(QStringLiteral("DetayliHesapDialog"));
        DetayliHesapDialog->resize(1011, 683);
        verticalLayout_4 = new QVBoxLayout(DetayliHesapDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_9 = new QLabel(DetayliHesapDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_Minimize = new QPushButton(DetayliHesapDialog);
        pushButton_Minimize->setObjectName(QStringLiteral("pushButton_Minimize"));
        pushButton_Minimize->setMinimumSize(QSize(30, 30));
        pushButton_Minimize->setMaximumSize(QSize(30, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_Minimize->setFont(font);

        horizontalLayout->addWidget(pushButton_Minimize);

        pushButton_toggleFullScreen = new QPushButton(DetayliHesapDialog);
        pushButton_toggleFullScreen->setObjectName(QStringLiteral("pushButton_toggleFullScreen"));
        pushButton_toggleFullScreen->setMinimumSize(QSize(30, 30));
        pushButton_toggleFullScreen->setMaximumSize(QSize(30, 30));
        pushButton_toggleFullScreen->setFont(font);

        horizontalLayout->addWidget(pushButton_toggleFullScreen);

        pushButton_Close = new QPushButton(DetayliHesapDialog);
        pushButton_Close->setObjectName(QStringLiteral("pushButton_Close"));
        pushButton_Close->setMinimumSize(QSize(30, 30));
        pushButton_Close->setMaximumSize(QSize(30, 30));
        pushButton_Close->setFont(font);

        horizontalLayout->addWidget(pushButton_Close);


        verticalLayout_4->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(DetayliHesapDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(22, 25));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(256, 16777215));
        QFont font1;
        font1.setPointSize(10);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 9, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_CariControlFilter = new QLineEdit(groupBox);
        lineEdit_CariControlFilter->setObjectName(QStringLiteral("lineEdit_CariControlFilter"));

        horizontalLayout_2->addWidget(lineEdit_CariControlFilter);


        verticalLayout->addLayout(horizontalLayout_2);

        listView_CariiControlKisiList = new QListView(groupBox);
        listView_CariiControlKisiList->setObjectName(QStringLiteral("listView_CariiControlKisiList"));
        listView_CariiControlKisiList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_CariiControlKisiList->setAlternatingRowColors(true);
        listView_CariiControlKisiList->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(listView_CariiControlKisiList);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        doubleSpinBox_CariControlToplamOdeme = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_CariControlToplamOdeme->setObjectName(QStringLiteral("doubleSpinBox_CariControlToplamOdeme"));
        QFont font2;
        font2.setPointSize(12);
        doubleSpinBox_CariControlToplamOdeme->setFont(font2);
        doubleSpinBox_CariControlToplamOdeme->setReadOnly(true);

        gridLayout->addWidget(doubleSpinBox_CariControlToplamOdeme, 1, 1, 1, 1);

        doubleSpinBox_CariControlToplamBorc = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_CariControlToplamBorc->setObjectName(QStringLiteral("doubleSpinBox_CariControlToplamBorc"));
        doubleSpinBox_CariControlToplamBorc->setFont(font2);
        doubleSpinBox_CariControlToplamBorc->setReadOnly(true);

        gridLayout->addWidget(doubleSpinBox_CariControlToplamBorc, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        doubleSpinBox_CariControlToplamNakitOdeme = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_CariControlToplamNakitOdeme->setObjectName(QStringLiteral("doubleSpinBox_CariControlToplamNakitOdeme"));
        doubleSpinBox_CariControlToplamNakitOdeme->setFont(font2);
        doubleSpinBox_CariControlToplamNakitOdeme->setReadOnly(true);

        gridLayout->addWidget(doubleSpinBox_CariControlToplamNakitOdeme, 2, 1, 1, 1);

        doubleSpinBox_CariControlKrediOdeme = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_CariControlKrediOdeme->setObjectName(QStringLiteral("doubleSpinBox_CariControlKrediOdeme"));
        doubleSpinBox_CariControlKrediOdeme->setFont(font2);
        doubleSpinBox_CariControlKrediOdeme->setReadOnly(true);

        gridLayout->addWidget(doubleSpinBox_CariControlKrediOdeme, 3, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        doubleSpinBox_CariControlKalanBorc = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_CariControlKalanBorc->setObjectName(QStringLiteral("doubleSpinBox_CariControlKalanBorc"));
        doubleSpinBox_CariControlKalanBorc->setFont(font2);
        doubleSpinBox_CariControlKalanBorc->setReadOnly(true);

        gridLayout->addWidget(doubleSpinBox_CariControlKalanBorc, 4, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 433, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(groupBox_2);

        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        dateEdit_MalzemeGiderSetDate = new QDateEdit(tab_3);
        dateEdit_MalzemeGiderSetDate->setObjectName(QStringLiteral("dateEdit_MalzemeGiderSetDate"));
        dateEdit_MalzemeGiderSetDate->setCalendarPopup(false);

        horizontalLayout_4->addWidget(dateEdit_MalzemeGiderSetDate);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        doubleSpinBox_MalzemeGiderMaxCiro = new QDoubleSpinBox(tab_3);
        doubleSpinBox_MalzemeGiderMaxCiro->setObjectName(QStringLiteral("doubleSpinBox_MalzemeGiderMaxCiro"));
        doubleSpinBox_MalzemeGiderMaxCiro->setDecimals(0);
        doubleSpinBox_MalzemeGiderMaxCiro->setMinimum(1000);
        doubleSpinBox_MalzemeGiderMaxCiro->setMaximum(50000);
        doubleSpinBox_MalzemeGiderMaxCiro->setSingleStep(1000);
        doubleSpinBox_MalzemeGiderMaxCiro->setValue(10000);

        horizontalLayout_6->addWidget(doubleSpinBox_MalzemeGiderMaxCiro);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButton_MalzemeGiderCreateTestEntry = new QPushButton(tab_3);
        pushButton_MalzemeGiderCreateTestEntry->setObjectName(QStringLiteral("pushButton_MalzemeGiderCreateTestEntry"));

        horizontalLayout_6->addWidget(pushButton_MalzemeGiderCreateTestEntry);

        pushButton_MalzemeGiderExport = new QPushButton(tab_3);
        pushButton_MalzemeGiderExport->setObjectName(QStringLiteral("pushButton_MalzemeGiderExport"));

        horizontalLayout_6->addWidget(pushButton_MalzemeGiderExport);


        verticalLayout_3->addLayout(horizontalLayout_6);

        graphicsView_MalzemeGider = new QGraphicsView(tab_3);
        graphicsView_MalzemeGider->setObjectName(QStringLiteral("graphicsView_MalzemeGider"));
        graphicsView_MalzemeGider->setDragMode(QGraphicsView::ScrollHandDrag);

        verticalLayout_3->addWidget(graphicsView_MalzemeGider);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());

        verticalLayout_4->addWidget(tabWidget);


        retranslateUi(DetayliHesapDialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DetayliHesapDialog);
    } // setupUi

    void retranslateUi(QDialog *DetayliHesapDialog)
    {
        DetayliHesapDialog->setWindowTitle(QApplication::translate("DetayliHesapDialog", "Dialog", nullptr));
        label_9->setText(QApplication::translate("DetayliHesapDialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Hesap Kontrol</span></p></body></html>", nullptr));
        pushButton_Minimize->setText(QApplication::translate("DetayliHesapDialog", "_", nullptr));
        pushButton_toggleFullScreen->setText(QApplication::translate("DetayliHesapDialog", "O", nullptr));
        pushButton_Close->setText(QApplication::translate("DetayliHesapDialog", "X", nullptr));
        groupBox->setTitle(QApplication::translate("DetayliHesapDialog", "Ki\305\237i Hesaplar\304\261", nullptr));
        label->setText(QApplication::translate("DetayliHesapDialog", "Filter", nullptr));
        groupBox_2->setTitle(QApplication::translate("DetayliHesapDialog", "Bakiye Durumu", nullptr));
        label_2->setText(QApplication::translate("DetayliHesapDialog", "Toplam Bor\303\247lanma", nullptr));
        label_4->setText(QApplication::translate("DetayliHesapDialog", "\305\236uana Kadar Nakit \303\226deme", nullptr));
        label_3->setText(QApplication::translate("DetayliHesapDialog", "\305\236uana Kadar Toplam \303\226deme", nullptr));
        label_5->setText(QApplication::translate("DetayliHesapDialog", "\305\236uana Kadar Kredi Kart\304\261 \303\226deme", nullptr));
        label_6->setText(QApplication::translate("DetayliHesapDialog", "Kalan Bor\303\247", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DetayliHesapDialog", "Cari Kontrol", nullptr));
        label_7->setText(QApplication::translate("DetayliHesapDialog", "Ba\305\237lang\304\261\303\247", nullptr));
        dateEdit_MalzemeGiderSetDate->setDisplayFormat(QApplication::translate("DetayliHesapDialog", "MMMM", nullptr));
        label_8->setText(QApplication::translate("DetayliHesapDialog", "Baz", nullptr));
        pushButton_MalzemeGiderCreateTestEntry->setText(QApplication::translate("DetayliHesapDialog", "#Create Test Entry", nullptr));
        pushButton_MalzemeGiderExport->setText(QApplication::translate("DetayliHesapDialog", "\303\207\304\261kart", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("DetayliHesapDialog", "Cari Gelir/Gider", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("DetayliHesapDialog", "Harici Giderler", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DetayliHesapDialog", "Masa Gelir/Gider", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("DetayliHesapDialog", "Net Tablo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetayliHesapDialog: public Ui_DetayliHesapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAYLIHESAPDIALOG_H
