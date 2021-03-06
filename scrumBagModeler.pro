QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canvas.cpp \
    contactus.cpp \
    ellipses.cpp \
    line.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    polygon.cpp \
    polyline.cpp \
    qt2stringconversion.cpp \
    qtconversions.cpp \
    rectangle.cpp \
    reportwindow.cpp \
    shape.cpp \
    shapeparser.cpp \
    testimonywindow.cpp \
    textBox.cpp \
	viewtestimonies.cpp

HEADERS += \
    canvas.h \
    contactus.h \
    ellipses.h \
    line.h \
    login.h \
    mainwindow.h \
    polygon.h \
    polyline.h \
    qt2stringconversion.h \
    qtconversions.h \
    rectangle.h \
    reportwindow.h \
    shape.h \
    shapeparser.h \
    testimonywindow.h \
    vector.h \
    textBox.h \
	viewtestimonies.h

FORMS += \
    contactus.ui \
    login.ui \
    mainwindow.ui \
    reportwindow.ui \
    testimonywindow.ui \
	viewtestimonies.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    shapes.txt \
    testimonials.txt \

RESOURCES += \
    Resources.qrc
