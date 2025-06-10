#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qsqltablemodel.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Product;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateButtons();

private:
    Ui::MainWindow *ui;

    // Numer aktualnie wybranego stolika (1–6)
    int m_currentTable = 0;

    // Dla każdego stolika przechowujemy listę nazw wybranych produktów
    QVector<QStringList> m_tableOrders;

    // Pokazuje stronę "pageStolik" dla danego stolika:
    void showTable(int tableNumber);

    // Składa łańcuch z nazw + cen + sumy:
    QString formatOrder(const QStringList &names);

    QStringList parseCurrentOrder() const;
    void saveCurrentOrder();
};
#endif // MAINWINDOW_H
