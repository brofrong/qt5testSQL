#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QtSql/QSqlDatabase>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_string_returnPressed();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString connectToDB(QSqlDatabase db);
};



#endif // MAINWINDOW_H
