#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include "shape.h"
#include "vector.h"
#include "canvas.h"
#include "rectangle.h"
#include "textBox.h"
#include "line.h"
#include "ellipses.h"
#include "polyline.h"
#include "polygon.h"
#include "qtconversions.h"
#include "qt2stringconversion.h"
#include <iostream>
#include <string>
#include <ios>
#include <limits>
#include <fstream>
#include <vector>
#include <sstream>
#include <QDebug>
#include <QFile>
using namespace std;

class Shape_Parser
{
public:
    Shape_Parser();
    ~Shape_Parser();

    //! Gets a single line from the input file.
    /*! Reads in each line of the input file as one string, then parses it individually for information.
     * \param file the input filestream variable
     * \returns The relevant parsed data as a string
     */
    string getStringFromFile(ifstream &file);

    //! Creates a pointer of type Shape that relates to a specific derived class object via inheritance & polymorphism
    /*! Depending on the type of shape dictated in the file, returns a pointer to that type of shape.
     *! Initialized the shapes data field with an alternate constructor
     * \param shapeType the type of shape, as a string
     * \param color the color of the shape
     * \param penWidth the width of the QPen
     * \param penStyle the style of the QPen
     * \param capStyle the cap style of the QPen
     * \param joinStyle the join style of the QPen
     * \param the color of the QBrush
     * \param the style of the QBrush
     * \param the number of Dimensions
     * \param an array containing the Dimensions
     * \returns The Shape pointer to the specific shape dictated by shapeType.
     */
    Shapes* getShapePtr(string shapeType, string color, int penWidth, string penStyle, string capStyle,
                        string joinStyle, string brushColor, string brushStyle, int tempNumDimensions, int *tempDimensions);

    //! Reads in shapes and populates the shape vector from a file
    /*! Reads through the entire file and populates the shape vector with Shape pointers holding shape specifications and properties.
     * Tracks the number of shapes that are entering the vector.
     * \param v_shapes the vector of Shape pointers, passed in by reference
     */
    void parseShape(Shapes_Vector<Shapes*>& vShapeList);

    //! Goes through a list of shapes and outputs all its contents to "shapes.txt"
    /*! Updates the textfile with any new changes to the shapes
     * \param vShapeList the vector of that contains all the shapes
     */
    void seriallizer(Shapes_Vector<Shapes*>& vShapeList, int numShapes);

private:
    int dimensions[10];
    int dimensions_count;
    QString ShapeFileName;
    int ShapeId;
    QString Dimensions;
    QString ShapeType;
    int PenColor;
    int PenWidth;
    int PenStyle;
    int PenCapStyle;
    int PenJoinStyle;
    int BrushColor;
    int BrushStyle;
    QString TextQstring;
    int TextColor;
    int TextAlignment;
    int TextPointSize;
    int TextFontFamily;
    int TextFontStyle;
    int TextFontWeight;
};

#endif // SHAPEPARSER_H
