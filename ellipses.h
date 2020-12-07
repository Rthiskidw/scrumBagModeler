#ifndef ELLIPSES_H
#define ELLIPSES_H


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

//!  Class Ellipse
/*!
  Class to construct an Ellipse.
*/
class Ellipse : public Shapes
{
private:
    QPoint center;
    double width;
    double height;
public:


    //! Default constructor.
    /*!
      \param device pointer to a QPaintDevice
      \param id is of the shape object
    */
    Ellipse(QPaintDevice* device = nullptr, int id = -1);


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
    Ellipse(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle, int setX, int setY, double setWidth, double setHeight);


    //! Destructor.
    /*!
    */
    virtual ~Ellipse() {};


    //! Getter function to get the center of an Ellipse Object.
    /*!
      \return center
    */
    QPoint& get_center();


    //! Getter function to get the width of an Ellipse Object.
    /*!
      \return width
    */
    double get_width() const;


    //! Getter function to get the height of an Ellipse Object.
    /*!
      \return height
    */
    double get_height() const;


    //! Getter function to get the dimensions of the Ellipse.
    /*!
      \return dimensions
    */
    int* getDimensions() override;


    //! Setter function to set the center of an Ellipse using QPoint coordinates.
    /*!
      \param setCenter is a Qpoint variable
    */
    void set_center1(QPoint setCenter);


    //! Setter function to set the center of an Ellipse using x and y coordinates.
    /*!
      \param x an integer
      \param y an integer
    */
    void set_center2(int setX, int setY);


    //! Setter function to set the width of an Ellipse using setWidth.
    /*!
      \param setWidth is a double
    */
    void set_width(double setWidth);


    //! Setter function to set the height of an Ellipse using setHeight.
    /*!
      \param setHeight is a double
    */
    void set_height(double setHeight);


    //! Setter function to set the width of an Ellipse using QPoint coordinates, setWidth and setHeight.
    /*!
      \param setCenter is a Qpoint variable
      \param setHeight is a double
      \param setWidth is a double
    */
    void set_all(QPoint setCenter, double setWidth, double setHeight);


    //! Function to move an Ellipse.
    /*!
      \param x an integer
      \param y an integer
      \param vecotr an integer
      \return New location
    */
    void move(int x, int y, int vector) override;


    //! Function to draw an Ellipse.
    /*!
      \param device pointer to a QPaintDevice
    */
    void draw(QPaintDevice *device) override;
};

#endif // ELLIPSES_H
