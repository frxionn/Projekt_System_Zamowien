#ifndef DODAJZAMOWIENIEDIALOG_H
#define DODAJZAMOWIENIEDIALOG_H

#include <QDialog>
#include <QListWidget>

class DodajZamowienieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajZamowienieDialog(QWidget *parent = nullptr);
    QString getWybranyProdukt() const;

private:
    QListWidget *listaProduktow;
    QString wybranyProdukt;
};

#endif // DODAJZAMOWIENIEDIALOG_H
