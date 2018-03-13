#ifndef ADDMALZEMEDIALOG_H
#define ADDMALZEMEDIALOG_H


#include <QtGlobal>



#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif


#include "../snkkey.h"
#include "qtbsonobject.h"

#include <QStandardItem>
#include <QStandardItemModel>

#include <QMessageBox>

namespace Ui {
class addMalzemeDialog;
}

class addMalzemeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addMalzemeDialog(mongocxx::database* _db , QWidget *parent = 0);
    ~addMalzemeDialog();


    bool Accepted() const;

    QModelIndex getCurrentIndex() const;

    double getSelectedValue() const;

    QString getSelectedValueType() const;

    std::string getOid() const;

private:
    Ui::addMalzemeDialog *ui;


    QModelIndex CurrentIndex;
    void setCurrentIndex(const QModelIndex &value);

    std::string m_oid;
    void setOid(const std::string &oid);

    double mSelectedValue;
    void setSelectedValue(double selectedValue);

    QString mSelectedValueType;
    void setSelectedValueType(const QString &selectedValueType);

    bool m_Accepted;
    void setAccepted(bool Accepted);

    mongocxx::database* db;

    QStandardItemModel* model;

    void refreshKategori();

    void setmessage(QString e);
    void setmessage(mongocxx::exception &e);
    void setmessage(bsoncxx::exception &e);

private slots:
    void refreshList(QString val);
    void on_comboBox_currentIndexChanged(int index);
    void on_listView_doubleClicked(const QModelIndex &index);
};

#endif // ADDMALZEMEDIALOG_H
