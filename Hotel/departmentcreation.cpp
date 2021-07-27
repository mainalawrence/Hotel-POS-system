#include "departmentcreation.h"

Departmentcreation::Departmentcreation(QObject *parent) : QObject(parent)
{

}

QString Departmentcreation::getD_name() const
{
    return d_name;
}

void Departmentcreation::setD_name(const QString &value)
{
    d_name = value;
}
