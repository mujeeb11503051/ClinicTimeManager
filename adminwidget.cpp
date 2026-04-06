#include "adminwidget.h"
#include "ui_adminwidget.h"

AdminWidget::AdminWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminWidget)
{
    ui->setupUi(this);

}

AdminWidget::~AdminWidget()
{
    delete ui;
}

void AdminWidget::on_btnLogout_clicked()
{
    emit logoutRequested();
}

