#include "shapeparser.h"

#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "polyline.h"
#include "polygon.h"
#include "ellipses.h"
#include "textBox.h"
#include <vector>

//!Gets a single string from the input file and extracts the useful information
//! Retruns this information as a string
Shape_Parser::Shape_Parser()
{

}
Shape_Parser::~Shape_Parser()
{

}
string Shape_Parser::getStringFromFile(ifstream &file)
{
    string temp;

    file.ignore(numeric_limits<streamsize>::max(),' ');
    getline(file, temp, '\n');

    return temp;
}

//! Gets a pointer to a new polymorphic shape depending on the string passed in
//! Initializes the new shape with the data passed in the parameters
Shapes* Shape_Parser::getShapePtr(string shapeType, string color, int penWidth, string penStyle, string capStyle,
                    string joinStyle, string brushColor, string brushStyle, int tempNumDimensions, int *tempDimensions)
{
    Shapes* shapePtr = nullptr;

    if(shapeType == "Line")
    {
        shapePtr = new Line(colorConversion(color), penStyleConversion(penStyle), penCapConversion(capStyle), penJoinConversion(joinStyle),
                            colorConversion(brushColor), brushStyleConversion(brushStyle), QPoint(tempDimensions[0], tempDimensions[1]), QPoint(tempDimensions[2], tempDimensions[3]));
        shapePtr->set_shape(Shapes::ShapeType::Line);
        shapePtr->set_width(penWidth);

    }
    else if(shapeType == "Polyline")
    {
        //Creats an array of QPoints
        QPoint *values;
        values = new QPoint[tempNumDimensions / 2];
        int q = 0;
        int p = 1;

        for(int index = 0; index < (tempNumDimensions/2); index++)
        {

            values[index] = QPoint(tempDimensions[index + q], tempDimensions[index + p]);

            ++q;
            ++p;
        }

        shapePtr = new Polyline(colorConversion(color), penStyleConversion(penStyle), penCapConversion(capStyle), penJoinConversion(joinStyle),
                                colorConversion(brushColor), brushStyleConversion(brushStyle), (tempNumDimensions/2), values);
        shapePtr->set_shape(Shapes::ShapeType::Polyline);
        shapePtr->set_width(penWidth);
    }
    else if(shapeType == "Polygon")
    {
        //Creats an array of QPoints
        QPoint *values;
        values = new QPoint[tempNumDimensions / 2];
        int q = 0;
        int p = 1;

        for(int index = 0; index < (tempNumDimensions/2); index++)
        {

            values[index] = QPoint(tempDimensions[index + q], tempDimensions[index + p]);

            ++q;
            ++p;
        }

        shapePtr = new Polygon(colorConversion(color), penStyleConversion(penStyle), penCapConversion(capStyle), penJoinConversion(joinStyle),
                               colorConversion(brushColor), brushStyleConversion(brushStyle), (tempNumDimensions/2), values);
        shapePtr->set_shape(Shapes::ShapeType::Polygon);
        shapePtr->set_width(penWidth);
    }
    else if(shapeType == "Rectangle")
    {
        shapePtr = new Rectangle(colorConversion(color), penStyleConversion(penStyle), penCapConversion(capStyle), penJoinConversion(joinStyle),
                                 colorConversion(brushColor), brushStyleConversion(brushStyle), tempDimensions[0], tempDimensions[1], tempDimensions[2], tempDimensions[3]);
        shapePtr->set_shape(Shapes::ShapeType::Rectangle);
        shapePtr->set_width(penWidth);
    }
    else if(shapeType == "Square")
    {
        shapePtr = new Rectangle(colorConversion(color), penStyleConversion(penStyle), penCapConversion(capStyle), penJoinConversion(joinStyle),
                                 colorConversion(brushColor), brushStyleConversion(brushStyle), tempDimensions[0], tempDimensions[1], tempDimensions[2], tempDimensions[2]);
        shapePtr->set_shape(Shapes::ShapeType::Rectangle);
        shapePtr->set_width(penWidth);
    }
    else if(shapeType == "Ellipse")
    {

        shapePtr = new Ellipse(colorConversion(color), penStyleConversion(penStyle), penCapConversion(capStyle), penJoinConversion(joinStyle),
                               colorConversion(brushColor), brushStyleConversion(brushStyle), tempDimensions[0], tempDimensions[1], tempDimensions[2], tempDimensions[3]);
        shapePtr->set_shape(Shapes::ShapeType::Ellipse);
        shapePtr->set_width(penWidth);
    }
    else if(shapeType == "Circle")
    {
        shapePtr = new Ellipse(colorConversion(color), penStyleConversion(penStyle), penCapConversion(capStyle), penJoinConversion(joinStyle),
                               colorConversion(brushColor), brushStyleConversion(brushStyle), tempDimensions[0], tempDimensions[1], tempDimensions[2], tempDimensions[2]);
        shapePtr->set_shape(Shapes::ShapeType::Ellipse);
        shapePtr->set_width(penWidth);
    }
    else if(shapeType == "Text")
    {
        //initializes a Qfont, sets the style and weight and family
        //and is passed to set the font of the shape
        QFont font;
        font.setStyle(fontStyleConversion(brushColor));
        font.setWeight(fontWeightConversion(brushStyle));
        font.setFamily(joinStyle.c_str());
        font.setPointSize(penWidth);
        //converts string to QString
        QString textString = QString::fromStdString(penStyle);

        shapePtr = new Text(colorConversion(color), textString, font, QPoint(tempDimensions[0], tempDimensions[1]),
                            alignmentConversion(capStyle), tempDimensions[2], tempDimensions[3] );
        shapePtr->set_shape(Shapes::ShapeType::Text);
    }
    return shapePtr;
}

void Shape_Parser::parseShape(Shapes_Vector<Shapes*>& vShapeList)
{
    int    index = 0;
    int    tempId = 0;
    int    tempNumDimensions = 0;
    string tempName;
    string dimensionsString;

    ifstream dataFile;
    dataFile.open("shapes.txt");

    while(dataFile.good())
    {
        tempId = stoi(getStringFromFile(dataFile));

        tempName = getStringFromFile(dataFile);

        dimensionsString = getStringFromFile(dataFile);

        int dimensions;

        std::vector<int> vDimensions;

        istringstream buffer(dimensionsString);

        while(buffer >> dimensions)
        {
            vDimensions.push_back(dimensions);

            if((buffer >> std::ws).peek() == ',')
            {
                buffer.ignore();
            }
        }

        int *tempDimensions;
        tempDimensions = new int[vDimensions.size()];

        tempNumDimensions = vDimensions.size();

        for(int index = 0; index < tempNumDimensions; index++)
        {
            tempDimensions[index] = vDimensions[index];
        }

        Shapes *shapePtr = nullptr;

        if(tempName == "Text")
        {
            string textString = getStringFromFile(dataFile);
            string textColor  = getStringFromFile(dataFile);
            string textAlignment = getStringFromFile(dataFile);
            int textPointSize = stoi(getStringFromFile(dataFile));
            string textFamily = getStringFromFile(dataFile);
            string textFontStyle  = getStringFromFile(dataFile);
            string fontWeight = getStringFromFile(dataFile);

            shapePtr = getShapePtr(tempName, textColor, textPointSize, textString, textAlignment, textFamily,
                                   textFontStyle, fontWeight, tempNumDimensions, tempDimensions);
        }
        else
        {
            string color = getStringFromFile(dataFile);
            int penWidth = stoi(getStringFromFile(dataFile));
            string penStyle = getStringFromFile(dataFile);
            string capStyle = getStringFromFile(dataFile);
            string joinStyle = getStringFromFile(dataFile);

            string brushColor = "black";
            string brushStyle = "NoBrush";

            if(tempName != "Line" && tempName != "Polyline")
            {
                QBrush brush;

                brushColor = getStringFromFile(dataFile);
                brushStyle = getStringFromFile(dataFile);
            }
            shapePtr = getShapePtr(tempName, color, penWidth, penStyle, capStyle, joinStyle,
                                   brushColor, brushStyle, tempNumDimensions, tempDimensions);
        }
        shapePtr->set_id(tempId);

        vShapeList.push_back(shapePtr);

        dataFile.ignore(numeric_limits<streamsize>::max(), '\n');
        index++;
    }

    dataFile.close();
}

void Shape_Parser::seriallizer(Shapes_Vector<Shapes*>& vShapeList, int numShapes)
{

    ofstream outFile;
    outFile.open("shapes.txt");

    for (int index = 0; index < numShapes; index++)
    {
        QPen tempPen = vShapeList[index]->get_pen();
        QColor penColor = tempPen.color();
        QString colorCode = penColor.name();

        outFile << "ShapeId: " + to_string(vShapeList[index]->get_id());

        if(vShapeList[index]-> get_shape() == Shapes::ShapeType::Text)
        {

            qInfo() << "Testing Pen Color" << colorCode;

            int *dimensions = vShapeList[index]->getDimensions();
            Text *tempText = dynamic_cast<Text *>(vShapeList[index]);
            QFont font = tempText->get_text_font();
            outFile << "\nShapeType: Text";
            outFile << "\nShapeDimensions: ";
            for(int index = 0; index < 4; index++)
            {
                if(index != 3)
                    outFile << to_string(dimensions[index]) << ", ";
                else
                    outFile << to_string(dimensions[index]);
            }
            outFile << "\nTextString: " << tempText->get_text_string().toStdString()
                    << "\nTextColor: " << penColorString(colorCode)
                    << "\nTextAlignment: " << alignmentStringConversion(tempText->get_alignment_flag())
                    << "\nTextPointSize: " << to_string(font.pointSize())
                    << "\nTextFontFamily: " << font.family().toStdString()
                    << "\nTextFontStyle: " << fontStyleStringConversion(font.style())
                    << "\nTextFontWeight: " << fontWeightStringConversion(font.weight());
            if(index == numShapes -1)
            {
                outFile << "\n";
            }
            else
            {
                outFile << "\n\n";
            }

        }
        else if(vShapeList[index]-> get_shape() == Shapes::ShapeType::Line ||
                vShapeList[index]-> get_shape() == Shapes::ShapeType::Polyline)
        {
            int *dimensions = vShapeList[index]->getDimensions();

            if(vShapeList[index]-> get_shape() == Shapes::ShapeType::Line)
            {
                outFile <<"\nShapeType: Line";
                outFile <<"\nShapeDimensions: " + to_string(dimensions[0]) + ", " + to_string(dimensions[1]) + ", " + to_string(dimensions[2]) + ", " + to_string(dimensions[3]);
            }
            else
            {
                outFile<<"\nShapeType: Polyline";
                outFile << "\nShapeDimensions: ";
                for(int index = 0; index < 8; index++)
                {
                    if(index != 7)
                        outFile << to_string(dimensions[index]) << ", ";
                    else
                        outFile << to_string(dimensions[index]);
                }
            }
            outFile <<"\nPenColor: " << penColorString(colorCode)
                    <<"\nPenWidth: " << to_string(tempPen.width())
                    <<"\nPenStyle: " << penStyleString(tempPen.style())
                    <<"\nPenCapStyle: " << penCapStyleString(tempPen.capStyle())
                    <<"\nPenJoinStyle: " << penJoinStyleString(tempPen.joinStyle());
                      if(index == numShapes -1)
                      {
                          outFile << "\n";
                      }
                      else
                      {
                          outFile << "\n\n";
                      }
        }
        else
        {
            int *dimensions = vShapeList[index]->getDimensions();
            QBrush brush = vShapeList[index]->get_brush();
            QColor brushColor = brush.color();
            QString brushColorCode = brushColor.name();
            qInfo() << "TESTING BRUSH COLOR NAME " << brushColorCode << "\n";

            if(vShapeList[index]-> get_shape() == Shapes::ShapeType::Polygon)
            {
                outFile<<"\nShapeType: Polygon";
                outFile << "\nShapeDimensions: ";
                for(int index = 0; index < 8; index++)
                {
                    if(index != 7)
                        outFile << to_string(dimensions[index]) << ", ";
                    else
                        outFile << to_string(dimensions[index]);
                }
            }
            else if(vShapeList[index]-> get_shape() == Shapes::ShapeType::Rectangle)
            {
                if( dimensions[2] == dimensions[3])
                {
                    outFile << "\nShapeType: Square";
                    outFile << "\nShapeDimensions: ";
                    for(int index = 0; index < 3; index++)
                    {
                        if(index != 2)
                            outFile << to_string(dimensions[index]) << ", ";
                        else
                            outFile << to_string(dimensions[index]);
                    }
                }
                else
                {
                    outFile<<"\nShapeType: Rectangle";
                    outFile << "\nShapeDimensions: ";
                    for(int index = 0; index < 4; index++)
                    {
                        if(index != 3)
                            outFile << to_string(dimensions[index]) << ", ";
                        else
                            outFile << to_string(dimensions[index]);
                    }
                }
            }
            else if(vShapeList[index]-> get_shape() == Shapes::ShapeType::Ellipse)
            {
                if( dimensions[2] == dimensions[3])
                {
                    outFile << "\nShapeType: Circle";
                    outFile << "\nShapeDimensions: ";
                    for(int index = 0; index < 3; index++)
                    {
                        if(index != 2)
                            outFile << to_string(dimensions[index]) << ", ";
                        else
                            outFile << to_string(dimensions[index]);
                    }
                }
                else
                {
                    outFile<<"\nShapeType: Ellipse";
                    outFile << "\nShapeDimensions: ";
                    for(int index = 0; index < 4; index++)
                    {
                        if(index != 3)
                            outFile << to_string(dimensions[index]) << ", ";
                        else
                            outFile << to_string(dimensions[index]);
                    }
                }
            }
            outFile <<"\nPenColor: " << penColorString(colorCode)
                    <<"\nPenWidth: " << to_string(tempPen.width())
                    <<"\nPenStyle: " << penStyleString(tempPen.style())
                    <<"\nPenCapStyle: " << penCapStyleString(tempPen.capStyle())
                    <<"\nPenJoinStyle: " << penJoinStyleString(tempPen.joinStyle())
                    <<"\nBrushColor: " << penColorString(brushColorCode)
                    <<"\nBrushStyle: " << brushStyleStringConversion(brush.style());
                      if(index == numShapes -1)
                      {
                          outFile << "\n";
                      }
                      else
                      {
                          outFile << "\n\n";
                      }
        }

    }
    outFile.close();
}
