
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

//!  Class Shape
/*!
  Base class to create a Shape.
*/
class Shapes : public QPainter
{
public:

    /** \enum type Shapes, used to distinguish between shapes.
     */
    enum ShapeType {NoShape,
                    Line,
                    Polyline,
                    Polygon,
                    Rectangle,
                    Ellipse,
                    Text};


    //! Default Constructor.
    /*!
      Constructs a default shape
    */
    Shapes();


    //! Alternate constructor.
    /*!
      \param setTextColor a Qt::GlobalColor
    */
    Shapes(Qt::GlobalColor setTextColor);


    //! Alternate constructor.
    /*!
      \param setPenColor a Qt::GlobalColor
      \param setPenStyle a Qt::PenStyle
      \param setCapStyle a Qt::PenCapStyle
      \param setJointStyle a Qt::PenJoinStyle
      \param setBrushColor a Qt::GlobalColor
      \param setBrushStyle a Qt::BrushStyle
    */
    Shapes(Qt::GlobalColor setPenColor, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle, Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle);


    //! Destructor.
    /*!
      Destroys a shape.
    */
    virtual ~Shapes() {};


    //! Getter Function to get a shape
    /*!
      \return shape
    */
    ShapeType get_shape() const     {return this->shape;};


    //! Getter Function to get Shape Object pen.
    /*!
      \return pen
    */
    const QPen& get_pen() const;


    //! Getter Function to get Shape Object brush.
    /*!
      \return brush
    */
    const QBrush& get_brush() const;


    //! Getter Function to get number of shapes.
    /*!
      \return numberOfShapes
    */
    static int get_number_of_shapes();


    //! Getter Function to get Shape ID.
    /*!
      \return id
    */
    int get_id() const;


    //! Getter Function to return painter object.
    /*!
      \return qpainter
    */
    QPainter& getQtpainter();


    //! Getter function to get the dimensions of the Shape.
    /*!
      \return dimensions
    */
    virtual int* getDimensions() = 0;

    //! Setter Function to set ShapeType
    /*!
      \param setShape
    */
    void set_shape(ShapeType setShape);


    //! Setter Function to set pen properties.
    /*!
      \param setPenColor
      \param width
      \param setPenStyle
      \param setCapStyle
      \param setJointStyle
    */
    void set_pen(Qt::GlobalColor setPenColor, int width, Qt::PenStyle setPenStyle, Qt::PenCapStyle setCapStyle, Qt::PenJoinStyle setJointStyle);


    //! Setter Function to set width
    /*!
      \param width
    */
    void set_width(int width);


    //! Setter Function to set pen properties.
    /*!
      \param setPenColor
    */
    void set_pen(Qt::GlobalColor setPenColor);


    //! Setter Function to set brush
    /*!
      \param setBrushColor
      \param setBrushStyle
    */
    void set_brush(Qt::GlobalColor setBrushColor, Qt::BrushStyle setBrushStyle);


    //! Setter Function to set Shape Object ID
    /*!
      \param ID
    */
    void set_id(int id);


    //! Function to set Default style
    /*!
    */
    void default_style();


    //! Pure Virtual function to draw a Shape object.
    /*!
      \param device
    */
    virtual void draw(QPaintDevice *device) = 0;



    //! Pure Virtual function to move a Shape object. Used as a default in base class.
    /*!
      \param x_pos
      \param y_pos
      \param index
    */
    virtual void move(const int x_pos, const int y_pos, int index) = 0;

    //! Finds shape with lesser ID
    /*!
      \param theOtherShape
    */
    bool operator<(const Shapes &theOtherShape) const;

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



#endif // SHAPE_H
