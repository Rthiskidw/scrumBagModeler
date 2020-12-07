#ifndef CANVAS_H
#define CANVAS_H


#include <QFile>
#include <QTextStream>
#include "shape.h"
#include "vector.h"
#include <QPaintEvent>
#include <QWidget>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>
#include "vector.h"
#include "shape.h"
#include "shapeparser.h"


//!  Class canvas
/*!
  Class to construct the canvas that displays shapes on screen.
*/
class canvas : public QWidget
{
    Q_OBJECT

public:
    //! Default constructor.
    /*!
      \param parent pointer to a QWidget
    */
    explicit canvas(QWidget *parent = nullptr);
    
        
    //! Setter Function to set the shapes vector.
    /*!
      \param v
    */
    void setShapeVector(const Shapes_Vector<Shapes*> v);
   
    /*
    
    
    //! Function to 
    /*!
      \return QSize(1000,500)
    */
   //QSize sizeHint() const override;
    
    
    //! Function to 
    /*!
      \return QSize(1000,500)
    /*
    QSize minimumSizeHint() const override;
    
    
    *\
    
    
    //! Function to set a shapes vector from main to currentShapes.
    /*!
      \param shapesVector
    *\
    void gettingVectorFromMain(const Shapes_Vector<Shapes*> shapesVector);
    
    
    
    //! Function to paint an event on the canvas.
    /*!
      \param pointer
    *\
    void paintEvent(QPaintEvent *) override;
    
    
    //! Function to push a new shape to the currentShapes vector.
    /*!
      \param shapeIn
    *\
    void addShape(Shapes* shapeIn);
    
       
    //! Getter Function to get the size of the shapes vector.
    /*!
      \return currentShapes.size()
    *\
    int getSize();
    
    
    //! Getter Function to get the number of shapes on the render area.
    /*!
      \return numShapesRA
    *\
    int getnumShapesRA();
    

    //! Saves a shape using the shape parser and serializer.
    /*
    *\
    void saveShape();
    
    
    //! Removes a shape from the canvas.
    /*!
      \param indexRemove
    */
    void chopShape(int indexRemove);//Shape remove
    
    
     //! Function to move a shape on the canvas.
    /*!
      \param indexMove
      \param coordMove
      \param x
      \param y
    */
    void moveShape(int indexMove, int coordMove, int x, int y); //Move shape






    //! Getter Function to get a QString representing the color.
    /*!
      \return a QString that is the name of the QColor inputed.
    */
    QString getStringColor(QColor color);
    
    
    //! Getter Function to get a QString representing the pen cap style.
    /*!
      \return a QString that is the name of the Qt::PenCapStyle inputed.
    */
    QString getStringPenCap(Qt::PenCapStyle penCapStyle);
    
    
    //! Getter Function to get a QString representing the pen style.
    /*!
      \return a QString that is the name of the Qt::PenStyle inputed.
    */
    QString getStringPenStyle(Qt::PenStyle penStyle);
    
    
    //! Getter Function to get a QString representing the pen joint style.
    /*!
      \return a QString that is the name of the Qt::PenJoinStyle inputed.
    */
    QString getStringPenJointStyle(Qt::PenJoinStyle penJointStyle);
    
    
    //! Getter Function to get a QString representing the brush.
    /*!
      \return a QString that is the name of the Qt::BrushStyle inputed.
    */
    QString getStringBrush(Qt::BrushStyle brush);
    
    
    //! Getter Function to get a QString representing the flag.
    /*!
      \return a QString that is the name of the Qt::AlignmentFlag inputed.
    */
    QString getStringFlag(Qt::AlignmentFlag  flag);
    
    
    //! Getter Function to get a QString representing the font style.
    /*!
      \return a QString that is the name of the QFont::Style inputed.
    */
    QString getStringFontStyle(QFont::Style fontStyle);
    
    
    //! Getter Function to get a QString representing the font weight.
    /*!
      \return a QString that is the name of the font weight using the integer inputed.
    */
    QString getStringFontWeight(int fontWeight);







    //! Getter Function to get a ShapeType.
    /*!
      \return a ShapeType representing the QString inputed.
    */
    Shapes::ShapeType getShapeType(QString shape);
    
    
    //! Getter Function to get a color..
    /*!
      \return a Qt::GlobalColor representing the QString inputed.
    */   
    Qt::GlobalColor   getColor(QString color);
    
    
    //! Getter Function to get a pen cap style.
    /*!
      \return a Qt::PenCapStyle representing the QString inputed.
    */    
    Qt::PenCapStyle   getPenCapStyle(QString cap);
    
    
    //! Getter Function to get a pen style.
    /*!
      \return a Qt::PenStyle representing the QString inputed.
    */    
    Qt::PenStyle      getPenStyle(QString pen);
    
    
    //! Getter Function to get a pen joint style.
    /*!
      \return a Qt::PenJoinStyle representing the QString inputed.
    */   
    Qt::PenJoinStyle  getPenJointStyle(QString penJoint);
    
    
    //! Getter Function to get a brush style.
    /*!
      \return a Qt::BrushStyle representing the QString inputed.
    */    
    Qt::BrushStyle    getBrushStyle(QString brushStyle);
       
    
    //! Getter Function to get an alignment flag.
    /*!
      \return a Qt::AlignmentFlag representing the QString inputed.
    */
    Qt::AlignmentFlag getFlag(QString flag);
    
    
    //! Getter Function to get a font style.
    /*!
      \return a QFont::Style representing the QString inputed.
    */    
    QFont::Style      getFontStyle(QString fontStyle);
    
    
    //! Getter Function to get a font weight.
    /*!
      \return a QFont::Weight representing the QString inputed.
    */      
    QFont::Weight     getFontWeight(QString fontWeight);

signals:

private:
    Shapes_Vector<Shapes*> currentShapes;
    const QImage canvasObject;
    int numShapesRA;
};

#endif // CANVAS_H
