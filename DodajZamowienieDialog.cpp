#include "dodajzamowieniedialog.h"
#include <QVBoxLayout>
#include <QPushButton>

DodajZamowienieDialog::DodajZamowienieDialog(QWidget *parent)
    : QDialog(parent), listaProduktow(new QListWidget(this))
{
    // Przykładowe produkty
    listaProduktow->addItems({"Kawa Americano", "Kawa Cappucchino", "Kawa Espresso", "Ciasto Sernik", "Herbata Zielona", "Muffin Czekoladowy","Sok Wyciskany"});

    QPushButton *okButton = new QPushButton("OK", this);

    connect(okButton, &QPushButton::clicked, this, [=]() {
        if (listaProduktow->currentItem()) {
            wybranyProdukt = listaProduktow->currentItem()->text();
            accept();
        }
    });

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(listaProduktow);
    layout->addWidget(okButton);
    setLayout(layout);
}

QString DodajZamowienieDialog::getWybranyProdukt() const {
    return wybranyProdukt;
}
