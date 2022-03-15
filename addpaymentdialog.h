#ifndef ADDPAYMENTDIALOG_H
#define ADDPAYMENTDIALOG_H

#include <QDialog>
#include <QTextStream>
#include "objectinfoform.h"
#include "ownerinfoform.h"

class ObjectInfoForm;
class OwnerInfoForm;

namespace Ui {
class AddPaymentDialog;
}

class AddPaymentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPaymentDialog(QWidget *parent = nullptr);
    ~AddPaymentDialog();


    int getIdPaymentNumber();
    int getTicketPaymentNumber();
    QString getDatePayment();
    int getHousePaymentNumber();
    int getApartmentPaymentNumber();
    QString getFioPayment();
    unsigned int getPaymentSum();
    //friend QTextStream &operator<<(QTextStream &ds, const OwnerInfoForm &inObj);

private slots:
    void on_btnAdd_clicked();

    void on_btnClose_clicked();

    void on_cmbHouseNumber_currentIndexChanged(const QString &arg1);

    void on_cmbApartmentNumber_currentIndexChanged(const QString &arg1);

private:
    Ui::AddPaymentDialog *ui;

    QVector<ObjectInfoForm *> objectList;
    QVector<OwnerInfoForm *> ownerList;

    int apartmentNumbers = 0;
    int getNumberInList;
    int ID=0;
};

#endif // ADDPAYMENTDIALOG_H
