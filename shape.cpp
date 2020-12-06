

#include "shape.h"
#include <cmath>
#include <QtDebug>


// ************************************** [ SHAPES ] ************************************ //

int Shapes::numberOfShapes = 0;


// ******--> { CONSTRUCTORS } <--****** //

Shapes::Shapes()
{
    this->default_style();
    this->id = ++numberOfShapes;
}

Shapes::Shapes(Qt::GlobalColor setTextColor)
{
    this->pen.setColor(setTextColor);
    this->default_style();
    this->id = ++numberOfShapes;
}


Shapes::Shapes(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle)
{
    this->set_pen(setPenColor, 3, setPenStyle, setCapStyle, setJointStyle);
    this->set_brush(setBrushColor, setBrushStyle);
    this->id = ++numberOfShapes;
}




// ******--> { GETTERS } <--****** //

const QPen& Shapes::get_pen() const
{
    return this->pen;
}

const QBrush& Shapes::get_brush() const
{
    return this->brush;
}

int Shapes::get_id() const
{
    return this->id;
}

int Shapes::get_number_of_shapes()
{
    return numberOfShapes;
}

QPainter &Shapes::getQtpainter()
{
    return this->qpainter;
}




// ******--> { SETTERS } <--****** //

void Shapes::set_shape(ShapeType setShape)
{
    this->shape = setShape;
}

void Shapes::set_pen(Qt::GlobalColor setPenColor, int width, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle)
{
    pen.setColor(setPenColor);
    pen.setWidth(width);
    pen.setStyle(setPenStyle);
    pen.setCapStyle(setCapStyle);
    pen.setJoinStyle(setJointStyle);
}

void Shapes::set_width(int width)
{
    this->pen.setWidth(width);
}

void Shapes::set_pen(Qt::GlobalColor setPenColor)
{
    pen.setColor(setPenColor);
}

void Shapes::set_brush(Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle)
{
    brush = QBrush(setBrushColor,setBrushStyle);
}

void Shapes::set_id(int id)
{
    this->id = id;
}





// ******-> { DEFAULT STLYE } <-****** //

void Shapes::default_style()
{
    pen   = Qt::SolidLine;
    brush = Qt::NoBrush;
    qpainter.setPen(Qt::SolidLine);
    qpainter.setBrush(Qt::NoBrush);
}

// ************************************************************************** //


bool Shapes::operator<(const Shapes &theOtherShape) const
{
    return(id < theOtherShape.get_id());
}





