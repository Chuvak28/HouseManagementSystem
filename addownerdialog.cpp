#include "addownerdialog.h"
#include "ui_addownerdialog.h"
#include <QDebug>

AddOwnerDialog::AddOwnerDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::AddOwnerDialog)
{
    ui->setupUi(this);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    objectList = HouseManagementSystem::getInstance()->getObjectList();
    tarifList  = HouseManagementSystem::getInstance()->getTariffList();
    int listSize=objectList.size();

    for(int i=0;i<listSize;i++)
    {
        ui->comboBoxHouseNumber->addItem(QString::number(objectList[i]->GetNumber()));
    }
}



void AddOwnerDialog::on_comboBoxHouseNumber_currentIndexChanged(const QString &arg1)
{
    ui->comboBoxAppartmentNumber->clear();
    int listSize=objectList.size();
    int apartmentNumbers = 0;
    for(int i=0;i<listSize;++i)
    {
        if(arg1.toInt()==objectList[i]->GetNumber())
        {
            apartmentNumbers=objectList[i]->GetNumberApartments();
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

    for (auto p : qAsConst(objectList))
    {
        delete p;
    }
    objectList.clear();
    for (auto p : tarifList)
    {
        delete p;
    }
    tarifList.clear();
    delete ui;
}

QString AddOwnerDialog::GetOwnerLastName()
{
    return ui->lineEditLastName->text();
}

QString AddOwnerDialog::GetownerFirstName()
{
    return ui->lineEditFirstName->text();
}

QString AddOwnerDialog::GetOwnerMiddleName()
{
    return ui->lineEditMiddleName->text();
}

QString AddOwnerDialog::GetOwnerSex()
{
    return ui->comboBoxSex->currentText();
}

QString AddOwnerDialog::GetOwnerAge()
{
    return  ui->lineEditAge->text();
}

QString AddOwnerDialog::GetOwnerPhone()
{
    return ui->lineEditTelephon->text();
}

int AddOwnerDialog::GetOwnerHouseNumber()
{
    return ui->comboBoxHouseNumber->currentText().toInt();
}

int AddOwnerDialog::GetOwnerHouseCarNumber()
{
    return ui->lineEditCarNumber->text().toInt();
}

int AddOwnerDialog::GetOwnerHouseResidenceNumber()
{
    return ui->lineEditResidenceNumber->text().toInt();
}

int AddOwnerDialog::GetOwnerApartmentNumber()
{
    return ui->comboBoxAppartmentNumber->currentText().toInt();
}

QString AddOwnerDialog::GetOwnerApartmentType()
{
    return ui->comboBoxApartmentType->currentText();
}

float AddOwnerDialog::GetOwnerApartmentArea()
{
    return ui->comboBoxApartmentArea->currentText().toFloat();
}

QString AddOwnerDialog::GetOwnerDateRegistration()
{
    return ui->dateEdit->text();
}

float AddOwnerDialog::GetOwnerCalculatePaySum()
{
    int listSize=tarifList.size();
    //int apartmentNumbers = 0;
    //
    for(int i=0;i<listSize;++i)
    {
        //qDebug() << tarifList[i]->getHouseTarifNumber();
        //qDebug() << ui->comboBoxAppartmentNumber->currentText().toInt();
        if(GetOwnerHouseNumber()==tarifList[i]->GetHouseTarifNumber())
        {
            qDebug() << GetOwnerApartmentArea()*tarifList[i]->GetTarifSum();
            return GetOwnerApartmentArea()*tarifList[i]->GetTarifSum();
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
