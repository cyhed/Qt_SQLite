#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QString>
#include <QtSql>
#include <QList>
#include <QDebug>

#include <stdio.h>
#include <direct.h>
class DbHandler
{

public:
    ~DbHandler();
    static  DbHandler* getInstance();
    QList<QList<QString>>  getAllRecordsFromTable(QString nameTable);
    QSqlDatabase getDbConnection();
private:
    DbHandler();
    QSqlDatabase bdConnection;
    const static inline QString db_url = ".\\bd\\hospital.db";
    static inline DbHandler* instance = nullptr ;




};

#endif // DBHANDLER_H
