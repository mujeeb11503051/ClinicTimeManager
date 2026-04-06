#include "leavewidget.h"
#include "ui_leavewidget.h"

LeaveWidget::LeaveWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LeaveWidget)
{
    ui->setupUi(this);
}

LeaveWidget::~LeaveWidget()
{
    delete ui;
}
