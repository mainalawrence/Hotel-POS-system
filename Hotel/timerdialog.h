#ifndef TIMERDIALOG_H
#define TIMERDIALOG_H

#include <QDialog>
#include<QMessageBox>
#include<QTime>
#include "login.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QTimer>

namespace Ui {
class Timerdialog;
}

class Timerdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Timerdialog(QWidget *parent = nullptr);
    ~Timerdialog();

private slots:
    void on_buttonBox_accepted();
    void currenttime();
    bool starttime();
    bool endtime();
    void totaltime();


    void on_btnstarttimer_clicked();

    void on_btnpausetimer_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Timerdialog *ui;
    QSqlDatabase db;
    QSqlQuery querylogin;
    QString userid;
    QTimer *timer;
    QString nameofthelogger;

};

#endif // TIMERDIALOG_H
