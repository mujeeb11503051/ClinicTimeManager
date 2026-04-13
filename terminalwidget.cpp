#include "terminalwidget.h"
#include "ui_terminalwidget.h"
#include <QDateTime>
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlQuery>

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalWidget)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(PageInput);

    m_currentEmpId   = -1;
    m_currentEmpName = "";

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


void TerminalWidget::on_btnVerify_clicked()
{
    QString pNum = ui->editEmpId->text().trimmed();
    if (pNum.isEmpty()) return;

    // Look up employee by personal number
    QSqlQuery query;
    query.prepare("SELECT id, name FROM employees "
                  "WHERE personal_number = :pnum");
    query.bindValue(":pnum", pNum);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Not Found",
                             "No employee found with that ID.");
        ui->editEmpId->clear();
        return;
    }

    // Store employee info
    m_currentEmpId   = query.value(0).toInt();
    m_currentEmpName = query.value(1).toString();

    // Switch to action page
    ui->editEmpId->clear();
    ui->lblWelcome->setText("Hi, " + m_currentEmpName + "!");
    ui->stackedWidget->setCurrentIndex(PageAction);
}


void TerminalWidget::on_btnBack_clicked()
{
    ui->stackedWidget->setCurrentIndex(PageInput);
}

