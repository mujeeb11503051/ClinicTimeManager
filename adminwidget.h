#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>

namespace Ui {
class AdminWidget;
}

class AdminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWidget(QWidget *parent = nullptr);
    ~AdminWidget();

private:
    Ui::AdminWidget *ui;

signals:
    void logoutRequested();

private slots:
    void on_btnLogout_clicked();
};

#endif // ADMINWIDGET_H
