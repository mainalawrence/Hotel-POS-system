#ifndef REPORT_H
#define REPORT_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QAbstractTableModel>
#include<QSqlTableModel>
#include "database.h"

namespace Ui {
class Report;
}

class Report : public QMainWindow
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = nullptr);
    ~Report();
    void returndsales();
    void Topsales();
    void lessthan30days();
    void exporttoexcell();
    void selectwithdate();



private slots:
    void on_btnlastthetydays_clicked();
    
    void on_btnlast30days_clicked(bool checked);

private:
    Ui::Report *ui;
    QSqlDatabase dbnew;
    QSqlQueryModel *queryreport;
    QAbstractTableModel *model;
    bool amonthbtisclicked;
};

#endif // REPORT_H
