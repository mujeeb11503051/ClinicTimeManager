#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QDate>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:

    static DatabaseManager& instance();

    // Prevent copying — singleton pattern
    DatabaseManager(const DatabaseManager&) = delete;
    void operator=(const DatabaseManager&) = delete;

    bool isDbHealthy() const;
    void addTestEmployee();
    bool addEmployee(const QString &name, const QDate &dob, int vacation);

private:
    explicit DatabaseManager(QObject *parent = nullptr);
    void initDatabase();
    void createTables();

    QSqlDatabase m_db;


signals:
};

#endif // DATABASEMANAGER_H
