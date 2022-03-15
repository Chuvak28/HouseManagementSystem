#include "tariffinfoform.h"
#include "ui_tariffinfoform.h"

TariffInfoForm::TariffInfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TariffInfoForm)
{
    ui->setupUi(this);
    mAddTariffDialog= new AddTariffDialog; // Be sure to destroy you window somewhere
    mAddTariffDialog->setModal(true);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    readFromFile();
}

TariffInfoForm::~TariffInfoForm()
{
    delete ui;
}

QString TariffInfoForm::getDateTariff()
{
    return tariffDate;
}

int TariffInfoForm::getHouseTarifNumber()
{
    return tariffHouseNumber;
}

unsigned int TariffInfoForm::getTarifSum()
{
    return tariffSum;
}

void TariffInfoForm::setData()
{
    tariffDate=mAddTariffDialog->getDateTariff();
    tariffHouseNumber=mAddTariffDialog->getHouseTarifNumber();
    tariffSum=mAddTariffDialog->getTarifSum();
}

void TariffInfoForm::on_btnAdd_clicked()
{
    tableRows=ui->tableWidget->rowCount();
    if(mAddTariffDialog->exec()==QDialog::Accepted)
    {
        setData();
        ui->tableWidget->insertRow(tableRows);
        ui->tableWidget->setItem(tableRows,0, new QTableWidgetItem(tariffDate));
        ui->tableWidget->setItem(tableRows,1, new QTableWidgetItem(QString::number(tariffHouseNumber)));
        ui->tableWidget->setItem(tableRows,2, new QTableWidgetItem(QString::number(tariffSum)));

    }
}

void TariffInfoForm::on_btnDelete_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void TariffInfoForm::saveToFile()
{
    QFile f("tarif.csv");

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

void TariffInfoForm::closeEvent(QCloseEvent *event)
{
    saveToFile();
    event->accept();
}

void TariffInfoForm::readFromFile()
{
    QVector<TariffInfoForm *> tariffList = HouseManagementSystem::getInstance()->getTariffList();
    int counter=0;
    for(int i=0;i<tariffList.size();i++)
    {
        ui->tableWidget->insertRow(counter);
        ui->tableWidget->setItem(counter, 0,
                                 new QTableWidgetItem(tariffList[i]->getDateTariff()));
        ui->tableWidget->setItem(counter, 1,
                                 new QTableWidgetItem(QString::number(tariffList[i]->getHouseTarifNumber())));
        ui->tableWidget->setItem(counter, 2,
                                 new QTableWidgetItem(QString::number(tariffList[i]->getTarifSum())));
        counter++;
    }
}
