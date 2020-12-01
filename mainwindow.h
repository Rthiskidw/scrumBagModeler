#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>

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

    void on_line_button_clicked();

    void on_polyline_button_clicked();

    void on_polygon_button_clicked();

    void on_circle_button_clicked();

    void on_ellipse_button_clicked();

    void on_rectangle_button_clicked();

    void on_square_button_clicked();

private:
    Ui::MainWindow *ui;
    QComboBox *shapeComboBox;
    QLabel    *shapeLabel;
};
#endif // MAINWINDOW_H
