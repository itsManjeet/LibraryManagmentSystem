#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QDebug>
#include <QStringListModel>
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
    void on_Go_Btn_clicked();

private:
    Ui::MainWindow *ui;
    void SetData(QString Number);
};

#endif // MAINWINDOW_H
