#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Go_Btn_clicked()
{
    QString Number = ui->SearchBox->text();
    if (QDir("Data/" + Number).exists()) {
            //ui->MSGLBL->styleSheet("QLabel { color : green }");
            ui->MSGLBL->setText("Database Found");
    } else {
        //ui->MSGLBL->styleSheet("QLabel { color : red }");
        ui->MSGLBL->setText("Database Missing");
    }
}
