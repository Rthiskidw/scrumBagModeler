#include "qt2stringconversion.h"

string penColorString(QString color)
{
    string tempColor;
    if(color == "#00ff00")
    {
        tempColor = "green";
    }
    else if(color == "#0000ff")
    {
        tempColor = "blue";
    }
    else if(color == "#00ffff")
    {
        tempColor = "cyan";
    }
    else if(color == "#ff0000")
    {
        tempColor = "red";
    }
    else if(color == "#000000")
    {
        tempColor = "black";
    }
    else if(color == "#ffffff")
    {
        tempColor = "white";
    }
    else if(color == "#ffff00")
    {
        tempColor = "yellow";
    }
    else if(color == "#ff00ff")
    {
        tempColor = "magenta";
    }

    return tempColor;
}

string penStyleString(Qt::PenStyle style)
{
    string tempStyle;
    switch(style)
    {
    case Qt::SolidLine      : tempStyle = "SolidLine";
        break;
    case Qt::DashLine       : tempStyle = "DashLine";
        break;
    case Qt::DotLine        : tempStyle = "DotLine";
        break;
    case Qt::DashDotLine    : tempStyle = "DashDotLine";
        break;
    case Qt::DashDotDotLine : tempStyle = "DashDotDotLIne";
        break;
    }

    return tempStyle;
}

string penCapStyleString(Qt::PenCapStyle capStyle)
{
    string tempCapStyle;
    switch(capStyle)
    {
    case Qt::FlatCap   : tempCapStyle = "FlatCap";
        break;
    case Qt::SquareCap : tempCapStyle = "SquareCap";
        break;
    case Qt::RoundCap  : tempCapStyle = "RoundCap";
        break;
    }

    return tempCapStyle;
}

string penJoinStyleString(Qt::PenJoinStyle joinStyle)
{
    string tempJoinStyle;
    switch (joinStyle)
    {
    case Qt::BevelJoin : tempJoinStyle = "BevelJoin";
        break;
    case Qt::MiterJoin : tempJoinStyle = "MiterJoin";
        break;
    case Qt::RoundJoin : tempJoinStyle = "RoundJoin";
        break;
    }

    return tempJoinStyle;
}

string alignmentStringConversion(Qt::AlignmentFlag align)
{
    string tempFlag;
    switch (align)
    {
    case Qt::AlignCenter : tempFlag = "AlignCenter";
        break;
    case Qt::AlignRight  : tempFlag = "AlignRight";
        break;
    case Qt::AlignLeft   : tempFlag = "AlignLeft";
        break;
    }

    return tempFlag;
}

string fontStyleStringConversion(QFont::Style fontStyle)
{
    string tempStyle;
    switch (fontStyle)
    {
    case QFont::StyleNormal : tempStyle = "SquareCap";
        break;
    case QFont::StyleItalic : tempStyle = "FlatCap";
        break;
    case QFont::StyleOblique : tempStyle = "RoundCap";
        break;
    }

    return tempStyle;
}

string brushStyleStringConversion(Qt::BrushStyle brushStyle)
{
    string tempBrushStyle;
    switch (brushStyle)
    {
    case Qt::SolidPattern : tempBrushStyle = "SolidPattern";
        break;
    case Qt::VerPattern   : tempBrushStyle = "VerPattern";
        break;
    case Qt::HorPattern   : tempBrushStyle = "HorPattern";
        break;
    case Qt::NoBrush      : tempBrushStyle = "NoBrush";
        break;
    case Qt::CrossPattern : tempBrushStyle = "CrossPattern";
        break;
    }

    return tempBrushStyle;
}

string fontWeightStringConversion(int fontWeight)
{
    string tempFontWeight;
    switch (fontWeight)
    {
    case 0  : tempFontWeight = "Thin";
        break;
    case 50 : tempFontWeight = "Normal";
        break;
    case 75 : tempFontWeight = "Bold";
        break;
    }

    return tempFontWeight;
}
