<<<<<<< HEAD
#include "shapeparser.h"
#include <vector>
=======
#include "shapeParser.h"
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2

string getStringFromFile(ifstream &file)
{
    string temp;

    file.ignore(numeric_limits<streamsize>::max(),' ');
    getline(file, temp, '\n');

    return temp;
}

<<<<<<< HEAD
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
=======
Shape* getShapePtr(string shapeType)
{
    Shape* shapePtr = nullptr;

    if(shapeType == SHAPE_LIST[LINE])
    {
        shapePtr = new Line();
    }
    else if(shapeType == SHAPE_LIST[POLYLINE])
    {
        shapePtr = new Polyline();
    }
    else if(shapeType == SHAPE_LIST[POLYGON])
    {
        shapePtr = new Polygon();
    }
    else if(shapeType == SHAPE_LIST[RECTANGLE])
    {
        shapePtr = new Rectangle();
    }
    else if(shapeType == SHAPE_LIST[SQUARE])
    {
        shapePtr = new Square();
    }
    else if(shapeType == SHAPE_LIST[ELLIPSE])
    {
        shapePtr = new Ellipse();
    }
    else if(shapeType == SHAPE_LIST[CIRCLE])
    {
        shapePtr = new Circle();
    }
    else if(shapeType == SHAPE_LIST[TEXT])
    {
        shapePtr = new Text();
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2
    }


    return shapePtr;
}

<<<<<<< HEAD
void parseShape(std::vector<Shapes*>& vShapeList)
=======
void parseShape(vector<Shape*>& vShapeList)
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2
{
    int    tempId = 0;
    int    tempNumDimensions = 0;
    string tempName;
    string dimensionsString;

    ifstream dataFile;
<<<<<<< HEAD
    dataFile.open("shapes.txt");
=======
    dataFile.open("Shapes");
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2

    while(dataFile)
    {
        tempId = stoi(getStringFromFile(dataFile));

        tempName = getStringFromFile(dataFile);

        dimensionsString = getStringFromFile(dataFile);

<<<<<<< HEAD
        int dimensions;

        std::vector<int> vDimensions;
=======
        Shape *shapePtr = nullptr;
        shapePtr = getShapePtr(tempName);

        int dimensions;

        vector<int> vDimensions;
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2

        istringstream buffer(dimensionsString);

        while(buffer >> dimensions)
        {
            vDimensions.push_back(dimensions);

<<<<<<< HEAD
            if((buffer >> std::ws).peek() == ',')
=======
            char cTemp = buffer.peek();
            if(cTemp == ",")
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2
            {
                buffer.ignore();
            }
        }

<<<<<<< HEAD
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
=======
        tempNumDimensions = vDimensions.size();

        shapePtr ->setInfo(tempId, tempName, tempNumDimensions, vDimensions);

        QPen pen;

        string color = getStringFromFile(dataFile);
        int penWidth = stoi(getStringFromFile(dataFile));
        string penStyle = getStringFromFile(dataFile);
        string capStyle = getStringFromFile(dataFile);
        string joinStyle = getStringFromFile(dataFile);

        pen.setColor(QColor(color.c_str()));
        pen.setWidth(penWidth);
        pen.setStyle(penStyleConversion(penStyle));
        pen.setCapStyle(penCapConversion(capStyle));
        pen.setJoinStyle(penJoinConversion(joinStyle));

        shapePtr->setPen(pen);

        if(tempName != "Line" && tempName != "Polyline")
        {
            Qbrush brush;

            string brushColor = getStringFromFile(dataFile);
            string brushStyle = getStringFromFile(dataFile);

            brush.setColor(QColor(brushColor.c_str()));
            brush.setStyle(brushStyleConversion(brushStyle));

            shapePtr-> setBrush(brush);
        }
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2

        vShapeList.push_back(shapePtr);

        dataFile.ignore(numeric_limits<streamsize>::max(), '\n');
    }
<<<<<<< HEAD

    dataFile.close();
}

=======
}

Qt::PenStyle penStyleConversion(string style)
{
    Qt::PenStyle tempStyle;

    if(style == "NoPen")
    {
        tempStyle = Qt::NoPen;
    }
    else if(style == "SolidLine")
    {
        tempStyle = Qt::SolidLIne;
    }
    else if(style == "DashLine")
    {
        tempStyle = Qt::DashLine;
    }
    else if(style == "DotLine")
    {
        tempStyle = Qt::DotLine;
    }
    else if(style == "DashDotLine")
    {
        tempStyle = Qt::DashDotLine(3);
    }
    else if(style == "DashDotDotLine")
    {
        tempStyle = Qt::DashDotDotLine;
    }

    return tempStyle;
}

Qt::PenCapStyle penStyleConversion(string capStyle)
{
    Qt::PenCapStyle tempCap;

    if(capStyle == "FlatCap")
    {
        tempCap = Qt::FlatCap;
    }
    else if(capStyle == "SquareCap")
    {
        tempCap = Qt::SquareCap;
    }
    else if(capStyle == "RoundCap")
    {
        tempCap = Qt::RoundCap;
    }

    return tempCap;
}

Qt::PenJoinStyle penJoinConversion(string joinStyle)
{
    Qt::PenJoinStyle tempJoin;

    if(joinStyle == "MiterJoin")
    {
        tempJoin = Qt::MilterJoin;
    }
    else if(joinStyle == "BevelJoin")
    {
        tempJoin = Qt::BevelJoin;
    }
    else if(joinStyle == "RoundJoin")
    {
        tempJoin = Qt::RoundJoin;
    }
    else if(joinStyle == "SvgMiterJoin")
    {
        tempJoin = Qt::SvgMiterJoin;
    }

    return tempJoin;
}

Qt::BrushStyle brushStyleConversion(string brushStyle)
{
    Qt::BrushStyle tempBrush;

    if(brushStyle == "SolidPattern")
    {
        tempBrush = Qt::SolidPattern;
    }
    else if(brushStyle == "VerPattern")
    {
        tempBrush = Qt::VerPattern;
    }
    else if(brushStyle == "HorPattern")
    {
        tempBrush = Qt::HorPattern;
    }
    else if(brushStyle == "NoBrush")
    {
        tempBrush = Qt::NoBrush;
    }
    else if(brushStyle == "SolidPattern")
    {
        tempBrush = Qt::SolidPattern;
    }

    return tempBrush;
}
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2
