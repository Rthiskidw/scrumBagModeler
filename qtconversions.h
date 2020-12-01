#ifndef QTCONVERSIONS_H
#define QTCONVERSIONS_H

#include "shape.h"


Qt::PenStyle penStyleConversion(string style);

Qt::PenCapStyle penCapConversion(string capStyle);

Qt::PenJoinStyle penJoinConversion(string joinStyle);

Qt::BrushStyle brushStyleConversion(string brushStyle);

Qt::GlobalColor colorConversion(string color);

Qt::AlignmentFlag alignmentConversion(string align);

QFont::Weight fontWeightConversion(string fontWeight);

QFont::Style fontStyleConversion(string fontStyle);

#endif // QTCONVERSIONS_H
