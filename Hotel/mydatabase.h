#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>

class mydatabase : public QObject
{
    Q_OBJECT
public:
    explicit mydatabase(QObject *parent = nullptr);

signals:

public slots:
    void update();
    void addto();

private:

};

#endif // MYDATABASE_H
