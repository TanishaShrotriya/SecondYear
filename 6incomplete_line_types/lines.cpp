#include "lines.h"
#include "ui_lines.h"
#include "math.h"
#include "QtGui"

lines::lines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lines)
{
    ui->setupUi(this);
    connect(this->ui->p1,SIGNAL(clicked()),this,SLOT(input()));
    connect(this->ui->p3,SIGNAL(clicked()),this,SLOT(thick()));
    connect(this->ui->p4,SIGNAL(clicked()),this,SLOT(dotted()));
}

lines::~lines()
{
    delete ui;
}

void lines:: input() {

    x1= this->ui->te1->toPlainText().toFloat();
    y1= this->ui->te2->toPlainText().toFloat();
    x2= this->ui->te3->toPlainText().toFloat();
    y2= this->ui->te4->toPlainText().toFloat();
    display(x1,y1,x2,y2);
   // display(abs(x2-x1),abs(y2-y1),0);
}
void lines::display(int x1,int y1, int x2 , int y2) {

    float steps=0,xInc,yInc,x,y,i=0;
    QImage *q;
    q=new QImage(640,480,QImage::Format_ARGB32);
    QRgb value = qRgb(255,255,255);
    q->fill(QColor(Qt::black).value());

    if(abs(x2-x1)>=abs(y2-y1)) {
      steps= abs(x2-x1);
    }
    else {
      steps=abs(y2-y1);
    }
    xInc=(x2-x1)/steps;
    yInc=(y2-y1)/steps;
    x=x1;
    y=y1;

    for(i=0;i<steps;i++) {

        q->setPixel(round(x),round(y),value);
        ui->l1->setPixmap(QBitmap::fromImage(*q));
        x=x+xInc;
        y=y+yInc;

    }

}

void lines::display1(int x1 ,int y1,int x2,int y2) {

    float steps=0,xInc,yInc,x,y,i=0;

    QImage *q;
    q=new QImage(640,480,QImage::Format_ARGB32);
    QRgb value = qRgb(255,255,255);
  //  q->fill(QColor(Qt::black).value());

    if(abs(x2-x1)>=abs(y2-y1)) {
      steps= abs(x2-x1);
    }
    else {
      steps=abs(y2-y1);
    }
    xInc=(x2-x1)/steps;
    yInc=(y2-y1)/steps;
    x=x1;
    y=y1;


    for(i=0;i<steps;i++) {

        q->setPixel(round(x),round(y),value);

        x=x+xInc;
        y=y+yInc;

    }
    ui->l1->setPixmap(QBitmap::fromImage(*q));

}

void lines::thick () {
       int dx,dy,w,m,wy,wx,i=0;


       x1= this->ui->te1->toPlainText().toInt();
       y1= this->ui->te2->toPlainText().toInt();
       x2= this->ui->te3->toPlainText().toInt();
       y2= this->ui->te4->toPlainText().toInt();

       dx=x2-x1;
       dy=y2-y1;
       w= this->ui->te5->toPlainText().toInt();
       m=dy/dx;
       if(m<1) {
           wy=(((w-1)/2)*(sqrt((dx*dx)+(dy*dy))/abs(x2-x1)));
         for(i=0;i<wy;i++) {
           display1(x1,y1+i,x2,y2+i);
           display1(x1,y1-i,x2,y2-i);
         }
       }

       else {
           wx=(((w-1)/2)*(sqrt((dx*dx)+(dy*dy))/abs(y2-y1)));
       for(i=0;i<wx;i++) {
           display1(x1+i,y1,x2+i,y2);
           display1(x1-i,y1,x2-i,y2);
       }
       }

}
void lines::dotted() {

    int dx,dy,x,y,xinc,yinc,steps,i=0;
    QImage *q;
    q=new QImage(640,480,QImage::Format_ARGB32);
    QRgb value = qRgb(255,255,255);
    q->fill(QColor(Qt::black).value());


    x1= this->ui->te1->toPlainText().toInt();
    y1= this->ui->te2->toPlainText().toInt();
    x2= this->ui->te3->toPlainText().toInt();
    y2= this->ui->te4->toPlainText().toInt();

    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy)) {
        steps=dx;
    }
    else {
        steps=dy;
    }
    xinc=float(dx)/float(steps);
    yinc=float(dy)/float(steps);


    q->setPixel(round(x1),round(y1),value);
    ui->l1->setPixmap(QBitmap::fromImage(*q));
    x=x1,y=y1;
    for(i=0;i<steps;i++) {

            x=x+xinc;
            y=y+yinc;
        if(i%2==0) {
        q->setPixel(round(x),round(y),value);
        }
         ui->l1->setPixmap(QBitmap::fromImage(*q));
    }

}

int lines:: sign(int val) {
    if(val<0)
        return -1 ;
    else if(val==0)
      return 0 ;
    else
        return 1;
}
