#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include "shape.h"
#include "qtconversions.h"
#include <iostream>
#include <string>
#include <ios>
#include <limits>
#include <fstream>
#include <vector>
#include <sstream>


std::string getStringFromFile(std::ifstream &file);

Shapes* getShapePtr(std::string shapeType);

void parseShape(std::vector<Shapes*>& vShapeList);


#endif // SHAPEPARSER_H
