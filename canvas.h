#ifndef CANVAS_H
#define CANVAS_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include "vector.h"
#include "shape.h"

class canvas : public QWidget
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

private:
    const Shapes_Vector<Shapes*> currentShapes;

};

#endif // CANVAS_H
