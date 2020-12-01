#ifndef CANVAS_H
#define CANVAS_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "vector.h"
#include "shape.h"
#include "shapeparser.h"

class canvas : public QWidget
{
    Q_OBJECT

public:
    explicit canvas(QWidget *parent = nullptr);
    void setShapeVector(const Shapes_Vector<Shapes*> v);

protected:
    void paintEvent(QPaintEvent *) override;

signals:

private:
     Shapes_Vector<Shapes*> currentShapes;

};

#endif // CANVAS_H
