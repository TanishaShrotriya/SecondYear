#include "circle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    circle w;
    w.show();

    return a.exec();
}
