#include "objectinfoform.h"
#include "ui_objectinfoform.h"
#include <QDebug>

ObjectInfoForm::~ObjectInfoForm()
{
    delete ui;
    delete mAddEditDialog;
}
ObjectInfoForm::ObjectInfoForm(QWidget *parent) : QWidget(parent),
    ui(new Ui::ObjectInfoForm)
{
    ui->setupUi(this);
    mAddEditDialog= new AddEditDialog(this); // Be sure to destroy you window somewhere
    mAddEditDialog->setModal(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    readFromFile();
}

void ObjectInfoForm::setData()
{
    addressOfObject=mAddEditDialog->getAddress();
    areaOfLand=mAddEditDialog->getAreaLand();
    areaOfYard=mAddEditDialog->getAreaYard();
    areaOfBuilding=mAddEditDialog->getAreaBuilding();
    areaOfRoof=mAddEditDialog->getAreaRoof();
    areaOfBasement=mAddEditDialog->getAreaBasement();
    areaOfStaircase=mAddEditDialog->getAreaStaircase();
    numberOfFloors=mAddEditDialog->getNumberStages();
    numberOfEntrances=mAddEditDialog->getNumberEntrances();
    numberOfApartments=mAddEditDialog->getNumberApartments();
    objectId=mAddEditDialog->getNumber();
}

void ObjectInfoForm::on_btnAdd_2_clicked()
{
    tableRows=ui->tableWidget->rowCount();
    if(mAddEditDialog->exec()==QDialog::Accepted)
    {
        setData();
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
    saveToFile();
    event->accept();
}

void ObjectInfoForm::saveToFile()
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

void ObjectInfoForm::readFromFile()
{
    //std::vector<ObjectInfoForm> objectList = HouseManagementSystem::getInstance()->getObjectList();
    QVector<ObjectInfoForm *> objectList = HouseManagementSystem::getInstance()->getObjectList();
    int counter=0;
    for(int i=0;i<objectList.size();i++)
    {
        ui->tableWidget->insertRow(counter);
        ui->tableWidget->setItem(counter, 0,
                                 new QTableWidgetItem(QString::number(objectList[i]->getNumber())));
        ui->tableWidget->setItem(counter, 1,
                                 new QTableWidgetItem(objectList[i]->getAddress()));
        ui->tableWidget->setItem(counter, 2,
                                 new QTableWidgetItem(QString::number(objectList[i]->getAreaLand())));
        ui->tableWidget->setItem(counter, 3,
                                 new QTableWidgetItem(QString::number(objectList[i]->getAreaYard())));
        ui->tableWidget->setItem(counter, 4,
                                 new QTableWidgetItem(QString::number(objectList[i]->getAreaBuilding())));
        ui->tableWidget->setItem(counter, 5,
                                 new QTableWidgetItem(QString::number(objectList[i]->getNumberApartments())));
        ui->tableWidget->setItem(counter, 6,
                                 new QTableWidgetItem(QString::number(objectList[i]->getNumberStages())));
        ui->tableWidget->setItem(counter, 7,
                                 new QTableWidgetItem(QString::number(objectList[i]->getNumberEntrances())));
        ui->tableWidget->setItem(counter, 8,
                                 new QTableWidgetItem(QString::number(objectList[i]->getAreaRoof())));
        ui->tableWidget->setItem(counter, 9,
                                 new QTableWidgetItem(QString::number(objectList[i]->getAreaStaircase())));
        ui->tableWidget->setItem(counter, 10,
                                 new QTableWidgetItem(QString::number(objectList[i]->getAreaBasement())));
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

QString ObjectInfoForm::getAddress()
{
    return addressOfObject;
}

int ObjectInfoForm::getNumber()
{
    return objectId;
}

float ObjectInfoForm::getAreaLand()
{
    return areaOfLand;
}

float ObjectInfoForm::getAreaYard()
{
    return areaOfYard;
}

float ObjectInfoForm::getAreaBuilding()
{
    return areaOfBuilding;
}

float ObjectInfoForm::getAreaRoof()
{
    return areaOfRoof;
}

float ObjectInfoForm::getAreaBasement()
{
    return areaOfBasement;
}

float ObjectInfoForm::getAreaStaircase()
{
    return areaOfStaircase;
}

int ObjectInfoForm::getNumberStages()
{
    return numberOfFloors;
}

int ObjectInfoForm::getNumberApartments()
{
    return numberOfApartments;
}

int ObjectInfoForm::getNumberEntrances()
{
    return numberOfEntrances;
}
