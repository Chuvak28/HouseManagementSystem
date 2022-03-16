#ifndef OWNERINFOFORM_H
#define OWNERINFOFORM_H

#include <QWidget>
#include <QCloseEvent>
#include <QTextStream>
#include "addownerdialog.h"
#include "housemanagementsystem.h"
#include "tariffinfoform.h"

class TariffInfoForm;
class AddOwnerDialog;
namespace Ui {
class OwnerInfoForm;
}

class OwnerInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit OwnerInfoForm(QWidget *parent = nullptr);
    ~OwnerInfoForm();

    OwnerInfoForm(QString ownerLastName, QString ownerFirstName,
                  QString ownerMiddleName, int ownerHouseNumber,
                  int ownerApartmentNumber,QString ownerDateRegistration,
                  QString ownerSex,
                  QString ownerAge, QString ownerPhone,
                  int     ownerCalculated,int     ownerPayed,
                  int     ownerToPayment,
                  float ownerApartmentArea,
                  int ownerHouseCarNumber, int ownerHouseResidenceNumber,
                  QString ownerApartmentType
                  )
    {

        this->ownerLastName=ownerLastName ;
        this->ownerFirstName=ownerFirstName;
        this->ownerMiddleName=ownerMiddleName;
        this->ownerHouseNumber=ownerHouseNumber;
        this->ownerApartmentNumber=ownerApartmentNumber;
        this->ownerDateRegistration=ownerDateRegistration;
        this->ownerSex=ownerSex;
        this->ownerAge=ownerAge;//
        this->ownerPhone=ownerPhone;
        this->ownerCalculated=ownerCalculated;
        this->ownerPayed=ownerPayed;
        this->ownerToPayment=ownerToPayment;
        this->ownerApartmentArea=ownerApartmentArea;
        this->ownerHouseCarNumber=ownerHouseCarNumber;
        this->ownerHouseResidenceNumber=ownerHouseResidenceNumber;
        this->ownerApartmentType=ownerApartmentType;

    }
    ///SETTER
    ///
    void SetOwnerLastName() ;
    void SetownerFirstName();
    void SetOwnerMiddleName();
    void SetOwnerSex();
    void SetOwnerAge();
    void SetOwnerPhone();
    void SetOwnerApartmentType();
    void SetOwnerDateRegistration();
    void SetOwnerHouseNumber();
    void SetOwnerHouseCarNumber();
    void SetOwnerHouseResidenceNumber();
    void SetOwnerApartmentNumber();
    void SetOwnerCalculated();
    void SetOwnerPayment(int p)
    {
        ownerPayed=p;
    }
    void SetOwnerToPayment();

    void SetOwnerApartmentArea();

    ///GETTER
    QString GetOwnerLastName() const;
    QString GetownerFirstName()const;
    QString GetOwnerMiddleName()const;
    QString GetOwnerSex()const;
    QString GetOwnerAge()const;
    QString GetOwnerPhone()const;
    //QString getOwnerCredit();
    QString GetOwnerApartmentType()const;
    QString GetOwnerDateRegistration()const;
    int     GetOwnerHouseNumber()const;
    int     GetOwnerHouseCarNumber()const;
    int     GetOwnerHouseResidenceNumber()const;
    int     GetOwnerApartmentNumber()const;
    float   GetOwnerCalculated()const;
    int     GetOwnerPayed()const;
    int     GetOwnerToPayment()const;
    float   GetOwnerApartmentArea()const;



    void SetData();

private slots:
    void on_btnAdd_clicked();
    void closeEvent(QCloseEvent *event);
    void OnSaveToFile();
    void OnReadFromFile();

    void on_btnDelete_clicked();

    void on_btnCalc_clicked();

private:
    Ui::OwnerInfoForm *ui;

    QVector<OwnerInfoForm *> ownerList;
    QVector<TariffInfoForm *> tarifList;


    AddOwnerDialog *mAddOwnerDialog;
    int tableRows;

    QString ownerLastName;
    QString ownerFirstName;
    QString ownerMiddleName;
    QString ownerSex;
    QString ownerAge;
    QString ownerPhone;
    //QString ownerCredit;
    QString ownerApartmentType;
    QString ownerDateRegistration;
    float   ownerApartmentArea;
    int     ownerHouseNumber;
    int     ownerHouseCarNumber;
    int     ownerHouseResidenceNumber;
    int     ownerApartmentNumber;
    int     ownerCalculated=0;
    int     ownerPayed=0;
    int     ownerToPayment=0;

    int r;
    int c;

};

#endif // OWNERINFOFORM_H
