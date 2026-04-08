#include "directorywidget.h"
#include "ui_directorywidget.h"
#include "addemployeedialog.h"
#include "databasemanager.h"
#include <QMessageBox>

DirectoryWidget::DirectoryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DirectoryWidget)
{
    ui->setupUi(this);
    m_directoryModel = nullptr;
    initDirectoryGrid();
}

DirectoryWidget::~DirectoryWidget()
{
    delete ui;
}

void DirectoryWidget::initDirectoryGrid()
{
    m_directoryModel = new QSqlTableModel(this);
    m_directoryModel->setTable("employees");
    m_directoryModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_directoryModel->select();

    ui->employeeListView->setModel(m_directoryModel);
    ui->employeeListView->setViewMode(QListView::IconMode);
    ui->employeeListView->setMovement(QListView::Static);
    ui->employeeListView->setResizeMode(QListView::Adjust);
    ui->employeeListView->setSpacing(15);
    ui->employeeListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->employeeListView->setFlow(QListView::LeftToRight);
    ui->employeeListView->setWrapping(true);

    EmployeeDelegate *delegate = new EmployeeDelegate(this);
    ui->employeeListView->setItemDelegate(delegate);
}

void DirectoryWidget::on_btnLogout_clicked()
{
    emit logoutRequested();
}


void DirectoryWidget::on_btnAddEmployee_clicked()
{
    AddEmployeeDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        bool success = DatabaseManager::instance().addEmployee(
            dlg.getName(),
            dlg.getDob(),
            dlg.getVacationDays()
            );
        if (success) {
            m_directoryModel->select(); // Refresh cards
        } else {
            QMessageBox::critical(this, "Error", "Failed to save employee.");
        }
    }
}

void DirectoryWidget::on_employeeListView_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;

    int empId          = m_directoryModel->data(m_directoryModel->index(index.row(), 0)).toInt();
    QString name       = m_directoryModel->data(m_directoryModel->index(index.row(), 1)).toString();
    QString dob        = m_directoryModel->data(m_directoryModel->index(index.row(), 2)).toString();
    QString personalNum = m_directoryModel->data(m_directoryModel->index(index.row(), 3)).toString();
    int vacationDays   = m_directoryModel->data(m_directoryModel->index(index.row(), 4)).toInt();

    emit employeeSelected(empId, name, dob, personalNum, vacationDays);
}

