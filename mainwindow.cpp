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

    connect(ui->btnDodajZamowienie, &QPushButton::clicked, this, [=]() {
        DodajZamowienieDialog dialog(this);

        //przykładowe dane testowe
        dialog.dodajProdukt("Pizza Margherita");
        dialog.dodajProdukt("Kawa");
        dialog.dodajProdukt("Herbata");
        dialog.dodajProdukt("Frytki");
        dialog.dodajProdukt("Piwo");

        if (dialog.exec() == QDialog::Accepted) {
            QStringList wybrane = dialog.getWybraneProdukty();
            if (!wybrane.isEmpty()) {
                QString tekst = ui->txtAktualneZamowienie->toPlainText();
                for (const QString &prod : wybrane) {
                    tekst += prod + "\n";
                }
                ui->txtAktualneZamowienie->setPlainText(tekst);
            }
        }
    });

    //przycisk modyfikuj zamowienie

    connect(ui->btnModyfikujZamowienie, &QPushButton::clicked, this, [=]() {
        DodajZamowienieDialog dialog(this);

        dialog.dodajProdukt("Pizza Margherita");
        dialog.dodajProdukt("Kawa");
        dialog.dodajProdukt("Herbata");
        dialog.dodajProdukt("Frytki");

        // pobiera obecne produkty z pola tekstyowego
        QStringList obecneZamowienie = ui->txtAktualneZamowienie->toPlainText().split('\n', Qt::SkipEmptyParts);

        // zaznacza, które są aktualnie w zamówieniu
        dialog.setPoczatkowoZaznaczone(obecneZamowienie);

        if (dialog.exec() == QDialog::Accepted) {
            QStringList wybrane = dialog.getWybraneProdukty();
            ui->txtAktualneZamowienie->setPlainText(wybrane.join("\n"));
        }
    });

    //przycisk usun zamowienie
    connect(ui->btnUsunZamowienie, &QPushButton::clicked, this, [=]() {
        QString aktualnyTekst = ui->txtAktualneZamowienie->toPlainText();
        aktualnyTekst = "";
        ui->txtAktualneZamowienie->setPlainText(aktualnyTekst);
    });
}


MainWindow::~MainWindow()
{
    delete ui;
}
