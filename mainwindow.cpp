#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
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

void connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); // <- Użyj QMYSQL

    db.setHostName("localhost");
    db.setPort(3306); // domyślny port MySQL
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("%zEK74*K4Rj&45s8%&#C64e!");

    if (!db.open()) {
        qDebug() << "Błąd połączenia z bazą:" << db.lastError().text();
    } else {
        qDebug() << "Połączono z MySQL!";
    }
}
