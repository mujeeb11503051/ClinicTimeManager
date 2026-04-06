#ifndef LEAVEWIDGET_H
#define LEAVEWIDGET_H

#include <QWidget>

namespace Ui {
class LeaveWidget;
}

class LeaveWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LeaveWidget(QWidget *parent = nullptr);
    ~LeaveWidget();

private:
    Ui::LeaveWidget *ui;
};

#endif // LEAVEWIDGET_H
