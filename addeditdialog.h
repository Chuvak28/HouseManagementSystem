#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

#include <QDialog>

namespace Ui {
class AddEditDialog;
}

class AddEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditDialog(QWidget *parent = nullptr);
    ~AddEditDialog();
    QString GetAddress();
    int     GetNumber();
    float   GetAreaLand();//
    float   GetAreaYard();
    float   GetAreaBuilding();
    float   GetAreaRoof();//
    float   GetAreaBasement();
    float   GetAreaStaircase();
    int     GetNumberStages();
    int     GetNumberApartments();
    int     GetNumberEntrances();
    void    SetData();

private slots:
    void on_btnAdd_3_clicked();

    void on_btnClose_3_clicked();

private:
    Ui::AddEditDialog *ui;
};

#endif // ADDEDITDIALOG_H
