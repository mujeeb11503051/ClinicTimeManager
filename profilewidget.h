#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>

namespace Ui {
class ProfileWidget;
}

class ProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWidget(QWidget *parent = nullptr);
    ~ProfileWidget();

    // Called by AdminWidget when an employee is selected
    void loadEmployee(int empId, const QString &name,
                      const QString &dob, const QString &personalNumber,
                      int vacationDays);


signals:
    void backRequested();
    void attendanceRequested();
    void leaveRequested();


private slots:
    void on_btn_back_clicked();

    void on_btn_attendance_clicked();

    void on_btn_leave_clicked();

private:
    Ui::ProfileWidget *ui;
    int m_currentEmpId;
};

#endif // PROFILEWIDGET_H
