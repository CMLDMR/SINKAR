/********************************************************************************
** Form generated from reading UI file 'odemealdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ODEMEALDIALOG_H
#define UI_ODEMEALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OdemeAlDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_minimize;
    QPushButton *pushButton_toogleMaximize;
    QPushButton *pushButton_close;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLineEdit *lineEdit_filter;
    QListView *listView_KisiList;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_Oid;
    QLabel *label_11;
    QLabel *label_2;
    QLineEdit *lineEdit_isim;
    QDoubleSpinBox *doubleSpinBox_ToplamBorc;
    QLabel *label_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_NakitOde;
    QPushButton *pushButton_NakitTamami;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_KrediKartiOde;
    QPushButton *pushButton_KrediOdeme;
    QLabel *label_KalanMiktar;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_OdemeListesiniCikar;
    QLabel *label_iade;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_OdeneBilecekRakam;
    QPushButton *pushButton_OdemeAl;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableView_HesapList;

    void setupUi(QDialog *OdemeAlDialog)
    {
        if (OdemeAlDialog->objectName().isEmpty())
            OdemeAlDialog->setObjectName(QStringLiteral("OdemeAlDialog"));
        OdemeAlDialog->resize(1017, 559);
        QFont font;
        font.setPointSize(10);
        OdemeAlDialog->setFont(font);
        verticalLayout_4 = new QVBoxLayout(OdemeAlDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_12 = new QLabel(OdemeAlDialog);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(40, 40));
        label_12->setMaximumSize(QSize(40, 40));
        label_12->setFrameShape(QFrame::Box);
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/icon/icon.ico")));
        label_12->setScaledContents(true);
        label_12->setAlignment(Qt::AlignCenter);
        label_12->setMargin(4);
        label_12->setIndent(-1);

        horizontalLayout_4->addWidget(label_12);

        label = new QLabel(OdemeAlDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_minimize = new QPushButton(OdemeAlDialog);
        pushButton_minimize->setObjectName(QStringLiteral("pushButton_minimize"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_minimize->sizePolicy().hasHeightForWidth());
        pushButton_minimize->setSizePolicy(sizePolicy);
        pushButton_minimize->setMinimumSize(QSize(30, 30));
        pushButton_minimize->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pushButton_minimize);

        pushButton_toogleMaximize = new QPushButton(OdemeAlDialog);
        pushButton_toogleMaximize->setObjectName(QStringLiteral("pushButton_toogleMaximize"));
        pushButton_toogleMaximize->setMinimumSize(QSize(30, 30));
        pushButton_toogleMaximize->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pushButton_toogleMaximize);

        pushButton_close = new QPushButton(OdemeAlDialog);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(30, 30));
        pushButton_close->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pushButton_close);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox = new QGroupBox(OdemeAlDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(250, 16777215));
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        lineEdit_filter = new QLineEdit(groupBox);
        lineEdit_filter->setObjectName(QStringLiteral("lineEdit_filter"));
        lineEdit_filter->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_filter->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lineEdit_filter);


        verticalLayout->addLayout(horizontalLayout);

        listView_KisiList = new QListView(groupBox);
        listView_KisiList->setObjectName(QStringLiteral("listView_KisiList"));
        listView_KisiList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_KisiList->setAlternatingRowColors(true);

        verticalLayout->addWidget(listView_KisiList);


        horizontalLayout_5->addWidget(groupBox);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_Oid = new QLineEdit(OdemeAlDialog);
        lineEdit_Oid->setObjectName(QStringLiteral("lineEdit_Oid"));
        lineEdit_Oid->setReadOnly(true);
        lineEdit_Oid->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_Oid->setClearButtonEnabled(false);

        gridLayout->addWidget(lineEdit_Oid, 1, 1, 1, 1);

        label_11 = new QLabel(OdemeAlDialog);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        label_2 = new QLabel(OdemeAlDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_isim = new QLineEdit(OdemeAlDialog);
        lineEdit_isim->setObjectName(QStringLiteral("lineEdit_isim"));
        lineEdit_isim->setReadOnly(true);

        gridLayout->addWidget(lineEdit_isim, 0, 1, 1, 1);

        doubleSpinBox_ToplamBorc = new QDoubleSpinBox(OdemeAlDialog);
        doubleSpinBox_ToplamBorc->setObjectName(QStringLiteral("doubleSpinBox_ToplamBorc"));
        doubleSpinBox_ToplamBorc->setReadOnly(true);
        doubleSpinBox_ToplamBorc->setMaximum(1e+12);

        gridLayout->addWidget(doubleSpinBox_ToplamBorc, 2, 1, 1, 1);

        label_3 = new QLabel(OdemeAlDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        groupBox_3 = new QGroupBox(OdemeAlDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_3->setFont(font1);
        groupBox_3->setAlignment(Qt::AlignCenter);
        groupBox_3->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);

        doubleSpinBox_NakitOde = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_NakitOde->setObjectName(QStringLiteral("doubleSpinBox_NakitOde"));
        doubleSpinBox_NakitOde->setReadOnly(false);
        doubleSpinBox_NakitOde->setMaximum(1e+13);

        horizontalLayout_2->addWidget(doubleSpinBox_NakitOde);

        pushButton_NakitTamami = new QPushButton(groupBox_3);
        pushButton_NakitTamami->setObjectName(QStringLiteral("pushButton_NakitTamami"));
        pushButton_NakitTamami->setMinimumSize(QSize(106, 0));

        horizontalLayout_2->addWidget(pushButton_NakitTamami);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_3->addWidget(label_10);

        doubleSpinBox_KrediKartiOde = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_KrediKartiOde->setObjectName(QStringLiteral("doubleSpinBox_KrediKartiOde"));
        doubleSpinBox_KrediKartiOde->setReadOnly(false);
        doubleSpinBox_KrediKartiOde->setMaximum(1e+13);

        horizontalLayout_3->addWidget(doubleSpinBox_KrediKartiOde);

        pushButton_KrediOdeme = new QPushButton(groupBox_3);
        pushButton_KrediOdeme->setObjectName(QStringLiteral("pushButton_KrediOdeme"));

        horizontalLayout_3->addWidget(pushButton_KrediOdeme);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_KalanMiktar = new QLabel(groupBox_3);
        label_KalanMiktar->setObjectName(QStringLiteral("label_KalanMiktar"));

        verticalLayout_2->addWidget(label_KalanMiktar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_OdemeListesiniCikar = new QPushButton(groupBox_3);
        pushButton_OdemeListesiniCikar->setObjectName(QStringLiteral("pushButton_OdemeListesiniCikar"));

        verticalLayout_2->addWidget(pushButton_OdemeListesiniCikar);

        label_iade = new QLabel(groupBox_3);
        label_iade->setObjectName(QStringLiteral("label_iade"));

        verticalLayout_2->addWidget(label_iade);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        doubleSpinBox_OdeneBilecekRakam = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_OdeneBilecekRakam->setObjectName(QStringLiteral("doubleSpinBox_OdeneBilecekRakam"));
        doubleSpinBox_OdeneBilecekRakam->setMaximum(1e+14);

        horizontalLayout_6->addWidget(doubleSpinBox_OdeneBilecekRakam);


        verticalLayout_2->addLayout(horizontalLayout_6);

        pushButton_OdemeAl = new QPushButton(groupBox_3);
        pushButton_OdemeAl->setObjectName(QStringLiteral("pushButton_OdemeAl"));

        verticalLayout_2->addWidget(pushButton_OdemeAl);


        verticalLayout_3->addWidget(groupBox_3);


        horizontalLayout_5->addLayout(verticalLayout_3);

        groupBox_2 = new QGroupBox(OdemeAlDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(355, 0));
        groupBox_2->setAlignment(Qt::AlignCenter);
        groupBox_2->setFlat(true);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tableView_HesapList = new QTableView(groupBox_2);
        tableView_HesapList->setObjectName(QStringLiteral("tableView_HesapList"));
        tableView_HesapList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_HesapList->setAlternatingRowColors(true);
        tableView_HesapList->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView_HesapList->setSortingEnabled(true);
        tableView_HesapList->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_5->addWidget(tableView_HesapList);


        horizontalLayout_5->addWidget(groupBox_2);


        verticalLayout_4->addLayout(horizontalLayout_5);


        retranslateUi(OdemeAlDialog);

        QMetaObject::connectSlotsByName(OdemeAlDialog);
    } // setupUi

    void retranslateUi(QDialog *OdemeAlDialog)
    {
        OdemeAlDialog->setWindowTitle(QApplication::translate("OdemeAlDialog", "Dialog", nullptr));
        label_12->setText(QString());
        label->setText(QApplication::translate("OdemeAlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\303\226deme Al</span></p></body></html>", nullptr));
        pushButton_minimize->setText(QApplication::translate("OdemeAlDialog", "_", nullptr));
        pushButton_toogleMaximize->setText(QApplication::translate("OdemeAlDialog", "O", nullptr));
        pushButton_close->setText(QApplication::translate("OdemeAlDialog", "X", nullptr));
        groupBox->setTitle(QApplication::translate("OdemeAlDialog", "Ki\305\237i Bilgileri", nullptr));
        label_8->setText(QApplication::translate("OdemeAlDialog", "Filter", nullptr));
        label_11->setText(QApplication::translate("OdemeAlDialog", "<html><head/><body><p>Oid</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("OdemeAlDialog", "<html><head/><body><p><span style=\" font-weight:600;\">\304\260sim</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("OdemeAlDialog", "<html><head/><body><p><span style=\" font-weight:600; color:#ff0004;\">Toplam Bor\303\247</span></p></body></html>", nullptr));
        groupBox_3->setTitle(QApplication::translate("OdemeAlDialog", "\303\226deme", nullptr));
        label_9->setText(QApplication::translate("OdemeAlDialog", "Nakit", nullptr));
        pushButton_NakitTamami->setText(QApplication::translate("OdemeAlDialog", "Tamam\304\261", nullptr));
        label_10->setText(QApplication::translate("OdemeAlDialog", "Kredi Kart\304\261", nullptr));
        pushButton_KrediOdeme->setText(QApplication::translate("OdemeAlDialog", "Kalan\304\261n Tamam\304\261", nullptr));
        label_KalanMiktar->setText(QApplication::translate("OdemeAlDialog", "Kalan Miktar", nullptr));
        pushButton_OdemeListesiniCikar->setText(QApplication::translate("OdemeAlDialog", "\303\226deme Listesini \303\207\304\261kar", nullptr));
        label_iade->setText(QApplication::translate("OdemeAlDialog", "\304\260ade", nullptr));
        label_4->setText(QApplication::translate("OdemeAlDialog", "\303\226denebilecek Rakam", nullptr));
        pushButton_OdemeAl->setText(QApplication::translate("OdemeAlDialog", "\303\226demeyi Al", nullptr));
        groupBox_2->setTitle(QApplication::translate("OdemeAlDialog", "Ge\303\247mi\305\237 Hesaplar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OdemeAlDialog: public Ui_OdemeAlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ODEMEALDIALOG_H
