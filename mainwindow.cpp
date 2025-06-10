#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databasemanager.h"
#include <QSqlTableModel>
#include "DodajZamowienieDialog.h"

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

    connect(ui->buttonStolik2, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageStolik1);; // Przejście do strony stolik1
    });
    connect(ui->buttonStolik3, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageStolik1);; // Przejście do strony stolik1
    });
    connect(ui->buttonStolik4, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageStolik1);; // Przejście do strony stolik1
    });
    connect(ui->buttonStolik5, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageStolik1);; // Przejście do strony stolik1
    });
    connect(ui->buttonStolik6, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageStolik1);; // Przejście do strony stolik1
    });


    connect(ui->buttonBackStolik1, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageHome); // Powrót do strony głównej
    });

    //przycisk dodaj zamowienie

    // connect(ui->btnDodajZamowienie, &QPushButton::clicked, this, [=]() {
    //     DodajZamowienieDialog dialog(this);
    //     if (dialog.exec() == QDialog::Accepted) {
    //         QString produkt = dialog.getWybranyProdukt();
    //         if (!produkt.isEmpty()) {
    //             QString aktualnyTekst = ui->txtAktualneZamowienie->toPlainText();
    //             aktualnyTekst += produkt + "\n";
    //             ui->txtAktualneZamowienie->setPlainText(aktualnyTekst);
    //         }
    //     }
    // });

    // //przycisk usun zamowienie
    // connect(ui->btnUsunZamowienie, &QPushButton::clicked, this, [=]() {
    //     QString aktualnyTekst = ui->txtAktualneZamowienie->toPlainText();
    //     aktualnyTekst = "";
    //     ui->txtAktualneZamowienie->setPlainText(aktualnyTekst);
    // });
}


MainWindow::~MainWindow()
{
    delete ui;
}
