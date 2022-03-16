#ifndef ADDOWNERDIALOG_H
#define ADDOWNERDIALOG_H

#include <QDialog>
#include "objectinfoform.h"
#include "tariffinfoform.h"

class ObjectInfoForm;
class TariffInfoForm;

namespace Ui {
class AddOwnerDialog;
}

class AddOwnerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddOwnerDialog(QWidget *parent = nullptr);
    ~AddOwnerDialog();
    QString GetOwnerLastName();
    QString GetownerFirstName();
    QString GetOwnerMiddleName();
    QString GetOwnerSex();
    QString GetOwnerAge();
    QString GetOwnerPhone();
    //QString getOwnerCredit();
    int     GetOwnerHouseNumber();
    int     GetOwnerHouseCarNumber();
    int     GetOwnerHouseResidenceNumber();
    int     GetOwnerApartmentNumber();
    QString GetOwnerApartmentType();
    float   GetOwnerApartmentArea();
    QString GetOwnerDateRegistration();
    float   GetOwnerCalculatePaySum();
private slots:
    void on_btnAddOwner_clicked();
    void on_pushButton_2_clicked();
    void on_comboBoxHouseNumber_currentIndexChanged(const QString &arg1);

private:
    Ui::AddOwnerDialog *ui;
    QVector<ObjectInfoForm *> objectList;
    QVector<TariffInfoForm *> tarifList;
};

#endif // ADDOWNERDIALOG_H
