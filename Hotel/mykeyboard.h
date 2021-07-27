#ifndef MYKEYBOARD_H
#define MYKEYBOARD_H

#include <QObject>
#include<QtVirtualKeyboard/QtVirtualKeyboard>

class mykeyboard : public QObject
{
    Q_OBJECT
public:
    explicit mykeyboard(QObject *parent = nullptr);

signals:

};

#endif // MYKEYBOARD_H
