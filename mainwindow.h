#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QDebug>
#include <QDate>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_GO_BTN_clicked();

    void on_BACK_BTN_clicked();

private:
    QDate date;
    QSqlDatabase db;
    int ROLL_NO = 0;
    Ui::MainWindow *ui;
    int load_data(int rollno);
};

#endif // MAINWINDOW_H
