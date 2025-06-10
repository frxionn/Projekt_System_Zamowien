#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databasemanager.h"
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Product p = {0, "Pizza Margherita", 22.50, "Pizza", true};
    DatabaseManager::addProduct(p);
    QSqlDatabase db = DatabaseManager::getDatabase();

    ui->setupUi(this);

    model = new QSqlTableModel(this, db);
    model->setTable("products");
    model->select();

    //funkcjonalności przycisków - przechodzenie do innych widoków

    connect(ui->buttonHelp, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageHelp); // Przejście na stronę pomocy
    });

    connect(ui->buttonBack, &QPushButton::clicked, this, [this]() {
       ui->stackedWidget->setCurrentWidget(ui->pageHome); // Powrót do strony głównej
    });

    connect(ui->buttonStolik1, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageStolik1); // Przejście do strony stolik1
    });

    connect(ui->buttonAddOrder, &QPushButton::clicked, this, [&, this]() {
        ui->tableView->setModel(model);
    });

    connect(ui->buttonBackStolik1, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageHome); // Powrót do strony głównej
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
