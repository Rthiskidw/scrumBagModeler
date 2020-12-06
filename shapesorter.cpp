#include "shapesorter.h"



stringstream seriallizer(Shapes_Vector<Shapes*>& vShapeList)
{
    stringstream outString;

    for ( Shapes* shape : vShapeList)
    {
        QPen tempPen = shape->get_pen();
        QColor penColor = tempPen.color();
        QString colorCode = penColor.name();

        outString << "ShapeId: " + to_string(shape->get_id());

        if(shape-> get_shape() == Shapes::ShapeType::Text)
        {

            qInfo() << "Testing Pen Color" << colorCode;

            int *dimensions = shape->getDimensions();
            Text *tempText = dynamic_cast<Text *>(shape);
            QFont font = tempText->get_text_font();
            outString << "\nShapeType: Text";
            outString << "\nShapeDimensions: ";
            for(int index = 0; index < 4; index++)
            {
                if(index != 3)
                    outString << to_string(dimensions[index]) << ", ";
                else
                    outString << to_string(dimensions[index]);
            }
            outString << "\nTextString: " << tempText->get_text_string().toStdString()
                    << "\nTextColor : " << penColorString(colorCode)
                    << "\nTextAlignment: " << alignmentStringConversion(tempText->get_alignment_flag())
                    << "\nTextPointSize: " << to_string(font.pointSize())
                    << "\nTextFontFamily: " << font.family().toStdString()
                    << "\nTextFontStyle: " << fontStyleStringConversion(font.style())
                    << "\nTextFontWeight: " << fontWeightStringConversion(font.weight())
                    << "\n\n";

        }
        else if(shape-> get_shape() == Shapes::ShapeType::Line ||
                shape-> get_shape() == Shapes::ShapeType::Polyline)
        {
            int *dimensions = shape->getDimensions();

            if(shape-> get_shape() == Shapes::ShapeType::Line)
            {
                outString <<"\nShapeType: Line";
                outString <<"\nShapeDimensions: " + to_string(dimensions[0]) + ", " + to_string(dimensions[1]) + ", " + to_string(dimensions[2]) + ", " + to_string(dimensions[3]);
            }
            else
            {
                outString<<"\nShapeType: Polyline";
                outString << "\nShapeDimensions: ";
                for(int index = 0; index < 8; index++)
                {
                    if(index != 7)
                        outString << to_string(dimensions[index]) << ", ";
                    else
                        outString << to_string(dimensions[index]);
                }
            }
            outString <<"\nPenColor: " << penColorString(colorCode)
                    <<"\nPenWidth: " << to_string(tempPen.width())
                    <<"\nPenStyle: " << penStyleString(tempPen.style())
                    <<"\nPenCapStyle: " << penCapStyleString(tempPen.capStyle())
                    <<"\nPenJoinStyle: " << penJoinStyleString(tempPen.joinStyle())
                    <<"\n\n";
        }
        else
        {
            int *dimensions = shape->getDimensions();
            QBrush brush = shape->get_brush();
            QColor brushColor = brush.color();
            QString brushColorCode = brushColor.name();
            qInfo() << "TESTING BRUSH COLOR NAME " << brushColorCode << "\n";

            if(shape-> get_shape() == Shapes::ShapeType::Polygon)
            {
                outString<<"\nShapeType: Polygon";
                outString << "\nShapeDimensions: ";
                for(int index = 0; index < 8; index++)
                {
                    if(index != 7)
                        outString << to_string(dimensions[index]) << ", ";
                    else
                        outString << to_string(dimensions[index]);
                }
            }
            else if(shape-> get_shape() == Shapes::ShapeType::Rectangle)
            {
                if( dimensions[2] == dimensions[3])
                {
                    outString << "\nShapeType: Square";
                    outString << "\nShapeDimensions: ";
                    for(int index = 0; index < 3; index++)
                    {
                        if(index != 2)
                            outString << to_string(dimensions[index]) << ", ";
                        else
                            outString << to_string(dimensions[index]);
                    }
                }
                else
                {
                    outString<<"\nShapeType: Rectangle";
                    outString << "\nShapeDimensions: ";
                    for(int index = 0; index < 4; index++)
                    {
                        if(index != 3)
                            outString << to_string(dimensions[index]) << ", ";
                        else
                            outString << to_string(dimensions[index]);
                    }
                }
            }
            else if(shape-> get_shape() == Shapes::ShapeType::Ellipse)
            {
                if( dimensions[2] == dimensions[3])
                {
                    outString << "\nShapeType: Circle";
                    outString << "\nShapeDimensions: ";
                    for(int index = 0; index < 3; index++)
                    {
                        if(index != 2)
                            outString << to_string(dimensions[index]) << ", ";
                        else
                            outString << to_string(dimensions[index]);
                    }
                }
                else
                {
                    outString<<"\nShapeType: Ellipse";
                    outString << "\nShapeDimensions: ";
                    for(int index = 0; index < 4; index++)
                    {
                        if(index != 3)
                            outString << to_string(dimensions[index]) << ", ";
                        else
                            outString << to_string(dimensions[index]);
                    }
                }
            }
            outString <<"\nPenColor: " << penColorString(colorCode)
                    <<"\nPenWidth: " << to_string(tempPen.width())
                    <<"\nPenStyle: " << penStyleString(tempPen.style())
                    <<"\nPenCapSyle: " << penCapStyleString(tempPen.capStyle())
                    <<"\nPenJoinStyle: " << penJoinStyleString(tempPen.joinStyle())
                    <<"\nBrushColor: " << penColorString(brushColorCode)
                    <<"\nBrushStyle: " << brushStyleStringConversion(brush.style())
                    <<"\n\n";
        }
    }
    return outString;
}

