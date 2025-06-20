#include "mainwindow.h"
#include "databasemanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!DatabaseManager::initializeDatabase()) {
        qCritical() << "Nie udało się zainicjalizować bazy danych.";
        return -1;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
