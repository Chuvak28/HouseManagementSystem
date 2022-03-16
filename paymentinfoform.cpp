#include "paymentinfoform.h"
#include "ui_paymentinfoform.h"

PaymentInfoForm::PaymentInfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaymentInfoForm)
{
    ui->setupUi(this);
    mAddPaymentDialog= new AddPaymentDialog; // Be sure to destroy you window somewhere
    mAddPaymentDialog->setModal(true);
    //    readFromFile();
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    OnReadFromFile();
}



void PaymentInfoForm::SetData()
{
    idPaymentNumber=mAddPaymentDialog->GetIdPaymentNumber();
    ticketPaymentNumber=mAddPaymentDialog->GetTicketPaymentNumber();
    datePayment=mAddPaymentDialog->GetDatePayment();
    housePaymentNumber=mAddPaymentDialog->GetHousePaymentNumber();
    apartmentPaymentNumber=mAddPaymentDialog->GetApartmentPaymentNumber();
    fioPayment=mAddPaymentDialog->GetFioPayment();
    paymentSum=mAddPaymentDialog->GetPaymentSum();
}

void PaymentInfoForm::on_btnAdd_clicked()
{
    tableRows=ui->tableWidget->rowCount();
    if(mAddPaymentDialog->exec()==QDialog::Accepted)
    {
        SetData();
        ui->tableWidget->insertRow(tableRows);
        ui->tableWidget->setItem(tableRows,0, new QTableWidgetItem(QString::number(idPaymentNumber)));
        ui->tableWidget->setItem(tableRows,1, new QTableWidgetItem(QString::number(ticketPaymentNumber)));
        ui->tableWidget->setItem(tableRows,2, new QTableWidgetItem(datePayment));
        ui->tableWidget->setItem(tableRows,3, new QTableWidgetItem(QString::number(housePaymentNumber)));
        ui->tableWidget->setItem(tableRows,4, new QTableWidgetItem(QString::number(apartmentPaymentNumber)));
        ui->tableWidget->setItem(tableRows,5, new QTableWidgetItem(fioPayment));
        ui->tableWidget->setItem(tableRows,6, new QTableWidgetItem(QString::number(paymentSum)));
    }
}

void PaymentInfoForm::OnSaveToFile()
{
    QFile f("payment.csv");

    if (f.open(QIODevice::WriteOnly))
    {
        QTextStream data( &f );
        QStringList strList;

        for( int r = 0; r < ui->tableWidget->rowCount(); ++r )
        {
            strList.clear();
            for( int c = 0; c < ui->tableWidget->columnCount(); ++c )
            {
                strList << ui->tableWidget->item( r, c )->text();
            }
            data << strList.join( ";" )+"\n";
        }
        f.close();
    }
}

void PaymentInfoForm::closeEvent(QCloseEvent *event)
{
    OnSaveToFile();
    event->accept();
}

void PaymentInfoForm::OnReadFromFile()
{
    QVector<PaymentInfoForm *> paymentList = HouseManagementSystem::getInstance()->getPaymentList();
    int counter=0;
    for(int i=0;i<paymentList.size();i++)
    {
        ui->tableWidget->insertRow(counter);
        ui->tableWidget->setItem(counter, 0,
                                 new QTableWidgetItem(QString::number(paymentList[i]->GetIdPaymentNumber())));
        ui->tableWidget->setItem(counter, 1,
                                 new QTableWidgetItem(QString::number(paymentList[i]->GetTicketPaymentNumber())));
        ui->tableWidget->setItem(counter, 2,
                                 new QTableWidgetItem(paymentList[i]->GetDatePayment()));
        ui->tableWidget->setItem(counter, 3,
                                 new QTableWidgetItem(QString::number(paymentList[i]->GetHousePaymentNumber())));
        ui->tableWidget->setItem(counter, 4,
                                 new QTableWidgetItem(QString::number(paymentList[i]->GetApartmentPaymentNumber())));
        ui->tableWidget->setItem(counter, 5,
                                 new QTableWidgetItem(paymentList[i]->GetFioPayment()));
        ui->tableWidget->setItem(counter, 6,
                                 new QTableWidgetItem(QString::number(paymentList[i]->GetPaymentSum())));
        counter++;

    }
}


void PaymentInfoForm::on_btnDelete_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

int PaymentInfoForm::GetIdPaymentNumber()
{
    return idPaymentNumber;
}

int PaymentInfoForm::GetTicketPaymentNumber()
{
    return ticketPaymentNumber;
}

QString PaymentInfoForm::GetDatePayment()
{
    return datePayment;
}

int PaymentInfoForm::GetHousePaymentNumber()
{
    return housePaymentNumber;
}

int PaymentInfoForm::GetApartmentPaymentNumber()
{
    return apartmentPaymentNumber;
}

QString PaymentInfoForm::GetFioPayment()
{
    return fioPayment;
}

unsigned int PaymentInfoForm::GetPaymentSum()
{
    return paymentSum;
}

PaymentInfoForm::~PaymentInfoForm()
{
    delete mAddPaymentDialog;

    for (auto p : qAsConst(ownerList))
    {
        delete p;
    }
    ownerList.clear();
    delete ui;
}
