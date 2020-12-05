#ifndef LINE_H
#define LINE_H

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


//!  Class Line
/*!
  Class to construct a Line.
*/

class Line : public Shapes
{
private:
    QPoint point_begin;
    QPoint point_end;
    //QPoint point_mid;
public:

    //! Default constructor.
    /*!
      \param device pointer to a QPaintDevice
      \param id is of the shape object
    */
    Line(QPaintDevice* device = nullptr, int id = -1);


    //! Alternate constructor.
    /*!
      \param setPenColor a Qt::GlobalColor
      \param setPenStyle a Qt::PenStyle
      \param setCapStyle a Qt::PenCapStyle
      \param setJointStyle a Qt::PenJoinStyle
      \param setBrushColor a Qt::GlobalColor
      \param setBrushStyle a Qt::BrushStyle
      \param begin a QPoint
      \param setY a QPoint
    */
    Line(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, QPoint begin, QPoint end);


    //! Destructor.
    /*!
    */
    virtual ~Line()  {};


    //! Getter function to get the point_begin of a Line.
    /*!
      \return point_begin
    */
    QPoint& get_point_begin();



    //! Getter function to get the point_end of a Line.
    /*!
      \return point_end
    */
    QPoint& get_point_end();

    int* getDimensions() override;


    //! Mutator function to set the points of a Line Object.
    /*!
      \param point_begin a QPoint&
      \param point_end a QPoint&
    */
    void set_points(const QPoint& point_begin, const QPoint& point_end);



    //! Function to move a Line.
    /*!
      \param x_pos a constant integer
      \param y_pos a constant integer
      \param index an integer
      \return New location
    */
    void move(const int x_pos, const int y_pos, int index) override;



    //! Function to draw a Line.
    /*!
      \param device a pointer to a QPaintDevice
    */
    void draw(QPaintDevice *device) override;

};


#endif // LINE_H
