#include "databasemanager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool DatabaseManager::initializeDatabase() {
    if (!QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("restaurant.db");

        if (!db.open()) {
            qDebug() << "Błąd otwierania bazy:" << db.lastError().text();
            return false;
        }
    }

    createTables();
    return true;
}

QSqlDatabase DatabaseManager::getDatabase() {
    return QSqlDatabase::database();
}

void DatabaseManager::createTables() {
    QSqlQuery query;
    QString create = R"(
        CREATE TABLE IF NOT EXISTS products (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            price REAL NOT NULL,
            category TEXT,
            available INTEGER DEFAULT 1
        )
    )";

    if (!query.exec(create)) {
        qDebug() << "Błąd tworzenia tabeli products:" << query.lastError().text();
    }
}

bool DatabaseManager::addProduct(const Product &product) {
    QSqlQuery query;
    query.prepare("INSERT INTO products (name, price, category, available) VALUES (?, ?, ?, ?)");
    query.addBindValue(product.name);
    query.addBindValue(product.price);
    query.addBindValue(product.category);
    query.addBindValue(product.available ? 1 : 0);
    if (!query.exec()) {
        qDebug() << "Błąd dodawania produktu:" << query.lastError().text();
        return false;
    }
    return true;
}

QVector<Product> DatabaseManager::getAllProducts() {
    QVector<Product> products;
    QSqlQuery query("SELECT id, name, price, category, available FROM products");

    while (query.next()) {
        Product p;
        p.id = query.value(0).toInt();
        p.name = query.value(1).toString();
        p.price = query.value(2).toDouble();
        p.category = query.value(3).toString();
        p.available = query.value(4).toInt() != 0;
        products.append(p);
    }

    return products;
}

bool DatabaseManager::deleteProduct(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM products WHERE id = ?");
    query.addBindValue(id);
    if (!query.exec()) {
        qDebug() << "Błąd usuwania produktu:" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::updateProduct(const Product &product) {
    QSqlQuery query;
    query.prepare(R"(
        UPDATE products
        SET name = ?, price = ?, category = ?, available = ?
        WHERE id = ?
    )");
    query.addBindValue(product.name);
    query.addBindValue(product.price);
    query.addBindValue(product.category);
    query.addBindValue(product.available ? 1 : 0);
    query.addBindValue(product.id);

    if (!query.exec()) {
        qDebug() << "Błąd aktualizacji produktu:" << query.lastError().text();
        return false;
    }
    return true;
}
