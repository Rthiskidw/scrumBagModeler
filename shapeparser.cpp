#include "shapeparser.h"
#include <vector>

string getStringFromFile(ifstream &file)
{
    string temp;

    file.ignore(numeric_limits<streamsize>::max(),' ');
    getline(file, temp, '\n');

    return temp;
}

Shapes* getShapePtr(string shapeType, string color, int penWidth, string penStyle, string capStyle,
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
        QPoint *values;
        values = new QPoint[tempNumDimensions / 2];
        for(int index = 0; index < tempNumDimensions/2; index++)
        {
            values[index] = QPoint(tempDimensions[index], tempDimensions[index + 1]);
        }
        shapePtr = new Polyline(colorConversion(color), penStyleConversion(penStyle), penCapConversion(capStyle), penJoinConversion(joinStyle),
                                colorConversion(brushColor), brushStyleConversion(brushStyle), (tempNumDimensions/2), values);
        shapePtr->set_shape(Shapes::ShapeType::Polyline);
        shapePtr->set_width(penWidth);
    }
    else if(shapeType == "Polygon")
    {
//        shapePtr = new Polygon();
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
        QFont font;
        font.setStyle(fontStyleConversion(brushColor));
        font.setWeight(fontWeightConversion(brushStyle));
        font.setFamily(joinStyle.c_str());
        QString textString =QString::fromStdString(penStyle);

        shapePtr = new Text(colorConversion(color), textString, font, QPoint(tempDimensions[0], tempDimensions[1]), alignmentConversion(capStyle), tempDimensions[2], tempDimensions[3] );
    }


    return shapePtr;
}

void parseShape(std::vector<Shapes*>& vShapeList)
{
    int    tempId = 0;
    int    tempNumDimensions = 0;
    string tempName;
    string dimensionsString;

    ifstream dataFile;
    dataFile.open("shapes.txt");

    while(dataFile)
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

        for(int index = 0; index < vDimensions.size(); index++)
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

            QFont font;
            font.setWeight(23);
            font.setItalic(5);


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
    }

    dataFile.close();
}

