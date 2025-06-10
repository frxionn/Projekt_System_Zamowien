#include "DodajZamowienieDialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>

DodajZamowienieDialog::DodajZamowienieDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Wybierz produkty");

    // główny layout dialogu
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // scrollowalny widget z checkboxami
    QWidget *scrollWidget = new QWidget(this);
    layoutCheckboxow = new QVBoxLayout(scrollWidget);
    scrollWidget->setLayout(layoutCheckboxow);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(scrollWidget);
    mainLayout->addWidget(scrollArea);

    // przycisk OK
    QPushButton *okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addWidget(okButton);
}

void DodajZamowienieDialog::dodajProdukt(const QString &nazwaProduktu)
{
    QCheckBox *checkbox = new QCheckBox(nazwaProduktu);
    checkboxy.append(checkbox);
    layoutCheckboxow->addWidget(checkbox);
}

void DodajZamowienieDialog::setPoczatkowoZaznaczone(const QStringList &produkty)
{
    for (QCheckBox *cb : checkboxy) {
        cb->setChecked(produkty.contains(cb->text()));
    }
}

QStringList DodajZamowienieDialog::getWybraneProdukty() const
{
    QStringList wybrane;
    for (const auto &cb : checkboxy) {
        if (cb->isChecked()) {
            wybrane.append(cb->text());
        }
    }
    return wybrane;
}
