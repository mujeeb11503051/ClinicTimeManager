#ifndef DIRECTORYWIDGET_H
#define DIRECTORYWIDGET_H

#include <QWidget>

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

signals:
    void logoutRequested();

private slots:
    void on_btnLogout_clicked();
};

#endif // DIRECTORYWIDGET_H
