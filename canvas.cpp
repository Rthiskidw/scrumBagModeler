#include "canvas.h"
#include <QDebug>
#include <iostream>
#include <QString>
using namespace std;

canvas::canvas(QWidget *parent)
      : QWidget(parent),currentShapes{NULL}
{  
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}


void canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //drawing line onto canvas
    QPen paintpen(Qt::black);
    paintpen.setWidth(6);
    painter.drawLine(10,10,100,100);



    for ( Shapes* shape : currentShapes)
    {
        shape->draw(this);
    }

}

void canvas::gettingVectorFromMain(const Shapes_Vector<Shapes*> shapesVector)
{
    currentShapes = shapesVector;
}
