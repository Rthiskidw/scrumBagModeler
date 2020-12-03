#ifndef QT2STRINGCONVERSION_H
#define QT2STRINGCONVERSION_H
#include "shape.h"

string penColorString(QString color);

string penStyleString(Qt::PenStyle style);

string penCapStyleString(Qt::PenCapStyle capStyle);

string penJoinStyleString(Qt::PenJoinStyle joinStyle);

string brushStringStyle(Qt::BrushStyle brushStyle);

string alignmentStringConversion(Qt::AlignmentFlag align);

string fontStyleStringConversion(QFont::Style fontStyle);

string brushStyleStringConversion(Qt::BrushStyle brushStyle);

string fontWeightStringConversion(int fontWeight);

#endif // QT2STRINGCONVERSION_H
