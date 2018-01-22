#include "linestyles.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    linestyles w;
    w.show();

    return a.exec();
}
