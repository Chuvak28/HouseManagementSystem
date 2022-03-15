#ifndef ADDTARIFFDIALOG_H
#define ADDTARIFFDIALOG_H

#include <QDialog>
#include "objectinfoform.h"
#include "ownerinfoform.h"

class ObjectInfoForm;
class OwnerInfoForm;

namespace Ui {
class AddTariffDialog;
}

class AddTariffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTariffDialog(QWidget *parent = nullptr);
    ~AddTariffDialog();

    QString getDateTariff();
    int getHouseTarifNumber();
    unsigned int getTarifSum();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddTariffDialog *ui;

    QVector<ObjectInfoForm *> objectList;
    QVector<OwnerInfoForm *> ownerList;
};

#endif // ADDTARIFFDIALOG_H
