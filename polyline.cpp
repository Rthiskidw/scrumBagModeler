
#include "shape.h"


// ************************************ [ POLYLINE ] ************************************** //

#include "polyline.h"
#include <cmath>
#include <QtDebug>


// ******--> { CONSTRUCTORS } <--****** //


Polyline::Polyline(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int numberOfPts, QPoint* pointValues)
    : Shapes(setPenColor, setPenStyle, setCapStyle, setJointStyle, setBrushColor, setBrushStyle)
{
    numberOfPoints = numberOfPts;
    for(int i = 0; i < numberOfPts; i++)
    {
        pointArray[i] = pointValues[i];
    }
        this->set_shape(ShapeType::Polyline);
}




// ******--> { GETTERS } <--****** //

int Polyline::get_points() const
{
    return numberOfPoints;
}


int* Polyline::getDimensions()
{
    int* dimensions = new int[numberOfPoints * 2];

    dimensions[0] = pointArray[0].x();
    dimensions[1] = pointArray[0].y();
    dimensions[2] = pointArray[1].x();
    dimensions[3] = pointArray[1].y();
    dimensions[4] = pointArray[2].x();
    dimensions[5] = pointArray[2].y();
    dimensions[6] = pointArray[3].x();
    dimensions[7] = pointArray[3].y();

    return dimensions;
}


// ******--> { SET POINT } <--****** //

void Polyline::set_point(const QPoint &point)
{
    pointArray[(get_points()) - 1] = point;
    numberOfPoints++;
}




// ******--> { TOTAL POINTS } <--****** //

void Polyline::add_points(int n)
{
    numberOfPoints = n;
}




// ******--> { MOVE } <--****** //

void Polyline::move(const int x_pos, const int y_pos, int vertex)
{
    QPoint temp(x_pos, y_pos);
    pointArray[vertex - 1] = temp;
}




// ******--> { DRAW } <--****** //
void Polyline::draw(QPaintDevice *device)
{
    qpainter.begin(device);
    qpainter.setPen(get_pen());
    qpainter.setBrush(get_brush());
    qpainter.drawPolyline(pointArray, numberOfPoints);
    qpainter.drawText(pointArray[0], QString::number(get_id()));
    qpainter.end();
}


// ************************************************************************** //
