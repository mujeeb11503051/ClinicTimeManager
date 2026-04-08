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

    // When employee card is clicked, load their data into profile page
    connect(m_directory, &DirectoryWidget::employeeSelected,
            this, [this](int empId, const QString &name,
                   const QString &dob, const QString &personalNumber,
                   int vacationDays) {
                m_profile->loadEmployee(empId, name, dob, personalNumber, vacationDays);
                ui->adminStackedWidget->setCurrentIndex(PageProfile);
            });

    // Profile navigation signals
    connect(m_profile, &ProfileWidget::backRequested, this, [this]() {
        ui->adminStackedWidget->setCurrentIndex(PageDirectory);
    });

    connect(m_profile, &ProfileWidget::attendanceRequested, this, [this]() {
        ui->adminStackedWidget->setCurrentIndex(PageAttendance);
    });

    connect(m_profile, &ProfileWidget::leaveRequested, this, [this]() {
        ui->adminStackedWidget->setCurrentIndex(PageLeave);
    });
}

AdminWidget::~AdminWidget()
{
    delete ui;
}

void AdminWidget::on_btnLogout_clicked()
{
    emit logoutRequested();
}

