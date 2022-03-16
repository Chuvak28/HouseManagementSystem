#include "addeditdialog.h"
#include "ui_addeditdialog.h"

AddEditDialog::AddEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDialog)
{
    ui->setupUi(this);
}

AddEditDialog::~AddEditDialog()
{
    delete ui;
}

void AddEditDialog::on_btnAdd_3_clicked()
{
    accept();
}
QString AddEditDialog::GetAddress()
{
    return ui->lineEditAddress_3->text();
}

int AddEditDialog::GetNumber()
{
    return ui->lineEditNumber_3->text().toInt();
}

float AddEditDialog::GetAreaLand()
{
    return ui->lineEditAreaOfLand_3->text().toFloat();
}

float AddEditDialog::GetAreaYard()
{
    return ui->lineEditAreaOfYard_3->text().toFloat();
}

float AddEditDialog::GetAreaBuilding()
{
    return ui->lineEditAreaOfBuilding_3->text().toFloat();
}

float AddEditDialog::GetAreaRoof()
{
    return ui->lineEditAreaOfRoof_3->text().toFloat();
}

float AddEditDialog::GetAreaBasement()
{
    return ui->lineEditAreaOfBasement_3->text().toFloat();
}

float AddEditDialog::GetAreaStaircase()
{
    return ui->lineEditAreaOfStaircase_3->text().toFloat();
}

int AddEditDialog::GetNumberStages()
{
    return ui->lineEditNumberOfFloors_3->text().toInt();
}

int AddEditDialog::GetNumberApartments()
{
    return ui->lineEditOfApartments_3->text().toInt();
}

int AddEditDialog::GetNumberEntrances()
{
    return ui->lineEditOfEntrances_3->text().toInt();
}

void AddEditDialog::on_btnClose_3_clicked()
{
    close();
}

