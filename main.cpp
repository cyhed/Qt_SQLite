#include "mainwindow.h"
#include "dbhandler.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DbHandler* dbHandler =  DbHandler::getInstance();
    dbHandler->getAllEmployees();
    w.show();
    return a.exec();
}
