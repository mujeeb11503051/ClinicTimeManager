#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class TerminalWidget;
}

class TerminalWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TerminalWidget(QWidget *parent = nullptr);
    ~TerminalWidget();

private:
    Ui::TerminalWidget *ui;

    enum Pages {
        pageTerminal = 0,
        pageAction    = 1
    };

    QTimer *m_clockTimer;


signals:
    void goToAdminRequested();

private slots:
    void on_btnGoToAdmin_clicked();
    void updateDateTime();
};

#endif // TERMINALWIDGET_H
