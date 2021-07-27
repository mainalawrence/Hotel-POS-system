#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QMainWindow>
#include<QSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDate>
#include<QBitArray>
#include<QMessageBox>
#include<QSqlRecord>
#include<QSqlTableModel>
#include<QDebug>
#include<QString>
#include<QImage>
#include<QFileDialog>

namespace Ui {
class Employee;
}

class Employee : public QMainWindow
{
    Q_OBJECT

public:
    explicit Employee(QWidget *parent = nullptr);
    ~Employee();
   // void addemployee(QString name,QString email,QString sname, QString address,QDate DOB,QString username,QString password, QString role ,QPixmap image);
    void deletemployee();
    void updateemloyee();
    void getchecked();
    void checkedrdio();
    QSqlQueryModel *addemployeemodel;
    QSqlTableModel *employeemodel;



private slots:
    void on_btnbrowse_clicked();

    void on_pushButton_2_clicked();

    void on_btnaddnew_clicked();

    void on_btnupdateemployee_clicked();

    void on_btnbrowseforimage_clicked();

private:
    Ui::Employee *ui;

    QSqlDatabase dbemployee;
    QString checkedradib;
    QByteArray thereal;


};

#endif // EMPLOYEE_H
