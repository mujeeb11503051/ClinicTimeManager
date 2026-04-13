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
        PageInput = 0,
        PageAction     = 1
    };

    QTimer *m_clockTimer;

    int     m_currentEmpId;
    QString m_currentEmpName;


signals:
    void goToAdminRequested();

private slots:
    void on_btnGoToAdmin_clicked();
    void updateDateTime();
    void on_btnVerify_clicked();
    void on_btnBack_clicked();
};

#endif // TERMINALWIDGET_H
