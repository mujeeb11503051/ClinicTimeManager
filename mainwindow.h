#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "terminalwidget.h"
#include "adminwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    TerminalWidget *m_terminal;
    AdminWidget    *m_admin;

    // Add the enum:
    enum Pages {
        TerminalPage = 0,
        AdminPage    = 1
    };

};
#endif // MAINWINDOW_H
