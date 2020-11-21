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
    else if(brushStyle == "SolidPattern")
    {
        tempBrush = Qt::SolidPattern;
    }

    return tempBrush;
}
