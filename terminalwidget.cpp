#include "terminalwidget.h"
#include "ui_terminalwidget.h"
#include <QInputDialog>
#include <QMessageBox>

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalWidget)
{
    ui->setupUi(this);

}

TerminalWidget::~TerminalWidget()
{
    delete ui;
}

void TerminalWidget::on_btnGoToAdmin_clicked()
{
    bool ok;
    QString password = QInputDialog::getText(
        this,
        "Admin Access",
        "Enter Admin Password:",
        QLineEdit::Password,
        "", &ok);

    if (!ok) return; // User pressed Cancel

    if (password == "admin123") {
        emit goToAdminRequested();
    } else {
        QMessageBox::critical(this, "Access Denied", "Incorrect password.");
    }
}

