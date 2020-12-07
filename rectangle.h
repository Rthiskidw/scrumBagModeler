
#ifndef RECTANGLE_H
#define RECTANGLE_H

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


//!  Class Rectangle
/*!
  Class to construct a Rectangle on screen.
*/
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

    //! Default constructor.
    /*!
      \param device pointer to a QPaintDevice
      \param id is of the shape object
    */
    Rectangle(QPaintDevice* device = nullptr, int id = -1);


    //! Alternate constructor.
    /*!
      \param setPenColor a Qt::GlobalColor
      \param setPenStyle a Qt::PenStyle
      \param setCapStyle a Qt::PenCapStyle
      \param setJointStyle a Qt::PenJoinStyle
      \param setBrushColor a Qt::GlobalColor
      \param setBrushStyle a Qt::BrushStyle
      \param setX an integer
      \param setY an integer
      \param setWidth a double
      \param setHeight a double
    */
    Rectangle(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int setX, int setY, double setWidth, double setHeight);



    //! Destructor.
    /*!
    */
    virtual ~Rectangle() {}



    //! Getter function to get the x of a Rectangle.
    /*!
      \return x
    */
    int get_x() const;



    //! Getter function to get the y of a Rectangle.
    /*!
      \return y
    */
    int get_y() const;


    //! Getter function to get the width of a Rectangle.
    /*!
      \return width
    */
    double get_width() const;



    //! Getter function to get the height of a Rectangle.
    /*!
      \return height
    */
    double get_height() const;



    //! Getter function to get the point of a Rectangle.
    /*!
      \return point
    */
    QPoint& get_point();



    //! Getter function to get the dimensions of the Rectangle.
    /*!
      \return dimensions
    */
    int* getDimensions() override;


    //! Setter Function to set rectangle's x-coordinate.
    /*!
      \param setX
    */
    void set_x(int setX);


    //! Setter Function to set rectangle's y-coordinate.
    /*!
      \param setY
    */
    void set_y(int setY);


    //! Setter Function to set rectangle's width.
    /*!
      \param setWidth
    */
    void set_width(double setWidth);



    //! Setter Function to set rectangle's height.
    /*!
      \param setHeight
    */
    void set_height(double setHeight);


    //! Setter Function to set rectangle's axis.
    /*!
      \param setPoint
    */
    void set_point1(QPoint setPoint);


    //! Setter Function to set rectangle's axis.
    /*!
      \param setX
      \param setY
    */
    void set_point2(int setX, int setY);


    //! Setter Function to set rectangle's width and height.
    /*!
      \param setWidth
      \param setHeight
    */
    void set_dimensions(double setWidth, double setHeight);


    //! Setter Function to set all of the rectangle's dimensions.
    /*!
      \param setWidth
      \param setHeight
      \param setX
      \param setY
    */
    void set_all(int setX, int setY, double setWidth, double setHeight);



     //! Function that moves the rectangle at a certain point.
     /*!
       \param x
       \param y
       \param vector
     */
    void move(int x, int y, int vector) override;


    //! Function that draws the rectangle on the canvas.
    /*!
      \param device
    */
    void draw(QPaintDevice *device) override;
};



#endif // RECTANGLE_H
