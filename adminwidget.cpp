#include "adminwidget.h"
#include "ui_adminwidget.h"

AdminWidget::AdminWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminWidget)
{
    ui->setupUi(this);

    connect(ui->btnLogout, &QPushButton::clicked,
            this, &AdminWidget::logoutRequested);
}

AdminWidget::~AdminWidget()
{
    delete ui;
}
