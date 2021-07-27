#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include<QTimer>
#include "waiter.h"
#include "report.h"
#include "employee.h"
#include "settings.h"
#include<QSqlDatabase>
#include<QSqlQuery>


namespace Ui {
class Manager;
}

class Manager:public QMainWindow
{
    Q_OBJECT

public:
    explicit Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
   void on_btnEmployee_clicked();

   void on_btnReports_clicked();

   void on_btnSales_clicked();

   void on_btnDepartments_clicked();

   void on_btnSetting_clicked();

   void on_btnlogout_clicked();
   void currenttime();

private:
    Ui::Manager *ui;
    QTimer *timer;
    Waiter *waiter;
    Employee* employee;
    Settings *setting;
    QSqlDatabase db;
    Report *report;
   // QSqlQuery querylogin;



};

#endif // MANAGER_H
