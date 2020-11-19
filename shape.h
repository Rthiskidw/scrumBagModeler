//#ifndef shape_h
//#define shape_h
//#include <stdio.h>
//#include <QPainter>
//#include <QPen>
//#include <QBrush>
//#include <QFont>
//#include "vector.h"

//using namespace std;

//enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

//namespace Project {
//class Shape
//=======
//
//  Shapes.hpp

//#ifndef Shapes_hpp
//#define Shapes_hpp
//#include <stdio.h>
//#include <QPainter>
//#include <QPen>
//#include <QBrush>
//#include <QFront>
//using namespace std;

//#include "vector.h"

//namespace Project {
//class Shapes
//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b
//{
//protected:
//    QPainter& get_qpainter();
//private:
//    QPainter& qpainter;
//    int id;
//    ShapeType shape;
//    QPen pen;
//    QBrush brush;
//<<<<<<< HEAD

//public:
//    Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape);
//    virtual ~Shape() {}
//=======
//public:
//    enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

//    Shapes(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape);
//    virutal ~Shape() {}
//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b

//    //add delete and copy operators

//    ShapeType get_shape() const;
//    const QPen& get_pen() const;
//    const QBrush get_brush() const;

//    void set_shape(ShapeType, shape);
//    void set_pen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
//    void set_pen(Qt::GlobalColor);
//    void set_brush(Qt::GlobalColor, Qt::BrushStyle);

//<<<<<<< HEAD
//=======


//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b
//    void default_style();
//    void draw_rect(int width, int height);

//    virtual void draw(const int translate_x, const int translate_y) = 0;

//};

//<<<<<<< HEAD
//class Line : public Shape
//=======
//class Line : public Shapes
//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b
//{
//private:
//    QPoint point_begin;
//    QPoint point_end;
//public:
//<<<<<<< HEAD
//    Line(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Line} {}
//    //destructor
//=======
//    Line(QPaintDevice* device = nullptr, int id = -1) : Shapes{device, id, ShapeType::Line} {}
//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b
//    ~Line() override {}
//    void set_points(const QPoint& point_begin, const QPoint& point_end);
//    void draw(const int translate_x = 0, const int translate_y = 0) override;
//};

//<<<<<<< HEAD
//class Polyline : public Shape
//=======
//class Polyline : public Shapes
//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b
//{
//private:
//    QPoint point;
//public:
//<<<<<<< HEAD
//    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Polyline){}
//=======
//    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shapes(device, id, ShapeType::Polyline){}
//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b
//    ~Polyline() override {}
//    void set_point(const QPoint& point);
//    void draw(const int translate_x = 0, const int translate_y = 0) override;

//<<<<<<< HEAD
//};

//class Polygon : public Shape
//{
//private:
//    QPoint point_side;
//    QPoint point_angle;
//    QPoint point_length;
//public:
//    Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Polygon){}
//    ~Polygon() override {}
//    void set_points(const QPoint& point_side, const QPoint& point_angle, const QPoint& point_length);
//    void draw(const int translate_x = 0, const int translate_y = 0) override;
//};

//class Rectangle : public Shape
//{
//private:
//    QPoint angle_1;
//    QPoint angle_2;
//    QPoint angle_3;
//    QPoint angle_4;
//public:
//    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Rectangle){}
//    ~Rectangle() override{}
//    void set_points(const QPoint& angle_1, const QPoint& angle_2, const QPoint& angle_2 ,const QPoint& angle_4);
//    void draw(const int translate_x = 0, const int translate_y = 0) override;
//};

//class Ellipse : public Shape
//{
//private:
//    QPoint center;
//    QPoint major_axis;
//    QPoint minor_axis;
//    QPoint foci;
//public:
//    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Ellipse){}
//    ~Ellipse() override{}
//    void set_points(const QPoint& center, const QPoint& major_axis, const QPoint& minor_axis, const QPoint& foci);
//    void draw(const int translate_x = 0, const int translate_y = 0) override;
//};

//class Text : public Shape
//=======
//};

//class Polygon : public Shapes
//{
//private:
//    QPoint point_side;
//    QPoint point_angle;
//    QPoint point_length;
//public:
//    Polygon(QPaintDevice* device = nullptr, int id = -1) : Shapes(device, id, ShapeType::Polygon){}
//    ~Polygon() override {}
//    void set_points(const QPoint& point_side, const QPoint& point_angle, const QPoint& point_length);
//    void draw(const int translate_x = 0, const int translate_y = 0) override;
//};

//class Rectangle : public Shapes
//{
//private:
//    QPoint angle_1;
//    QPoint angle_2;
//    QPoint angle_3;
//    QPoint angle_4;
//public:
//    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shapes(device, id, ShapeType::Rectangle){}
//    ~Rectangle() override{}
//    void set_points(const QPoint& angle_1, const QPoint& angle_2, const QPoint& angle_2 ,const QPoint& angle_4);
//    void draw(const int translate_x = 0, const int translate_y = 0) override;
//};

//class Ellipse : public Shapes
//{
//private:
//    QPoint center;
//    QPoint major_axis;
//    QPoint minor_axis;
//    QPoint foci;
//public:
//    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shapes(device, id, ShapeType::Ellipse){}
//    ~Ellipse() override{}
//    void set_points(const QPoint& center, const QPoint& major_axis, const QPoint& minor_axis, const QPoint& foci);
//    void draw(const int translate_x = 0, const int translate_y = 0) override;
//};

//class Text : public Shapes
//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b
//{
//private:
//    QPoint text_string;
//    QPoint text_color;
//    QPoint text_alignment;
//    QPoint text_pointSize;
//    QPoint text_fontFamily;
//    QPoint text_fontStyle;
//    QPoint text_fontWeight;
//public:
//<<<<<<< HEAD
//    Text(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Text){}
//=======
//    Text(QPaintDevice* device = nullptr, int id = -1) : Shapes(device, id, ShapeType::Text){}
//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b
//    ~Text() override{}
//    void set_points(const QPoint& text_string,const QPoint& text_color, const QPoint& text_alignment, const QPoint& text_pointSize, const QPoint& text_fontFamily,const QPoint& text_fontStyle, const QPoint& text_fontWeight);
//    void draw(const int translate_x = 0, const int translate_y = 0) override;
//};
//<<<<<<< HEAD
//}
//#endif
//=======
//>>>>>>> da78918b2201010db2af70d37104616e8f43af3b



//
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

    QPoint point_side;
    QPoint point_angle;
    QPoint point_length;


public:
    Polygon(QPaintDevice* device = nullptr, int id = -1);

    virtual ~Polygon() override {};

    void set_points(const QPoint& point_side, const QPoint& point_angle, const QPoint& point_length);

    void draw(QPaintDevice *device) override;
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
