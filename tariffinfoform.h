#ifndef TARIFFINFOFORM_H
#define TARIFFINFOFORM_H

#include <QWidget>
#include <QCloseEvent>
#include <QTextStream>
#include "addtariffdialog.h"
#include "housemanagementsystem.h"

class AddTariffDialog;

namespace Ui {
class TariffInfoForm;
}

class TariffInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit TariffInfoForm(QWidget *parent = nullptr);
    ~TariffInfoForm();

    TariffInfoForm(QString tariffDate,int tariffHouseNumber,
    unsigned int tariffSum)
    {
        this->tariffDate=tariffDate ;
        this->tariffHouseNumber=tariffHouseNumber;
        this->tariffSum=tariffSum;
    }

    QString getDateTariff();
    int getHouseTarifNumber();
    unsigned int getTarifSum();

    void setData();


private slots:
    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

    void saveToFile();
    void closeEvent(QCloseEvent *event);
    void readFromFile();

private:
    Ui::TariffInfoForm *ui;

    AddTariffDialog *mAddTariffDialog;
    int tableRows;

    QString tariffDate;
    int tariffHouseNumber;
    unsigned int tariffSum;
};

#endif // TARIFFINFOFORM_H
