#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "contactus.h"
#include "shapeparser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*parseShape(shapeList);*/ //parsing shape file filling shape list
    //giving canvas shapeList
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
