#ifndef VIEWTESTIMONIES_H
#define VIEWTESTIMONIES_H

#include "mainwindow.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class ViewTestimonies;
}
QT_END_NAMESPACE

//! Class ViewTestimonies
/*!
    Class to construct the view the testimonies.
*/
class ViewTestimonies : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \brief ViewTestimonies
    /*!
        \param parent pointer to a QWidget and QString.
    */
    explicit ViewTestimonies(QString& line, QWidget *parent = nullptr);

    /*!
       Destructor
    */
    ~ViewTestimonies();

private slots:
    //! Function invokes when done button is clicked and returns back to testimonial window.
    /*!
    */
    void on_doneButton_clicked();

private:
    Ui::ViewTestimonies *ui;
};

#endif // VIEWTESTIMONIES_H
