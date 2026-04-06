#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the widgets
    m_terminal = new TerminalWidget(this);
    m_admin    = new AdminWidget(this);

    // Replace the dummy pages with real widgets
    ui->stackedWidget->insertWidget(TerminalPage, m_terminal);
    ui->stackedWidget->insertWidget(AdminPage,    m_admin);

    // Remove the original dummy pages Qt Designer created
    // (index shifts after insert, so remove index 2 twice)
    ui->stackedWidget->removeWidget(ui->stackedWidget->widget(2));
    ui->stackedWidget->removeWidget(ui->stackedWidget->widget(2));

    // Start on terminal page
    ui->stackedWidget->setCurrentIndex(TerminalPage);

    connect(m_terminal, &TerminalWidget::goToAdminRequested, this, [this]() {
        ui->stackedWidget->setCurrentIndex(AdminPage);
    });

    connect(m_admin, &AdminWidget::logoutRequested, this, [this]() {
        ui->stackedWidget->setCurrentIndex(TerminalPage);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
