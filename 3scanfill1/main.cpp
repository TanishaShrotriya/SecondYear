#include "scanfill1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    scanfill1 w;
    w.resize(500,500);
    w.setWindowTitle("scanfill");
    w.show();

    return a.exec();
}
