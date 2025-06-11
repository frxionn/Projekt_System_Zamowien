#ifndef DODAJZAMOWIENIEDIALOG_H
#define DODAJZAMOWIENIEDIALOG_H

#include <QDialog>
#include <QVector>
#include <QCheckBox>
#include <QStringList>

class QVBoxLayout;

class DodajZamowienieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajZamowienieDialog(QWidget *parent = nullptr);
    // Zwraca nazwy produktów, które były zaznaczone
    QStringList getWybraneProdukty() const;

    // umożliwienie późniejszego dodania checkboxów
    void setPoczatkowoZaznaczone(const QStringList &produkty);

private:
    QVBoxLayout *layoutCheckboxow;
    QVector<QCheckBox*> checkboxy;

    // Ładuje z bazy kategorie i produkty i tworzy nagłówki + checkboxy
    void loadProductsByCategory();
};

#endif // DODAJZAMOWIENIEDIALOG_H
