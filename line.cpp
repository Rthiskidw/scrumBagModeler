
#include "shape.h"


// ************************************ [ LINE ] ************************************** //

#include "line.h"
#include <cmath>
#include <QtDebug>

// ******--> { CONSTRUCTORS } <--****** //


Line::Line(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, QPoint begin, QPoint end)
    :Shapes(setPenColor, setPenStyle, setCapStyle, setJointStyle, setBrushColor, setBrushStyle)
{
    this->set_shape(ShapeType::Line);
    this->set_points(begin, end);
}

// ******--> { GETTERS } <--****** //

QPoint& Line::get_point_begin()
{
    return this->point_begin;
}

QPoint& Line::get_point_end()
{
    return this->point_end;
}

int* Line::getDimensions()
{
    QPoint p1 = get_point_begin();
    QPoint p2 = get_point_end();

    int *dimensions = new int[4];

    dimensions[0] = p1.x();
    dimensions[1] = p1.y();
    dimensions[2] = p2.x();
    dimensions[3] = p2.y();

    return dimensions;
}

// ******--> { SETTERS } <--****** //
void Line::set_points(const QPoint &set_point_begin, const QPoint &set_point_end)
{
    this->point_begin = set_point_begin;
    this->point_end   = set_point_end;
}

// ******--> { MOVE } <--****** //

void Line::move(const int x_pos, const int y_pos, int index)
{
    QPoint input(x_pos, y_pos);
    QPoint temp;

    temp = point_begin - input;
    point_begin = input;
    point_end = point_end - temp;
}

// ******--> { DRAW } <--****** //

void Line::draw(QPaintDevice *device)
{
    qpainter.begin(device);
    qpainter.setPen(get_pen());
    qpainter.setBrush(get_brush());
    qpainter.drawLine(point_begin, point_end);
    qpainter.drawText(point_begin, QString::number(get_id()));
    qpainter.end();
}

// ************************************************************************** //
