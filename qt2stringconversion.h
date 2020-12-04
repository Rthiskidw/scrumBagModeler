#ifndef QT2STRINGCONVERSION_H
#define QT2STRINGCONVERSION_H
#include "shape.h"

//! Takes in a QString color code
/*!
 *\param color the QString to search for the color string to return
 *\return A string used in the serializer to output the pen and brush color to shapes.txt
 */
string penColorString(QString color);

//! Takes in a Qt::PenStyle to search for tha appropriate string to return
/*!
 *\param style the Qt::PenStyle to search for the PenStyle string to return
 *\return A string used in the serializer to output the PenStyle to shapes.txt
 */
string penStyleString(Qt::PenStyle style);

//! Takes in a Qt::PenCapStyle to search for tha appropriate string to return
/*!
 *\param capStyle the Qt::PenCapStyle to search for the PenCapStyle string to return
 *\return A string used in the serializer to output the PenCapStyle to shapes.txt
 */
string penCapStyleString(Qt::PenCapStyle capStyle);

//! Takes in a Qt::PenJoinCapStyle to search for tha appropriate string to return
/*!
 *\param joinStyle the Qt::PeJoinStyle to search for the PenJoinStyle string to return
 *\return A string used in the serializer to output the PenJoinStyle to shapes.txt
 */
string penJoinStyleString(Qt::PenJoinStyle joinStyle);

//! Takes in a Qt::AlignmentFlag to search for tha appropriate string to return
/*!
 *\param align the Qt::AlignmentFlag to search for the Texts alignment string to return
 *\return A string used in the serializer to output the Texts AlignmentFlag to shapes.txt
 */
string alignmentStringConversion(Qt::AlignmentFlag align);

//! Takes in a QFont::Style to search for tha appropriate string to return
/*!
 *\param fontStyle the QFont::Style to search for the FontStyle string to return
 *\return A string used in the serializer to output the Text shape font style to shapes.txt
 */
string fontStyleStringConversion(QFont::Style fontStyle);

//! Takes in a Qt::BrushStyle to search for tha appropriate string to return
/*!
 *\param brushStyle the Qt::BrushStyle to search for the BrushStyle string to return
 *\return A string used in the serializer to output the BrushStyle to shapes.txt
 */
string brushStyleStringConversion(Qt::BrushStyle brushStyle);

//! Takes in an integer to search for tha appropriate string to return
/*!
 *\param fontWeight the QFont::Style to search for the FontStyle string to return
 *\return A string used in the serializer to output the Text font weight to shapes.txt
 */
string fontWeightStringConversion(int fontWeight);

#endif // QT2STRINGCONVERSION_H
