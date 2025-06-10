#ifndef DODAJZAMOWIENIEDIALOG_H
#define DODAJZAMOWIENIEDIALOG_H

#include <QDialog>
#include <QVector>
#include <QCheckBox>

class QVBoxLayout;

class DodajZamowienieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajZamowienieDialog(QWidget *parent = nullptr);
    QStringList getWybraneProdukty() const;

    // umożliwienie późniejszego dodania checkboxów
    void dodajProdukt(const QString &nazwaProduktu);
    void setPoczatkowoZaznaczone(const QStringList &produkty);

private:
    QVBoxLayout *layoutCheckboxow;
    QVector<QCheckBox*> checkboxy;
};

#endif // DODAJZAMOWIENIEDIALOG_H
