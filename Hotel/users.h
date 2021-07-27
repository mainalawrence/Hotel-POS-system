#ifndef USERS_H
#define USERS_H

#include <QObject>
#include<QDate>
#include<QStringList>
#include<QString>

class Users : public QObject
{
    Q_OBJECT



public:
    explicit Users(QObject *parent = nullptr);

    QString getU_fname() const;
    void setU_fname(const QString &value);

    QString getU_lname() const;
    void setU_lname(const QString &value);

    QDate getU_dateofbirth() const;
    void setU_dateofbirth(const QDate &value);

    QStringList getU_phonenumber() const;
    void setU_phonenumber(const QStringList &value);

    QStringList getU_address() const;
    void setU_address(const QStringList &value);

    QString getU_role() const;
    void setU_role(const QString &value);

    QStringList getU_email() const;
    void setU_email(const QStringList &value);

    QStringList getU_password() const;
    void setU_password(const QStringList &value);

    QString getU_username() const;
    void setU_username(const QString &value);

signals:

public slots:


private:
    QString u_fname;
    QString u_lname;
    QDate u_dateofbirth ;
    QStringList u_phonenumber;
    QStringList u_address;
    QString u_role;
    QStringList u_email;
    QStringList u_password;
    QString u_username;

};

#endif // USERS_H
