#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
{
    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("Hotelpost");
   void opendb();
}

//void  Database::logincheker(QString usernameEntered,QString passwordEntered)
//{
//}

void Database::addusers()
{

}

void Database::opendb()
{

    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("Hotelpost");

    if(!db.open()){
        //QMessageBox::information(this,"")
        qDebug()<<"not open";
    }
}
