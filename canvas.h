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

class canvas : public QWidget
{
    Q_OBJECT

public:
    explicit canvas(QWidget *parent = nullptr);
    void setShapeVector(const Shapes_Vector<Shapes*> v);
    void gettingVectorFromMain(const Shapes_Vector<Shapes*> shapesVector);

protected:
    void paintEvent(QPaintEvent *) override;

signals:

private:
     Shapes_Vector<Shapes*> currentShapes;

};

#endif // CANVAS_H
