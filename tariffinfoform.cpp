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
    OnReadFromFile();
}

TariffInfoForm::~TariffInfoForm()
{
    delete mAddTariffDialog;
    delete ui;
}

QString TariffInfoForm::GetDateTariff()
{
    return tariffDate;
}

int TariffInfoForm::GetHouseTarifNumber()
{
    return tariffHouseNumber;
}

unsigned int TariffInfoForm::GetTarifSum()
{
    return tariffSum;
}

void TariffInfoForm::SetData()
{
    tariffDate=mAddTariffDialog->GetDateTariff();
    tariffHouseNumber=mAddTariffDialog->GetHouseTarifNumber();
    tariffSum=mAddTariffDialog->GetTarifSum();
}

void TariffInfoForm::on_btnAdd_clicked()
{
    tableRows=ui->tableWidget->rowCount();
    if(mAddTariffDialog->exec()==QDialog::Accepted)
    {
        SetData();
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

void TariffInfoForm::OnSaveToFile()
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
    OnSaveToFile();
    event->accept();
}

void TariffInfoForm::OnReadFromFile()
{
    QVector<TariffInfoForm *> tariffList = HouseManagementSystem::getInstance()->getTariffList();
    int counter=0;
    for(int i=0;i<tariffList.size();i++)
    {
        ui->tableWidget->insertRow(counter);
        ui->tableWidget->setItem(counter, 0,
                                 new QTableWidgetItem(tariffList[i]->GetDateTariff()));
        ui->tableWidget->setItem(counter, 1,
                                 new QTableWidgetItem(QString::number(tariffList[i]->GetHouseTarifNumber())));
        ui->tableWidget->setItem(counter, 2,
                                 new QTableWidgetItem(QString::number(tariffList[i]->GetTarifSum())));
        counter++;
    }
}
