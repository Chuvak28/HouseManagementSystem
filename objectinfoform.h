#ifndef OBJECTINFOFORM_H
#define OBJECTINFOFORM_H

#include <QWidget>
#include "addeditdialog.h"
#include <QCloseEvent>
#include "housemanagementsystem.h"


namespace Ui {
class ObjectInfoForm;
}

class ObjectInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit ObjectInfoForm(QWidget *parent = nullptr);
    //ObjectInfoForm(){}
    ObjectInfoForm(int objectId, QString addressOfObject,
                   float  areaOfLand,
                   float areaOfYard, float areaOfBuilding,
                   int numberOfApartments, int numberOfFloors,
                   int numberOfEntrances, float areaOfRoof,
                   float areaOfStaircase,float areaOfBasement)
    {
        this->objectId=objectId;
        this->addressOfObject=addressOfObject;
        this->areaOfLand=areaOfLand;
        this->areaOfYard=areaOfYard;
        this->areaOfBuilding=areaOfBuilding;;
        this->numberOfApartments=numberOfApartments;
        this->numberOfFloors=numberOfFloors;
        this->numberOfEntrances=numberOfEntrances;
        this->areaOfRoof=areaOfRoof;
        this->areaOfStaircase=areaOfStaircase;
        this->areaOfBasement=areaOfBasement;
    }
    ~ObjectInfoForm();
    void    SetData();
    QString GetAddress();
    int     GetNumber();
    float   GetAreaLand();//
    float   GetAreaYard();
    float   GetAreaBuilding();
    float   GetAreaRoof();//
    float   GetAreaBasement();
    float   GetAreaStaircase();
    int     GetNumberStages();
    int     GetNumberApartments();
    int     GetNumberEntrances();

private slots:
    void on_btnAdd_2_clicked();
    void closeEvent(QCloseEvent *event);
    void OnSaveToFile();
    void OnReadFromFile();
    void on_btnDelete_2_clicked();

private:
    Ui::ObjectInfoForm *ui;
    AddEditDialog *mAddEditDialog;
    QString addressOfObject;
    float areaOfLand;
    float areaOfYard;
    float areaOfBuilding;
    float areaOfRoof;
    float areaOfBasement;
    float areaOfStaircase;
    int numberOfFloors;
    int numberOfEntrances;
    int numberOfApartments;
    int objectId;//number of house

    int tableRows;

};

#endif // OBJECTINFOFORM_H
