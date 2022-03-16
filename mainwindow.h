#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QMdiSubWindow>
#include <QToolButton>
#include <QHBoxLayout>
#include <QMdiArea>

#include "objectinfoform.h"
#include "ownerinfoform.h"
#include "paymentinfoform.h"
#include "tariffinfoform.h"
#include "sidebar.h"

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
//    void on_actionAddObject_triggered();

//    void on_actionAddOwner_triggered();

//    void on_actionAddPayment_triggered();

//    void on_actionAddTarif_triggered();

private:
    void CreateUi();
    void ConnectObjects();

public slots:
    void OnAddObject_triggered();
    void OnAddOwner_triggered();
    void OnAddPayment_triggered();
    void OnAddTarif_triggered();

private:
    void LoadSubWindow(QWidget *widget);

    Ui::MainWindow *ui;

    QPointer<ObjectInfoForm> mAddEditObjectForm;
    QPointer<OwnerInfoForm> mAddEditOwnerForm;
    QPointer<PaymentInfoForm> mAddEditPaymentForm;
    QPointer<TariffInfoForm> mAddEditTariffForm;
    SideBar *s_Bar;
    QAction *a_Object;
    QAction *a_Owner;
    QAction *a_Payment;
    QAction *a_Tafir;
    QMdiArea *m_Area;
    QHBoxLayout *m_mainLayout;
    QWidget *m_Widget;

};
#endif // MAINWINDOW_H
