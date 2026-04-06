#include "terminalwidget.h"
#include "ui_terminalwidget.h"

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalWidget)
{
    ui->setupUi(this);

    connect(ui->btnGoToAdmin, &QPushButton::clicked,
            this, &TerminalWidget::goToAdminRequested);
}

TerminalWidget::~TerminalWidget()
{
    delete ui;
}
