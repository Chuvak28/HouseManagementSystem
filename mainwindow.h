#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QMdiSubWindow>
#include <QToolButton>
#include "objectinfoform.h"
#include "ownerinfoform.h"
#include "paymentinfoform.h"
#include "tariffinfoform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_actionAddObject_triggered();

    void on_actionAddOwner_triggered();

    void on_actionAddPayment_triggered();

    void on_actionAddTarif_triggered();

private:
    Ui::MainWindow *ui;
    void loadSubWindow(QWidget *widget);
    QPointer<ObjectInfoForm> mAddEditObjectForm;
    QPointer<OwnerInfoForm> mAddEditOwnerForm;
    QPointer<PaymentInfoForm> mAddEditPaymentForm;
    QPointer<TariffInfoForm> mAddEditTariffForm;
};
#endif // MAINWINDOW_H
