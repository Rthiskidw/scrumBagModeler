#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "contactus.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->shapeComboBox->addItem(tr("Polygon"));
//    shapeLabel = new QLabel(tr("&Shape:"));
//    shapeLabel->setBuddy(shapeComboBox);

//    QGridLayout *mainLayout = new QGridLayout;

//    mainLayout->setColumnStretch(0, 1);
//    mainLayout->setColumnStretch(3, 1);
//    mainLayout->addWidget(shapeComboBox,2,1);
//    setLayout(mainLayout);


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
