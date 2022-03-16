#ifndef PAYMENTINFOFORM_H
#define PAYMENTINFOFORM_H

#include <QWidget>
#include <QCloseEvent>
#include <QTextStream>
#include "addpaymentdialog.h"
#include "housemanagementsystem.h"

class AddPaymentDialog;
namespace Ui {
class PaymentInfoForm;
}

class PaymentInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentInfoForm(QWidget *parent = nullptr);
    PaymentInfoForm(int idPaymentNumber, int ticketPaymentNumber,
                    QString datePayment, int housePaymentNumber,
                    int apartmentPaymentNumber, QString fioPayment,
                    unsigned int paymentSum)
    {
        this->idPaymentNumber=idPaymentNumber ;
        this->ticketPaymentNumber=ticketPaymentNumber;
        this->datePayment=datePayment;
        this->housePaymentNumber=housePaymentNumber;
        this->apartmentPaymentNumber=apartmentPaymentNumber;
        this->fioPayment=fioPayment;
        this->paymentSum=paymentSum;//
    }

    int GetIdPaymentNumber();
    int GetTicketPaymentNumber();
    QString GetDatePayment();
    int GetHousePaymentNumber();
    int GetApartmentPaymentNumber();
    QString GetFioPayment();
    unsigned int GetPaymentSum();

    void SetData();

    ~PaymentInfoForm();

private slots:
    void on_btnAdd_clicked();
    void OnSaveToFile();
    void closeEvent(QCloseEvent *event);
    void OnReadFromFile();

    void on_btnDelete_clicked();

private:
    Ui::PaymentInfoForm *ui;

    AddPaymentDialog *mAddPaymentDialog;
    int tableRows;

    int idPaymentNumber;
    int ticketPaymentNumber;
    QString datePayment;
    int housePaymentNumber;
    int apartmentPaymentNumber;
    QString fioPayment;
    unsigned int paymentSum;


    QVector<OwnerInfoForm *> ownerList;
};

#endif // PAYMENTINFOFORM_H
