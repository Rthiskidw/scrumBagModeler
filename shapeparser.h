#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <iostream>
#include <string>
#include <ios>
#include <limits>
#include <fstream>
#include <vector>
#include <sstream>
#include "shape.h"

using namespace std;

string getStringFromFile(ifstream &file);

Shape* getShapePtr(string shapeType);

void parseShape(vector<Shape*>& vShapeList);

#endif // SHAPEPARSER_H
