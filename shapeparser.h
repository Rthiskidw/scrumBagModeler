#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

<<<<<<< HEAD
<<<<<<< HEAD
#include "shape.h"
#include "qtconversions.h"
=======
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2
#include <iostream>
#include <string>
#include <ios>
#include <limits>
#include <fstream>
#include <vector>
#include <sstream>
<<<<<<< HEAD


std::string getStringFromFile(std::ifstream &file);

Shapes* getShapePtr(std::string shapeType);

void parseShape(std::vector<Shapes*>& vShapeList);
=======
//#include <iostream>
//#include <string>
//#include <ios>
//#include <limits>
//#include <fstream>
//#include <vector>
//#include <sstream>
//#include "shape.h"
=======
#include "shape.h"
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2

class shapeParser
{
public:
    std::string getStringFromFile(std::ifstream &file);

    Shape* getShapePtr(std::string shapeType);

<<<<<<< HEAD
//    void parseShape(std::vector<shape*>& vShapeList);
//};
>>>>>>> 7f11dab43727551713fbabb647bd679b5165bbe6
=======
    void parseShape(std::vector<shape*>& vShapeList);
};
>>>>>>> f2ff9fffe2932f4b1b788669f30656961dd509d2

#endif // SHAPEPARSER_H
