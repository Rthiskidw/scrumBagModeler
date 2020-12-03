#include "shape.h"
#include <vector>
#include "qtconversions.h"
#include "shapeparser.h"
#include "qt2stringconversion.h"
#include <QColor>


#include <QDebug>

#include "mainwindow.h"
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();

}
