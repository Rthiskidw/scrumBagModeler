#include "qtconversions.h"

Qt::PenStyle penStyleConversion(string style)
{
    Qt::PenStyle tempStyle;

    if(style == "NoPen")
    {
        tempStyle = Qt::NoPen;
    }
    else if(style == "SolidLine")
    {
        tempStyle = Qt::SolidLine;
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
        tempStyle = Qt::DashDotLine;
    }
    else if(style == "DashDotDotLine")
    {
        tempStyle = Qt::DashDotDotLine;
    }

    return tempStyle;
}

Qt::PenCapStyle penCapConversion(string capStyle)
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
        tempJoin = Qt::MiterJoin;
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
    else if(brushStyle == "CrossPattern")
    {
        tempBrush = Qt::CrossPattern;
    }

    return tempBrush;
}

Qt::GlobalColor colorConversion(string color)
{
    Qt::GlobalColor tempColor;

    if(color == "blue")
    {
        tempColor = Qt::blue;
    }
    else if(color == "green")
    {
        tempColor = Qt::green;
    }
    else if(color == "cyan")
    {
        tempColor = Qt::cyan;
    }
    else if(color == "red")
    {
        tempColor = Qt::red;
    }
    else if(color == "black")
    {
        tempColor = Qt::black;
    }
    else if(color == "magenta")
    {
        tempColor = Qt::magenta;
    }

    return tempColor;
}

Qt::AlignmentFlag alignmentConversion(string align)
{
    Qt::AlignmentFlag tempFlag;
    if(align == "AlignLeft")
    {
        tempFlag = Qt::AlignLeft;
    }
    else if(align == "AlignCenter")
    {
        tempFlag = Qt::AlignCenter;
    }
    else if(align == "AlignRight")
    {
        tempFlag = Qt::AlignRight;
    }
    return tempFlag;
}

QFont::Weight fontWeightConversion(string fontWeight)
{
    QFont::Weight tempWeight;
    if(fontWeight == "Thin")
    {
        tempWeight = QFont::Thin;
    }
    else if(fontWeight == "Normal")
    {
        tempWeight = QFont::Normal;
    }
    else if(fontWeight == "Bold")
    {
        tempWeight = QFont::Bold;
    }

    return tempWeight;
}

QFont::Style fontStyleConversion(string fontStyle)
{
    QFont::Style tempStyle;
    if(fontStyle == "SquareCap")
    {
        tempStyle = QFont::StyleNormal;
    }
    else if(fontStyle == "FlatCap")
    {
        tempStyle = QFont::StyleItalic;
    }
    else if(fontStyle == "RoundCap")
    {
        tempStyle = QFont::StyleOblique;
    }

    return tempStyle;
}

