#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QDialog>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ContactUs;
}
QT_END_NAMESPACE

//! Class ContactUs
/*!
    Class to construct the contact window
*/
class ContactUs : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \brief TestimonyWindow
    /*!
        \param parent pointer to a QWidget.
    */
    explicit ContactUs(QWidget *parent = nullptr);

    /*!
       Destructor
    */
    ~ContactUs();

private slots:
    //! Function invokes when submit button is clicked and returns back to main window.
    //! Puts user entered text into text file.
    /*!
    */
    void on_submitButton_clicked();

    //! Function invokes when cancel button is clicked and returns back to main window.
    /*!
    */
    void on_cancelButton_clicked();

private:
    Ui::ContactUs *ui;
};

#endif // CONTACTUS_H
