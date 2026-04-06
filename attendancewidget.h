#ifndef ATTENDANCEWIDGET_H
#define ATTENDANCEWIDGET_H

#include <QWidget>

namespace Ui {
class AttendanceWidget;
}

class AttendanceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AttendanceWidget(QWidget *parent = nullptr);
    ~AttendanceWidget();

private:
    Ui::AttendanceWidget *ui;
};

#endif // ATTENDANCEWIDGET_H
