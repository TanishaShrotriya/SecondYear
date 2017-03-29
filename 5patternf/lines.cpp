#include "lines.h"
#include "ui_lines.h"
#include "math.h"
#include "QtGui"

lines::lines(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lines)
{
    ui->setupUi(this);
    connect(this->ui->p1,SIGNAL(clicked()),this,SLOT(pattern_()));
    connect(this->ui->p3,SIGNAL(clicked()),this,SLOT(pattern()));
    connect(this->ui->p2,SIGNAL(clicked()),this,SLOT(clear()));
}

lines::~lines()
{
    delete ui;
}

void lines::display(int x1,int y1, int x2 , int y2, QImage *q, QRgb value) {

    float steps=0,xInc,yInc,x,y,i=0;

    //q->fill(QColor(Qt::black).value());

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

void lines::pattern_() {

    int x1,y1,x2,y2;

    QImage *q;
    q=new QImage(640,480,QImage::Format_ARGB32);
    QRgb value = qRgb(255,255,255);


    display(100,200,150,200,q,value);
    display(150,200,150,250,q,value);
    display(150,250,100,250,q,value);
    display(100,250,100,200,q,value);

    display(125,200,150,225,q,value);
    display(150,225,125,250,q,value);
    display(125,250,100,225,q,value);
    display(100,225,125,200,q,value);

    x1=x2=(125+150)/2;
    y1=(200+225)/2;
    y2=(225+250)/2;

    display(x1,y1,x2,y2,q,value);

    x1=(150+125)/2;
    y1=y2=(250+225)/2;
    x2=(100+125)/2;


    display(x1,y1,x2,y2,q,value);

    x1=x2=(100+125)/2;
    y1=(250+225)/2;
    y2=(225+200)/2;

    display(x1,y1,x2,y2,q,value);

    x1=(100+125)/2;
    y1=y2=(225+200)/2;
    x2=(150+125)/2;


    display(x1,y1,x2,y2,q,value);

}

void lines::pattern() {

    int temp;

    QImage *q;
    q=new QImage(640,480,QImage::Format_ARGB32);
    QRgb value = qRgb(255,255,255);


    int x1= this->ui->te1->toPlainText().toFloat();
    int y1= this->ui->te2->toPlainText().toFloat();
    int x2= this->ui->te3->toPlainText().toFloat();
    int y2= this->ui->te4->toPlainText().toFloat();

    display(x1,y1,x2,y1,q,value);
    display(x2,y1,x2,y2,q,value);
    display(x2,y2,x1,y2,q,value);
    display(x1,y2,x1,y1,q,value);


    display((x1+x2)/2,y1,x2,(y1+y2)/2,q,value);
    display(x2,(y1+y2)/2,(x2+x1)/2,y2,q,value);
    display((x2+x1)/2,y2,x1,(y2+y1)/2,q,value);
    display(x1,(y2+y1)/2,(x2+x1)/2,y1,q,value);

    temp = x1;
    x1=(x2+x1)/2;
    x2=(temp+x2)/2;
    temp = y1;
    y1=(y2+y1)/2;
    y2=(temp+y2)/2;

    display(x1,y1,x2,y1,q,value);
    display(x2,y1,x2,y2,q,value);
    display(x2,y2,x1,y2,q,value);
    display(x1,y2,x1,y1,q,value);

}


void lines::clear()
{
    ui->te1->setText("");
    ui->te2->setText("");
    ui->te3->setText("");
    ui->te4->setText("");
    ui->l1->clear();

}
