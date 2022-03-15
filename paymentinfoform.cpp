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
    readFromFile();
}



void PaymentInfoForm::setData()
{
    idPaymentNumber=mAddPaymentDialog->getIdPaymentNumber();
    ticketPaymentNumber=mAddPaymentDialog->getTicketPaymentNumber();
    datePayment=mAddPaymentDialog->getDatePayment();
    housePaymentNumber=mAddPaymentDialog->getHousePaymentNumber();
    apartmentPaymentNumber=mAddPaymentDialog->getApartmentPaymentNumber();
    fioPayment=mAddPaymentDialog->getFioPayment();
    paymentSum=mAddPaymentDialog->getPaymentSum();
}

void PaymentInfoForm::on_btnAdd_clicked()
{
    tableRows=ui->tableWidget->rowCount();
    if(mAddPaymentDialog->exec()==QDialog::Accepted)
    {
        setData();
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

void PaymentInfoForm::saveToFile()
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
    saveToFile();
    event->accept();
}

void PaymentInfoForm::readFromFile()
{
    QVector<PaymentInfoForm *> paymentList = HouseManagementSystem::getInstance()->getPaymentList();
    int counter=0;
    for(int i=0;i<paymentList.size();i++)
    {
        ui->tableWidget->insertRow(counter);
        ui->tableWidget->setItem(counter, 0,
                                 new QTableWidgetItem(QString::number(paymentList[i]->getIdPaymentNumber())));
        ui->tableWidget->setItem(counter, 1,
                                 new QTableWidgetItem(QString::number(paymentList[i]->getTicketPaymentNumber())));
        ui->tableWidget->setItem(counter, 2,
                                 new QTableWidgetItem(paymentList[i]->getDatePayment()));
        ui->tableWidget->setItem(counter, 3,
                                 new QTableWidgetItem(QString::number(paymentList[i]->getHousePaymentNumber())));
        ui->tableWidget->setItem(counter, 4,
                                 new QTableWidgetItem(QString::number(paymentList[i]->getApartmentPaymentNumber())));
        ui->tableWidget->setItem(counter, 5,
                                 new QTableWidgetItem(paymentList[i]->getFioPayment()));
        ui->tableWidget->setItem(counter, 6,
                                 new QTableWidgetItem(QString::number(paymentList[i]->getPaymentSum())));
        counter++;

    }
}


void PaymentInfoForm::on_btnDelete_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

int PaymentInfoForm::getIdPaymentNumber()
{
    return idPaymentNumber;
}

int PaymentInfoForm::getTicketPaymentNumber()
{
    return ticketPaymentNumber;
}

QString PaymentInfoForm::getDatePayment()
{
    return datePayment;
}

int PaymentInfoForm::getHousePaymentNumber()
{
    return housePaymentNumber;
}

int PaymentInfoForm::getApartmentPaymentNumber()
{
    return apartmentPaymentNumber;
}

QString PaymentInfoForm::getFioPayment()
{
    return fioPayment;
}

unsigned int PaymentInfoForm::getPaymentSum()
{
    return paymentSum;
}

PaymentInfoForm::~PaymentInfoForm()
{
    delete ui;
}
