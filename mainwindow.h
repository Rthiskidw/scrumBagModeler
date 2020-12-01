#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include "vector.h"
#include "shape.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Canvas;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionLogin_triggered();
    void on_actionContact_Us_triggered();

private:
    Ui::MainWindow *ui;
    QComboBox              *shapeComboBox;
    QLabel                 *shapeLabel;
    Shapes_Vector<Shapes*>  shapeList;
};
#endif // MAINWINDOW_H
