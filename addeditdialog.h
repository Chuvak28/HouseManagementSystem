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
    QString getAddress();
    int     getNumber();
    float   getAreaLand();//
    float   getAreaYard();
    float   getAreaBuilding();
    float   getAreaRoof();//
    float   getAreaBasement();
    float   getAreaStaircase();
    int     getNumberStages();
    int     getNumberApartments();
    int     getNumberEntrances();
    void    setData();

private slots:
    void on_btnAdd_3_clicked();

    void on_btnClose_3_clicked();

private:
    Ui::AddEditDialog *ui;
};

#endif // ADDEDITDIALOG_H
