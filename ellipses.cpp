
#include "shape.h"


// ************************************ [ ELLIPSES ] ************************************** //

#include "ellipses.h"
#include <cmath>
#include <QtDebug>


// ******--> { CONSTRUCTORS } <--****** //

Ellipse::Ellipse(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int setX, int setY, double setWidth, double setHeight)
    :Shapes(setPenColor, setPenStyle, setCapStyle, setJointStyle, setBrushColor, setBrushStyle)
{
    this->set_shape(ShapeType::Ellipse);

    this->set_center2(setX, setY);

    this->set_width(setWidth);
    this->set_height(setHeight);


    // Makes a Circle if one parameter is 0.
    if(this->height == 0)
    {
        this->height = width;
    }
    if(this->width == 0)
    {
        this->width = this->height;
    }

}





// ******--> { GETTERS } <--****** //

QPoint& Ellipse::get_center()
{
    return this->center;
}

double Ellipse::get_width() const
{
    return this->width;
}

double Ellipse::get_height() const
{
    return this->height;
}

int* Ellipse::getDimensions()
{
    QPoint p = get_center();
    int *dimensoins = new int[4];
    dimensoins[0] = p.x();
    dimensoins[1] = p.y();
    dimensoins[2] = get_width();
    dimensoins[3] = get_height();

    return dimensoins;
}



// ******--> { SETTERS } <--****** //

void Ellipse::set_center1(QPoint setCenter)
{
    this->center = setCenter;
}

void Ellipse::set_center2(int setX, int setY)
{
    QPoint temp(setX, setY);
    this->center = temp;
}

void Ellipse::set_width(double setWidth)
{
    this->width = setWidth;
}

void Ellipse::set_height(double setHeight)
{
    this->height = setHeight;
}

void Ellipse::set_all(QPoint setCenter, double setWidth, double setHeight)
{
    this->center = setCenter;

    this->width = setWidth;
    this->height = setHeight;
}






// ******--> { MOVE } <--****** //

void Ellipse::move(int x, int y, int na)
{
    QPoint temp(x,y);
    this->set_center1(temp);
}




// ******--> { DRAW } <--****** //

void Ellipse::draw(QPaintDevice *device)
{
    qpainter.begin(device);
    qpainter.setPen(get_pen());
    qpainter.setBrush(get_brush());
    qpainter.drawEllipse(center.x(), center.y(), width, height);
    qpainter.drawText(center, QString::number(get_id()));
    qpainter.end();
}

// ************************************************************************** //

