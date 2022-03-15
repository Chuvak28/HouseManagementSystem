#include "addownerdialog.h"
#include "ui_addownerdialog.h"
#include <QDebug>

AddOwnerDialog::AddOwnerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddOwnerDialog)
{
    ui->setupUi(this);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    objectList = HouseManagementSystem::getInstance()->getObjectList();
    tarifList  = HouseManagementSystem::getInstance()->getTariffList();
    int listSize=objectList.size();

    for(int i=0;i<listSize;i++)
    {
        ui->comboBoxHouseNumber->addItem(QString::number(objectList[i]->getNumber()));
    }
}



void AddOwnerDialog::on_comboBoxHouseNumber_currentIndexChanged(const QString &arg1)
{
    ui->comboBoxAppartmentNumber->clear();
    int listSize=objectList.size();
    int apartmentNumbers = 0;
    for(int i=0;i<listSize;++i)
    {
        if(arg1.toInt()==objectList[i]->getNumber())
        {
            apartmentNumbers=objectList[i]->getNumberApartments();
            break;
        }
    }
    for(int j=0;j<apartmentNumbers;j++)
    {
        ui->comboBoxAppartmentNumber->addItem(QString::number(j+1));
    }
    //int listSize=objectList.size();
    //qDebug() << listSize;
//    for(int i=0;i<listSize;i++)
//    {
//        ui->comboBoxHouseNumber->addItem(QString::number(objectList[i]->getNumber()));
//    }
}
AddOwnerDialog::~AddOwnerDialog()
{
    delete ui;
}

QString AddOwnerDialog::getOwnerLastName()
{
    return ui->lineEditLastName->text();
}

QString AddOwnerDialog::getownerFirstName()
{
    return ui->lineEditFirstName->text();
}

QString AddOwnerDialog::getOwnerMiddleName()
{
    return ui->lineEditMiddleName->text();
}

QString AddOwnerDialog::getOwnerSex()
{
    return ui->comboBoxSex->currentText();
}

QString AddOwnerDialog::getOwnerAge()
{
    return  ui->lineEditAge->text();
}

QString AddOwnerDialog::getOwnerPhone()
{
    return ui->lineEditTelephon->text();
}

int AddOwnerDialog::getOwnerHouseNumber()
{
    return ui->comboBoxHouseNumber->currentText().toInt();
}

int AddOwnerDialog::getOwnerHouseCarNumber()
{
    return ui->lineEditCarNumber->text().toInt();
}

int AddOwnerDialog::getOwnerHouseResidenceNumber()
{
    return ui->lineEditResidenceNumber->text().toInt();
}

int AddOwnerDialog::getOwnerApartmentNumber()
{
    return ui->comboBoxAppartmentNumber->currentText().toInt();
}

QString AddOwnerDialog::getOwnerApartmentType()
{
    return ui->comboBoxApartmentType->currentText();
}

float AddOwnerDialog::getOwnerApartmentArea()
{
    return ui->comboBoxApartmentArea->currentText().toFloat();
}

QString AddOwnerDialog::getOwnerDateRegistration()
{
    return ui->dateEdit->text();
}

float AddOwnerDialog::getOwnerCalculatePaySum()
{
    int listSize=tarifList.size();
    //int apartmentNumbers = 0;
    //
    for(int i=0;i<listSize;++i)
    {
        //qDebug() << tarifList[i]->getHouseTarifNumber();
        //qDebug() << ui->comboBoxAppartmentNumber->currentText().toInt();
        if(getOwnerHouseNumber()==tarifList[i]->getHouseTarifNumber())
        {
            qDebug() << getOwnerApartmentArea()*tarifList[i]->getTarifSum();
            return getOwnerApartmentArea()*tarifList[i]->getTarifSum();
            //break;
        }
    }
    return -1;
}

void AddOwnerDialog::on_btnAddOwner_clicked()
{
    accept();
}

void AddOwnerDialog::on_pushButton_2_clicked()
{
    close();
}
