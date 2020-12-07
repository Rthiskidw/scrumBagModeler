#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "contactus.h"
#include "shapeparser.h"
#include "reportwindow.h"
#include "canvas.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

   ui->setupUi(this);

   parser = new Shape_Parser;
   parser->parseShape(shapeList);                       //parsing shape file filling shape list

   ui->CanvasObject->gettingVectorFromMain(shapeList); //giving canvas shape vector
   ui->shapeMenu->setCurrentWidget(ui->logo_page);

    //Canvas = new canvas;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLogin_triggered()
{
    auto* login = new Login(this);
    login->show();
}

void MainWindow::on_actionContact_Us_triggered()
{
    auto* contactUs = new ContactUs(this);
    contactUs->show();
}



void MainWindow::on_line_button_clicked()
{
    ui->shapeMenu->addWidget(ui->addLine_page);
    ui->shapeMenu->setCurrentWidget(ui->addLine_page);
}

void MainWindow::on_polyline_button_clicked()
{
    ui->shapeMenu->addWidget(ui->addPolyline_page);
    ui->shapeMenu->setCurrentWidget(ui->addPolyline_page);
}

void MainWindow::on_polygon_button_clicked()
{
    ui->shapeMenu->addWidget(ui->addPolygon_page);
    ui->shapeMenu->setCurrentWidget(ui->addPolygon_page);
}

void MainWindow::on_circle_button_clicked()
{
    ui->shapeMenu->addWidget(ui->addCircle_page);
    ui->shapeMenu->setCurrentWidget(ui->addCircle_page);
}

void MainWindow::on_ellipse_button_clicked()
{
    ui->shapeMenu->addWidget(ui->addEllipse_page);
    ui->shapeMenu->setCurrentWidget(ui->addEllipse_page);
}

void MainWindow::on_rectangle_button_clicked()
{
    ui->shapeMenu->addWidget(ui->addRect_page);
    ui->shapeMenu->setCurrentWidget(ui->addRect_page);
}
void MainWindow::on_square_button_clicked()
{
    ui->shapeMenu->addWidget(ui->addSquare_page);
    ui->shapeMenu->setCurrentWidget(ui->addSquare_page);
}

void MainWindow::on_text_button_clicked()
{
    ui->shapeMenu->addWidget(ui->addText_page);
    ui->shapeMenu->setCurrentWidget(ui->addText_page);
}

void MainWindow::on_cancelText_button_clicked()
{
    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_cancelPolygon_button_clicked()
{
   on_cancelText_button_clicked();
}

void MainWindow::on_cancelSquare_button_clicked()
{
    on_cancelText_button_clicked();
}

void MainWindow::on_cancelPolyline_button_clicked()
{
    on_cancelText_button_clicked();
}

void MainWindow::on_cancelRectangle_button_clicked()
{
    on_cancelText_button_clicked();
}

void MainWindow::on_cancelEllipse_button_clicked()
{
    on_cancelText_button_clicked();
}

void MainWindow::on_cancelLine_button_clicked()
{
    on_cancelText_button_clicked();
}

void MainWindow::on_cancelCircle_button_clicked()
{
    on_cancelText_button_clicked();
}

void MainWindow::on_lineBuild_button_clicked()
{
    GlobalColor lineColor;
    PenStyle linePenStyle;
    PenCapStyle linePenCapStyle;
    PenJoinStyle linePenJoinStyle;
    GlobalColor lineBrushColor;
    BrushStyle lineBrushStyle;

    lineColor = ui->CanvasObject->getColor(ui->line_penColor_box->currentText());
    linePenStyle = ui->CanvasObject->getPenStyle(ui->line_penStyle_box->currentText());
    linePenCapStyle = ui->CanvasObject->getPenCapStyle(ui->line_penCapStyle_box->currentText());
    linePenJoinStyle = ui->CanvasObject->getPenJointStyle(ui->line_penJointStyle_box->currentText());
    lineBrushColor = lineColor;
    lineBrushStyle = SolidPattern;

    QPoint P1(ui->line_x1_box->text().toInt(), ui->line_y1_box->text().toInt());
    QPoint P2(ui->line_x2_box->text().toInt(), ui->line_y2_box->text().toInt());

    Shapes *line = new Line(lineColor, linePenStyle, linePenCapStyle, linePenJoinStyle, lineBrushColor, lineBrushStyle, P1, P2);

    ui->CanvasObject->addShape(line);

    ui->CanvasObject->update();

    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);

}

void MainWindow::on_circleBuild_button_clicked()
{
    GlobalColor color;
    PenStyle penStyle;
    PenCapStyle penCapStyle;
    PenJoinStyle penJoinStyle;
    GlobalColor brushColor;
    BrushStyle brushStyle;

    color = ui->CanvasObject->getColor(ui->circlePenColor_box->currentText());
    penStyle = ui->CanvasObject->getPenStyle(ui->circlePenStyle_box->currentText());
    penCapStyle = ui->CanvasObject->getPenCapStyle(ui->circlePenCapStyle_box->currentText());
    penJoinStyle = ui->CanvasObject->getPenJointStyle(ui->circlePenJoinStyle_box->currentText());
    brushColor = ui->CanvasObject->getColor(ui->circleBrushColor_box->currentText());
    brushStyle = ui->CanvasObject->getBrushStyle(ui->circleBrushStyle_box->currentText());

    int X = ui->circleX_box->text().toInt();
    int Y = ui->circleY_box->text().toInt();
    double W = ui->circleWidth_box->text().toInt();
    double H = ui->circleHeight_box->text().toInt();

    Shapes *circle = new Ellipse(color, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle, X, Y, W, H);

    ui->CanvasObject->addShape(circle);

    ui->CanvasObject->update();

    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_textBuild_button_clicked()
{
    GlobalColor color;
    QString getText;
    QFont font;
    AlignmentFlag alignment;
    int height;
    int width;

    color = ui->CanvasObject->getColor(ui->textColor_box->currentText());
    getText = ui->textInput_box->toPlainText();
    //font.setStyle(fontStyleConversion(ui->textFontStyle_box->currentText()));
    font.setStyle(ui->CanvasObject->getFontStyle(ui->textFontStyle_box->currentText()));
    //font = ui->CanvasObject->getFont(ui->textFontStyle_box->currentText());
    alignment = ui->CanvasObject->getFlag(ui->textAllignment_box->currentText());

    int X = ui->textX_box->text().toInt();
    int Y = ui->textY_box->text().toInt();
    QPoint coordinate(X,Y);

    height = ui->textBoxHeight_box->text().toInt();
    width = ui->textBoxWidth_box->text().toInt();

    Shapes *text = new Text(color, getText, font, coordinate, alignment, width, height);

    ui->CanvasObject->addShape(text);

    ui->CanvasObject->update();

    ui->CanvasObject->addShape(text);

    ui->CanvasObject->update();
    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_polygonBuild_button_clicked()
{
    GlobalColor PolygonColor;
    PenStyle PolygonPenStyle;
    PenCapStyle PolygonPenCapStyle;
    PenJoinStyle PolygonPenJoinStyle;
    GlobalColor PolygonBrushColor;
    BrushStyle PolygonBrushStyle;
    int totalPoints = 4;
    QPoint pointArray[4];

    QPoint one(ui->polygonX1_box->text().toInt(), ui->polygonY1_box->text().toInt());
    pointArray[0] = one;

    QPoint two(ui->polygonX2_box->text().toInt(), ui->polygonY2_box->text().toInt());
    pointArray[1] = two;

    QPoint three(ui->polygonX3_box->text().toInt(), ui->polygonY3_box->text().toInt());
    pointArray[2] = three;

    QPoint four(ui->polygonX4_box->text().toInt(), ui->polygonY4_box->text().toInt());
    pointArray[3] = four;

    PolygonColor = ui->CanvasObject->getColor(ui->polygonPenColor_box->currentText());
    PolygonPenStyle = ui->CanvasObject->getPenStyle(ui->polygonPenStyle_box->currentText());
    PolygonPenCapStyle = ui->CanvasObject->getPenCapStyle(ui->polygonPenCapStyle_box->currentText());
    PolygonPenJoinStyle = ui->CanvasObject->getPenJointStyle(ui->polygonPenJoinStyle_box->currentText());
    PolygonBrushColor = ui->CanvasObject->getColor(ui->polyBrushColor_comboBox->currentText());
    PolygonBrushStyle = ui->CanvasObject->getBrushStyle(ui->polyBrushStyle_comboBox->currentText());


    Shapes *polygon = new Polygon(PolygonColor, PolygonPenStyle, PolygonPenCapStyle, PolygonPenJoinStyle, PolygonBrushColor, PolygonBrushStyle, totalPoints, pointArray);
    polygon->set_shape(Shapes::ShapeType::Polygon);
    polygon->set_width(1);
    ui->CanvasObject->addShape(polygon);

    ui->CanvasObject->update();

    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_squareBuild_button_clicked()
{
    GlobalColor SquareColor;
    PenStyle SquarePenStyle;
    PenCapStyle SquarePenCapStyle;
    PenJoinStyle SquarePenJoinStyle;
    GlobalColor SquareBrushColor;
    BrushStyle SquareBrushStyle;
    int SquareX;
    int SquareY;
    double SquareWidth;
    double SquareLength;


    SquareColor = ui->CanvasObject->getColor(ui->penColor_comboBox_12->currentText());
    SquarePenStyle = ui->CanvasObject->getPenStyle(ui->penStyle_comboBox_9->currentText());
    SquarePenCapStyle = ui->CanvasObject->getPenCapStyle(ui->penCapStyle_comboBox_9->currentText());
    SquarePenJoinStyle = ui->CanvasObject->getPenJointStyle(ui->penJoinStyle_comboBox_9->currentText());
    SquareBrushColor = ui->CanvasObject->getColor(ui->brushColor_comboBox_4->currentText());
    SquareBrushStyle = ui->CanvasObject->getBrushStyle(ui->brushStyle_comboBox_4->currentText());
    SquareLength = ui->length_spinBox_9->text().toInt();
    SquareWidth = SquareLength;
    SquareX = ui->xCoordinate_spinBox_9->text().toInt();
    SquareY = ui->yCoordinate_spinBox_9->text().toInt();

    Shapes *square = new Rectangle(SquareColor, SquarePenStyle, SquarePenCapStyle, SquarePenJoinStyle, SquareBrushColor, SquareBrushStyle, SquareX, SquareY, SquareWidth, SquareLength);

    ui->CanvasObject->addShape(square);

    ui->CanvasObject->update();

    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_polylineBuild_button_clicked()
{
    GlobalColor PolyLineColor;
    PenStyle PolyLinePenStyle;
    PenCapStyle PolyLinePenCapStyle;
    PenJoinStyle PolyLinePenJoinStyle;
    GlobalColor PolyLineBrushColor;
    BrushStyle PolyLineBrushStyle;
    int polyLineTotalPoints;
    polyLineTotalPoints = ui->lineEdit_6->text().toInt();
    QPoint polyLinePointArray[polyLineTotalPoints];

    if (polyLineTotalPoints == 1)
    {
        QPoint one(ui->polyLine_XspinBox_1->text().toInt(), ui->polyLine_YspinBox_1->text().toInt());
        polyLinePointArray[0] = one;
    }
    else if (polyLineTotalPoints == 2)
    {
        QPoint one(ui->polyLine_XspinBox_1->text().toInt(), ui->polyLine_YspinBox_1->text().toInt());
        polyLinePointArray[0] = one;

        QPoint two(ui->polyLine_XspinBox_2->text().toInt(), ui->polyLine_YspinBox_2->text().toInt());
        polyLinePointArray[1] = two;
    }
    else if (polyLineTotalPoints == 3)
    {
        QPoint one(ui->polyLine_XspinBox_1->text().toInt(), ui->polyLine_YspinBox_1->text().toInt());
        polyLinePointArray[0] = one;

        QPoint two(ui->polyLine_XspinBox_2->text().toInt(), ui->polyLine_YspinBox_2->text().toInt());
        polyLinePointArray[1] = two;

        QPoint three(ui->polyLine_XspinBox_3->text().toInt(), ui->polyLine_YspinBox_3->text().toInt());
        polyLinePointArray[2] = three;
    }
    else if (polyLineTotalPoints == 4)
    {
        QPoint one(ui->polyLine_XspinBox_1->text().toInt(), ui->polyLine_YspinBox_1->text().toInt());
        polyLinePointArray[0] = one;

        QPoint two(ui->polyLine_XspinBox_2->text().toInt(), ui->polyLine_YspinBox_2->text().toInt());
        polyLinePointArray[1] = two;

        QPoint three(ui->polyLine_XspinBox_3->text().toInt(), ui->polyLine_YspinBox_3->text().toInt());
        polyLinePointArray[2] = three;

        QPoint four(ui->polyLine_XspinBox_4->text().toInt(), ui->polyLine_YspinBox_4->text().toInt());
        polyLinePointArray[3] = four;
    }
    else
    {
        QPoint one(ui->polyLine_XspinBox_1->text().toInt(), ui->polyLine_YspinBox_1->text().toInt());
        polyLinePointArray[0] = one;

        QPoint two(ui->polyLine_XspinBox_2->text().toInt(), ui->polyLine_YspinBox_2->text().toInt());
        polyLinePointArray[1] = two;

        QPoint three(ui->polyLine_XspinBox_3->text().toInt(), ui->polyLine_YspinBox_3->text().toInt());
        polyLinePointArray[2] = three;

        QPoint four(ui->polyLine_XspinBox_4->text().toInt(), ui->polyLine_YspinBox_4->text().toInt());
        polyLinePointArray[3] = four;

        QPoint five(ui->polyLine_XspinBox_5->text().toInt(), ui->polyLine_YspinBox_5->text().toInt());
        polyLinePointArray[4] = five;
    }


    PolyLineColor = ui->CanvasObject->getColor(ui->polyLinePenColor_comboBox->currentText());
    PolyLinePenStyle = ui->CanvasObject->getPenStyle(ui->polyLinePenStyle_comboBox->currentText());
    PolyLinePenCapStyle = ui->CanvasObject->getPenCapStyle(ui->polyLinePenCapStyle_comboBox->currentText());
    PolyLinePenJoinStyle = ui->CanvasObject->getPenJointStyle(ui->polyLinePenJoinStyle_comboBox->currentText());
    PolyLineBrushColor = ui->CanvasObject->getColor(ui->polyLineBrushColor_comboBox->currentText());
    PolyLineBrushStyle = ui->CanvasObject->getBrushStyle(ui->polyLineBrushStyle_comboBox->currentText());



    Shapes *polyLine = new Polyline(PolyLineColor, PolyLinePenStyle, PolyLinePenCapStyle, PolyLinePenJoinStyle, PolyLineBrushColor, PolyLineBrushStyle, polyLineTotalPoints, polyLinePointArray);
    //polygon->set_shape(Shapes::ShapeType::Polygon);
    //polygon->set_width(1);
    ui->CanvasObject->addShape(polyLine);

    ui->CanvasObject->update();

    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_rectangleBuild_button_clicked()
{
    GlobalColor RectColor;
    PenStyle RectPenStyle;
    PenCapStyle RectPenCapStyle;
    PenJoinStyle RectPenJoinStyle;
    GlobalColor RectBrushColor;
    BrushStyle RectBrushStyle;
    int rectX;
    int rectY;
    double rectWidth;
    double rectLength;


    RectColor = ui->CanvasObject->getColor(ui->penColor_comboBox_2->currentText());
    RectPenStyle = ui->CanvasObject->getPenStyle(ui->penStyle_comboBox_2->currentText());
    RectPenCapStyle = ui->CanvasObject->getPenCapStyle(ui->penCapStyle_comboBox_2->currentText());
    RectPenJoinStyle = ui->CanvasObject->getPenJointStyle(ui->penJoinStyle_comboBox_2->currentText());
    RectBrushColor = ui->CanvasObject->getColor(ui->brushColor_comboBox_2->currentText());
    RectBrushStyle = ui->CanvasObject->getBrushStyle(ui->brushStyle_comboBox_2->currentText());
    rectLength = ui->length_spinBox_2->text().toInt();
    rectWidth = ui->width_spinBox_2->text().toInt();
    rectX = ui->xCoordinate_spinBox_2->text().toInt();
    rectY = ui->yCoordinate_spinBox_2->text().toInt();

    Shapes *rect = new Rectangle(RectColor, RectPenStyle, RectPenCapStyle, RectPenJoinStyle, RectBrushColor, RectBrushStyle, rectX, rectY, rectWidth, rectLength);

    ui->CanvasObject->addShape(rect);

    ui->CanvasObject->update();

    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_ellipseBuild_button_clicked()
{
    GlobalColor color;
    PenStyle penStyle;
    PenCapStyle penCapStyle;
    PenJoinStyle penJoinStyle;
    GlobalColor brushColor;
    BrushStyle brushStyle;

    color = ui->CanvasObject->getColor(ui->ellipsePenColor_box->currentText());
    penStyle = ui->CanvasObject->getPenStyle(ui->ellipsePenStyle_box->currentText());
    penCapStyle = ui->CanvasObject->getPenCapStyle(ui->ellipsePenCapStyle_box->currentText());
    penJoinStyle = ui->CanvasObject->getPenJointStyle(ui->ellipsePenJoinStyle_box->currentText());
    brushColor = ui->CanvasObject->getColor(ui->ellipseBrushColor_box->currentText());
    brushStyle = ui->CanvasObject->getBrushStyle(ui->ellipseBrushStyle_box->currentText());

    int X = ui->ellipseX_box->text().toInt();
    int Y = ui->ellipseY_box->text().toInt();
    double W = ui->ellipseWidth_box->text().toInt();
    double H = ui->ellipseHeight_box->text().toInt();

    Shapes *ellipse = new Ellipse(color, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle, X, Y, W, H);

    ui->CanvasObject->addShape(ellipse);

    ui->CanvasObject->update();

    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_moveButton_clicked()
{
    ui->shapeMenu->addWidget(ui->moveShape_page);
    ui->shapeMenu->setCurrentWidget(ui->moveShape_page);
}

void MainWindow::on_moveConfirm_button_clicked()
{
    int shapeID = ui->move_id->text().toInt();
    int x = ui->move_x->text().toInt();
    int y = ui->move_y->text().toInt();
    ui->CanvasObject->moveShape(shapeID, 0, x, y);
    ui->CanvasObject->update();

    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_cancelMove_button_clicked()
{
    ui->shapeMenu->addWidget(ui->addRect_page);
    ui->shapeMenu->setCurrentWidget(ui->addRect_page);
}

void MainWindow::on_eraseButton_clicked()
{
    ui->shapeMenu->addWidget(ui->eraseShape_page);
    ui->shapeMenu->setCurrentWidget(ui->eraseShape_page);
}

void MainWindow::on_eraseConfirm_button_clicked()
{
    int shapeID = ui->eraseShape_line_edit->text().toInt();
    ui->CanvasObject->chopShape(shapeID);
    ui->CanvasObject->update();

    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_cancelErase_button_clicked()
{
    on_cancelText_button_clicked();
}


void MainWindow::on_actionSort_By_ID_triggered()
{
    //std::sort(shapeList.begin(),shapeList.end());
    //stringstream output = seriallizer(shapeList);
    //reportWindow* report = new reportWindow(QString::fromStdString(output.str()).replace(": ", ":\t"),this);
    //report->show();
}

void MainWindow::on_actionSort_By_Area_triggered()
{
    QString hey = "hey";
    auto report = new reportWindow(hey,this);
    report->show();
}

void MainWindow::on_actionSort_By_Perimeter_triggered()
{
    QString hey = "hey";
    auto report = new reportWindow(hey,this);
    report->show();

}

void MainWindow::on_saveButton_clicked()
{
    ui->CanvasObject->saveShape();
}
