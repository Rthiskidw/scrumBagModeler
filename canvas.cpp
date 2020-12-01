#include "canvas.h"

canvas::canvas(QWidget *parent)
    : QWidget(parent),currentShapes{NULL}
{  
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen paintpen(Qt::black);
    paintpen.setWidth(6);
    painter.drawLine(10,10,100,100);
}
