#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connectToDB(this->db);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(this->db.isOpen()){
        ui->textBrowser->setText("db connected");
    }else{
        ui->textBrowser->setText("aaaaaaa");
    }

}

void MainWindow::on_string_returnPressed()
{
    QString test;
    test = ui->string->text();
    ui->textBrowser->setText(test);
}
QSqlDatabase db;
QString MainWindow::connectToDB(QSqlDatabase db){
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("brofrong-home");
    bool ok = db.open();
    if(ok){
        return "db";
    } else{
        throw "db not connected";
    }
}
