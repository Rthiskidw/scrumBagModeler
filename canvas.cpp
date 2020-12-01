#include "canvas.h"
#include <QDebug>
#include <iostream>
#include <QString>
using namespace std;

canvas::canvas(QWidget *parent)
    : QWidget(parent),currentShapes{NULL}
{  
    parseShape(currentShapes);

    qDebug() <<  QString::number(currentShapes[0]->get_id());

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}


void canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPen paintpen(Qt::black);
    paintpen.setWidth(6);
    painter.drawLine(10,10,100,100);



    for ( Shapes* shape : currentShapes)
    {
        shape->draw(this);
    }

}
