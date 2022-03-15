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
QString AddEditDialog::getAddress()
{
    return ui->lineEditAddress_3->text();
}

int AddEditDialog::getNumber()
{
    return ui->lineEditNumber_3->text().toInt();
}

float AddEditDialog::getAreaLand()
{
    return ui->lineEditAreaOfLand_3->text().toFloat();
}

float AddEditDialog::getAreaYard()
{
    return ui->lineEditAreaOfYard_3->text().toFloat();
}

float AddEditDialog::getAreaBuilding()
{
    return ui->lineEditAreaOfBuilding_3->text().toFloat();
}

float AddEditDialog::getAreaRoof()
{
    return ui->lineEditAreaOfRoof_3->text().toFloat();
}

float AddEditDialog::getAreaBasement()
{
    return ui->lineEditAreaOfBasement_3->text().toFloat();
}

float AddEditDialog::getAreaStaircase()
{
    return ui->lineEditAreaOfStaircase_3->text().toFloat();
}

int AddEditDialog::getNumberStages()
{
    return ui->lineEditNumberOfFloors_3->text().toInt();
}

int AddEditDialog::getNumberApartments()
{
    return ui->lineEditOfApartments_3->text().toInt();
}

int AddEditDialog::getNumberEntrances()
{
    return ui->lineEditOfEntrances_3->text().toInt();
}

void AddEditDialog::on_btnClose_3_clicked()
{
    close();
}

