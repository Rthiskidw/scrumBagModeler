
#include "shape.h"


/* shape.cpp */

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






// ************************************ [ LINE ] ************************************** //


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






// ******--> { SETTERS } <--****** //
void Line::set_points(const QPoint &set_point_begin, const QPoint &set_point_end)
{
    this->point_begin = set_point_begin;
    this->point_end   = set_point_end;
}




// ******--> { MOVE } <--****** //

void Line::move(const int x_pos, const int y_pos, int index)
{
    QPoint temp(x_pos, y_pos);
    switch (index)
    {
        case 1: point_begin = temp;
                break;
        case 2: point_end = temp;
                break;
        default:
                break;
    }
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





// ************************************ [ POLYLINE ] ************************************** //


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


// ************************************ [ POLYGON ] ************************************** //


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



// ************************************ [ RECTANGLE ] ************************************** //

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





// ************************************ [ ELLIPSES ] ************************************** //

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



// ************************************ [ TEXT ] ************************************** //

// ******--> { CONSTRUCTORS } <--****** //

Text::Text(Qt::GlobalColor setFontColor, QString setText, QFont setFont, QPoint setLocation, Qt::AlignmentFlag setFlag, int setWidth, int setHeight)
    :Shapes(setFontColor)
{
    this->set_shape(ShapeType::Text);

    this->set_text_string(setText);
    this->set_text_font(setFont);
    this->set_location1(setLocation);
    this->set_alignment_flag(setFlag);
    this->set_text_box_width(setWidth);
    this->set_text_box_height(setHeight);

    this->text_font.setFamily("Times");
}





// ******--> { GETTERS } <--****** //

QString& Text::get_text_string()
{
    return text_string;
}

QFont& Text::get_text_font()
{
    return text_font;
}

QPoint& Text::get_location()
{
    return location;
}

Qt::AlignmentFlag& Text::get_alignment_flag()
{
    return flag;
}

int Text::get_text_box_width() const
{
    return textBoxWidth;
}

int Text::get_text_box_height() const
{
    return textBoxHeight;
}






// ******--> { SETTERS } <--****** //

void Text::set_text_string(QString setTextString)
{
    this->text_string = setTextString;
}

void Text::set_text_font(QFont setTextFont)
{
    this->text_font = setTextFont;
}

void Text::set_location1(QPoint setLocation)
{
    this->location = setLocation;
}

void Text::set_location2(int x, int y)
{
    QPoint temp(x,y);
    this->location = temp;
}

void Text::set_alignment_flag(Qt::AlignmentFlag setFlag)
{
    this->flag = setFlag;
}

void Text::set_text_box_width(int setWidth)
{
    this->textBoxWidth = setWidth;
}

void Text::set_text_box_height(int setHeight)
{
    this->textBoxHeight = setHeight;
}





// ******--> { MOVE } <--****** //

void Text::move(int x, int y, int a)
{
    QPoint temp(x,y);
    location = temp;
}


// ******--> { DRAW } <--****** //

void Text::draw(QPaintDevice *device)
{
    qpainter.begin(device);
    qpainter.setPen(get_pen());
    qpainter.setBrush(get_brush());
    qpainter.drawText(location.x(), location.y(), textBoxWidth, textBoxHeight, flag, text_string);
    qpainter.drawText(location, QString::number(get_id()));
    qpainter.end();
}

// ************************************************************************** //




