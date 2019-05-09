#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QDebug>
#include <QDate>
#include <QMessageBox>
#include <QListWidgetItem>
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

    void on_Book_Bank_List_itemDoubleClicked(QListWidgetItem *item);

    void on_BACK_FROM_BOOK_clicked();

private:
    QDate date;
    QSqlDatabase db,bookdb;
    int ROLL_NO = 0;
    int BBK[4];
    int MOB[3];
    Ui::MainWindow *ui;
    int load_data(int rollno);
};

#endif // MAINWINDOW_H
