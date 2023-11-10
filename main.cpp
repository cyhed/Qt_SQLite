#include "mainwindow.h"
#include "dbhandler.h"
#include <QApplication>

#include <QList>
#include <QDebug>
int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

    DbHandler* dbHandler =  DbHandler::getInstance();
    MainWindow w(dbHandler );

    w.dbHandler = dbHandler;

    w.show();
    return a.exec();
}





/*
    QList<QList<QString>>  listEmployees = dbHandler->getAllRecordsFromTable("Employee");
    for(int i = 0 ; i< listEmployees.size() ; i++){
        QList<QString> row = listEmployees.at(i);
        for(int j = 0 ; j < row.size() ; j++)
            qDebug() << row.at(j);
    }
*/
