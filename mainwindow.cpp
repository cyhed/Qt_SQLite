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
    model1->setTable("Employee");
    model1->select();

    this->setCentralWidget(ui->tableView);

    //разрешить модели принимать изменения от виджета QTableView
    model1->setEditStrategy(QSqlTableModel::OnFieldChange);

    //запретить изменения  для виджета
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);

    //разрешения редактирования по двойному щелчку и по нажатию любой клавиши
    ui->tableView->setEditTriggers(QTableView::DoubleClicked|
                                   QTableView::AnyKeyPressed);

    ui->tableView->setModel(model1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

