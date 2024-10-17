#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QMainWindow>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connect_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("data");
    db.setUserName("root");
    db.setPassword("root");
    db.open();

    qDebug() << db.lastError().text();
}


void MainWindow::on_view_data_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM persons");
    ui->tableView->setModel(model);

}


void MainWindow::on_insert_record_clicked()
{
    QSqlQuery query;
    query.prepare(QString::fromLatin1("INSERT INTO persons (LastName, FirstName, Address, City)")
                  + QString::fromLatin1("VALUES ('DAN', 'JOHN', '25 RP', 'COROZAL TOWN');"));
    query.exec();

}


void MainWindow::on_update_record_clicked()
{
    QSqlQuery query;
    query.prepare(QString::fromLatin1("UPDATE persons SET FirstName")
                + QString::fromLatin1("= 'John 2' WHERE PersonID  = 3;"));
    query.exec();
}


void MainWindow::on_delete_record_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM persons WHERE PersonID = 1;");
    query.exec();
}

