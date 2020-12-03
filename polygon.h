#ifndef POLYGON_H
#define POLYGON_H


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
#include "shape.h"


class Polygon : public Shapes
{
private:

    Shapes_Vector<QPoint> vertVect;
    QPoint vertsArray[DEFAULT_VERTICES];
    int     numVerts;

public:

    Polygon(QPaintDevice* dev = nullptr, int id = -1);

    Polygon(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int numberOfPts, QPoint* pointValues);

    ~Polygon() override {}

    virtual void draw(QPaintDevice *dev) override;

    virtual void move(int x, int y, int vertex) override;

    double area();

    double perimeter();

    void setNumVertices(int numVertices);

    int getNumVertices()const;

    int* getDimensions() override;

    void addVertex(const QPoint& vertex);

    Shapes_Vector<QPoint>& getVertices();
};

#endif // POLYGON_H
