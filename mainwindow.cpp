#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(DbHandler* dbHandler ,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->dbHandler = dbHandler;

    QSqlDatabase connection = dbHandler->getDbConnection();

    QSqlTableModel *model1;
    model1 = new QSqlTableModel(this);
    this->model1 = model1;
    model1->setTable("Employee");
    model1->select();



    //разрешить модели принимать изменения от виджета QTableView
    model1->setEditStrategy(QSqlTableModel::OnFieldChange);

    //запретить изменения  для виджета
    //ui->tableView->setEditTriggers(QTableView::NoEditTriggers);

    //разрешения редактирования по двойному щелчку и по нажатию любой клавиши
    ui->tableView->setEditTriggers(QTableView::DoubleClicked|
                                   QTableView::AnyKeyPressed);
    //запрет редактирования первого столбца
    ui->tableView->setItemDelegateForColumn(0, new NonEditTableColumnDelegate());
    ui->tableView->setModel(model1);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if ( QMessageBox::question(this, "Delete row?",
                              QString("Do you want to delete selected row?"),
                              QMessageBox::Ok|QMessageBox::Cancel) == QMessageBox::Ok )
    {
        this->model1->removeRow( ui->tableView->currentIndex().row() );
        this->model1->select();
    }
}



void MainWindow::on_pushButton_2_clicked()
{
     qDebug() << model1->tableName();

    QString str_insert = "INSERT INTO "+ model1->tableName()  +" VALUES ();";

    QSqlQuery query;
    bool b = query.exec(str_insert);
    if (!b) {
        qDebug() << query.lastError().text();
    }
}






void MainWindow::on_Employee_button_clicked()
{
    model1->setTable("Employee");
    model1->select();
}


void MainWindow::on_Patient_button_clicked()
{
    model1->setTable("Patient");
    model1->select();
}


void MainWindow::on_Update_button_clicked()
{
    model1->select();
}


