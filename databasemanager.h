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
};

class DatabaseManager {
public:
    static bool initializeDatabase();
    static QSqlDatabase getDatabase();

    static bool addProduct(const Product &product);
    static QStringList getAllProducts();
    static bool deleteProduct(int id);
    static bool updateProduct(const Product &product);

private:
    static void createTables();
};

#endif // DATABASEMANAGER_H
