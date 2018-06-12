#include "mainwindow.h"
#include <QApplication>


#include "personel/logindialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mongocxx::instance instance{};

    mongocxx::client* Client;
    try {
        Client = new mongocxx::client(mongocxx::uri(SNKKey::dbresturl.c_str()));
    } catch (mongocxx::exception& e) {
        std::cout << "Error Connection " << e.what() << std::endl;
        return 0;
    }

    mongocxx::database db;

    db = Client->database(SNKKey::dbrest.c_str());

    MainWindow w(&db);

    LoginDialog* mLoginDialog = new LoginDialog(&db);
    QObject::connect(mLoginDialog,&LoginDialog::signSuccessFully,&w,&MainWindow::showMainWindow);
    QObject::connect(mLoginDialog,&LoginDialog::applicationQuit,[&a](){
        a.quit();
    });
    mLoginDialog->exec();
    mLoginDialog->deleteLater();

    return a.exec();
}
