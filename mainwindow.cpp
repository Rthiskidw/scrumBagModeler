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

}

void MainWindow::on_polyline_button_clicked()
{

}

void MainWindow::on_polygon_button_clicked()
{

}

void MainWindow::on_circle_button_clicked()
{

}

void MainWindow::on_ellipse_button_clicked()
{

}

void MainWindow::on_rectangle_button_clicked()
{

}
void MainWindow::on_square_button_clicked()
{

}
