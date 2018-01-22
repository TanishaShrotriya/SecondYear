#include "circle1.h"
#include "ui_circle1.h"
#include<QtGui>
#include<math.h>

circle1::circle1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::circle1)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(draw()));
    connect(this->ui->pushButton_2,SIGNAL(clicked()),this,SLOT(clear()));
}

circle1::~circle1()
{
    delete ui;
}
void circle1::draw(){
    QImage *q;
    q=new QImage(640,480,QImage::Format_ARGB32 );
    QRgb value=qRgb(255,255,255);

 x=this->ui->lineEdit->text().toInt();
 y=this->ui->lineEdit_2->text().toInt();
 r=this->ui->lineEdit_3->text().toInt();
int  xi=0;
 int yi=r;
 int d=2*(1-r);
 int limit=0;
 int d1,d2;
 while(yi>=limit){
  //q->setPixel(x,y,value);
  if(d<0){
      d1=(2*d)+(2*yi)-1;
      if(d1<=0)
      {
          xi=xi+1;
          d=d+(2*xi)+1;
      }
      else
         {
          xi=xi+1;
          yi=yi-1;
          d=d+(2*xi)-(2*yi)+2;
      }
  }
  else if(d>0){
      d2=(2*d)-(2*xi)-1;
      if(d2<=0)
         {
          xi=xi+1;
          yi=yi-1;
          d=d+(2*xi)-(2*yi)+2;
      }
      else
      {
          yi=yi-1;
          d=d-(2*yi)+1;
      }
  }
  else if(d==0){
      xi=xi+1;
      yi=yi-1;
      d=d+(2*xi)-(2*yi)+2;
  }

  q->setPixel(x+xi,y+yi,value);
  q->setPixel(y+yi,x+xi,value);
  q->setPixel(y+yi,x-xi,value);
  q->setPixel(x+xi,y-yi,value);
  q->setPixel(x-xi,y-yi,value);
  q->setPixel(y-yi,x-xi,value);
  q->setPixel(x-xi,y+yi,value);
  q->setPixel(y-yi,x+xi,value);
 }

 ui->label_4->setPixmap(QBitmap::fromImage(*q));

}
void circle1::mh(int, int, int){
    xi=xi+1;
    d=d+(2*xi)+1;
}
void circle1::md(int, int, int){
    xi=xi+1;
    yi=yi-1;
    d=d+(2*xi)-(2*yi)+2;
}
void circle1::mv(int, int, int){
    yi=yi-1;
    d=d-(2*yi)+1;
}
void circle1::clear()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");

    ui->label_4->clear();

}
