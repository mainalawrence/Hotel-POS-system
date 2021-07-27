#include "employee.h"
#include "ui_employee.h"

Employee::Employee(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Employee)
{
    ui->setupUi(this);

    ui->tbaddnew->hide();
    dbemployee=QSqlDatabase::addDatabase("QODBC");
    dbemployee.setDatabaseName("Hotelpost");
    dbemployee.setHostName("localhost");
   // QPixmap
   // ui->lblimage->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));



}

Employee::~Employee()
{
    dbemployee.close();
    delete ui;
}

//void Employee::addemployee(QString name, QString email, QString sname,
//QString address, QDate DOB, QString username, QString password,
//                           QString role, QPixmap image)
//{

//    QSqlRecord recod=employeemodel->record();
//    recod.setValue("name",name);
//    recod.setValue("sname",sname);
//    recod.setValue("address",address);
//    recod.setValue("dob",DOB);
//    recod.setValue("username",username);
//    recod.setValue("password",password);
//    recod.setValue("email",email);
//    recod.setValue("role",role);
//    recod.setValue("image",image);
//    employeemodel->insertRecord(-1,recod);
//    ui->lineEdit_name->text();
//    ui->lineEdit_sname->text();
//    ui->lineEdit_password->text();
//    ui->lineEdit_address->text();
//    ui->dateEditDOB->date();
//    ui->lineEdit_username->text();
//    ui->lineEdit_email->text();

//    ui->lblimage->toolTip();
//}



void Employee::checkedrdio()
{
    if(ui->rdbAdmin->isChecked())
       checkedradib=ui->rdbAdmin->text();
    else if(ui->rdbWaiter->isChecked())
         checkedradib=ui->rdbWaiter->text();
    else if(ui->rdbCashier->isChecked())
         checkedradib=ui->rdbCashier->text();
    else if(ui->rdbManager->isChecked())
         checkedradib=ui->rdbManager->text();
    else if(ui->rdbDirector->isChecked())
         checkedradib=ui->rdbDirector->text();
    else if(ui->rdbSupervisor->isChecked())
         checkedradib=ui->rdbSupervisor->text();

}

void Employee::on_btnbrowse_clicked()
{
  // tree module to allow one toget to the images


}

void Employee::on_pushButton_2_clicked()
{
    //delete the employee
}

void Employee::on_btnaddnew_clicked()
{

    ui->lblpassword->clear();
    ui->lblusername->clear();
    ui->lbladdress->clear();
    ui->lblsname->clear();
    ui->lblimage->clear();
    ui->lblemail->clear();
    ui->lblname->clear();
    //add new employee
    checkedrdio();

    QString Name=ui->lblname->text();
    QString SName=ui->lblsname->text();
    QString Password=ui->lblpassword->text();
    QString Address=ui->lbladdress->text();
    QString DOB=ui->dateEditDOB->text();
    QString username=ui->lblusername->text();
    QString Email=ui->lblemail->text();
    QString Role=checkedradib;
    QVariant images=ui->lblimage->picture();
   // QImage thereall=images.Image;



     qDebug()<<"======================================================================================"<<endl;
     qDebug()<<thereall;
      qDebug()<<"======================================================================================"<<endl;

   //insert to the database
    if(!dbemployee.open())
    {
        qDebug()<<"failed to open the data base !!!!!!!!!!!!!!!!";
    }
    else{
     qDebug()<<"database connected !!!!!!!!!!!!!!!!";
     QSqlQuery queryemp;
//     QString prepare("insert into  login(name,sname,address,dob,username,password,email,role) values(:Name,:SName,:Address,:DOB,:username,:Password,:email,:Role)");
//     queryemp.prepare(prepare);
//     queryemp.bindValue(":Name",Name);
//     queryemp.bindValue(":SName",SName);
//     queryemp.bindValue(":Address",Address);
//     queryemp.bindValue(":DOB",DOB);
//     queryemp.bindValue(":username",username);
//     queryemp.bindValue(":Password",Password);
//     queryemp.bindValue(":email",Email);
//     queryemp.bindValue(":Role",Role);
//     queryemp.bindValue(":images",bitimage);


     if(queryemp.exec()){
            qDebug()<<"query succeful";
     }
     else{
         qDebug()<<"query failed";
     }
    }

}

void Employee::on_btnupdateemployee_clicked()
{
    //update the database containing the user


}

void Employee::on_btnbrowseforimage_clicked()
{
    // QRgb value;
     //value = qRgb(10, 10,10);
  QFileDialog dialog(this);
  dialog.setNameFilter("images(*.png *.xpm *.jpg)");
  dialog.setViewMode(QFileDialog::Detail);
  QString filename=QFileDialog::getOpenFileName(this,"open image","C:/Users/LAWRENCE/Pictures","Image file (*.png *.xpm *.jpg)");
  if(!filename.isEmpty()){

      QImage image(filename);
     ui->lblimage->setPixmap(QPixmap::fromImage(image.scaled(200,300,Qt::KeepAspectRatio)));
  }
}
