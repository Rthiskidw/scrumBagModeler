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

void ContactUs::on_submitButton_clicked()
{
    QMessageBox::information(this, "Contact Us", "Thank you for contacting us!");
    QString fileName = "feedback.txt";
    QFile file(fileName);
    QString feedback = ui->textEdit->toPlainText();
    if(file.open(QIODevice::Append))
    {
        QTextStream stream(&file);
        stream << feedback << "/n";
        stream << "------------------------------------------------------------" << "/n";
    }
    file.close();
    hide();
}

void ContactUs::on_cancelButton_clicked()
{
    hide();
}
