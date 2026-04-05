#include "databasemanager.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::isDbHealthy() const
{
    if (!m_db.isOpen()) return false;

    QSqlQuery query("PRAGMA integrity_check");
    if (query.next() && query.value(0).toString() == "ok")
        return true;

    return false;
}

void DatabaseManager::addTestEmployee()
{
    // Don't insert if employees already exist
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM employees");
    if (query.next() && query.value(0).toInt() > 0)
        return;

    // Just call addEmployee() with hardcoded test data
    // Same logic, no duplication
    addEmployee("John Doe",   QDate(1995,  5, 25), 30);
    addEmployee("Jane Smith", QDate(1988, 11, 12), 30);

    qDebug() << "Test employees added.";
}

bool DatabaseManager::addEmployee(const QString &name, const QDate &dob, int vacation)
{
    QSqlQuery query;
    query.prepare("INSERT INTO employees (name, dob, personal_number, vacation_days) "
                  "VALUES (:name, :dob, :p_num, :vacation)");

    query.bindValue(":name", name);
    query.bindValue(":dob",  dob.toString("yyyy-MM-dd"));
    query.bindValue(":p_num", dob.toString("ddMMyy")); // same logic as test employee
    query.bindValue(":vacation", vacation);

    if (!query.exec()) {
        qDebug() << "Add employee error:" << query.lastError().text();
        return false;
    }
    return true;
}

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject{parent}
{
    initDatabase();
}

void DatabaseManager::initDatabase()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(path);

    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QString dbPath = dir.filePath("attendance.db");

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbPath);

    if (!m_db.open()) {
        qDebug() << "Error: Could not open database!" << m_db.lastError().text();
    } else {
        qDebug() << "Success: Connected to database at" << dbPath;
        createTables();
    }
}

void DatabaseManager::createTables()
{
    QSqlQuery query;

    // Table 1: Employees
    QString employeesTable = R"(
        CREATE TABLE IF NOT EXISTS employees (
            id               INTEGER PRIMARY KEY AUTOINCREMENT,
            name             TEXT    NOT NULL,
            dob              DATE,
            personal_number  TEXT    UNIQUE,
            vacation_days    INTEGER DEFAULT 30
        )
    )";

    // Table 2: Time logs (terminal clock-in/out events)
    QString logsTable = R"(
        CREATE TABLE IF NOT EXISTS time_logs (
            id           INTEGER PRIMARY KEY AUTOINCREMENT,
            employee_id  INTEGER  NOT NULL,
            timestamp    DATETIME DEFAULT CURRENT_TIMESTAMP,
            type         TEXT     NOT NULL,
            FOREIGN KEY(employee_id) REFERENCES employees(id)
        )
    )";

    if (!query.exec(employeesTable))
        qDebug() << "Error creating employees table:" << query.lastError().text();
    else
        qDebug() << "Employees table is ready.";

    if (!query.exec(logsTable))
        qDebug() << "Error creating time_logs table:" << query.lastError().text();
    else
        qDebug() << "Time logs table is ready.";
}
