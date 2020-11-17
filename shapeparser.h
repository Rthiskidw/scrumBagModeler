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

class shapeParser
{
public:
    std::string getStringFromFile(std::ifstream &file);

    shapes* getShapePtr(std::string shapeType);

    void parseShape(std::vector<shapes*>& vShapeList);
};

#endif // SHAPEPARSER_H
