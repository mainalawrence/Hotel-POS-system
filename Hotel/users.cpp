#include "users.h"

Users::Users(QObject *parent) : QObject(parent)
{

}

QString Users::getU_fname() const
{
    return u_fname;
}

void Users::setU_fname(const QString &value)
{   if( u_fname != value){
    u_fname = value;
   // emit getU_fnameChanged();
    }
}

QString Users::getU_lname() const
{
    return u_lname;
}

void Users::setU_lname(const QString &value)
{
    if( u_lname != value){
    u_lname = value;
//    emit getU_lnameChanged();
    }
}

QDate Users::getU_dateofbirth() const
{
    return u_dateofbirth;
}

void Users::setU_dateofbirth(const QDate &value)
{
    if(u_dateofbirth != value)
    {
    u_dateofbirth = value;
   // emit getU_dateofbirthChanged();
    }
}

QStringList Users::getU_phonenumber() const
{
    return u_phonenumber;
}

void Users::setU_phonenumber(const QStringList &value)
{
    if(u_phonenumber!=value)
    {
    u_phonenumber = value;
    //emit getU_phonenumberChanged();
    }
}

QStringList Users::getU_address() const
{
    return u_address;
}

void Users::setU_address(const QStringList &value)
{
    if(u_address != value){
    u_address = value;
   // emit getU_addressChanged();
    }
}

QString Users::getU_role() const
{
    return u_role;
}

void Users::setU_role(const QString &value)
{
    if( u_role != value){
    u_role = value;
   // emit getU_roleChanged();
    }
}

QStringList Users::getU_email() const
{
    return u_email;
}

void Users::setU_email(const QStringList &value)
{
    if(u_email != value){
    u_email = value;
   // emit getU_emailChanged();
    }
}

QStringList Users::getU_password() const
{
    return u_password;
}

void Users::setU_password(const QStringList &value)
{
    if(u_password != value){
    u_password = value;
    //emit getU_passwordChanged();
    }
}

QString Users::getU_username() const
{
    return u_username;
}

void Users::setU_username(const QString &value)
{
    if( u_username != value)
    {
    u_username = value;
    //emit getU_usernameChanged();
    }
}
