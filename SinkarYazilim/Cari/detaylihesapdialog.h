#ifndef DETAYLIHESAPDIALOG_H
#define DETAYLIHESAPDIALOG_H


#include <QtGlobal>

#include "dbuser.h"
#include "delegate.h"


#include <QStandardItem>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QSortFilterProxyModel>
#include <QGraphicsScene>
#include <QGraphicsRectItem>


#include <random>



#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

namespace Ui {
class DetayliHesapDialog;
}

class DetayliHesapDialog : public QDialog , public DBUser
{
    Q_OBJECT

public:
    explicit DetayliHesapDialog(mongocxx::database* _db , bsoncxx::document::value* _user , QWidget *parent = nullptr);
    ~DetayliHesapDialog();


    bool getMinitMalzemeGider() const;
    void setMinitMalzemeGider(bool value);

private slots:
    void on_lineEdit_CariControlFilter_textChanged(const QString &arg1);
    void on_listView_CariiControlKisiList_clicked(const QModelIndex &index);



    void mCurrentTabIndex(int index);
// Tab 1 -> Kisi Hesap Kontrol
    void on_pushButton_toggleFullScreen_clicked();

    void on_pushButton_Minimize_clicked();

    void on_pushButton_Close_clicked();

    void on_pushButton_MalzemeGiderCreateTestEntry_clicked();


private:
    Ui::DetayliHesapDialog *ui;
    QStandardItemModel* modelCariControlKisiList;
    QSortFilterProxyModel* proxyCariControlKisiList;
    Delegate::KisiDelegate* mCariKontrolKisiDelegate;
    void initCariControl();
    void initCariKisiList();


// Tab 2 -> Malzeme Giderleri
private:
    QGraphicsScene* mMalzemeGiderScene;
    bool minitMalzemeGider;
    void initMalzemeGider();
    void exportMalzemeGider();
    void ClearMalzemeGiderScene();
    bool addGunBarMalzemeGiderScene(qint64 date , double gelir , double gider );
    bool addAyBartoBottomGunBar(QString ay , double gelir , double gider);
    const qreal barPadding = 5.0;
    qreal mxpos;

    double getReceteGider(std::string receteoid,double receteMiktar);
};

#endif // DETAYLIHESAPDIALOG_H
