#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "cashier.h"
#include "database.h"
#include"manager.h"
#include<QKeyEvent>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login:public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
 QString role;
private slots:


    void on_pushButton_3_clicked();

    void on_btnLogin_clicked();

    void on_btnTimer_clicked();

    void on_btnQuit_clicked();

    void  checker();

    void on_pushButton_clicked();

    void on_btnTimerStrat_clicked();

    void buttonclicked();


private:
    Ui::Login *ui;
    Cashier *first;
    Manager *manager;
    QSqlDatabase db;
    QSqlQuery querylogin;


};
#endif // LOGIN_H
