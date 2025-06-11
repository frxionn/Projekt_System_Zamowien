#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "databasemanager.h"
#include <QSqlTableModel>
#include "DodajZamowienieDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    DatabaseManager::deleteAllProducts();

    QVector<Product> products;
    products << Product{0, "Pizza Margherita", 22.50, "Pizza", true}
             << Product{1, "Kawa", 10, "Napoje", 1}
             << Product{2, "Woda", 2, "Napoje", 1}
             << Product{3, "Piwo", 7, "Napoje", 1}
             << Product{4, "Sernik", 18, "Ciasta", 1}
             << Product{5, "Tiramisu", 15, "Ciasta", 1}
             << Product{6, "Herbata", 8, "Napoje", 1};

    for (const Product &product : products) {
        DatabaseManager::addProduct(product);
    }

    ui->setupUi(this);

    m_tableOrders.resize(7);

    auto switchTable = [this](int tableNumber){
        saveCurrentOrder();        // 1) zachowaj zamówienie poprzedniego stolika
        showTable(tableNumber);    // 2) przełącz na nowy stolik
    };

    connect(ui->buttonStolik1, &QPushButton::clicked, this, [=](){ switchTable(1); });
    connect(ui->buttonStolik2, &QPushButton::clicked, this, [=](){ switchTable(2); });
    connect(ui->buttonStolik3, &QPushButton::clicked, this, [=](){ switchTable(3); });
    connect(ui->buttonStolik4, &QPushButton::clicked, this, [=](){ switchTable(4); });
    connect(ui->buttonStolik5, &QPushButton::clicked, this, [=](){ switchTable(5); });
    connect(ui->buttonStolik6, &QPushButton::clicked, this, [=](){ switchTable(6); });

    connect(ui->txtAktualneZamowienie, &QTextEdit::textChanged,
            this, &MainWindow::updateButtons);

    updateButtons();

    //funkcjonalności przycisków - przechodzenie do innych widoków

    connect(ui->buttonHelp, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageHelp); // Przejście na stronę pomocy
    });

    connect(ui->buttonBack, &QPushButton::clicked, this, [this]() {
       ui->stackedWidget->setCurrentWidget(ui->pageHome); // Powrót do strony głównej
    });

    connect(ui->buttonBackStolik1, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->pageHome); // Powrót do strony głównej
    });

    //przycisk dodaj zamowienie

    connect(ui->btnDodajZamowienie, &QPushButton::clicked, this, [=]() {
        DodajZamowienieDialog dialog(this);

        if (dialog.exec() == QDialog::Accepted) {
            auto wybrane = dialog.getWybraneProdukty();
            if (!wybrane.isEmpty()) {
                // pobierz zaznaczone produkty
                const QStringList wybrane = dialog.getWybraneProdukty();

                // zapisz w wektorze dla bieżącego stolika
                m_tableOrders[m_currentTable] = wybrane;

                // odśwież widok: pokaz zamówienie + przyciski + etykiety
                showTable(m_currentTable);
            }
        }
    });

    //przycisk modyfikuj zamowienie

    connect(ui->btnModyfikujZamowienie, &QPushButton::clicked, this, [this]() {
        DodajZamowienieDialog dialog(this);

        // wstępne zaznaczenie z tego, co już jest zapisane
        dialog.setPoczatkowoZaznaczone(m_tableOrders[m_currentTable]);

        if (dialog.exec() == QDialog::Accepted) {
            // pobierz nową listę
            const QStringList wybrane = dialog.getWybraneProdukty();

            // zapisz w wektorze
            m_tableOrders[m_currentTable] = wybrane;

            // odśwież widok
            showTable(m_currentTable);
        }
    });

    //przycisk usun zamowienie
    connect(ui->btnUsunZamowienie, &QPushButton::clicked, this, [=]() {
        // usuń zamówienie bieżącego stolika
        m_tableOrders[m_currentTable].clear();
        // odśwież widok i przyciski
        showTable(m_currentTable);
    });

    //style dla całego programu
    //this->setStyleSheet("background-color: white;");
    this->setStyleSheet("QMainWindow {background-color: white; } QPushButton { background-color: #c72121; border: 3px solid #fe5152; border-radius: 10px; padding: 6px; color: white; font-size: 15px; }");
    this->setWindowTitle("Symulator Kawiarni");
    this->setWindowIcon(QIcon(":/images/images/logo.png"));
}


MainWindow::~MainWindow()
{
    delete ui;
}

// Pokazuje widok stolika, ustawia jego numer i istniejące zamówienie
void MainWindow::showTable(int tableNumber)
{
    m_currentTable = tableNumber;

    // Zmieniamy nagłówek ze stałym widgetem label_2 w pageStolik1
    ui->label_2->setText(QString("STOLIK NR %1").arg(tableNumber));  // :contentReference[oaicite:0]{index=0}

    // Wyświetlamy zamówienie zapisane w m_tableOrders
    ui->txtAktualneZamowienie->setPlainText(
        formatOrder(m_tableOrders[tableNumber])
        );

    // Przełączamy stronę (tutaj używamy tylko jednej strony pageStolik1)
    ui->stackedWidget->setCurrentWidget(ui->pageStolik1);         // :contentReference[oaicite:1]{index=1}

    // Włącz/wyłącz przyciski zgodnie ze stanem (teraz jest aktywny stolik)
    updateButtons();
}

// Buduje tekst z listy nazw: każda linia "Nazwa – Cena zł", + suma na dole
QString MainWindow::formatOrder(const QStringList &names)
{
    double sum = 0.0;
    QString text;

    for (const QString &nazwa : names) {
        Product p = DatabaseManager::getProductByName(nazwa);
        text += QString("%1 – %2 zł\n")
                    .arg(p.name)
                    .arg(QString::number(p.price, 'f', 2));
        sum += p.price;
    }

    if (!names.isEmpty()) {
        text += "\nŁączna suma: "
                + QString::number(sum, 'f', 2)
                + " zł";
    }

    return text;
}

// Parsuje tekst z ui->txtAktualneZamowienie i zwraca listę samych nazw
QStringList MainWindow::parseCurrentOrder() const
{
    QStringList lines = ui->txtAktualneZamowienie
                            ->toPlainText()
                            .split('\n', Qt::SkipEmptyParts);
    QStringList names;
    for (const QString &line : lines) {
        if (line.startsWith("Łączna suma"))
            continue;
        names.append(line.section(" – ", 0, 0));
    }
    return names;
}

/// Zachowuje bieżące zamówienie do wektora pod indeksem m_currentTable
void MainWindow::saveCurrentOrder()
{
    if (m_currentTable > 0) {
        m_tableOrders[m_currentTable] = parseCurrentOrder();
    }
}

void MainWindow::updateButtons()
{
    // Sprawdź, czy jest jakiś tekst (czyli aktywne zamówienie)
    const bool hasOrder = !ui->txtAktualneZamowienie
                               ->toPlainText()
                               .trimmed()
                               .isEmpty();

    // Dodaj = tylko gdy brak aktywnego zamówienia
    ui->btnDodajZamowienie->setEnabled(!hasOrder);

    // Modyfikuj / Usuń = tylko gdy jest aktywne zamówienie
    ui->btnModyfikujZamowienie->setEnabled(hasOrder);
    ui->btnUsunZamowienie   ->setEnabled(hasOrder);

    // Zaktualizuj etykiety przycisków stolików
    for (int i = 1; i <= 6; ++i) {
        // Czy stolik i ma zapisane zamówienie?
        bool occupied = !m_tableOrders[i].isEmpty();

        // Budujemy tekst: "Stolik N" lub "Stolik N - Z"
        QString label = QString("Stolik %1").arg(i);
        if (occupied) {
            label += " - Z";
        }

        // Przypisz do właściwego QPushButton
        switch (i) {
        case 1: ui->buttonStolik1->setText(label); break;
        case 2: ui->buttonStolik2->setText(label); break;
        case 3: ui->buttonStolik3->setText(label); break;
        case 4: ui->buttonStolik4->setText(label); break;
        case 5: ui->buttonStolik5->setText(label); break;
        case 6: ui->buttonStolik6->setText(label); break;
        }
    }
}
