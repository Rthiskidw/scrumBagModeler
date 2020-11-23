
//  Shapes.hpp

#ifndef SHAPE_H_
#define SHAPE_H_
#include <stdio.h>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QObject>
#include <QPaintDevice>
#include <string>

//using namespace Qt;
using namespace std;


#include "vector.h"
const int MAX_NUMBER_OF_POINTS = 5;     // Refer to Polyline Class.
const int DEFAULT_VERTICES = 8;         // Refer to Polygon Class


class Shapes : public QPainter
{
public:
    enum ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

    Shapes();
    Shapes(Qt::GlobalColor setTextColor);
    Shapes(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle);

    virtual ~Shapes() {};

    //add delete and copy operators

    ShapeType get_shape() const     {return this->shape;};
    const QPen& get_pen() const;
    const QBrush& get_brush() const;
    static int get_number_of_shapes();
    int get_id() const;
    QPainter& getQtpainter();

    void set_shape(ShapeType setShape);
    void set_pen(Qt::GlobalColor setPenColor, int width, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle);
    void set_width(int width);
    void set_pen(Qt::GlobalColor setPenColor);
    void set_brush(Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle);
    void set_id(int id);



    void default_style();

    virtual void draw(QPaintDevice *device) = 0;
    virtual void move(const int x_pos, const int y_pos, int index) = 0;


protected:
    QPainter& getQtPainter();
    QPainter qpainter;
    ShapeType shape;
private:
    static int numberOfShapes;
    int id;
    QPen pen;
    QBrush brush;

};




class Line : public Shapes
{
private:
    QPoint point_begin;
    QPoint point_end;
public:
    Line(QPaintDevice* device = nullptr, int id = -1);
    Line(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, QPoint begin, QPoint end);

    virtual ~Line()  {};

    QPoint& get_point_begin();
    QPoint& get_point_end();

    void set_points(const QPoint& point_begin, const QPoint& point_end);


    void move(const int x_pos, const int y_pos, int index) override;
    void draw(QPaintDevice *device) override;

};




class Polyline : public Shapes
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1);
    Polyline(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int numberOfPts, QPoint* pointValues);

    ~Polyline() override  {};


    int get_points() const;

    void set_point(const QPoint& point);
    void add_points(int n);


    void move(const int x_pos, const int y_pos, int vertex) override;
    void draw(QPaintDevice *device) override;


private:
    int numberOfPoints;
    QPoint pointArray[MAX_NUMBER_OF_POINTS];

};




class Polygon : public Shapes
{
private:

    Shapes_Vector<QPoint> vertVect;
    QPoint vertsArray[DEFAULT_VERTICES];
    int     numVerts;

public:

    Polygon(QPaintDevice* dev = nullptr, int id = -1);

    ~Polygon() override {}

    virtual void draw(QPaintDevice *dev) override;

    virtual void move(int x, int y, int vertex) override;

    double area();

    double perimeter();

    void setNumVertices(int numVertices);

    int getNumVertices()const;

    void addVertex(const QPoint& vertex);

    Shapes_Vector<QPoint>& getVertices();
};




class Rectangle : public Shapes
{
private:
    int x;
    int y;
    double width;
    double height;
    QRectF rectangle;
    QPoint point;
public:
    Rectangle(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int setX, int setY, double setWidth, double setHeight);
    Rectangle(QPaintDevice* device = nullptr, int id = -1);

    virtual ~Rectangle() {}

    int get_x() const;
    int get_y() const;
    double get_width() const;
    double get_height() const;
    QPoint& get_point();


    void set_x(int setX);
    void set_y(int setY);
    void set_width(double setWidth);
    void set_height(double setHeight);

    void set_point1(QPoint setPoint);
    void set_point2(int setX, int setY);
    void set_dimensions(double setWidth, double setHeight);
    void set_all(int setX, int setY, double setWidth, double setHeight);




    void move(int x, int y, int vector) override;

    void draw(QPaintDevice *device) override;
};




class Ellipse : public Shapes
{
private:
    QPoint center;
    double width;
    double height;
public:
    Ellipse(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int setX, int setY, double setWidth, double setHeight);
    Ellipse(QPaintDevice* device = nullptr, int id = -1);

    virtual ~Ellipse() {};

    QPoint& get_center();
    double get_width() const;
    double get_height() const;

    void set_center1(QPoint setCenter);
    void set_center2(int setX, int setY);
    void set_width(double setWidth);
    void set_height(double setHeight);
    void set_all(QPoint setCenter, double setWidth, double setHeight);


    void move(int x, int y, int vector) override;

    void draw(QPaintDevice *device) override;
};




class Text : public Shapes
{
private:
    QString text_string;
    QFont  text_font;
    QPoint location;
    Qt::AlignmentFlag flag;
    int textBoxWidth;
    int textBoxHeight;
public:
    Text(Qt::GlobalColor setFontColor, QString setText, QFont setFont, QPoint setLocation, Qt::AlignmentFlag setFlag, int setWidth, int setHeight);     // Might change to allow family variable.
    Text(QPaintDevice* device = nullptr, int id = -1);

    virtual ~Text() {};

    QString& get_text_string();
    QFont& get_text_font();
    QPoint& get_location();
    Qt::AlignmentFlag& get_alignment_flag();
    int get_text_box_width() const;
    int get_text_box_height() const;

    void set_text_string(QString setTextString);
    void set_text_font(QFont setTextFont);
    void set_location1(QPoint setLocation);
    void set_location2(int x, int y);
    void set_alignment_flag(Qt::AlignmentFlag setFlag);
    void set_text_box_width(int setWidth);
    void set_text_box_height(int setHeight);


    //void set_points(const QPoint& text_string, const QPoint& text_color, const QPoint& text_alignment, const QPoint& text_pointSize, const QPoint& text_fontFamily, const QPoint& text_fontStyle, const QPoint& text_fontWeight);

    void move(int x, int y, int na) override;

    void draw(QPaintDevice *device) override;
};

#endif // SHAPE_H
