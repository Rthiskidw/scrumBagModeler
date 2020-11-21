#include "shapeparser.h"

string getStringFromFile(ifstream &file)
{
    string temp;

    file.ignore(numeric_limits<streamsize>::max(),' ');
    getline(file, temp, '\n');

    return temp;
}

Shapes* getShapePtr(string shapeType)
{
    Shapes* shapePtr = nullptr;

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
    }


    return shapePtr;
}

void parseShape(vector<Shapes*>& vShapeList)
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

        Shapes *shapePtr = nullptr;
        shapePtr = getShapePtr(tempName);

        if(tempName == "Text")
        {
            QFont::Bold
            string color = getStringFromFile(dataFile);
            shapePtr -> setText(getStringFromFile(dataFile));




        }
        else
        {
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

            shapePtr->set_pen(pen);

            if(tempName != "Line" && tempName != "Polyline")
            {
                QBrush brush;

                string brushColor = getStringFromFile(dataFile);
                string brushStyle = getStringFromFile(dataFile);

                brush.setColor(QColor(brushColor.c_str()));
                brush.setStyle(brushStyleConversion(brushStyle));

                shapePtr-> set_brush(brush);
            }
        }
        int dimensions;

        vector<int> vDimensions;

        istringstream buffer(dimensionsString);

        while(buffer >> dimensions)
        {
            vDimensions.push_back(dimensions);

            if((buffer >> std::ws).peek() == ',')
            {
                buffer.ignore();
            }
        }

        tempNumDimensions = vDimensions.size();

        shapePtr ->setInfo(tempId, tempName, tempNumDimensions, vDimensions);

        vShapeList.push_back(shapePtr);

        dataFile.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    dataFile.close();
}
