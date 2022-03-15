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
        ui->cmbHouseNumber->addItem(QString::number(objectList[i]->getNumber()));
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

    ownerList[getNumberInList]->setOwnerPayment(getPaymentSum());
    ownerList[getNumberInList]->setOwnerToPayment();
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
            data << vecElement->getOwnerLastName() << ";"
               << vecElement->getownerFirstName()<< ';'
               << vecElement->getOwnerMiddleName() << ";"
               << vecElement->getOwnerHouseNumber() << ";"
               << vecElement->getOwnerApartmentNumber() << ";"
               << vecElement->getOwnerDateRegistration() << ";"
               << vecElement->getOwnerSex() << ";"
               << vecElement->getOwnerAge() << ";"
               << vecElement->getOwnerPhone() << ";"
               << vecElement->getOwnerCalculated() << ";"
               << vecElement->getOwnerPayed() << ";"
               << vecElement->getOwnerToPayment() << ";"
               << vecElement->getOwnerApartmentArea() << ";"
               << vecElement->getOwnerHouseCarNumber() << ";"
               << vecElement->getOwnerHouseResidenceNumber() << ";"
               << vecElement->getOwnerApartmentType() << ";"
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
        if(arg1.toInt()==objectList[i]->getNumber())
        {
            apartmentNumbers=objectList[i]->getNumberApartments();

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
        if(arg1.toInt()==ownerList[i]->getOwnerApartmentNumber())
        {
            name=ownerList[i]->getOwnerLastName()+
                    " " +ownerList[i]->getownerFirstName()+
                    " " +ownerList[i]->getOwnerMiddleName();
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
    delete ui;
}

int AddPaymentDialog::getIdPaymentNumber()
{
    return ID++;
}

int AddPaymentDialog::getTicketPaymentNumber()
{
    return ui->lineEdit->text().toInt();
}

QString AddPaymentDialog::getDatePayment()
{
    return ui->dateTimeEdit->text();
}

int AddPaymentDialog::getHousePaymentNumber()
{
    return ui->cmbHouseNumber->currentText().toInt();
}

int AddPaymentDialog::getApartmentPaymentNumber()
{
    return ui->cmbApartmentNumber->currentText().toInt();
}

QString AddPaymentDialog::getFioPayment()
{
    return ui->lineEditName->text();
}

unsigned int AddPaymentDialog::getPaymentSum()
{
    return ui->lineEditSum->text().toUInt();
}
