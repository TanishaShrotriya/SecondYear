#include <QtGui/QApplication>
#include "widget.h"

int main(int argc, char *argv[])

{
    QApplication a(argc, argv);
    Widget w;
    w.resize(500,500);
    w.setWindowTitle("2-D Trasformation");
    w.show();
    return a.exec();
}

