#include "attendancewidget.h"
#include "ui_attendancewidget.h"

AttendanceWidget::AttendanceWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AttendanceWidget)
{
    ui->setupUi(this);
}

AttendanceWidget::~AttendanceWidget()
{
    delete ui;
}
