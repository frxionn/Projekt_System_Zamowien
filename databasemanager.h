#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QVector>
#include <QString>

struct Product {
    int id;
    QString name;
    double price;
    QString category;
    bool available;

    Product(int i = -1, const QString &n = {}, double p = 0.0,
            const QString &c = {}, bool a = false)
        : id(i), name(n), price(p), category(c), available(a) {}
};

class DatabaseManager {
public:
    static bool initializeDatabase();
    static QSqlDatabase getDatabase();

    static bool addProduct(const Product &product);
    static QStringList getAllProducts();
    static bool deleteProduct(int id);
    static bool deleteAllProducts();
    static bool updateProduct(const Product &product);
    static Product getProductByName(const QString &name);

private:
    static void createTables();
};

#endif // DATABASEMANAGER_H
