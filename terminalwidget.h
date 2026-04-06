#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H

#include <QWidget>

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


signals:
    void goToAdminRequested();

};

#endif // TERMINALWIDGET_H
