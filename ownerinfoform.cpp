#include "ownerinfoform.h"
#include "ui_ownerinfoform.h"

OwnerInfoForm::OwnerInfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnerInfoForm)
{
    ui->setupUi(this);
    tarifList  = HouseManagementSystem::getInstance()->getTariffList();
    mAddOwnerDialog= new AddOwnerDialog; // Be sure to destroy you window somewhere
    mAddOwnerDialog->setModal(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    readFromFile();



}

OwnerInfoForm::~OwnerInfoForm()
{
    delete ui;
    delete mAddOwnerDialog;
}

void OwnerInfoForm::on_btnCalc_clicked()
{
    for(  r = 0; r < ui->tableWidget->rowCount(); ++r )
    {
        int listSize=tarifList.size();

        for(int i=0;i<listSize;++i)
        {
            //qDebug() << tarifList[i]->getHouseTarifNumber();
            //qDebug() << ui->comboBoxAppartmentNumber->currentText().toInt();
            if(ui->tableWidget->item( r, 3)->text().toInt()==tarifList[i]->getHouseTarifNumber())
            {
                key=i;
                data=datat;
            }


        }
        float calc=ui->tableWidget->item(r,12)->text().toInt()*tarifList[i]->getTarifSum();
        ui->tableWidget->item( r, 9 )->setText(QString::number(calc));
        ui->tableWidget->item( r, 10 )->setText(QString::number(0));
        int toPayment=calc+ui->tableWidget->item( r, 11 )->text().toInt();
        ui->tableWidget->item( r, 11 )->setText(QString::number(toPayment));

    }
}

void OwnerInfoForm::setOwnerCalculated()
{

}

void OwnerInfoForm::setOwnerToPayment()
{
    ownerToPayment=ownerToPayment-ownerPayed;
}

void OwnerInfoForm::setData()
{
    ownerLastName=mAddOwnerDialog->getOwnerLastName();
    ownerFirstName=mAddOwnerDialog->getownerFirstName();
    ownerMiddleName=mAddOwnerDialog->getOwnerMiddleName();
    ownerDateRegistration=mAddOwnerDialog->getOwnerDateRegistration();
    ownerSex=mAddOwnerDialog->getOwnerSex();
    ownerAge=mAddOwnerDialog->getOwnerAge();
    ownerPhone=mAddOwnerDialog->getOwnerPhone();
    ownerApartmentArea=mAddOwnerDialog->getOwnerApartmentArea();
    ownerHouseNumber=mAddOwnerDialog->getOwnerHouseNumber();
    ownerHouseCarNumber=mAddOwnerDialog->getOwnerHouseCarNumber();
    ownerHouseResidenceNumber=mAddOwnerDialog->getOwnerHouseResidenceNumber();
    ownerApartmentNumber=mAddOwnerDialog->getOwnerApartmentNumber();
    ownerApartmentType=mAddOwnerDialog->getOwnerApartmentType();
    ownerPayed=0;
    ownerCalculated=mAddOwnerDialog->getOwnerCalculatePaySum();
    ownerToPayment=ownerCalculated;
}

void OwnerInfoForm::on_btnAdd_clicked()
{
    tableRows=ui->tableWidget->rowCount();
    if(mAddOwnerDialog->exec()==QDialog::Accepted)
    {
        setData();
        ui->tableWidget->insertRow(tableRows);
        ui->tableWidget->setItem(tableRows,0, new QTableWidgetItem(ownerLastName));
        ui->tableWidget->setItem(tableRows,1, new QTableWidgetItem(ownerFirstName));
        ui->tableWidget->setItem(tableRows,2, new QTableWidgetItem(ownerMiddleName));
        ui->tableWidget->setItem(tableRows,3, new QTableWidgetItem(QString::number(ownerHouseNumber)));
        ui->tableWidget->setItem(tableRows,4, new QTableWidgetItem(QString::number(ownerApartmentNumber)));
        ui->tableWidget->setItem(tableRows,5, new QTableWidgetItem(ownerDateRegistration));
        ui->tableWidget->setItem(tableRows,6, new QTableWidgetItem(ownerSex));
        ui->tableWidget->setItem(tableRows,7, new QTableWidgetItem(ownerAge));
        ui->tableWidget->setItem(tableRows,8, new QTableWidgetItem(ownerPhone));
        ui->tableWidget->setItem(tableRows,9, new QTableWidgetItem(QString::number(ownerCalculated)));
        ui->tableWidget->setItem(tableRows,10, new QTableWidgetItem(QString::number(ownerPayed)));
        ui->tableWidget->setItem(tableRows,11, new QTableWidgetItem(QString::number(ownerToPayment)));
        ui->tableWidget->setItem(tableRows,12, new QTableWidgetItem(QString::number(ownerApartmentArea)));
        ui->tableWidget->setItem(tableRows,13, new QTableWidgetItem(QString::number(ownerHouseCarNumber)));
        ui->tableWidget->setItem(tableRows,14, new QTableWidgetItem(QString::number(ownerHouseResidenceNumber)));
        ui->tableWidget->setItem(tableRows,15, new QTableWidgetItem(ownerApartmentType));
    }
}

void OwnerInfoForm::closeEvent(QCloseEvent *event)
{
    saveToFile();
    event->accept();
}

void OwnerInfoForm::saveToFile()
{
    QFile f("owner.csv");

    if (f.open(QIODevice::WriteOnly))
    {
        QTextStream data( &f );
        QStringList strList;

        for(  r = 0; r < ui->tableWidget->rowCount(); ++r )
        {
            strList.clear();
            for(  c = 0; c < ui->tableWidget->columnCount(); ++c )
            {
                strList << ui->tableWidget->item( r, c )->text();
            }
            data << strList.join( ";" )+"\n";
        }
        f.close();
    }
}

void OwnerInfoForm::readFromFile()
{
    ownerList = HouseManagementSystem::getInstance()->getOwnerList();
    int counter=0;
    for(int i=0;i<ownerList.size();i++)
    {
        ui->tableWidget->insertRow(counter);
        ui->tableWidget->setItem(counter, 0,
                                 new QTableWidgetItem(ownerList[i]->getOwnerLastName()));
        ui->tableWidget->setItem(counter, 1,
                                 new QTableWidgetItem(ownerList[i]->getownerFirstName()));
        ui->tableWidget->setItem(counter, 2,
                                 new QTableWidgetItem(ownerList[i]->getOwnerMiddleName()));
        ui->tableWidget->setItem(counter, 3,
                                 new QTableWidgetItem(QString::number(ownerList[i]->getOwnerHouseNumber())));
        ui->tableWidget->setItem(counter, 4,
                                 new QTableWidgetItem(QString::number(ownerList[i]->getOwnerApartmentNumber())));
        ui->tableWidget->setItem(counter, 5,
                                 new QTableWidgetItem(ownerList[i]->getOwnerDateRegistration()));
        ui->tableWidget->setItem(counter, 6,
                                 new QTableWidgetItem(ownerList[i]->getOwnerSex()));
        ui->tableWidget->setItem(counter, 7,
                                 new QTableWidgetItem(ownerList[i]->getOwnerAge()));
        ui->tableWidget->setItem(counter, 8,
                                 new QTableWidgetItem(ownerList[i]->getOwnerPhone()));
        ui->tableWidget->setItem(counter, 9,
                                 new QTableWidgetItem(QString::number(ownerList[i]->getOwnerCalculated())));
        ui->tableWidget->setItem(counter, 10,
                                 new QTableWidgetItem(QString::number(ownerList[i]->getOwnerPayed())));
        ui->tableWidget->setItem(counter, 11,
                                 new QTableWidgetItem(QString::number(ownerList[i]->getOwnerToPayment())));
        ui->tableWidget->setItem(counter, 12,
                                 new QTableWidgetItem(QString::number(ownerList[i]->getOwnerApartmentArea())));
        ui->tableWidget->setItem(counter, 13,
                                 new QTableWidgetItem(QString::number(ownerList[i]->getOwnerHouseCarNumber())));
        ui->tableWidget->setItem(counter, 14,
                                 new QTableWidgetItem(QString::number(ownerList[i]->getOwnerHouseResidenceNumber())));
        ui->tableWidget->setItem(counter, 15,
                                 new QTableWidgetItem(ownerList[i]->getOwnerApartmentType()));
        counter++;

    }
    //    QFile file("owner.csv");
    //    QTextStream stream(&file);

    //    if (file.open(QIODevice::ReadOnly)){
    //        int counter=0;
    //        while (!stream.atEnd()){
    //            QString str = stream.readLine();
    //            QStringList strList = str.split(";");
    //            ui->tableWidget->insertRow(counter);
    //            ui->tableWidget->setItem(counter, 0,
    //                                     new QTableWidgetItem(strList.at(0)));
    //            ui->tableWidget->setItem(counter, 1,
    //                                     new QTableWidgetItem(strList.at(1)));
    //            ui->tableWidget->setItem(counter, 2,
    //                                     new QTableWidgetItem(strList.at(2)));
    //            ui->tableWidget->setItem(counter, 3,
    //                                     new QTableWidgetItem(strList.at(3)));
    //            ui->tableWidget->setItem(counter, 4,
    //                                     new QTableWidgetItem(strList.at(4)));
    //            ui->tableWidget->setItem(counter, 5,
    //                                     new QTableWidgetItem(strList.at(5)));
    //            ui->tableWidget->setItem(counter, 6,
    //                                     new QTableWidgetItem(strList.at(6)));
    //            ui->tableWidget->setItem(counter, 7,
    //                                     new QTableWidgetItem(strList.at(7)));
    //            ui->tableWidget->setItem(counter, 8,
    //                                     new QTableWidgetItem(strList.at(8)));
    //            ui->tableWidget->setItem(counter, 9,
    //                                     new QTableWidgetItem(strList.at(9)));
    //            ui->tableWidget->setItem(counter, 10,
    //                                     new QTableWidgetItem(strList.at(10)));
    //            ui->tableWidget->setItem(counter, 11,
    //                                     new QTableWidgetItem(strList.at(11)));
    //            counter++;
    //        }
    //    }
    //    file.close();
}

QString OwnerInfoForm::getOwnerLastName() const
{
    return ownerLastName;
}

QString OwnerInfoForm::getownerFirstName() const
{
    return ownerFirstName;
}

QString OwnerInfoForm::getOwnerMiddleName() const
{
    return ownerMiddleName;
}

QString OwnerInfoForm::getOwnerSex() const
{
    return ownerSex;
}

QString OwnerInfoForm::getOwnerAge() const
{
    return ownerAge;
}

QString OwnerInfoForm::getOwnerPhone() const
{
    return ownerPhone;
}

int OwnerInfoForm::getOwnerHouseNumber()const
{
    return ownerHouseNumber;
}

int OwnerInfoForm::getOwnerHouseCarNumber()const
{
    return ownerHouseCarNumber;
}

int OwnerInfoForm::getOwnerHouseResidenceNumber()const
{
    return ownerHouseResidenceNumber;
}

int OwnerInfoForm::getOwnerApartmentNumber()const
{
    return ownerApartmentNumber;
}

float OwnerInfoForm::getOwnerCalculated()const
{
    return ownerCalculated;
}

int OwnerInfoForm::getOwnerPayed()const
{
    return ownerPayed;
}

int OwnerInfoForm::getOwnerToPayment()const
{
    return ownerToPayment;
}

QString OwnerInfoForm::getOwnerApartmentType()const
{
    return ownerApartmentType;
}

QString OwnerInfoForm::getOwnerDateRegistration()const
{
    return ownerDateRegistration;
}

float OwnerInfoForm::getOwnerApartmentArea()const
{
    return ownerApartmentArea;
}

void OwnerInfoForm::on_btnDelete_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}




