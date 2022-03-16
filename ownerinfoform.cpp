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
    OnReadFromFile();



}

OwnerInfoForm::~OwnerInfoForm()
{
    for (auto p : qAsConst(ownerList))
    {
        delete p;
    }
    ownerList.clear();
    for (auto p : qAsConst(tarifList))
    {
        delete p;
    }
    tarifList.clear();

    delete mAddOwnerDialog;

    delete ui;
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
            //            if(ui->tableWidget->item( r, 3)->text().toInt()==tarifList[i]->getHouseTarifNumber())
            //            {
            //                //key=i;
            //                data=datat;
            //            }



            float calc=ui->tableWidget->item(r,12)->text().toInt()*tarifList[i]->GetTarifSum();
            ui->tableWidget->item( r, 9 )->setText(QString::number(calc));
            ui->tableWidget->item( r, 10 )->setText(QString::number(0));
            int toPayment=calc+ui->tableWidget->item( r, 11 )->text().toInt();
            ui->tableWidget->item( r, 11 )->setText(QString::number(toPayment));
        }

    }
}

void OwnerInfoForm::SetOwnerCalculated()
{

}

void OwnerInfoForm::SetOwnerToPayment()
{
    ownerToPayment=ownerToPayment-ownerPayed;
}

void OwnerInfoForm::SetData()
{
    ownerLastName=mAddOwnerDialog->GetOwnerLastName();
    ownerFirstName=mAddOwnerDialog->GetownerFirstName();
    ownerMiddleName=mAddOwnerDialog->GetOwnerMiddleName();
    ownerDateRegistration=mAddOwnerDialog->GetOwnerDateRegistration();
    ownerSex=mAddOwnerDialog->GetOwnerSex();
    ownerAge=mAddOwnerDialog->GetOwnerAge();
    ownerPhone=mAddOwnerDialog->GetOwnerPhone();
    ownerApartmentArea=mAddOwnerDialog->GetOwnerApartmentArea();
    ownerHouseNumber=mAddOwnerDialog->GetOwnerHouseNumber();
    ownerHouseCarNumber=mAddOwnerDialog->GetOwnerHouseCarNumber();
    ownerHouseResidenceNumber=mAddOwnerDialog->GetOwnerHouseResidenceNumber();
    ownerApartmentNumber=mAddOwnerDialog->GetOwnerApartmentNumber();
    ownerApartmentType=mAddOwnerDialog->GetOwnerApartmentType();
    ownerPayed=0;
    ownerCalculated=mAddOwnerDialog->GetOwnerCalculatePaySum();
    ownerToPayment=ownerCalculated;
}

void OwnerInfoForm::on_btnAdd_clicked()
{
    tableRows=ui->tableWidget->rowCount();
    if(mAddOwnerDialog->exec()==QDialog::Accepted)
    {
        SetData();
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
    OnSaveToFile();
    event->accept();
}

void OwnerInfoForm::OnSaveToFile()
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

void OwnerInfoForm::OnReadFromFile()
{
    ownerList = HouseManagementSystem::getInstance()->getOwnerList();
    int counter=0;
    for(int i=0;i<ownerList.size();i++)
    {
        ui->tableWidget->insertRow(counter);
        ui->tableWidget->setItem(counter, 0,
                                 new QTableWidgetItem(ownerList[i]->GetOwnerLastName()));
        ui->tableWidget->setItem(counter, 1,
                                 new QTableWidgetItem(ownerList[i]->GetownerFirstName()));
        ui->tableWidget->setItem(counter, 2,
                                 new QTableWidgetItem(ownerList[i]->GetOwnerMiddleName()));
        ui->tableWidget->setItem(counter, 3,
                                 new QTableWidgetItem(QString::number(ownerList[i]->GetOwnerHouseNumber())));
        ui->tableWidget->setItem(counter, 4,
                                 new QTableWidgetItem(QString::number(ownerList[i]->GetOwnerApartmentNumber())));
        ui->tableWidget->setItem(counter, 5,
                                 new QTableWidgetItem(ownerList[i]->GetOwnerDateRegistration()));
        ui->tableWidget->setItem(counter, 6,
                                 new QTableWidgetItem(ownerList[i]->GetOwnerSex()));
        ui->tableWidget->setItem(counter, 7,
                                 new QTableWidgetItem(ownerList[i]->GetOwnerAge()));
        ui->tableWidget->setItem(counter, 8,
                                 new QTableWidgetItem(ownerList[i]->GetOwnerPhone()));
        ui->tableWidget->setItem(counter, 9,
                                 new QTableWidgetItem(QString::number(ownerList[i]->GetOwnerCalculated())));
        ui->tableWidget->setItem(counter, 10,
                                 new QTableWidgetItem(QString::number(ownerList[i]->GetOwnerPayed())));
        ui->tableWidget->setItem(counter, 11,
                                 new QTableWidgetItem(QString::number(ownerList[i]->GetOwnerToPayment())));
        ui->tableWidget->setItem(counter, 12,
                                 new QTableWidgetItem(QString::number(ownerList[i]->GetOwnerApartmentArea())));
        ui->tableWidget->setItem(counter, 13,
                                 new QTableWidgetItem(QString::number(ownerList[i]->GetOwnerHouseCarNumber())));
        ui->tableWidget->setItem(counter, 14,
                                 new QTableWidgetItem(QString::number(ownerList[i]->GetOwnerHouseResidenceNumber())));
        ui->tableWidget->setItem(counter, 15,
                                 new QTableWidgetItem(ownerList[i]->GetOwnerApartmentType()));
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

QString OwnerInfoForm::GetOwnerLastName() const
{
    return ownerLastName;
}

QString OwnerInfoForm::GetownerFirstName() const
{
    return ownerFirstName;
}

QString OwnerInfoForm::GetOwnerMiddleName() const
{
    return ownerMiddleName;
}

QString OwnerInfoForm::GetOwnerSex() const
{
    return ownerSex;
}

QString OwnerInfoForm::GetOwnerAge() const
{
    return ownerAge;
}

QString OwnerInfoForm::GetOwnerPhone() const
{
    return ownerPhone;
}

int OwnerInfoForm::GetOwnerHouseNumber()const
{
    return ownerHouseNumber;
}

int OwnerInfoForm::GetOwnerHouseCarNumber()const
{
    return ownerHouseCarNumber;
}

int OwnerInfoForm::GetOwnerHouseResidenceNumber()const
{
    return ownerHouseResidenceNumber;
}

int OwnerInfoForm::GetOwnerApartmentNumber()const
{
    return ownerApartmentNumber;
}

float OwnerInfoForm::GetOwnerCalculated()const
{
    return ownerCalculated;
}

int OwnerInfoForm::GetOwnerPayed()const
{
    return ownerPayed;
}

int OwnerInfoForm::GetOwnerToPayment()const
{
    return ownerToPayment;
}

QString OwnerInfoForm::GetOwnerApartmentType()const
{
    return ownerApartmentType;
}

QString OwnerInfoForm::GetOwnerDateRegistration()const
{
    return ownerDateRegistration;
}

float OwnerInfoForm::GetOwnerApartmentArea()const
{
    return ownerApartmentArea;
}

void OwnerInfoForm::on_btnDelete_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}




