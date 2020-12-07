#ifndef TEXTBOX_H
#define TEXTBOX_H


#include <stdio.h>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QObject>
#include <QPaintDevice>
#include <string>

//using namespace Qt;
using namespace std;


#include "vector.h"
#include "shape.h"



//!  Class Text
/*!
  Class to construct a Text on screen.
*/
class Text : public Shapes
{
private:
    QString text_string;
    QFont  text_font;
    QPoint location;
    Qt::AlignmentFlag flag;
    int textBoxWidth;
    int textBoxHeight;
public:


    //! Default constructor.
    /*!
      \param device pointer to a QPaintDevice
      \param id is of the shape object
    */
    Text(QPaintDevice* device = nullptr, int id = -1);



    //! Alternate constructor.
    /*!
      \param setFontColor a Qt::GlobalColor
      \param setText a QString
      \param setFont a QFont
      \param setLocation a QPoint
      \param setFlag a Qt::AlignmentFlag
      \param setWidth a double
      \param setHeight a double
    */
    Text(Qt::GlobalColor setFontColor, QString setText, QFont setFont, QPoint setLocation, Qt::AlignmentFlag setFlag, int setWidth, int setHeight);     // Might change to allow family variable.

//    Text(const Text& otherText);

    //! Destructor.
    /*!
    */
    virtual ~Text() {};


    //! Getter function to get the text of a Text object.
    /*!
      \return text_string
    */
    QString& get_text_string();



    //! Getter function to get the font of a Text object.
    /*!
      \return text_font
    */
    QFont& get_text_font();


    //! Getter function to get the location of a Text Object.
    /*!
      \return location
    */
    QPoint& get_location();


    //! Getter function to get the alignment flag of a Text Object.
    /*!
      \return flag
    */
    Qt::AlignmentFlag& get_alignment_flag();


     //! Getter function to get the box width of a Text Object.
     /*!
       \return textBoxWidth
     */
    int get_text_box_width() const;


    //! Getter function to get the box height of a Text Object.
    /*!
      \return textBoxHeight
    */
    int get_text_box_height() const;



    //! Getter function to get the dimensions of the Text Object.
    /*!
      \return dimensions
    */
    int* getDimensions() override;


    //! Setter function to set the text of a Text Object.
    /*!
      \param setTextString QString to set text_string
    */
    void set_text_string(QString setTextString);


    //! Setter function to set the font of a Text Object.
    /*!
      \param setTextFont QFont to set text_font
    */
    void set_text_font(QFont setTextFont);



    //! Setter function to set the location of a Text Object using x and y coordinates.
    /*!
      \param setLocation Qpoint to set location
    */
    void set_location1(QPoint setLocation);


    //! Setter function to set the location of a Text Object using x and y coordinates.
     /*!
       \param x an integer
       \param y an integer
     */
    void set_location2(int x, int y);


     //! Setter function to set the flag of a Text Object.
     /*!
       \param setFlag is an Qt::AlignmentFlag
     */
    void set_alignment_flag(Qt::AlignmentFlag setFlag);


    //! Setter function to set the box width of a Text Object.
    /*!
      \param setWidth integer to set width
    */
    void set_text_box_width(int setWidth);



    //! Setter function to set the box height of a Text Object.
    /*!
      \param setHeight integer to set height
    */
    void set_text_box_height(int setHeight);


    //! Function to move a Text Object.
    /*!
      \param x an integer
      \param y an integer
      \param vertext an integer
      \return New location
    */
    void move(int x, int y, int na) override;


    //! Function to draw a Text Object.
    /*!
      \param device a pointer to a QPaintDevice
    */
    void draw(QPaintDevice *device) override;
};


#endif // TEXTBOX_H
