#include "profilewidget.h"
#include "ui_profilewidget.h"

ProfileWidget::ProfileWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfileWidget)
{
    ui->setupUi(this);
    m_currentEmpId = -1;
}

ProfileWidget::~ProfileWidget()
{
    delete ui;
}

void ProfileWidget::loadEmployee(int empId, const QString &name, const QString &dob, const QString &personalNumber, int vacationDays)
{
    m_currentEmpId = empId;
    ui->lblName->setText(name);
    ui->lblDob->setText("Date of Birth: " + dob);
    ui->lblPersonalNumber->setText("Personal ID: " + personalNumber);
    ui->lblVacation->setText("Vacation Days: " + QString::number(vacationDays));
}

void ProfileWidget::on_btn_back_clicked()
{
    emit backRequested();
}


void ProfileWidget::on_btn_attendance_clicked()
{
    emit attendanceRequested();
}


void ProfileWidget::on_btn_leave_clicked()
{
    emit leaveRequested();
}

