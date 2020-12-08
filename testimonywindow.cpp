#include "testimonywindow.h"
#include "ui_testimonywindow.h"
#include "viewtestimonies.h"

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

void TestimonyWindow::on_view_testimonies_clicked()
{
        QString fileName = "testimonials.txt";
        QFile file(fileName);
        QString line;

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            QTextStream ReadFile(&file);
            while(!stream.atEnd())
            {
                line.append(stream.readLine() + "\n");
            }
        file.close();
    }

    auto* viewTestimonies = new ViewTestimonies(line,this);
    viewTestimonies->show();
}
