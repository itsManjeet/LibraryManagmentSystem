#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    date = QDate::currentDate();
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->ROLL_NO_BOX->setInputMask("99999999999999");
    ui->MSG_LABEL->setStyleSheet("QLabel {color : red;}");

    /*  Load Database  */

    db = QSqlDatabase::addDatabase("QSQLITE","Students Connection");
    db.setDatabaseName("/home/itsmanjeet/Projects/LibraryManagmentTools/Library/student.db");
    if (!db.open()) {
        ui->MSG_LABEL->setText("Error while Opening Students Database\n" + db.lastError().text());
    }

    bookdb = QSqlDatabase::addDatabase("QSQLITE","Books Database");
    bookdb.setDatabaseName("/home/itsmanjeet/Projects/LibraryManagmentTools/Library/books.db");
    if (!bookdb.open()) {
        ui->MSG_LABEL->setText( ui->MSG_LABEL->text() + "Error while Opening Books Database\n" + bookdb.lastError().text());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_GO_BTN_clicked()
{
    ROLL_NO = ui->ROLL_NO_BOX->text().toInt();
    load_data(ROLL_NO);
}

int MainWindow::load_data(int rollno)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM STUDENT WHERE ROLL = " + QString::number(rollno));
    if(!query.exec()) {
        ui->MSG_LABEL->setText("Error while Processing Query : SELECT ROLL \n" + db.lastError().text());
    }
    query.next();
    int out = query.value(0).toInt();
    if (out == rollno){
        qDebug("Data for %d found",rollno);
        ui->stackedWidget->setCurrentIndex(1);
        ui->Name_Box->setText(query.value(1).toString());
        ui->Roll_NoBox->setText(QString::number(rollno));
        ui->SemBox->setText(QString::number( (date.year() - ((rollno % 100) + 2000))*2) + "th");
        for(int i = 0; i<4; i++) {
            BBK[i] = query.value(i+2).toInt();
            ui->Book_Bank_List->addItem(QString::number(query.value(i+2).toInt()));
        }
        for(int i= 0; i<3;i++) {
            MOB[i] = query.value(i+6).toInt();
            ui->MonthlyBookList->addItem(QString::number(query.value(i+6).toInt()));
        }
    }    else {
        ui->MSG_LABEL->setText("No Data Found for rollno \n" + db.lastError().text());
    }

}

void MainWindow::on_BACK_BTN_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->ROLL_NO_BOX->setText("");
    ROLL_NO = 0;
}

void MainWindow::on_Book_Bank_List_itemDoubleClicked(QListWidgetItem *item)
{
    ui->stackedWidget->setCurrentIndex(2);
    QSqlQuery query(bookdb);
    query.prepare("SELECT * FROM BOOKS WHERE ID = " + item->text());
    if(!query.exec()) {
        ui->MSG_LABEL->setText("Error while Processing Query : SELECT BOOK \n" + db.lastError().text());
    }
    query.next();
    ui->MSG_LABEL->setText(item->text());
    ui->BOOK_ID->setText(QString::number(query.value(0).toInt()));
    ui->OCCUPIED_BY->setText(QString::number(query.value(1).toInt()));
}

void MainWindow::on_BACK_FROM_BOOK_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
