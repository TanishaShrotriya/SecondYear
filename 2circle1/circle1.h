#ifndef CIRCLE1_H
#define CIRCLE1_H

#include <QMainWindow>
#include<QImage>
#include<QPixmap>

namespace Ui {
class circle1;
}

class circle1 : public QMainWindow
{
    Q_OBJECT
    int x,y,r,xi,yi,d,d1,d2,limit;

public:
    explicit circle1(QWidget *parent = 0);
    ~circle1();

private:
    Ui::circle1 *ui;
private slots:
    void draw();
    void clear();
    void mh(int, int, int);
    void md(int,int,int);
    void mv(int,int,int);
};

#endif // CIRCLE1_H
