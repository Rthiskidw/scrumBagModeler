
#include "shape.h"


// ************************************ [ POLYGON ] ************************************** //

#include "polygon.h"
#include <cmath>
#include <QtDebug>

Polygon::Polygon(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int numberOfVerts, QPoint* pointValues)
    : Shapes(setPenColor, setPenStyle, setCapStyle, setJointStyle, setBrushColor, setBrushStyle)
{
    numVerts = numberOfVerts;
    for(int index = 0; index < numVerts; index++)
    {
        vertsArray[index] = pointValues[index];
    }
}

// ******--> { DRAW } <--****** //
void Polygon::draw(QPaintDevice *device)
{
    qpainter.begin(device);
    qpainter.setPen(get_pen());
    qpainter.setBrush(get_brush());
    qpainter.drawConvexPolygon(vertsArray, numVerts);
    qpainter.drawText(vertsArray[0] ,QString::number(get_id()));
    qpainter.end();
}



// ******--> { MOVE } <--****** //
void Polygon::move(int x, int y, int vertex)
{
    QPoint temp(x,y);

    if(vertex <= numVerts)
    {
        //sets the x and y coordinates of the vertex in the vertex vector.
        vertVect.set(vertex - 1, temp);
        vertsArray[vertex - 1] = temp;
    }
    else
    {
        qDebug() << "unable to move polygon";
    }
}



// ******--> { GETTERS } <--****** //
Shapes_Vector<QPoint>& Polygon::getVertices()
{
    return vertVect;    //returns the vector that holds all of the vertices.
}

void Polygon::setNumVertices(int numVertices)
{
    if(numVertices > 0)
    {
        numVerts = numVertices;
    }
    else
    {
        qDebug() << "ERROR: Number of vertices is invalid";
    }
}

int Polygon::getNumVertices() const
{
    return numVerts; //returns the number of vertices in the polygon
}

int* Polygon::getDimensions()
{
    int* dimensions = new int[numVerts * 2];
    QPoint *points = vertsArray;

    for(int index = 0; index < numVerts; index++)
    {
        dimensions[index] = points[index].x();
        dimensions[index + 1] = points[index].y();
    }
    return dimensions;
}




// ******--> { SETTERS } <--****** //
double Polygon::area()
{

    int xMid;
    int yMid;
    int xMid2;
    int yMid2;
    int xCenter;
    int yCenter;
    double area;
    double apothem;
    double perimeter = this->perimeter();

    if(numVerts%2 == 0) //if even, finds the midpoint of the first side
    {
        xMid = ((vertVect[0].x() + vertVect[1].x()) / 2);
        yMid = ((vertVect[0].y() + vertVect[1].y()) / 2);
    }
    else //if odd, gets the x and y coordinates of the first vertex
    {
        xMid = vertVect[0].x();
        yMid = vertVect[0].y();
    }

    //Finds the x and y coordinates of the midpoint of opposite side of the polygon from the first midpoint.
    xMid2 = ((vertVect[numVerts - 2].x() + vertVect[numVerts - 1].x()) / 2);
    yMid2 = ((vertVect[numVerts - 2].y() + vertVect[numVerts - 1].y()) / 2);

    //Calculates the x and y coordinates of the center of the polygon using the two midpoints.
    xCenter = ((xMid + xMid2) / 2);
    yCenter = ((yMid + yMid2) / 2);

    //calculates the apothem of the polygon.
    apothem = sqrt(pow((xMid - xCenter), 2) + pow((yMid - yCenter), 2));

    if(apothem < 0)
    {
        apothem = apothem + (apothem * -2);    //makes sure that the apothem is a positive number.
    }

    area = (apothem * perimeter) / 2;           //calculates area using the apothem and perimeter of  the polygon.

    return area;
}

double Polygon::perimeter()
{
    double perimPolygon = 0.0;
    double distance = 0.0;

    for(int loop = 0; loop < numVerts; loop++) //calculates the distance of each side using the distance formula.
    {
        if(loop < numVerts - 1) //measures all sides of the polygon except the last side one by one
        {
            distance = sqrt(pow((vertVect[numVerts + 1].x() - vertVect[numVerts].x()), 2) + pow((vertVect[numVerts + 1].y() - vertVect[numVerts].y()), 2));
        }
        else //measures the distance between the last vertex and the first vertex of the polygon
        {
            distance = sqrt(pow((vertVect[0].x() - vertVect[numVerts].x()), 2) + pow((vertVect[0].y() - vertVect[numVerts].y()), 2));
        }
        perimPolygon = perimPolygon + distance; //adds the value of each side to the total perimeter size.
    }
    return perimPolygon;
}

void Polygon::addVertex(const QPoint& vertex)
{
    vertVect.push_back(vertex);
    vertsArray[numVerts] = vertex;
    numVerts++;
}


// ************************************************************************** //
