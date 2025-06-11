#include "DodajZamowienieDialog.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QWidget>
#include <QTreeWidgetItem>
#include <QTreeWidgetItemIterator>
#include <QSqlQuery>
#include <QLabel>

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

    loadProductsByCategory();

    // przycisk OK
    QPushButton *okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addWidget(okButton);
}

void DodajZamowienieDialog::loadProductsByCategory()
{
    layoutCheckboxow->setSpacing(5);

    // pobierz kategorie + nazwy
    QSqlQuery query(
        "SELECT category, name "
        "FROM products "
        "ORDER BY category, name"
        );

    QString lastCat;
    while (query.next()) {
        const QString cat  = query.value(0).toString();
        const QString name = query.value(1).toString();

        if (cat != lastCat) {
            // dodaj nagłówek kategorii
            QLabel *lbl = new QLabel(cat, this);
            QFont f = lbl->font();
            f.setBold(true);
            lbl->setFont(f);
            layoutCheckboxow->addWidget(lbl);
            lastCat = cat;
        }

        // dodaj checkbox produktu
        QCheckBox *cb = new QCheckBox(name, this);
        checkboxy.append(cb);
        layoutCheckboxow->addWidget(cb);
    }
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
