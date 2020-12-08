#ifndef TESTIMONYWINDOW_H
#define TESTIMONYWINDOW_H

#include "mainwindow.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class TestimonyWindow;
}
QT_END_NAMESPACE

//! Class TestimonyWindow
/*!
    Class to construct the view/add testimony window
*/

class TestimonyWindow : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \brief TestimonyWindow
    /*!
        \param parent pointer to a QWidget.
    */
    explicit TestimonyWindow(QWidget *parent = nullptr);

    /*!
       Destructor
    */
    ~TestimonyWindow();

private slots:
    //! Function invokes when submit button is clicked and returns back to main window.
    /*!
    */
    void on_submitButton_clicked();

    //! Function invokes when cancel button is clicked to return back to main window.
    /*!
    */
    void on_cancelButton_clicked();

    //! Function invokes when view button is clicked to go to view testimonies window.
    /*!
    */
    void on_view_testimonies_clicked();

private:
    Ui::TestimonyWindow *ui;
};

#endif // TESTIMONYWINDOW_H
