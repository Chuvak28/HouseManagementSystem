#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();

    ui->leftToolBar->setStyleSheet("QToolBar {background: rgb(100, 100, 100)}");
    ui->leftToolBar->setMovable(false);

    //ui->leftToolBar->setIconSize(QSize(90,90));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAddObject_triggered()
{
    mAddEditObjectForm=new ObjectInfoForm(this);
    loadSubWindow(mAddEditObjectForm);
}

void MainWindow::loadSubWindow(QWidget *widget)
{
    auto window = ui->mdiArea->addSubWindow(widget);
    window->setWindowTitle(widget->windowTitle());
    window->show();
}

void MainWindow::on_actionAddOwner_triggered()
{
    mAddEditOwnerForm=new OwnerInfoForm(this);
    loadSubWindow(mAddEditOwnerForm);
}


void MainWindow::on_actionAddPayment_triggered()
{
    mAddEditPaymentForm=new PaymentInfoForm(this);
    loadSubWindow(mAddEditPaymentForm);
}


void MainWindow::on_actionAddTarif_triggered()
{
    mAddEditTariffForm = new TariffInfoForm(this);
    loadSubWindow(mAddEditTariffForm);
}

