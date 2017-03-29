#ifndef LINESTYLES_H
#define LINESTYLES_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>



namespace Ui {
class linestyles;
}

class linestyles : public QMainWindow
{
    Q_OBJECT

public:
    explicit linestyles(QWidget *parent = 0);
    ~linestyles();

private:
    Ui::linestyles *ui;
    int x1,y1,x2,y2,dx,dy;
    float x_1,y_1;
private slots:
    void display1();
    void display2();
   void dashed();
   void dashdot();
  void thick();
  //void displaythick(int,int,int,int);
    void display(int,int);
    void dotted(int,int);
    void clear();
    int sign(int);

};

#endif // LINESTYLES_H
