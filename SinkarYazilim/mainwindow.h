#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGlobal>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif



#include <QLabel>
#include <QProgressBar>



#include "../snkkey.h"
#include "mongoheaders.h"


using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(mongocxx::database* _db , QWidget *parent = 0);
    ~MainWindow();


public slots:
    void showMainWindow(std::string personelOid);

private:
    Ui::MainWindow *ui;


private slots:

    void setMessage(const char* message);


    void on_pushButton_Personel_clicked();
    void on_pushButton_options_clicked();

    void applicationQuit();




    void on_pushButton_Stok_clicked();

    void on_pushButton_OpenKasa_clicked();

    void on_pushButton_Close_clicked();

    void on_pushButton_Cari_clicked();

    void on_pushButton_ExternalOutGoing_clicked();

private:
    mongocxx::database *db;
    bsoncxx::document::value User;
};

#endif // MAINWINDOW_H
