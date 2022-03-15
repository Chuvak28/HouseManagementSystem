#ifndef HOUSEMANAGEMENTSYSTEM_H
#define HOUSEMANAGEMENTSYSTEM_H

#include <QDebug>
#include <QFile>
#include <QVector>
#include "objectinfoform.h"
#include "ownerinfoform.h"
#include "paymentinfoform.h"
#include "tariffinfoform.h"

class OwnerInfoForm;
class ObjectInfoForm;
class PaymentInfoForm;
class TariffInfoForm;

class HouseManagementSystem
{
private:
    HouseManagementSystem();
    HouseManagementSystem(HouseManagementSystem const &){}
    static HouseManagementSystem* instance;

public:
    static HouseManagementSystem* getInstance();
    QVector<ObjectInfoForm *> getObjectList();
    QVector<OwnerInfoForm *> getOwnerList();
    QVector<PaymentInfoForm *> getPaymentList();
    QVector<TariffInfoForm *> getTariffList();

};

#endif // HOUSEMANAGEMENTSYSTEM_H
