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
    connect(this->ui->p4,SIGNAL(clicked()),this,SLOT(newdotted()));
    connect(this->ui->p5,SIGNAL(clicked()),this,SLOT(dashed()));
    connect(this->ui->p6,SIGNAL(clicked()),this,SLOT(dash_dot()));
}

lines::~lines()
{
    delete ui;
}

void lines::input() {

    float x1,x2,y1,y2;

    x1= this->ui->te1->toPlainText().toFloat();
    y1= this->ui->te2->toPlainText().toFloat();
    x2= this->ui->te3->toPlainText().toFloat();
    y2= this->ui->te4->toPlainText().toFloat();
    thin(x1,y1,x2,y2);

}

void lines::thin(float x1,float y1,float x2, float y2) {

    int steps=0,xInc,yInc,x,y,i=0;
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

    while(i<=steps) {


        q->setPixel(round(x),round(y),value);
        x=x+xInc;
        y=y+yInc;
        i++;
    }
     ui->l1->setPixmap(QBitmap::fromImage(*q));
}

void lines::newdotted()
{
    float x1,x2,y1,y2;

    x1= this->ui->te1->toPlainText().toFloat();
    y1= this->ui->te2->toPlainText().toFloat();
    x2= this->ui->te3->toPlainText().toFloat();
    y2= this->ui->te4->toPlainText().toFloat();

    int steps=0,xInc,yInc,x,y,i=0;
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

    while(i<=steps) {

        ui->l1->setPixmap(QBitmap::fromImage(*q));
        if(i%5==0)
        {
        q->setPixel(round(x),round(y),value);
        }
        x=x+xInc;
        y=y+yInc;
        i++;
    }

}

void lines :: thick () {
    float x1,x2,y1,y2;
 int steps,i,x,y,wy,w,m;
  int xinc,yinc;


  x1= this->ui->te1->toPlainText().toFloat();
  y1= this->ui->te2->toPlainText().toFloat();
  x2= this->ui->te3->toPlainText().toFloat();
  y2= this->ui->te4->toPlainText().toFloat();
   w= this->ui->te5->toPlainText().toFloat();

  QImage *q;
  q=new QImage(640,480,QImage::Format_ARGB32 );
  QRgb value=qRgb(255,255,255);



  if(abs(x2-x1)>=(y2-y1))
      steps=abs(x2-x1);
  else
      steps=abs(y2-y1);

  xinc=float(x2-x1)/steps;
  yinc=float(y2-y1)/steps;

  x=x1;
  y=y1;


  m=(y2-y1)/(x2-x1);

if(m<1)
{

  wy=((w-1)/2)*sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))/abs(x2-x1);
  for(i=0;i<steps;i++)
  {
    for(int j=0;j<wy;j++)
    {
        q->setPixel(x,y,value);
        q->setPixel(x,y+j,value);
        q->setPixel(x,y-j,value);
    }
    x=x+xinc;
    y=y+yinc;

    ui->label_6->setPixmap(QBitmap::fromImage(*q));

  }
}
  else
  {

      wy=((w-1)/2)*sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))/abs(y2-y1);

    for(i=0;i<steps;i++)
    {
        for(int j=0;j<wy;j++)
        {
            q->setPixel(x,y,value);
            q->setPixel(x+j,y,value);
            q->setPixel(x-j,y,value);
        }
        x=x+xinc;
        y=y+yinc;

        ui->label_6->setPixmap(QBitmap::fromImage(*q));

    }
  }

}

void lines::dashed() {
    float x1,x2,y1,y2;

    x1= this->ui->te1->toPlainText().toFloat();
    y1= this->ui->te2->toPlainText().toFloat();
    x2= this->ui->te3->toPlainText().toFloat();
    y2= this->ui->te4->toPlainText().toFloat();

    int steps=0,xInc,yInc,x,y,i=0;
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

    while(i<=steps) {

        ui->l1->setPixmap(QBitmap::fromImage(*q));

        if(i%10>4)
        {
          q->setPixel(round(x),round(y),value);
        }
        x=x+xInc;
        y=y+yInc;
        i++;
    }


}

void lines::dash_dot() {
    float x1,x2,y1,y2;

    x1= this->ui->te1->toPlainText().toFloat();
    y1= this->ui->te2->toPlainText().toFloat();
    x2= this->ui->te3->toPlainText().toFloat();
    y2= this->ui->te4->toPlainText().toFloat();

    int steps=0,xInc,yInc,x,y,i=0;
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

    while(i<=steps) {

        ui->l1->setPixmap(QBitmap::fromImage(*q));
        if(i%10==2) {
            q->setPixel(round(x),round(y),value);
        }
        if(i%10>4)
        {
          q->setPixel(round(x),round(y),value);
        }
        x=x+xInc;
        y=y+yInc;
        i++;
    }

}
