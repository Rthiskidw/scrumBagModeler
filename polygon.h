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

    //! Default constructor.
    /*!
      \param device pointer to a QPaintDevice
      \param id is of the shape object
    */
    Polygon(QPaintDevice* dev = nullptr, int id = -1);


    //! Alternate constructor.
    /*!
      \param setPenColor a Qt::GlobalColor
      \param setPenStyle a Qt::PenStyle
      \param setCapStyle a Qt::PenCapStyle
      \param setJointStyle a Qt::PenJoinStyle
      \param setBrushColor a Qt::GlobalColor
      \param setBrushStyle a Qt::BrushStyle
      \param numberOfPts an integer
      \param pointValues a QPoint* 
    */
    Polygon(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int numberOfPts, QPoint* pointValues);


    //! Destructor.
    /*!
    */
    ~Polygon() override {}


    //! Function that draws the rectangle on the canvas.
    /*!
      \param device
    */
    virtual void draw(QPaintDevice *dev) override;


    //! Function that moves the rectangle at a certain point.
    /*!
      \param x
      \param y
      \param vertex
    */
    virtual void move(int x, int y, int vertex) override;
    
    

    //! Function to calculate the area of the Polygon.
    /*!
      \return area
    */
    double area();



    //! Function to calculate the perimeter of the Polygon.
    /*!
      \return perimeter
    */
    double perimeter();



    //! Setter Function to set Polygon's numVerts.
    /*!
      \param numVertices
    */
    void setNumVertices(int numVertices);



    //! Getter Function to get Polygon's numVerts.
    /*!
      \return numVerts
    */
    int getNumVertices()const;
    
    
    
    //! Getter Function to get Polygon's dimensions.
    /*!
      \return dimensions
    */
    int* getDimensions() override;
    
    

    //! Function to add a vertex to the Polygon.
    /*!
      \param vertex
    */
    void addVertex(const QPoint& vertex);



    //! Getter function that returns the Polygon vector that contains the vertices.
   /*!
     \return vertVect
   */
    Shapes_Vector<QPoint>& getVertices();
};
};

#endif // POLYGON_H
