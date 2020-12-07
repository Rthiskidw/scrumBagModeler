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
    void on_actionLogin_triggered();
    void on_actionContact_Us_triggered();
    void on_actionView_Add_Testimonials_triggered();

    void on_line_button_clicked();

    void on_polyline_button_clicked();

    void on_polygon_button_clicked();

    void on_circle_button_clicked();

    void on_ellipse_button_clicked();

    void on_rectangle_button_clicked();

    void on_square_button_clicked();

    void on_text_button_clicked();

    void on_cancelText_button_clicked();

    void on_cancelPolygon_button_clicked();

    void on_cancelSquare_button_clicked();

    void on_cancelPolyline_button_clicked();

    void on_cancelRectangle_button_clicked();

    void on_cancelEllipse_button_clicked();

    void on_cancelLine_button_clicked();

    void on_cancelCircle_button_clicked();

    void on_lineBuild_button_clicked();

    void on_circleBuild_button_clicked();

    void on_textBuild_button_clicked();

    void on_polygonBuild_button_clicked();

    void on_squareBuild_button_clicked();

    void on_polylineBuild_button_clicked();

    void on_rectangleBuild_button_clicked();

    void on_ellipseBuild_button_clicked();

    void on_moveButton_clicked();

    void on_moveConfirm_button_clicked();

    void on_cancelMove_button_clicked();

    void on_eraseConfirm_button_clicked();

    void on_cancelErase_button_clicked();

    void on_eraseButton_clicked();

    void on_actionSort_By_ID_triggered();

    void on_actionSort_By_Area_triggered();

    void on_actionSort_By_Perimeter_triggered();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    canvas *Canvas;
    Shape_Parser* parser;
    QComboBox              *shapeComboBox;
    QLabel                 *shapeLabel;
    Shapes_Vector<Shapes*>  shapeList;
};
#endif // MAINWINDOW_H
