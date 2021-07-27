#ifndef DEPARTMENTCREATION_H
#define DEPARTMENTCREATION_H

#include <QObject>
#include<QString>

class Departmentcreation : public QObject
{
    Q_OBJECT
   // Q_PROPERTY(QString d_name READ d_name WRITE setD_name NOTIFY d_nameChanged)
public:
    explicit Departmentcreation(QObject *parent = nullptr);

    QString getD_name() const;
    void setD_name(const QString &value);

signals:

public slots:
private:
    QString d_name;
    QString abour;
};

#endif // DEPARTMENTCREATION_H
