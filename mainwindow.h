#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbhandler.h"
#include "NonEditTableColumnDelegate.h"
#include <QMainWindow>
#include <QtSql>
#include <QLabel>
#include <QSqlTableModel>
#include <QMessageBox>


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
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();



    void on_Employee_button_clicked();

    void on_Patient_button_clicked();

    void on_Update_button_clicked();

    void on_submit_clicked();

private:
    int lastRow;
    QSqlTableModel *model1;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
