#ifndef DIRECTORYWIDGET_H
#define DIRECTORYWIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include "employeedelegate.h"

namespace Ui {
class DirectoryWidget;
}

class DirectoryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DirectoryWidget(QWidget *parent = nullptr);
    ~DirectoryWidget();

private:
    Ui::DirectoryWidget *ui;
    QSqlTableModel *m_directoryModel;
    void initDirectoryGrid();

signals:
    void logoutRequested();
    void employeeSelected(int employeeId, const QString &name);

private slots:
    void on_btnLogout_clicked();
    void on_btnAddEmployee_clicked();
    void on_employeeListView_clicked(const QModelIndex &index);

};

#endif // DIRECTORYWIDGET_H
