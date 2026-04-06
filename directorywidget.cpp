#include "directorywidget.h"
#include "ui_directorywidget.h"

DirectoryWidget::DirectoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DirectoryWidget)
{
    ui->setupUi(this);
}

DirectoryWidget::~DirectoryWidget()
{
    delete ui;
}

void DirectoryWidget::on_btnLogout_clicked()
{
    emit logoutRequested();
}

