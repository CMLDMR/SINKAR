#ifndef HARICIGIDERDIALOG_H
#define HARICIGIDERDIALOG_H

#include <QtGlobal>

#include "dbuser.h"
#include "delegate.h"

#include <QStandardItemModel>


#include <QMessageBox>
#include <QCompleter>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

namespace Ui {
class HariciGiderDialog;
}

class HariciGiderDialog : public QDialog , public DBUser
{
    Q_OBJECT
public:
    explicit HariciGiderDialog(mongocxx::database* _db , bsoncxx::document::value* _user , QWidget *parent = nullptr);
    ~HariciGiderDialog();

    bool selectedIndex() const;
    void setSelectedIndex(bool selectedIndex);

private slots:
    void on_pushButton_ekle_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::HariciGiderDialog *ui;

    QStandardItemModel* model;

    Delegate::KisiDelegate *delegate;

    void listKategoriList();

    void listCompleter();

    void insertGiderDoc(std::string adi, qint64 julienDate, double miktar, std::string kategoriOid);

    bool mSelectedIndex;

};

#endif // HARICIGIDERDIALOG_H
