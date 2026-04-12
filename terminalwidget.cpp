#include "terminalwidget.h"
#include "ui_terminalwidget.h"
#include <QDateTime>
#include <QInputDialog>
#include <QMessageBox>

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalWidget)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(pageTerminal);

    m_clockTimer = new QTimer(this);
    connect(m_clockTimer, &QTimer::timeout,
            this, &TerminalWidget::updateDateTime);
    m_clockTimer->start(1000);
    updateDateTime(); // Show immediately, don't wait 1 second

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

void TerminalWidget::updateDateTime()
{
    QDateTime now = QDateTime::currentDateTime();
    ui->labelTime->setText(now.toString("HH:mm:ss"));
    ui->labelDate->setText(now.toString("dddd, d MMMM yyyy"));
}

