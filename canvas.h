#ifndef CANVAS_H
#define CANVAS_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

class canvas : public QWidget
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);

signals:

};

#endif // CANVAS_H
