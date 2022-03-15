#include "addtariffdialog.h"
#include "ui_addtariffdialog.h"

AddTariffDialog::AddTariffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTariffDialog)
{
    ui->setupUi(this);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    objectList = HouseManagementSystem::getInstance()->getObjectList();
    int listSize=objectList.size();

    for(int i=0;i<listSize;i++)
    {
        ui->cmbHouseNumber->addItem(QString::number(objectList[i]->getNumber()));
    }
}

AddTariffDialog::~AddTariffDialog()
{
    delete ui;
}

QString AddTariffDialog::getDateTariff()
{
    return ui->dateEdit->text();
}

int AddTariffDialog::getHouseTarifNumber()
{
    return ui->cmbHouseNumber->currentText().toInt();
}

unsigned int AddTariffDialog::getTarifSum()
{
    return ui->lineEditTariff->text().toInt();
}

void AddTariffDialog::on_pushButton_2_clicked()
{
    close();
}

void AddTariffDialog::on_pushButton_clicked()
{
    accept();
}

