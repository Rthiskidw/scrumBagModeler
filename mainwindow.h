#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include "vector.h"
#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "polyline.h"
#include "polygon.h"
#include "ellipses.h"
#include "textBox.h"
#include "canvas.h"

using namespace Qt;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class canvas;

//!  Class MainWindow
/*!
  Class to construct the main window.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //! Default constructor.
    /*!
      \param parent pointer to a QWidget.
    */
    MainWindow(QWidget *parent = nullptr);
    
    
    //! Destructor.
    /*!
    */
    ~MainWindow();

private slots:
 //! Function to show the login screen.
    /*!
    */
    void on_actionLogin_triggered();


    //! Function to show the Contact Us screen.
    /*!
    */
    void on_actionContact_Us_triggered();





    //! Function to create a line widget for the interface.
    /*!
    */
    void on_line_button_clicked();


    //! Function to create a polyline widget for the interface.
    /*!
    */
    void on_polyline_button_clicked();


    //! Function to create a line widget for the interface.
    /*!
    */
    void on_polygon_button_clicked();


    //! Function to create a circle widget for the interface.
    /*!
    */
    void on_circle_button_clicked();


    //! Function to create an ellipse widget for the interface.
    /*!
    */
    void on_ellipse_button_clicked();


    //! Function to create a recctangle widget for the interface.
    /*!
    */
    void on_rectangle_button_clicked();


    //! Function to create a square widget for the interface.
    /*!
    */
    void on_square_button_clicked();


    //! Function to create a text widget for the interface.
    /*!
    */
    void on_text_button_clicked();






    //! Function to cancel the creation of a text widget for the interface.
    /*!
    */
    void on_cancelText_button_clicked();


    //! Function to cancel the creation of a polygon widget for the interface.
    /*!
    */
    void on_cancelPolygon_button_clicked();


    //! Function to cancel the creation of a square widget for the interface.
    /*!
    */
    void on_cancelSquare_button_clicked();


    //! Function to cancel the creation of a polyline widget for the interface.
    /*!
    */
    void on_cancelPolyline_button_clicked();


    //! Function to cancel the creation of a rectangle widget for the interface.
    /*!
    */
    void on_cancelRectangle_button_clicked();


    //! Function to cancel the creation of a ellipse widget for the interface.
    /*!
    */
    void on_cancelEllipse_button_clicked();


    //! Function to cancel the creation of a line widget for the interface.
    /*!
    */
    void on_cancelLine_button_clicked();


    //! Function to cancel the creation of a circle widget for the interface.
    /*!
    */
    void on_cancelCircle_button_clicked();






    //! Function to build a line widget for the interface.
    /*!
    */
    void on_lineBuild_button_clicked();


    //! Function to build a circle widget for the interface.
    /*!
    */
    void on_circleBuild_button_clicked();


    //! Function to build a text widget for the interface.
    /*!
    */
    void on_textBuild_button_clicked();


    //! Function to build a polygon widget for the interface.
    /*!
    */
    void on_polygonBuild_button_clicked();


    //! Function to build a square widget for the interface.
    /*!
    */
    void on_squareBuild_button_clicked();


    //! Function to build a polyline widget for the interface.
    /*!
    */
    void on_polylineBuild_button_clicked();


    //! Function to build a rectangle widget for the interface.
    /*!
    */
    void on_rectangleBuild_button_clicked();


    //! Function to build an ellipse widget for the interface.
    /*!
    */
    void on_ellipseBuild_button_clicked();




    //! Function to create a move button widget for the interface.
    /*!
    */
    void on_moveButton_clicked();


    //! Function to execute the move on the interface.
    /*!
    */
    void on_moveConfirm_button_clicked();


    //! Function to cancel the creation of a move button widget for the interface.
    /*!
    */
    void on_cancelMove_button_clicked();





    //! Function to execute the erase on the interface.
    /*!
    */
    void on_eraseConfirm_button_clicked();


    //! Function to cancel the creation of an erase button widget for the interface.
    /*!
    */
    void on_cancelErase_button_clicked();


    //! Function to create an erase button widget for the interface.
    /*!
    */
    void on_eraseButton_clicked();



    //! Function to sort the shapes by ID.
    /*!
    */
    void on_actionSort_By_ID_triggered();


    //! Function to sort the shapes by Area.
    /*!
    */
    void on_actionSort_By_Area_triggered();


    //! Function to sort the shapes by Perimeter.
    /*!
    */
    void on_actionSort_By_Perimeter_triggered();




    //! Function to save the changes to the shapes on the interface.
    /*!
    */
    void on_saveButton_clicked();

    void on_actionView_Add_Testimonials_triggered();

private:
    Ui::MainWindow *ui;
    canvas *Canvas;
    Shape_Parser* parser;
    QComboBox              *shapeComboBox;
    QLabel                 *shapeLabel;
    Shapes_Vector<Shapes*>  shapeList;
};
#endif // MAINWINDOW_H
