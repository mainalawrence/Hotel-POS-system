#include "manager.h"
#include "ui_manager.h"


Manager::Manager(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Manager)
{
    ui->setupUi(this);
    //ui->lblloggedinuser->setText(role);

    timer=new QTimer(nullptr);
    connect(timer,SIGNAL(timeout()),this,SLOT(currenttime()));
    timer->start(1000);

}

Manager::~Manager()
{
    delete ui;
}


void Manager::on_btnEmployee_clicked()
{
    employee=new Employee(this);
    employee->show();

}

void Manager::on_btnReports_clicked()
{
    report=new Report(nullptr);
    report->show();
}

void Manager::on_btnSales_clicked()
{
    waiter=new Waiter(nullptr);
    waiter->show();
}

void Manager::on_btnDepartments_clicked()
{


}

void Manager::on_btnSetting_clicked()
{
    //logout of the page go to the main page
    setting=new Settings(nullptr);
    setting->show();
}

void Manager::on_btnlogout_clicked()
{
QApplication::quit();

}

void Manager::currenttime()
{
     QTime time=QTime::currentTime();
     QString time_text=time.toString("hh:mm:ss");
    ui->lbldateandtime->setText(time_text);
}
