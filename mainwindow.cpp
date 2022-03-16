#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CreateUi();
    ConnectObjects();
    //ui->horizontalLayout->insertWidget(0,new SideBar(this));
    //ui->leftToolBar->setStyleSheet("QToolBar {background: rgb(100, 100, 100)}");
    //ui->leftToolBar->setMovable(false);

    //ui->leftToolBar->setIconSize(QSize(90,90));
}

MainWindow::~MainWindow()
{
    delete m_mainLayout;
    delete s_Bar;
    delete a_Object;
    delete a_Owner;
    delete a_Payment;
    delete a_Tafir;
    delete m_Area;
    delete ui;
}

void MainWindow::CreateUi()
{
    showMaximized();
    setWindowTitle(tr("HMS"));
    setWindowIcon(QIcon("://icons/icon-hms-64.jpg"));

    m_mainLayout = new QHBoxLayout;

    m_Widget = new QWidget;

    s_Bar = new SideBar(this);
    a_Object = new QAction;
    a_Owner = new QAction;
    a_Payment = new QAction;
    a_Tafir = new QAction;
    m_Area = new QMdiArea;

    a_Object->setText(tr("Добавить Объект"));
    a_Object->setIcon(QIcon("://icons/icons8-house-64.png"));
    a_Owner->setText(tr("Добавить Жильца"));
    a_Owner->setIcon(QIcon("://icons/icons8-business-64.png"));
    a_Payment->setText(tr("Добавить Оплату"));
    a_Payment->setIcon(QIcon("://icons/icons8-payment-64.png"));
    a_Tafir->setText(tr("Добавить Тариф"));
    a_Tafir->setIcon(QIcon("://icons/icons8-tariff-64.png"));

    s_Bar->addAction(a_Object);
    s_Bar->addAction(a_Owner);
    s_Bar->addAction(a_Payment);
    s_Bar->addAction(a_Tafir);

    m_mainLayout->addWidget(s_Bar);
    m_mainLayout->addWidget(m_Area);

    m_Widget->setLayout(m_mainLayout);
    setCentralWidget(m_Widget);

    //setLayout(m_Widget);

}

void MainWindow::ConnectObjects()
{
    connect(a_Object,&QAction::triggered,this,
            &MainWindow::OnAddObject_triggered);
    connect(a_Owner,&QAction::triggered,this,
            &MainWindow::OnAddOwner_triggered);
    connect(a_Payment,&QAction::triggered,this,
            &MainWindow::OnAddPayment_triggered);
    connect(a_Tafir,&QAction::triggered,this,
            &MainWindow::OnAddTarif_triggered);

    //menu bar
    connect(ui->actionaddo,&QAction::triggered,this,
            &MainWindow::OnAddObject_triggered);
}

void MainWindow::LoadSubWindow(QWidget *widget)
{
    //auto window = ui->mdiArea->addSubWindow(widget);
    auto window = m_Area->addSubWindow(widget);
    window->setWindowTitle(widget->windowTitle());
    window->show();
}

void MainWindow::OnAddObject_triggered()
{
    mAddEditObjectForm=new ObjectInfoForm(this);
    LoadSubWindow(mAddEditObjectForm);
}

void MainWindow::OnAddOwner_triggered()
{
    mAddEditOwnerForm=new OwnerInfoForm(this);
    LoadSubWindow(mAddEditOwnerForm);
}

void MainWindow::OnAddPayment_triggered()
{
    mAddEditPaymentForm=new PaymentInfoForm(this);
    LoadSubWindow(mAddEditPaymentForm);
}

void MainWindow::OnAddTarif_triggered()
{
    mAddEditTariffForm = new TariffInfoForm(this);
    LoadSubWindow(mAddEditTariffForm);
}

//void MainWindow::on_actionAddObject_triggered()
//{
//    mAddEditObjectForm=new ObjectInfoForm(this);
//    LoadSubWindow(mAddEditObjectForm);
//}



//void MainWindow::on_actionAddOwner_triggered()
//{
//    mAddEditOwnerForm=new OwnerInfoForm(this);
//    LoadSubWindow(mAddEditOwnerForm);
//}


//void MainWindow::on_actionAddPayment_triggered()
//{
//    mAddEditPaymentForm=new PaymentInfoForm(this);
//    LoadSubWindow(mAddEditPaymentForm);
//}


//void MainWindow::on_actionAddTarif_triggered()
//{
//    mAddEditTariffForm = new TariffInfoForm(this);
//    LoadSubWindow(mAddEditTariffForm);
//}



