#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("hi");


}

MainWindow::~MainWindow()
{
    delete ui;
}

