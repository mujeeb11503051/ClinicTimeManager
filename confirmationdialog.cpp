#include "confirmationdialog.h"
#include "ui_confirmationdialog.h"

ConfirmationDialog::ConfirmationDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfirmationDialog)
{
    ui->setupUi(this);
}

ConfirmationDialog::~ConfirmationDialog()
{
    delete ui;
}
