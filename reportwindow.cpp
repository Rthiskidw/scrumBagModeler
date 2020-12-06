#include "reportwindow.h"
#include "ui_reportwindow.h"

reportWindow::reportWindow(QString& inputText,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reportWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText(inputText);
}

reportWindow::~reportWindow()
{
    delete ui;
}

void reportWindow::on_pushButton_clicked()
{
    hide();
}
