#include "canvas.h"
#include <QDebug>
#include <iostream>
#include <QString>
using namespace std;

canvas::canvas(QWidget *parent)
      : QWidget(parent),currentShapes{0}
{  
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //QPen paintpen(Qt::black);
    //paintpen.setWidth(6);
    //painter.drawLine(10,10,100,100);

    //int j = currentShapes[0]->get_id();
    //changing

    for ( Shapes* shape : currentShapes)
    {
        shape->draw(this);
    }
}

void canvas::gettingVectorFromMain(const Shapes_Vector<Shapes*> shapesVector)
{
    currentShapes = shapesVector;
}

void canvas::addShape(Shapes* shapeIn)
{
    currentShapes.push_back(shapeIn);
    numShapesRA++;
    //shapeIn->draw(this);
}
void canvas::chopShape(int indexRemove)
{
    Shapes_Vector<Shapes*>::iterator i;
    for(i = currentShapes.begin(); i < currentShapes.end(); ++i)
        if((*i)->get_id() == indexRemove)
        {
            currentShapes.erase(i);
            numShapesRA--;
            break;
        }
}

void canvas::moveShape(int index, int coord, int x, int y)
{
    for(int i = 0; i < currentShapes.size(); i++)
        if(currentShapes[i]->get_id() == index){
            currentShapes[i]->move(x,y,coord); break; }
}

int canvas::getSize()
{
    return currentShapes.size();
}

QSize canvas::sizeHint() const
{
    return QSize(1000,500);
}

QSize canvas::minimumSizeHint() const
{
    return QSize(1000,500);
}

int canvas::getnumShapesRA()
{
    return numShapesRA;
}

Shapes::ShapeType canvas::getShapeType(QString shapeStr)
{
    if(shapeStr == "Line")
        return Shapes::ShapeType::Line;
    else if(shapeStr == "Polyline")
        return Shapes::ShapeType::Polyline;
    else if(shapeStr == "Polygon")
        return Shapes::ShapeType::Polygon;
    else if(shapeStr == "Rectangle")
        return Shapes::ShapeType::Rectangle;
    else if(shapeStr == "Ellipse")
        return Shapes::ShapeType::Ellipse;
    else if(shapeStr == "Text")
        return Shapes::ShapeType::Text;
    else
        return Shapes::ShapeType::NoShape;

}

Qt::GlobalColor canvas::getColor(QString colorStr)
{
    if(colorStr == "blue")
        return Qt::blue;
    else if(colorStr == "red")
        return Qt::red;
    else if(colorStr == "green")
        return Qt::green;
    else if(colorStr == "yellow")
        return Qt::yellow;
    else if(colorStr == "black")
        return Qt::black;
    else if(colorStr == "white")
        return Qt::white;
    else if(colorStr == "cyan")
        return Qt::cyan;
    else if(colorStr == "magenta")
        return Qt::magenta;
    else
        return Qt::gray;
}

Qt::PenCapStyle canvas::getPenCapStyle(QString capStr)
{

    if(capStr == "SquareCap")
        return Qt::SquareCap;
    else if(capStr == "FlatCap")
        return Qt::FlatCap;
    else
        return Qt::RoundCap;
}

Qt::PenStyle canvas::getPenStyle(QString penStr)
{
    if(penStr == "NoPen")
        return Qt::NoPen;
    else if(penStr == "SolidLine")
        return Qt::SolidLine;
    else if(penStr == "DashLine")
        return Qt::DashLine;
    else if(penStr == "DotLine")
        return Qt::DotLine;
    else if(penStr == "DashDotLine")
        return Qt::DashDotLine;
    else
        return Qt::DashDotDotLine;
}

Qt::PenJoinStyle canvas::getPenJointStyle(QString penJointStr)
{
    if(penJointStr == "MiterJoin")
        return Qt::MiterJoin;
    else if(penJointStr == "BevelJoin")
        return Qt::BevelJoin;
    else
        return Qt::RoundJoin;
}

Qt::BrushStyle canvas::getBrushStyle(QString brushStr)
{
    if(brushStr == "SolidPattern")
        return Qt::SolidPattern;
    else if(brushStr == "HorPattern")
        return Qt::HorPattern;
    else if(brushStr == "VerPattern")
        return Qt::VerPattern;
    else
        return Qt::NoBrush;
}

Qt::AlignmentFlag canvas::getFlag(QString flagStr)
{
    if(flagStr == "AlignLeft")
        return Qt::AlignLeft;
    else if(flagStr == "AlignRight")
        return Qt::AlignRight;
    else if(flagStr == "AlignTop")
        return Qt::AlignTop;
    else if(flagStr == "AlignBottom")
        return Qt::AlignBottom;
    else
        return Qt::AlignCenter;
}

QFont::Style canvas::getFontStyle(QString fontStyleStr)
{
    if(fontStyleStr == "StyleNormal")
        return QFont::StyleNormal;
    else if(fontStyleStr == "StyleItalic")
        return QFont::StyleItalic;
    else
        return QFont::StyleOblique;
}

QFont::Weight canvas::getFontWeight(QString fontWeightStr)
{
    if(fontWeightStr == "Thin")
        return QFont::Thin;
    else if(fontWeightStr == "Light")
        return QFont::Light;
    else if(fontWeightStr == "Normal")
        return QFont::Normal;
    else
        return QFont::Bold;
}

QString canvas::getStringColor(QColor color)
{
    if(color == Qt::blue)
        return "blue";
    else if(color == Qt::red)
        return "red";
    else if(color == Qt::green)
        return "green";
    else if(color == Qt::yellow)
        return "yellow";
    else if(color == Qt::black)
        return "black";
    else if(color == Qt::white)
        return "white";
    else if(color == Qt::cyan)
        return "cyan";
    else if(color == Qt::magenta)
        return "magenta";
    else
        return "gray";
}


QString canvas::getStringPenCap(Qt::PenCapStyle penStyle)
{
    if(penStyle == Qt::FlatCap)
        return "FlatCap";
    else if(penStyle == Qt::SquareCap)
        return "SquareCap";
    else
        return "RoundCap";
}

QString canvas::getStringPenStyle(Qt::PenStyle penStyle)
{
    if(penStyle == Qt::NoPen)
        return "NoPen";
    else if(penStyle == Qt::SolidLine)
        return "SolidLine";
    else if(penStyle == Qt::DashLine)
        return "DashLine";
    else if(penStyle == Qt::DotLine)
        return "DotLine";
    else if(penStyle == Qt::DashDotLine)
        return "DashDotLine";
    else
        return "DashDotDotLine";
}

QString canvas::getStringPenJointStyle(Qt::PenJoinStyle penJointStyle)
{
    if(penJointStyle == Qt::MiterJoin)
        return "MiterJoin";
    else if(penJointStyle == Qt::BevelJoin)
        return "BevelJoin";
    else
        return "RoundJoin";
}

QString canvas::getStringBrush(Qt::BrushStyle brush)
{
    if(brush == Qt::SolidPattern)
        return "SolidPattern";
    else if(brush == Qt::HorPattern)
        return "HorPattern";
    else if(brush == Qt::VerPattern)
        return "VerPattern";
    else
        return "NoBrush";
}

QString canvas::getStringFlag(Qt::AlignmentFlag  flag)
{
    if(flag == Qt::AlignLeft )
        return "AlignLeft";
    else if(flag == Qt::AlignRight)
        return "AlignRight";
    else if(flag == Qt::AlignTop)
        return "AlignTop";
    else if(flag == Qt::AlignBottom)
        return "AlignBottom";
    else
        return "AlignCenter";
}

 QString canvas::getStringFontStyle(QFont::Style fontStyle)
{
    if(fontStyle == QFont::StyleNormal)
        return "StyleNormal";
    else if(fontStyle == QFont::StyleItalic)
        return "StyleItalic";
    else
        return "StyleOblique";
}

QString canvas::getStringFontWeight(int fontWeight)
{
    if(fontWeight == 0)
        return "Thin";
    else if(fontWeight == 25)
        return "Light";
    else if(fontWeight == 50)
        return "Normal";
    else
        return "Bold";
}
