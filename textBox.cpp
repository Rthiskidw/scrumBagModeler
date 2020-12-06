
#include "shape.h"


// ************************************ [ TEXT ] ************************************** //

#include "textBox.h"
#include <cmath>
#include <QtDebug>



// ******--> { CONSTRUCTORS } <--****** //

Text::Text(Qt::GlobalColor setFontColor, QString setText, QFont setFont, QPoint setLocation, Qt::AlignmentFlag setFlag, int setWidth, int setHeight)
    :Shapes(setFontColor)
{
    this->set_shape(ShapeType::Text);

    this->set_text_string(setText);
    this->set_text_font(setFont);
    this->set_location1(setLocation);
    this->set_alignment_flag(setFlag);
    this->set_text_box_width(setWidth);
    this->set_text_box_height(setHeight);

    this->text_font.setFamily("Times");
}

//Text::Text(const Text& otherText)
//{
//    this->text_string = otherText.text_string;
//    this->text_font   = otherText.text_font;
//    this->location    = otherText.location;
//    this->flag        = otherText.flag;
//    this->textBoxWidth = otherText.textBoxWidth;
//    this->textBoxHeight = otherText.textBoxHeight;
//}


// ******--> { GETTERS } <--****** //

QString& Text::get_text_string()
{
    return text_string;
}

QFont& Text::get_text_font()
{
    return text_font;
}

QPoint& Text::get_location()
{
    return location;
}

Qt::AlignmentFlag& Text::get_alignment_flag()
{
    return flag;
}

int Text::get_text_box_width() const
{
    return textBoxWidth;
}

int Text::get_text_box_height() const
{
    return textBoxHeight;
}


int* Text::getDimensions()
{
    int *dimensions = new int[4];
    QPoint p = get_location();

    dimensions[0] = p.x();
    dimensions[1] = p.y();
    dimensions[2] = get_text_box_width();
    dimensions[3] = get_text_box_height();

    return dimensions;
}



// ******--> { SETTERS } <--****** //

void Text::set_text_string(QString setTextString)
{
    this->text_string = setTextString;
}

void Text::set_text_font(QFont setTextFont)
{
    this->text_font = setTextFont;
}

void Text::set_location1(QPoint setLocation)
{
    this->location = setLocation;
}

void Text::set_location2(int x, int y)
{
    QPoint temp(x,y);
    this->location = temp;
}

void Text::set_alignment_flag(Qt::AlignmentFlag setFlag)
{
    this->flag = setFlag;
}

void Text::set_text_box_width(int setWidth)
{
    this->textBoxWidth = setWidth;
}

void Text::set_text_box_height(int setHeight)
{
    this->textBoxHeight = setHeight;
}




// ******--> { MOVE } <--****** //

void Text::move(int x, int y, int a)
{
    QPoint temp(x,y);
    location = temp;
}


// ******--> { DRAW } <--****** //

void Text::draw(QPaintDevice *device)
{
    qpainter.begin(device);
    qpainter.setPen(get_pen());
    qpainter.setFont(text_font);
    qpainter.drawText(location.x(), location.y(), textBoxWidth, textBoxHeight, flag, text_string);
    qpainter.drawText(location, QString::number(get_id()));
    qpainter.end();
}

// ************************************************************************** //
