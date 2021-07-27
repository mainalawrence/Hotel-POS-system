#include "login.h"
#include "ui_login.h"
#include "cashier.h"
#include"database.h"
#include "timerdialog.h"
#include<QMessageBox>
#include<QtDebug>
#include"buttons.h"
#include<QPixmap>
#include<QPushButton>

Login::Login(QWidget *parent): QMainWindow(parent) , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->frame_buttons->hide();
    ui->frametimer->hide();
    QPixmap pixmap(":/images/hotel.jpeng");
    ui->lblforpic->setPixmap(pixmap.scaled(400,500,Qt::KeepAspectRatio));
    //lables enabled
    ui->lndusername->setEnabled(true);
    ui->lndpass->setEnabled(true);
    ui->lblforpic->setFocus();
    //database
    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");
    db.setDatabaseName("Hotelpost");
    if(!db.open()){
        //QMessageBox::information(this,"")
        qDebug()<<"not open";

}
    //the key buttons
    connect(ui->pushButton_0,&QPushButton::clicked,this,&Login::buttonclicked);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&Login::buttonclicked);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Login::buttonclicked);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&Login::buttonclicked);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&Login::buttonclicked);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&Login::buttonclicked);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&Login::buttonclicked);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&Login::buttonclicked);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&Login::buttonclicked);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&Login::buttonclicked);


}

Login::~Login()
{
    db.close();
    delete ui;
}




void Login::on_pushButton_3_clicked()
{


    Qt::Key key=Qt::Key_1;
    QKeyEvent pressEvent=QKeyEvent(QEvent::KeyPress, key ,Qt::NoModifier,QKeySequence(key).toString());
    QKeyEvent releaseEvent =QKeyEvent(QEvent::KeyRelease, key, Qt::NoModifier);
    QCoreApplication::sendEvent(QGuiApplication::focusObject(),&pressEvent);
    QCoreApplication::sendEvent(QGuiApplication::focusObject(),&releaseEvent);

}

void Login::on_btnLogin_clicked()
{

   qDebug()<<"am clicked";
   if(!db.open()){
       //error handler;
       QMessageBox::information(nullptr,"not opened",db.lastError().text());
       //qDebug()<<"not open"<<
   }
   else{
           QString usernameEntered=ui->lndusername->text();//.toLower();
           QString passwordEntered=ui->lndpass->text();//.toLower();
           QSqlQuery querylogin;
           querylogin.prepare("SELECT * FROM login WHERE username=:user and password=:pass");
           querylogin.bindValue(":user",usernameEntered);
           querylogin.bindValue(":pass",passwordEntered);
   if(! querylogin.exec()){
       //erro
       QMessageBox::information(nullptr,"failed","failed to log in wrong password");
   }
   else{
       while (querylogin.next()) {
           QString usernamefromdb=querylogin.value(5).toString();
           QString passwordfromdb=querylogin.value(6).toString();
            role=querylogin.value(8).toString();
           if((usernameEntered ==usernamefromdb) &&(passwordEntered==passwordfromdb)){

               if(role=="admin" || role=="Manager"||role=="director"||role=="supervisor"){
                   manager =new Manager();
                   manager->showMaximized();
                   //db.removeDatabase(QSqlDatabase::defaultConnection);

                    this->close();
               }
               else{
                  ui->lndusername->clear();
                  ui->lndpass->clear();
                  //lable to show that the password is not correct
                    }
           }
           else{
              ui->lndusername->clear();
               ui->lndpass->clear();
              //lable to show that the password is not correct
           }

       }
   }

   }

}



void Login::on_btnTimer_clicked(){
//Timerdialog tdialog;
//tdialog.setModal(true);
//tdialog.exec();
//    Timerdialog *T_dialog=new Timerdialog(this);
//    T_dialog->show();

    ui->frametimer->show();
    ui->frame_buttons->show();
    ui->loginform->hide();
}

void Login::on_btnQuit_clicked(){
    QApplication::quit();

    Qt::Key key=Qt::Key_1;
    QKeyEvent pressEvent=QKeyEvent(QEvent::KeyPress, key ,Qt::NoModifier,QKeySequence(key).toString());
    QKeyEvent releaseEvent =QKeyEvent(QEvent::KeyRelease, key, Qt::NoModifier);
    QCoreApplication::sendEvent(QGuiApplication::focusObject(),&pressEvent);
    QCoreApplication::sendEvent(QGuiApplication::focusObject(),&releaseEvent);

}

void Login::checker()
{

}



void Login::on_pushButton_clicked()
{

ui->frame_buttons->show();
   // buttons *but=new buttons();
    //but->show();

}



void Login::on_btnTimerStrat_clicked()
{
    ui->frame_buttons->hide();
    ui->frametimer->hide();
    ui->loginform->show();
}

void Login::buttonclicked()
{



}





