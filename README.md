# 2D Graphics Modeler

### Team Members: Dan Mateos, Jake Merill, Ryan Solanki, Craig Spengler, Reed Wilson, Alan Vuong, Sophia Yonus

# Project Description
### You are to create software for modeling basic 2D graphics objects. The modeler will demonstrate the capabilities of 2D Graphics Modeler Inc.’s graphics engine. Potential customers will be looking for a 2D graphics rendering librarywhich can be integrated into their own software suite.

# Requirements
### This project __requires__ the Qt application in order to run and for the shapes to rendered.


# Program Checklist
## 1) Provide satisfied customer testimonials (solicit for additional testimonials). Guest users may enter testimonials. The testimonials should be persistent between executions.
__Status - *Complete*__
##### Header File - contactus.h
##### CPP Source File - contactus.cpp
##### Frontend UI - contactus.ui

## 2) Provide “contact us” method with team name and logo.
__Status - *Complete*__
##### Header File - contactus.h
##### CPP Source File - contactus.cpp
##### Frontend UI - contactus.ui

## 3) Display all graphic objects (i.e. shapes including text) in rendering window. The shape id will be displayed above each shape identifying it. The rendering area to display shapes must have minimum dimensions of 1000 pixels (horizontal) by 500 pixels (vertical). The coordinate system is defined such that the top left corner of the point (1000,500).
**"Status - *In Progress*"**

## 4) Your program should read from a shape file that keeps track of allshapes currently being rendered by the 2D modeler. Shapes are identified by their type: line, polyline, polygon, rectangle, ellipse, text. Shapes have properties: shape dimensions, pen color, penwidth, pen style, pen cap style, pen join style, brush color, brush shape. Text has properties: shape dimensions, text string, text
__Status - *Complete*__
##### Header File - shapeparser.cpp
##### CPP Source File -- shapeparser.h
##### Implemented in -- mainwindow.cpp(Line 15)

## 5) Your program should be able to move shapes, including text, being rendered. This is accomplished via a move shape form. All changes are visible in the rendering area. – administrator only
**"Status - *In Progress*"**

## 6) Your program should be able to add and remove shapes, including text, being rendered. This is accomplished via an add/remove shape form. All changes are visible in the rendering area. – administrator only
**"Status - *In Progress*"**

## 7) Produce a shape listing report sorted by shape id (at any time). All shape properties should be included in the report.
**"Status - *In Progress*"**

## 8) Produce a shape listing report of ONLY shapes with an area sortedby area (at any time). The shape type, id and area should beincluded in the report.
**"Status - *In Progress*"**

## 9) Produce a shape listing report of ONLY shapes with a perimetersorted by perimeter (at any time). The shape type, id and perimeter should be included in the report.
**"Status - *In Progress*"**

## 10) Save all changes between executions
**"Status - *In Progress*"**
