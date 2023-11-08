#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <QString>
#include <QtSql>
#include <QList>
#include <QDebug>


class DbHandler
{

public:
    ~DbHandler();
    static  DbHandler* getInstance();
    QList<QString> getAllEmployees();
private:
    DbHandler();
    QSqlDatabase bdConnection;
    const static inline QString db_url = "D:\\PERSONAL_folder\\MY_PROJECT\\C_C++_C#\\C_C++\\qt\\lab4 qt_bd\\lab4\\bd\\hospital.db";
    static inline DbHandler* instance = nullptr ;




};

#endif // DBHANDLER_H
