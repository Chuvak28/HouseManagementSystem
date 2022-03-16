#include "objectinfoform.h"
#include "ui_objectinfoform.h"
#include <QDebug>

ObjectInfoForm::~ObjectInfoForm()
{
    delete mAddEditDialog;
    delete ui;
}
ObjectInfoForm::ObjectInfoForm(QWidget *parent) : QWidget(parent),
    ui(new Ui::ObjectInfoForm)
{
    ui->setupUi(this);
    mAddEditDialog= new AddEditDialog(this); // Be sure to destroy you window somewhere
    mAddEditDialog->setModal(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    OnReadFromFile();
}

void ObjectInfoForm::SetData()
{
    addressOfObject=mAddEditDialog->GetAddress();
    areaOfLand=mAddEditDialog->GetAreaLand();
    areaOfYard=mAddEditDialog->GetAreaYard();
    areaOfBuilding=mAddEditDialog->GetAreaBuilding();
    areaOfRoof=mAddEditDialog->GetAreaRoof();
    areaOfBasement=mAddEditDialog->GetAreaBasement();
    areaOfStaircase=mAddEditDialog->GetAreaStaircase();
    numberOfFloors=mAddEditDialog->GetNumberStages();
    numberOfEntrances=mAddEditDialog->GetNumberEntrances();
    numberOfApartments=mAddEditDialog->GetNumberApartments();
    objectId=mAddEditDialog->GetNumber();
}

void ObjectInfoForm::on_btnAdd_2_clicked()
{
    tableRows=ui->tableWidget->rowCount();
    if(mAddEditDialog->exec()==QDialog::Accepted)
    {
        SetData();
        ui->tableWidget->insertRow(tableRows);
        ui->tableWidget->setItem(tableRows,0, new QTableWidgetItem(QString::number(objectId)));
        ui->tableWidget->setItem(tableRows,1, new QTableWidgetItem(addressOfObject));
        ui->tableWidget->setItem(tableRows,2, new QTableWidgetItem(QString::number(areaOfLand)));
        ui->tableWidget->setItem(tableRows,3, new QTableWidgetItem(QString::number(areaOfYard)));
        ui->tableWidget->setItem(tableRows,4, new QTableWidgetItem(QString::number(areaOfBuilding)));
        ui->tableWidget->setItem(tableRows,5, new QTableWidgetItem(QString::number(numberOfApartments)));
        ui->tableWidget->setItem(tableRows,6, new QTableWidgetItem(QString::number(numberOfFloors)));
        ui->tableWidget->setItem(tableRows,7, new QTableWidgetItem(QString::number(numberOfEntrances)));
        ui->tableWidget->setItem(tableRows,8, new QTableWidgetItem(QString::number(areaOfRoof)));
        ui->tableWidget->setItem(tableRows,9, new QTableWidgetItem(QString::number(areaOfStaircase)));
        ui->tableWidget->setItem(tableRows,10, new QTableWidgetItem(QString::number(areaOfBasement)));
    }
}

void ObjectInfoForm::closeEvent(QCloseEvent *event)
{
    OnSaveToFile();
    event->accept();
}

void ObjectInfoForm::OnSaveToFile()
{
    QFile f( "data.csv" );

    if (f.open(QIODevice::WriteOnly))
    {
        QTextStream data( &f );
        QStringList strList;

        for( int r = 0; r < ui->tableWidget->rowCount(); ++r )
        {
            strList.clear();
            for( int c = 0; c < ui->tableWidget->columnCount(); ++c )
            {
                strList << ui->tableWidget->item( r, c )->text();
            }
            data << strList.join( ";" )+"\n";
        }
        f.close();
    }
}

void ObjectInfoForm::OnReadFromFile()
{
    //std::vector<ObjectInfoForm> objectList = HouseManagementSystem::getInstance()->getObjectList();
    QVector<ObjectInfoForm *> objectList = HouseManagementSystem::getInstance()->getObjectList();
    int counter=0;
    for(int i=0;i<objectList.size();i++)
    {
        ui->tableWidget->insertRow(counter);
        ui->tableWidget->setItem(counter, 0,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetNumber())));
        ui->tableWidget->setItem(counter, 1,
                                 new QTableWidgetItem(objectList[i]->GetAddress()));
        ui->tableWidget->setItem(counter, 2,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetAreaLand())));
        ui->tableWidget->setItem(counter, 3,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetAreaYard())));
        ui->tableWidget->setItem(counter, 4,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetAreaBuilding())));
        ui->tableWidget->setItem(counter, 5,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetNumberApartments())));
        ui->tableWidget->setItem(counter, 6,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetNumberStages())));
        ui->tableWidget->setItem(counter, 7,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetNumberEntrances())));
        ui->tableWidget->setItem(counter, 8,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetAreaRoof())));
        ui->tableWidget->setItem(counter, 9,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetAreaStaircase())));
        ui->tableWidget->setItem(counter, 10,
                                 new QTableWidgetItem(QString::number(objectList[i]->GetAreaBasement())));
        counter++;
    }
    //    QFile file("data.csv");
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
    //            counter++;
    //        }
    //    }
    //    file.close();
}

void ObjectInfoForm::on_btnDelete_2_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

QString ObjectInfoForm::GetAddress()
{
    return addressOfObject;
}

int ObjectInfoForm::GetNumber()
{
    return objectId;
}

float ObjectInfoForm::GetAreaLand()
{
    return areaOfLand;
}

float ObjectInfoForm::GetAreaYard()
{
    return areaOfYard;
}

float ObjectInfoForm::GetAreaBuilding()
{
    return areaOfBuilding;
}

float ObjectInfoForm::GetAreaRoof()
{
    return areaOfRoof;
}

float ObjectInfoForm::GetAreaBasement()
{
    return areaOfBasement;
}

float ObjectInfoForm::GetAreaStaircase()
{
    return areaOfStaircase;
}

int ObjectInfoForm::GetNumberStages()
{
    return numberOfFloors;
}

int ObjectInfoForm::GetNumberApartments()
{
    return numberOfApartments;
}

int ObjectInfoForm::GetNumberEntrances()
{
    return numberOfEntrances;
}
