#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class ContactUs;
}

class ContactUs : public QDialog
{
    Q_OBJECT

public:
    explicit ContactUs(QWidget *parent = nullptr);
    ~ContactUs();

private slots:
    void on_submitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ContactUs *ui;
};

#endif // CONTACTUS_H
