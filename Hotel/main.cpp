#include "login.h"


#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.showMaximized();
    return a.exec();
}
