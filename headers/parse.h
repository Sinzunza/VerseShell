#ifndef PARSE_H
#define PARSE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "base.hpp"
#include "indConnector.hpp"
#include "orConnector.hpp"
#include "andConnector.hpp"
#include "indParen.h"
#include "andParen.h"
#include "orParen.h"

class indParen;
class andParen;
class orParen;

class parse {
    public:
    
        static std::vector <base*> parseString(base* lastCommand, std::string userEntered, int &i, int &lastIndex);
};
#endif
