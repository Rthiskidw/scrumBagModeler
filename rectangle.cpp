
#include "shape.h"


// ************************************ [ RECTANGLE ] ************************************** //

#include "rectangle.h"
#include <cmath>
#include <QtDebug>


// ******--> { CONSTRUCTORS } <--****** //

Rectangle::Rectangle(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int setX, int setY, double setWidth, double setHeight)
    :Shapes(setPenColor, setPenStyle, setCapStyle, setJointStyle, setBrushColor, setBrushStyle)
{
    this->set_shape(ShapeType::Rectangle);

    this->set_point2(setX, setY);

    this->set_width(setWidth);
    this->set_height(setHeight);


    // Makes a square if one parameter is 0.
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

int Rectangle::get_x() const
{
    return this->x;
}

int Rectangle::get_y() const
{
    return this->y;
}

double Rectangle::get_width() const
{
    return this->width;
}

double Rectangle::get_height() const
{
    return this->height;
}

QPoint& Rectangle::get_point()
{
    return this->point;
}

int* Rectangle::getDimensions()
{
    int* dimensions = new int[4];
    dimensions[0] = get_x();
    dimensions[1] = get_y();
    dimensions[2] = get_width();
    dimensions[3] = get_height();

    return dimensions;
}




// ******--> { SETTERS } <--****** //

void Rectangle::set_x(int setX)
{
    this->x = setX;
}

void Rectangle::set_y(int setY)
{
    this->y = setY;
}

void Rectangle::set_width(double setWidth)
{
    this->width = setWidth;
}

void Rectangle::set_height(double setHeight)
{
    this->height = setHeight;
}

void Rectangle::set_point1(QPoint setPoint)
{
   this->point = setPoint;
}

void Rectangle::set_point2(int setX, int setY)
{
    this->x = setX;
    this->y = setY;

    QPoint temp(setX,setY);
    this->point = temp;
}

void Rectangle::set_dimensions(double setWidth, double setHeight)
{
    this->width = setWidth;
    this->height = setHeight;
}

void Rectangle::set_all(int setX, int setY, double setWidth, double setHeight)
{
    this->x = setX;
    this->y = setY;

    QPoint temp(setX,setY);
    this->point = temp;


    this->width = setWidth;
    this->height = setHeight;
}





// ******--> { MOVE } <--****** //


void Rectangle::move(int x, int y, int vector)
{
    this->set_point2(x,y);

}





// ******--> { DRAW } <--****** //

void Rectangle::draw(QPaintDevice *device)
{
    qpainter.begin(device);
    qpainter.setPen(get_pen());
    qpainter.setBrush(get_brush());
    qpainter.drawRect(point.x(), point.y(), width, height);
    qpainter.drawText(point, QString::number(get_id()));
    qpainter.end();
}

// ************************************************************************** //
