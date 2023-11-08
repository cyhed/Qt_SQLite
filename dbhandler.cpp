#include "dbhandler.h"


DbHandler::DbHandler()
{
    QSqlDatabase connection = QSqlDatabase::addDatabase("QSQLITE");
    connection.setDatabaseName(db_url);
    if (!connection.open()) {
        qDebug() << "Unable to connect database";
        qDebug() << connection.lastError().text();
        DbHandler::~DbHandler();
    }
    else{
        this->bdConnection = connection;
        qDebug() << "Successful connection to the database";
    }
}

DbHandler::~DbHandler(){
    this->bdConnection.close();
    this->bdConnection.removeDatabase(db_url);

};
DbHandler* DbHandler::getInstance()
{
    if (instance == nullptr )
        instance = new DbHandler();
    return instance;
}
QList<QString> DbHandler::getAllEmployees()
{
    QString str_select = "SELECT * FROM Employee";
    QSqlQuery query;
    bool b = query.exec(str_select);
    if(b) {
        while(query.next()) {

            qDebug() << query.value(0).toString() << " " <<
                query.value(1).toString() << " " <<
                query.value(2).toString() << " " <<
                query.value(3).toString() << " " <<
                query.value(4).toString() << " " << query.numRowsAffected() ;}
    } else {
        qDebug() << "Не могу прочитать данные";
        qDebug() << query.lastError().text();
    }
    QList<QString> list = { "one", "two", "three" };
    return list;
}
