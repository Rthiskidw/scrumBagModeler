#include "testimonywindow.h"
#include "ui_testimonywindow.h"

#include <QMessageBox>
#include <QPixmap>

TestimonyWindow::TestimonyWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestimonyWindow)
{
    ui->setupUi(this);
}

TestimonyWindow::~TestimonyWindow()
{
    delete ui;
}

void TestimonyWindow::on_submitButton_clicked()
{
    QMessageBox::information(this, "Testimonial", "Thank you for your opinion!");
    QString fileName = "testimonials.txt";
    QFile file(fileName);
    QString testimonials = ui->testimonial_edit->toPlainText();
    if(file.open(QIODevice::Append))
    {
        QTextStream stream(&file);
        stream << testimonials << Qt::endl;
        stream << "------------------------------------------------------------------------------------------------" << Qt::endl;
    }
    file.close();
    hide();
}

void TestimonyWindow::on_cancelButton_clicked()
{
    hide();
}

//void TestimonyWindow::on_viewTestimonies_clicked()
//{
//    QLabel *textLabel = new QLabel;
//    QString fileName = "testimonials.txt";
//    QFile file(fileName);
//    //if(file.open(QIODevice::ReadOnly))

//    QString line;
//    QTextStream textIn(&fileName);
//    while(!textIn.atEnd())
//    {
//        line = textIn.readLine();
//        line.append(textIn.readLine());
//    }
//    textLabel->setText(line);
//    file.close();

//    cout << line;


//}




