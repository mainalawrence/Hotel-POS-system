#include "report.h"
#include "ui_report.h"

Report::Report(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
    dbnew=QSqlDatabase::addDatabase("QODBC");
    dbnew.setHostName("localhost");
    dbnew.setDatabaseName("Hotelpost");



    if(!dbnew.open()){
       QMessageBox::warning(this,"CANT OPEN THE DATABASE",dbnew.lastError().text());
    }
    else {
        //for the sales

         QString qsales=("select *from sales");
         QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery(qsales);
         ui->tblSaleR->setModel(model);

          // for the returns
         QString qreturned=("select * from returnedsales");
         QSqlQueryModel *modelreturned = new QSqlQueryModel;

         modelreturned->setQuery(qreturned);
         ui->tblReturnR->setModel(modelreturned);
           // for high sales

           //

    }


}

Report::~Report()
{
    dbnew.close();
    delete ui;
}

void Report::returndsales()
{
 QString qsales=("select *from sales");


}

void Report::Topsales()
{
    

}

void Report::lessthan30days()
{

}

void Report::exporttoexcell()
{

}

void Report::selectwithdate()
{

}



void Report::on_btnlastthetydays_clicked()
{
    
}

void Report::on_btnlast30days_clicked(bool checked)
{
    if(checked){
        ui->tblSaleR->setModel(model);
    }
}
