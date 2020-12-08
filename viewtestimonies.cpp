#include "viewtestimonies.h"
#include "ui_viewtestimonies.h"
#include "testimonywindow.h"

#include <QMessageBox>
#include <QLabel>
#include <QPixmap>

ViewTestimonies::ViewTestimonies(QString& line, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTestimonies)
{
    ui->setupUi(this);
    ui->Output->setText(line);
}

ViewTestimonies::~ViewTestimonies()
{
    delete ui;
}

void ViewTestimonies::on_doneButton_clicked()
{
    hide();
}
