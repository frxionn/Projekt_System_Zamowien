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

    //funkcjonalności przycisków - przechodzenie do innych widoków

    connect(ui->buttonHelp, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageHelp);; // Przejście na stronę pomocy
    });

    connect(ui->buttonBack, &QPushButton::clicked, this, [this]() {
       ui->stackedWidget->setCurrentWidget(ui->pageHome);; // Powrót do strony głównej
    });

    connect(ui->buttonStolik1, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageStolik1);; // Przejście do strony stolik1
    });

    connect(ui->buttonBackStolik1, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageHome);; // Powrót do strony głównej
    });
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
