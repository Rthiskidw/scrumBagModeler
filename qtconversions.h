#ifndef QTCONVERSIONS_H
#define QTCONVERSIONS_H

#include "shape.h"

//! Takes in a string and returns the appropriate PenStyle
/*!
 *\param style the string to search for the PenStyle
 *\return A Qt::PenStyle used to initialize the PensStyle
 */
Qt::PenStyle penStyleConversion(string style);

//! Takes in a string and returns the appropriate PenCapStyle
/*!
 *\param capStyle the string to search for the PenStyle
 *\return A Qt::PenCapStyle used to initialize the PensCapStyle
 */
Qt::PenCapStyle penCapConversion(string capStyle);

//! Takes in a string and returns the appropriate PenJoinStyle
/*!
 *\param joinStyle the string to search for the PenJoinStyle
 *\return A Qt::PenJoinStyle used to initialize the PensJoinStyle
 */
Qt::PenJoinStyle penJoinConversion(string joinStyle);

//! Takes in a string and returns the appropriate BrushStyle
/*!
 *\param brushStyle the string to search for the BrushStyle
 *\return A Qt::BrushStyle used to initialize the BrushStyle
 */
Qt::BrushStyle brushStyleConversion(string brushStyle);

//! Takes in a string and returns the appropriate GlobalColr
/*!
 *\param color the string to search for the color of the ben and the brush
 *\return A Qt::GlobalColor used to initialize the Pen or brush color
 */
Qt::GlobalColor colorConversion(string color);

//! Takes in a string and returns the appropriate AlignmentFlag
/*!
 *\param align the string to search for the AlignmentFlag
 *\return A Qt::PenStyle used to initialize the AlignmentFlag of a Text Shape
 */
Qt::AlignmentFlag alignmentConversion(string align);

//! Takes in a string and returns the appropriate Font Weight
/*!
 *\param fontWeight the string to search for the Font Weight
 *\return A QFont::Weight used to initialize the the weight of the font
 */
QFont::Weight fontWeightConversion(string fontWeight);

//! Takes in a string and returns the appropriate FontStyle
/*!
 *\param fontStyle the string to search for the FontStyle
 *\return A QFont::Style used to initialize the Fonts style
 */
QFont::Style fontStyleConversion(string fontStyle);

#endif // QTCONVERSIONS_H
