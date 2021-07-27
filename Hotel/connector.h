#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include "login.h"
#include "database.h"

class connector : public QObject
{
    Q_OBJECT
public:
    explicit connector(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CONNECTOR_H
