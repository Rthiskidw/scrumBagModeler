#ifndef POLYLINE_H
#define POLYLINE_H


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



//!  Class Polyline
/*!
  Class to construct a Polyline.
*/
class Polyline : public Shapes
{
public:

    //! Default constructor.
    /*!
      \param device pointer to a QPaintDevice
      \param id is of the shape object
    */
    Polyline(QPaintDevice* device = nullptr, int id = -1);


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
    Polyline(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int numberOfPts, QPoint* pointValues);


    //! Destructor.
    /*!
    */
    ~Polyline() override  {};

    //! Getter function to get the number of points in a Polyline.
    /*!
      \return numberOfPoints
    */
    int get_points() const;


    int* getDimensions() override;


    //! Setter function to set a point of a Polyline using QPoint coordinates.
    /*!
      \param point is a Qpoint variable
    */
    void set_point(const QPoint& point);



    //! Function to add the total number of points in a Polyline.
    /*!
      \param n an integer
    */
    void add_points(int n);



    //! Function to move a Polyline Object.
    /*!
      \param x an integer
      \param y an integer
      \param vertex an integer
      \return New location
    */
    void move(const int x_pos, const int y_pos, int vertex) override;



    //! Function to draw a Polyline.
    /*!
      \param device a pointer to a QPaintDevice
    */
    void draw(QPaintDevice *device) override;


private:
    int numberOfPoints;
    QPoint pointArray[MAX_NUMBER_OF_POINTS];

};


#endif // POLYLINE_H
