#include "addemployeedialog.h"
#include "ui_addemployeedialog.h"

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEmployeeDialog)
{
    ui->setupUi(this);
}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}

QString AddEmployeeDialog::getName() const
{
    return ui->nameEdit->text();
}

QDate AddEmployeeDialog::getDob() const
{
    return ui->dobEdit->date();
}

int AddEmployeeDialog::getVacationDays() const
{
    return ui->vacationEdit->value();
}
