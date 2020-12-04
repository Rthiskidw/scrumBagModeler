#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "contactus.h"
#include "shapeparser.h"
#include "canvas.h"
//class canvas;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    parseShape(shapeList);                              //parsing shape file filling shape list
    ui->CanvasObject->gettingVectorFromMain(shapeList); //giving canvas shape vector

    ui->shapeMenu->setCurrentWidget(ui->logo_page);
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
    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_cancelSquare_button_clicked()
{
    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_cancelPolyline_button_clicked()
{
    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_cancelRectangle_button_clicked()
{
    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_cancelEllipse_button_clicked()
{
    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_cancelLine_button_clicked()
{
    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_cancelCircle_button_clicked()
{
    ui->shapeMenu->addWidget(ui->logo_page);
    ui->shapeMenu->setCurrentWidget(ui->logo_page);
}

void MainWindow::on_lineBuild_button_clicked()
{

}

void MainWindow::on_circleBuild_button_clicked()
{

}

void MainWindow::on_textBuild_button_clicked()
{

}

void MainWindow::on_polygonBuild_button_clicked()
{

}

void MainWindow::on_squareBuild_button_clicked()
{

}

void MainWindow::on_polylineBuild_button_clicked()
{

}

void MainWindow::on_rectangleBuild_button_clicked()
{

}

void MainWindow::on_ellipseBuild_button_clicked()
{

}
