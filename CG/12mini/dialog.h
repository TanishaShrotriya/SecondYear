#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QGraphicsScene>
#include <QtCore>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    //datamemebers
    Ui::Dialog *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse,*ellipse1;
    QGraphicsRectItem *rectangle,*rectangle2,*rectangle3;
};

#endif // DIALOG_H
