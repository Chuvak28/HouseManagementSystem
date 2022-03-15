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
    void setOwnerLastName() ;
    void setownerFirstName();
    void setOwnerMiddleName();
    void setOwnerSex();
    void setOwnerAge();
    void setOwnerPhone();
    void setOwnerApartmentType();
    void setOwnerDateRegistration();
    void     setOwnerHouseNumber();
    void     setOwnerHouseCarNumber();
    void     setOwnerHouseResidenceNumber();
    void     setOwnerApartmentNumber();
    void     setOwnerCalculated();
    void    setOwnerPayment(int p)
    {
        ownerPayed=p;
    }
    void     setOwnerToPayment();

    void   setOwnerApartmentArea();

    ///GETTER
    QString getOwnerLastName() const;
    QString getownerFirstName()const;
    QString getOwnerMiddleName()const;
    QString getOwnerSex()const;
    QString getOwnerAge()const;
    QString getOwnerPhone()const;
    //QString getOwnerCredit();
    QString getOwnerApartmentType()const;
    QString getOwnerDateRegistration()const;
    int     getOwnerHouseNumber()const;
    int     getOwnerHouseCarNumber()const;
    int     getOwnerHouseResidenceNumber()const;
    int     getOwnerApartmentNumber()const;
    float     getOwnerCalculated()const;
    int     getOwnerPayed()const;
    int     getOwnerToPayment()const;
    float   getOwnerApartmentArea()const;



    void setData();

private slots:
    void on_btnAdd_clicked();
    void closeEvent(QCloseEvent *event);
    void saveToFile();
    void readFromFile();

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
