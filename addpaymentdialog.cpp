#include "addpaymentdialog.h"
#include "ui_addpaymentdialog.h"
#include <QFile>

AddPaymentDialog::AddPaymentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPaymentDialog)
{
    ui->setupUi(this);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    objectList = HouseManagementSystem::getInstance()->getObjectList();
    ownerList = HouseManagementSystem::getInstance()->getOwnerList();
    int listSize=objectList.size();

    for(int i=0;i<listSize;i++)
    {
        ui->cmbHouseNumber->addItem(QString::number(objectList[i]->GetNumber()));
    }
}



//QTextStream &operator<<(QTextStream &ds, const OwnerInfoForm &inObj)
//{
//    //QStringList strList;
//    qDebug() << inObj.getOwnerLastName() << ";"
//       << inObj.getownerFirstName()<< ";"
//       << inObj.getOwnerMiddleName() << ";"
//       << QString::number(inObj.getOwnerHouseNumber()) << ";"
//       << QString::number(inObj.getOwnerApartmentNumber()) << ";"
//       << inObj.getOwnerDateRegistration() << ";"
//       << inObj.getOwnerSex() << ";"
//       << inObj.getOwnerAge() << ";"
//       << inObj.getOwnerPhone() << ";"
//       << QString::number(inObj.getOwnerCalculated()) << ";"
//       << QString::number(inObj.getOwnerPayed()) << ";"
//       << QString::number(inObj.getOwnerToPayment()) << ";"
//       << QString::number(inObj.getOwnerApartmentArea()) << ";"
//       << QString::number(inObj.getOwnerHouseCarNumber()) << ";"
//       << QString::number(inObj.getOwnerHouseResidenceNumber()) << ";"
//       << inObj.getOwnerApartmentType() << ";"
//        << endl;
//    ds << inObj.getOwnerLastName() << ";"
//       << inObj.getownerFirstName()<< ";"
//       << inObj.getOwnerMiddleName() << ";"
//       << QString::number(inObj.getOwnerHouseNumber()) << ";"
//       << QString::number(inObj.getOwnerApartmentNumber()) << ";"
//       << inObj.getOwnerDateRegistration() << ";"
//       << inObj.getOwnerSex() << ";"
//       << inObj.getOwnerAge() << ";"
//       << inObj.getOwnerPhone() << ";"
//       << QString::number(inObj.getOwnerCalculated()) << ";"
//       << QString::number(inObj.getOwnerPayed()) << ";"
//       << QString::number(inObj.getOwnerToPayment()) << ";"
//       << QString::number(inObj.getOwnerApartmentArea()) << ";"
//       << QString::number(inObj.getOwnerHouseCarNumber()) << ";"
//       << QString::number(inObj.getOwnerHouseResidenceNumber()) << ";"
//       << inObj.getOwnerApartmentType() << ";"
//        << endl;

//    //ds << strList;


//    return ds;
//}

void AddPaymentDialog::on_btnAdd_clicked()
{

    ownerList[getNumberInList]->SetOwnerPayment(GetPaymentSum());
    ownerList[getNumberInList]->SetOwnerToPayment();
//    for(auto vecElement : qAsConst(ownerList))
//    {
//        qDebug() << vecElement->getOwnerLastName() << ";"
//           << vecElement->getownerFirstName()<< ";"
//           << vecElement->getOwnerMiddleName() << ";"
//           << QString::number(vecElement->getOwnerHouseNumber()) << ";"
//           << QString::number(vecElement->getOwnerApartmentNumber()) << ";"
//           << vecElement->getOwnerDateRegistration() << ";"
//           << vecElement->getOwnerSex() << ";"
//           << vecElement->getOwnerAge() << ";"
//           << vecElement->getOwnerPhone() << ";"
//           << QString::number(vecElement->getOwnerCalculated()) << ";"
//           << QString::number(vecElement->getOwnerPayed()) << ";"
//           << QString::number(vecElement->getOwnerToPayment()) << ";"
//           << QString::number(vecElement->getOwnerApartmentArea()) << ";"
//           << QString::number(vecElement->getOwnerHouseCarNumber()) << ";"
//           << QString::number(vecElement->getOwnerHouseResidenceNumber()) << ";"
//           << vecElement->getOwnerApartmentType() << ";"
//            << endl;
//    }

    QFile f("owner.csv");

    if (f.open(QIODevice::WriteOnly))
    {
        QTextStream data( &f );
        QStringList strList;
        for(auto vecElement : qAsConst(ownerList))
        {
            data << vecElement->GetOwnerLastName() << ";"
               << vecElement->GetownerFirstName()<< ';'
               << vecElement->GetOwnerMiddleName() << ";"
               << vecElement->GetOwnerHouseNumber() << ";"
               << vecElement->GetOwnerApartmentNumber() << ";"
               << vecElement->GetOwnerDateRegistration() << ";"
               << vecElement->GetOwnerSex() << ";"
               << vecElement->GetOwnerAge() << ";"
               << vecElement->GetOwnerPhone() << ";"
               << vecElement->GetOwnerCalculated() << ";"
               << vecElement->GetOwnerPayed() << ";"
               << vecElement->GetOwnerToPayment() << ";"
               << vecElement->GetOwnerApartmentArea() << ";"
               << vecElement->GetOwnerHouseCarNumber() << ";"
               << vecElement->GetOwnerHouseResidenceNumber() << ";"
               << vecElement->GetOwnerApartmentType() << ";"
            << endl;
        }

        //data << OwnerInfoForm;
    }

    f.close();

    accept();
}

void AddPaymentDialog::on_btnClose_clicked()
{
    close();
}

void AddPaymentDialog::on_cmbHouseNumber_currentIndexChanged(const QString &arg1)
{
    ui->cmbApartmentNumber->clear();
    int listSize=objectList.size();
    apartmentNumbers = 0;
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
        ui->cmbApartmentNumber->addItem(QString::number(j+1));
    }
}

void AddPaymentDialog::on_cmbApartmentNumber_currentIndexChanged(const QString &arg1)
{

    int listSize=ownerList.size();
    QString name;
    for(int i=0;i<listSize;++i)
    {
        if(arg1.toInt()==ownerList[i]->GetOwnerApartmentNumber())
        {
            name=ownerList[i]->GetOwnerLastName()+
                    " " +ownerList[i]->GetownerFirstName()+
                    " " +ownerList[i]->GetOwnerMiddleName();
            getNumberInList=i;
            //qDebug() << "Appa Number" << getNumberInList;
            break;
        }
    }
    //qDebug() << name;
    ui->lineEditName->setText(name);


}

AddPaymentDialog::~AddPaymentDialog()
{

    for (auto p : qAsConst(objectList))
    {
        delete p;
    }
    objectList.clear();
    for (auto p : qAsConst(ownerList))
    {
        delete p;
    }
    ownerList.clear();
    delete ui;
}

int AddPaymentDialog::GetIdPaymentNumber()
{
    return ID++;
}

int AddPaymentDialog::GetTicketPaymentNumber()
{
    return ui->lineEdit->text().toInt();
}

QString AddPaymentDialog::GetDatePayment()
{
    return ui->dateTimeEdit->text();
}

int AddPaymentDialog::GetHousePaymentNumber()
{
    return ui->cmbHouseNumber->currentText().toInt();
}

int AddPaymentDialog::GetApartmentPaymentNumber()
{
    return ui->cmbApartmentNumber->currentText().toInt();
}

QString AddPaymentDialog::GetFioPayment()
{
    return ui->lineEditName->text();
}

unsigned int AddPaymentDialog::GetPaymentSum()
{
    return ui->lineEditSum->text().toUInt();
}
