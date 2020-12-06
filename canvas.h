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
    explicit canvas(QWidget *parent = nullptr);
    void setShapeVector(const Shapes_Vector<Shapes*> v);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void gettingVectorFromMain(const Shapes_Vector<Shapes*> shapesVector);
    void paintEvent(QPaintEvent *) override;

    void addShape(Shapes* shapeIn);

    int getSize();
    int getnumShapesRA();

    void saveShape();
    void chopShape(int indexRemove);//Shape remove
    void moveShape(int indexMove, int coordMove, int x, int y); //Move shape

    QString getStringColor(QColor color);
    QString getStringPenCap(Qt::PenCapStyle penCapStyle);
    QString getStringPenStyle(Qt::PenStyle penStyle);
    QString getStringPenJointStyle(Qt::PenJoinStyle penJointStyle);
    QString getStringBrush(Qt::BrushStyle brush);
    QString getStringFlag(Qt::AlignmentFlag  flag);
    QString getStringFontStyle(QFont::Style fontStyle);
    QString getStringFontWeight(int fontWeight);

    Shapes::ShapeType getShapeType(QString shape);
    Qt::GlobalColor   getColor(QString color);
    Qt::PenCapStyle   getPenCapStyle(QString cap);
    Qt::PenStyle      getPenStyle(QString pen);
    Qt::PenJoinStyle  getPenJointStyle(QString penJoint);
    Qt::BrushStyle    getBrushStyle(QString brushStyle);
    Qt::AlignmentFlag getFlag(QString flag);
    QFont::Style      getFontStyle(QString fontStyle);
    QFont::Weight     getFontWeight(QString fontWeight);

signals:

private:
    Shapes_Vector<Shapes*> currentShapes;
    const QImage canvasObject;
    int numShapesRA;
};

#endif // CANVAS_H
