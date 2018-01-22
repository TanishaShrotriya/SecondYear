#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    //painting elements
    QBrush blackBrush(Qt::black);
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(4);

    int n=12;
    static int y=-120;
    static int k=90;
    int x=y;
    int j=k;
    y=y+n;
    k=k+n;
    int h=40,w=60;

    rectangle = scene->addRect(x,y,j,k,blackpen,blueBrush);
    scene->setSceneRect(x,y,j,k);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);

    rectangle2 = scene->addRect(x+50,y+40,j-90,k-50,blackpen,blackBrush);
    scene->setSceneRect(x+50,y+40,j-90,k-50);
    rectangle2->setFlag(QGraphicsItem::ItemIsMovable);

    ellipse = scene->addEllipse(x+k-20,y+(j)-40,h,w,blackpen,blackBrush);
    scene->setSceneRect(x+20,y+(j)-40,20,20);
    rectangle2->setFlag(QGraphicsItem::ItemIsMovable);

    ellipse1 = scene->addEllipse(x-20,y+(j)-40,h,w,blackpen,blackBrush);
    scene->setSceneRect(x+20,y+(j)-40,20,20);
    ellipse1->setFlag(QGraphicsItem::ItemIsMovable);


    ui->graphicsView->setAlignment(Qt::AlignTop|Qt::AlignLeft);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //painting elements
    QBrush blackBrush(Qt::black);
    QBrush blueBrush(Qt::blue);
    QPen blackpen(Qt::black);
    blackpen.setWidth(6);

    int n=10;
    static int y=-120;
    static int k=90;
    static int h=40,w=60;
    int x=y;
    int j=k;
    k=k+n;
    h=h+3;
    w=w+3;
    y=y+n;

     rectangle->setVisible(false);
     rectangle = scene->addRect(x,y,j,k,blackpen,blueBrush);
     //top x, top y, width,height

     rectangle2->setVisible(false);
     rectangle2 = scene->addRect(x+50,y+40,j-90,k-50,blackpen,blackBrush);
      //top x, top y, width,height

     ellipse->setVisible(false);
     ellipse = scene->addEllipse(x-20,y+(j)-40,h,w,blackpen,blackBrush);

     ellipse1->setVisible(false);
     ellipse1 = scene->addEllipse(x+k-20-2*n,y+(j)-40,h,w,blackpen,blackBrush);
 }

