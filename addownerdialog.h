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
    QString getOwnerLastName();
    QString getownerFirstName();
    QString getOwnerMiddleName();
    QString getOwnerSex();
    QString getOwnerAge();
    QString getOwnerPhone();
    //QString getOwnerCredit();
    int     getOwnerHouseNumber();
    int     getOwnerHouseCarNumber();
    int     getOwnerHouseResidenceNumber();
    int     getOwnerApartmentNumber();
    QString getOwnerApartmentType();
    float   getOwnerApartmentArea();
    QString getOwnerDateRegistration();
    float getOwnerCalculatePaySum();
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
