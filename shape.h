#ifndef shape_h
#define shape_h
#include <stdio.h>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>
#include "vector.h"

using namespace std;

enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

namespace Project {
class Shape
{
protected:
    QPainter& get_qpainter();
private:
    QPainter& qpainter;
    int id;
    ShapeType shape;
    QPen pen;
    QBrush brush;

public:
    Shape(QPaintDevice* device = nullptr, int id = -1, ShapeType shape = ShapeType::NoShape);
    virtual ~Shape() {}

    //add delete and copy operators

    ShapeType get_shape() const;
    const QPen& get_pen() const;
    const QBrush get_brush() const;

    void set_shape(ShapeType, shape);
    void set_pen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
    void set_pen(Qt::GlobalColor);
    void set_brush(Qt::GlobalColor, Qt::BrushStyle);

    void default_style();
    void draw_rect(int width, int height);

    virtual void draw(const int translate_x, const int translate_y) = 0;

};

class Line : public Shape
{
private:
    QPoint point_begin;
    QPoint point_end;
public:
    Line(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, ShapeType::Line} {}
    //destructor
    ~Line() override {}
    void set_points(const QPoint& point_begin, const QPoint& point_end);
    void draw(const int translate_x = 0, const int translate_y = 0) override;
};

class Polyline : public Shape
{
private:
    QPoint point;
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Polyline){}
    ~Polyline() override {}
    void set_point(const QPoint& point);
    void draw(const int translate_x = 0, const int translate_y = 0) override;

};

class Polygon : public Shape
{
private:
    QPoint point_side;
    QPoint point_angle;
    QPoint point_length;
public:
    Polygon(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Polygon){}
    ~Polygon() override {}
    void set_points(const QPoint& point_side, const QPoint& point_angle, const QPoint& point_length);
    void draw(const int translate_x = 0, const int translate_y = 0) override;
};

class Rectangle : public Shape
{
private:
    QPoint angle_1;
    QPoint angle_2;
    QPoint angle_3;
    QPoint angle_4;
public:
    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Rectangle){}
    ~Rectangle() override{}
    void set_points(const QPoint& angle_1, const QPoint& angle_2, const QPoint& angle_2 ,const QPoint& angle_4);
    void draw(const int translate_x = 0, const int translate_y = 0) override;
};

class Ellipse : public Shape
{
private:
    QPoint center;
    QPoint major_axis;
    QPoint minor_axis;
    QPoint foci;
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Ellipse){}
    ~Ellipse() override{}
    void set_points(const QPoint& center, const QPoint& major_axis, const QPoint& minor_axis, const QPoint& foci);
    void draw(const int translate_x = 0, const int translate_y = 0) override;
};

class Text : public Shape
{
private:
    QPoint text_string;
    QPoint text_color;
    QPoint text_alignment;
    QPoint text_pointSize;
    QPoint text_fontFamily;
    QPoint text_fontStyle;
    QPoint text_fontWeight;
public:
    Text(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, ShapeType::Text){}
    ~Text() override{}
    void set_points(const QPoint& text_string,const QPoint& text_color, const QPoint& text_alignment, const QPoint& text_pointSize, const QPoint& text_fontFamily,const QPoint& text_fontStyle, const QPoint& text_fontWeight);
    void draw(const int translate_x = 0, const int translate_y = 0) override;
};
}
#endif
