#ifndef DATABASE_H
#define DATABASE_H
//#define drivers "QODBC"

#include <QObject>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>


class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

signals:
    void dbconnect();

public slots:
    //users
  // void logincheker(QString,QString);
    void addusers();
    //void updateusers();
    //time
   // void recordtimeofuser();
    //void viewthetime();
    //sales
  void opendb();
    //returns

private:
    QSqlDatabase db;
    QSqlQuery querylogin;

};

#endif // DATABASE_H
