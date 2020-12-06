#ifndef TESTIMONYWINDOW_H
#define TESTIMONYWINDOW_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class TestimonyWindow;
}

class TestimonyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TestimonyWindow(QWidget *parent = nullptr);
    ~TestimonyWindow();

private slots:
    void on_submitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::TestimonyWindow *ui;
};

#endif // TESTIMONYWINDOW_H

