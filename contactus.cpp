#include "contactus.h"
#include "ui_contactus.h"
#include <QMessageBox>
#include <QPixmap>

ContactUs::ContactUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUs)
{
    ui->setupUi(this);
}

ContactUs::~ContactUs()
{
    delete ui;
}

void ContactUs::on_pushButton_clicked()
{
    QMessageBox::information(this, "Contact Us", "Thank you for contacting us!");
    hide();
}

void ContactUs::on_pushButton_2_clicked()
{
    hide();
}
