#include "adminwidget.h"
#include "ui_adminwidget.h"

AdminWidget::AdminWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminWidget)
{
    ui->setupUi(this);

    m_directory  = new DirectoryWidget(this);
    m_profile    = new ProfileWidget(this);
    m_attendance = new AttendanceWidget(this);
    m_leave      = new LeaveWidget(this);

    ui->adminStackedWidget->insertWidget(PageDirectory,  m_directory);
    ui->adminStackedWidget->insertWidget(PageProfile,    m_profile);
    ui->adminStackedWidget->insertWidget(PageAttendance, m_attendance);
    ui->adminStackedWidget->insertWidget(PageLeave,      m_leave);

    // Remove all pages beyond index 3
    while (ui->adminStackedWidget->count() > 4) {
        ui->adminStackedWidget->removeWidget(
            ui->adminStackedWidget->widget(4));
    }

    ui->adminStackedWidget->setCurrentIndex(PageDirectory);

    connect(m_directory, &DirectoryWidget::logoutRequested,
            this, &AdminWidget::logoutRequested);

}

AdminWidget::~AdminWidget()
{
    delete ui;
}

void AdminWidget::on_btnLogout_clicked()
{
    emit logoutRequested();
}

