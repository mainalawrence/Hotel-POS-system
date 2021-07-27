#include "timerdialog.h"
#include "ui_timerdialog.h"

Timerdialog::Timerdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timerdialog)
{
    ui->setupUi(this);
    ui->btnpausetimer->setEnabled(false);
    ui->btnstarttimer->setEnabled(false);
    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("Hotelpost");
    timer=new QTimer(nullptr);
   // connect(timer,SIGNAL(timeout()),this,SLOT(currenttime()));
    timer->start(1000);



}

Timerdialog::~Timerdialog()
{
    delete ui;
}

void Timerdialog::on_buttonBox_accepted()
{
    if(!db.open()){
        //error handler;
        QMessageBox::information(this,"not opened",db.lastError().text());
        //qDebug()<<"not open"<<
    }
    else{
            QString usernameEntered=ui->lineEdit_username->text();//.toLower();
            QString passwordEntered=ui->lineEdit_password->text();//.toLower();
            QSqlQuery querylogin;
            querylogin.prepare("SELECT * FROM login WHERE username=:user and password=:pass");
            querylogin.bindValue(":user",usernameEntered);
            querylogin.bindValue(":pass",passwordEntered);
    if(! querylogin.exec()){
        //erro
        QMessageBox::information(this,"failed","failed to log in wrong password");
    }
    else{
        while (querylogin.next()) {
            QString usernamefromdb=querylogin.value(5).toString();
            QString passwordfromdb=querylogin.value(6).toString();
            QString role=querylogin.value(8).toString();
            QString nameofthelogger=querylogin.value(2).toString();
               userid=querylogin.value(0).toString();
            if((usernameEntered ==usernamefromdb) &&(passwordEntered==passwordfromdb)){

                if(role=="Admin" || role=="Manager"||role=="Director"||role=="Supervisor"){
                // QMessageBox::information(this,"success","welcome "+nameofthelogger);
                    ui->btnpausetimer->setEnabled(true);
                    ui->btnstarttimer->setEnabled(true);
                    qDebug()<<"welcome"<<nameofthelogger.toUpper();

                }
                else{

                       ui->lbldisplayerro->setText("wrong username or password");

                     }
            }
            else{
                ui->lineEdit_username->clear();
                ui->lineEdit_password->clear();
             //   QMessageBox::information(this,"failed","failed to log in wrong password");
                ui->lbldisplayerro->setText("wrong username or password");

            }

        }
    }


}

}

void Timerdialog::currenttime()
{
 QTime time=QTime::currentTime();
 QString time_text=time.toString("hh:mm:ss");

}

bool Timerdialog::starttime()
{

    QString starttime=QTime::currentTime().toString();
    QString qstart="insert into usertime(id,startt) values(:id,:start_time)";
    QSqlQuery Tquery;
    Tquery.prepare(qstart);
    Tquery.bindValue(":id",userid);
    Tquery.bindValue(":start_time",starttime);
    if(!Tquery.exec()){
        //error
    }
    else{
        return true;
    }
    return true;
}

bool Timerdialog::endtime()
{
 QString endtime=QTime::currentTime().toString();
 QString qstart="update usertime set endt=':end_time' where id=':id'";
 QSqlQuery Tquery;
 Tquery.prepare(qstart);
 Tquery.bindValue(":id",userid);
 Tquery.bindValue(":end_time",endtime);
 if(!Tquery.exec()){
     //error
     QMessageBox::information(this,"timer has failed","the promblem is"+Tquery.lastError().text());
 }
 else{
     return true;
 }
 return true;
}

void Timerdialog::totaltime()
{

}

void Timerdialog::on_btnstarttimer_clicked()
{
 ui->lbldisplayerro->setText("welcome sana "+nameofthelogger.toUpper());
}

void Timerdialog::on_btnpausetimer_clicked()
{

}

void Timerdialog::on_pushButton_2_clicked()
{
    if(!db.open()){
        //error handler;
        QMessageBox::information(this,"not opened",db.lastError().text());
        //qDebug()<<"not open"<<
    }
    else{
            QString usernameEntered=ui->lineEdit_username->text();//.toLower();
            QString passwordEntered=ui->lineEdit_password->text();//.toLower();
            QSqlQuery querylogin;
            querylogin.prepare("SELECT * FROM login WHERE username=:user and password=:pass");
            querylogin.bindValue(":user",usernameEntered);
            querylogin.bindValue(":pass",passwordEntered);
    if(! querylogin.exec()){
        //erro
        QMessageBox::information(this,"failed","failed to log in wrong password");
    }
    else{
        while (querylogin.next()) {
            QString usernamefromdb=querylogin.value(5).toString();
            QString passwordfromdb=querylogin.value(6).toString();
            QString role=querylogin.value(8).toString();
            nameofthelogger=querylogin.value(2).toString();
               userid=querylogin.value(0).toString();
            if((usernameEntered ==usernamefromdb) &&(passwordEntered==passwordfromdb)){

                if(role=="Admin" || role=="Manager"||role=="Director"||role=="Supervisor"){
                // QMessageBox::information(this,"success","welcome "+nameofthelogger);
                    ui->btnpausetimer->setEnabled(true);
                    ui->btnstarttimer->setEnabled(true);
                    qDebug()<<"welcome"<<nameofthelogger.toUpper();
                    ui->lbldisplayerro->setText("");

                }
                else{


                    ui->lbldisplayerro->setText("wrong username or password");
                    ui->lineEdit_password->clear();
                    ui->lineEdit_username->clear();
                     }
            }
            else{
                ui->lineEdit_username->clear();
                ui->lineEdit_password->clear();
             // QMessageBox::information(this,"failed","failed to log in wrong password");
            }

        }
    }


}
}
