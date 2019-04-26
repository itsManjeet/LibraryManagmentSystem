#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->PAGE->setCurrentIndex(0);
    resize(600,400);
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
            SetData(Number);
    } else {
        //ui->MSGLBL->styleSheet("QLabel { color : red }");
        ui->MSGLBL->setText("Database Missing");
    }
}

void
MainWindow::SetData(QString Number)
{
    resize(1200,800);
    QString Name, Branch;
    QFile Info("Data/" + Number + "/Info");
    if (Info.open(QIODevice::ReadOnly)) {
        QTextStream in(&Info);
        Name = in.readLine();
        Branch = in.readLine();
    }
    Info.close();
    ui->NAME_BOX->setText(Name);
    ui->ROLL_BOX->setText(Number);
    ui->BRANCH_BOX->setText(Branch);

    QDir BookIssued("Data/" + Number + "/BookIssued/" );
    QStringList Books = BookIssued.entryList(QStringList() << "*",QDir::Files);
    ui->BOOK_ISSUED_LIST->insertItems(1,Books);
    ui->PAGE->setCurrentIndex(ui->PAGE->currentIndex() + 1);
}
