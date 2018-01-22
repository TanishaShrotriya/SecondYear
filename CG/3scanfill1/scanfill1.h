#ifndef SCANFILL1_H
#define SCANFILL1_H
#include <QWidget>
#include <iostream>
namespace Ui {
class scanfill1;
}

class scanfill1 : public QWidget
{
    Q_OBJECT
     int x1,x2,y1,y2,flag;
public:
    explicit scanfill1(QWidget *parent = 0);
    ~scanfill1();

private:
    Ui::scanfill1 *ui;
protected: //as we have added base class QWidget
    void paintEvent(QPaintEvent *event);
    void myFunc(QPainter *ap);
};

#endif // SCANFILL1_H
