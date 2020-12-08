#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

//! Class Login
/*!
    Class to construct the view/add testimony window
*/
class Login : public QDialog
{
    Q_OBJECT

public:
    //!
    //! \brief TestimonyWindow
    /*!
        \param parent pointer to a QWidget.
    */
    explicit Login(QWidget *parent = nullptr);

    /*!
       Destructor
    */
    ~Login();

private slots:
    //! Function invokes when login button is clicked and returns back to main window.
    /*!
    */
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
