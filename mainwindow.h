#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbhandler.h"

#include <QMainWindow>
#include <QtSql>
#include <QLabel>
#include <QSqlTableModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DbHandler* dbHandler ,QWidget *parent = nullptr);
    ~MainWindow();
    DbHandler* dbHandler ;
private:
    QSqlTableModel *model1;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
