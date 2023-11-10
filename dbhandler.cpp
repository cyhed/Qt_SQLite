#include "dbhandler.h"


DbHandler::DbHandler()
{
    char current_work_dir[FILENAME_MAX];
    _getcwd(current_work_dir, sizeof(current_work_dir));
    qDebug() << current_work_dir;

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
QList<QList<QString>> DbHandler::getAllRecordsFromTable(QString nameTable)
{
    QString str_select = "SELECT * FROM " + nameTable;
    QSqlQuery query;


    bool b = query.exec(str_select);
    if(b) {
        QList<QList<QString>>  list ;
        QList<QString>  row;

        query.next();
        int column = query.record().count();
        qDebug()  <<  column;

        do {
            for(int i =0 ; i < column; i++){
                row <<  query.value(i).toString();

            }
            list << row;

        } while(query.next());

        return list;

    } else {
        qDebug() << "Cant reading data";
        qDebug() << query.lastError().text();

        return {{}};
    }
}

QSqlDatabase DbHandler::getDbConnection(){
    return this->bdConnection;
}



