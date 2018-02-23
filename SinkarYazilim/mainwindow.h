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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    mongocxx::client* Client;
    mongocxx::database db;


private slots:

    void setMessage(const char* message);


    void on_pushButton_Personel_clicked();
    void on_pushButton_options_clicked();
};

#endif // MAINWINDOW_H
