#include "housemanagementsystem.h"

HouseManagementSystem* HouseManagementSystem::instance = nullptr;
HouseManagementSystem::HouseManagementSystem()
{

}

QVector<ObjectInfoForm *> HouseManagementSystem::getObjectList()
{
    //std::vector<ObjectInfoForm> objectList;
    QVector<ObjectInfoForm *> objectList;
    QFile file("data.csv");
    QTextStream stream(&file);

    if (file.open(QIODevice::ReadOnly)){

        while (!stream.atEnd()){
            QString str = stream.readLine();
            QStringList strList = str.split(";");
            objectList.push_back( new ObjectInfoForm(strList.at(0).toInt(),
                                                     strList.at(1),
                                                     strList.at(2).toFloat(),
                                                     strList.at(3).toFloat(),
                                                     strList.at(4).toFloat(),
                                                     strList.at(5).toInt(),
                                                     strList.at(6).toInt(),
                                                     strList.at(7).toInt(),
                                                     strList.at(8).toFloat(),
                                                     strList.at(9).toFloat(),
                                                     strList.at(10).toFloat()));
        }
    }
    file.close();
    return objectList;
}

QVector<OwnerInfoForm *> HouseManagementSystem::getOwnerList()
{
    QVector<OwnerInfoForm *> ownerList;
    QFile file("owner.csv");
    QTextStream stream(&file);

    if (file.open(QIODevice::ReadOnly)){

        while (!stream.atEnd()){
            QString str = stream.readLine();
            QStringList strList = str.split(";");
            ownerList.push_back( new OwnerInfoForm(strList.at(0),
                                                   strList.at(1),
                                                   strList.at(2),
                                                   strList.at(3).toInt(),
                                                   strList.at(4).toInt(),
                                                   strList.at(5),
                                                   strList.at(6),
                                                   strList.at(7),
                                                   strList.at(8),
                                                   strList.at(9).toInt(),
                                                   strList.at(10).toInt(),
                                                   strList.at(11).toInt(),
                                                   strList.at(12).toFloat(),
                                                   strList.at(13).toInt(),
                                                   strList.at(14).toInt(),
                                                   strList.at(15)));
        }
    }
    file.close();
    return ownerList;
}

QVector<PaymentInfoForm *> HouseManagementSystem::getPaymentList()
{
    QVector<PaymentInfoForm *> paymentList;
    QFile file("payment.csv");
    QTextStream stream(&file);

    if (file.open(QIODevice::ReadOnly)){

        while (!stream.atEnd()){
            QString str = stream.readLine();
            QStringList strList = str.split(";");
            paymentList.push_back( new PaymentInfoForm(strList.at(0).toInt(),
                                                   strList.at(1).toInt(),
                                                   strList.at(2),
                                                   strList.at(3).toInt(),
                                                   strList.at(4).toInt(),
                                                   strList.at(5),
                                                   strList.at(6).toUInt()));
        }
    }
    file.close();
    return paymentList;
}

QVector<TariffInfoForm *> HouseManagementSystem::getTariffList()
{
    QVector<TariffInfoForm *> tariffList;
    QFile file("tarif.csv");
    QTextStream stream(&file);

    if (file.open(QIODevice::ReadOnly)){

        while (!stream.atEnd()){
            QString str = stream.readLine();
            QStringList strList = str.split(";");
            tariffList.push_back( new TariffInfoForm(strList.at(0),
                                                   strList.at(1).toInt(),
                                                   strList.at(2).toUInt()));
        }
    }
    file.close();
    return tariffList;
}

HouseManagementSystem *HouseManagementSystem::getInstance()
{
    if(instance == nullptr)
        instance = new HouseManagementSystem();
    return instance;
}
