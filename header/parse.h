#ifndef PARSE_H
#define PARSE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "../src/base.hpp"
#include "../src/indConnector.hpp"
#include "../src/orConnector.hpp"
#include "../src/andConnector.hpp"
#include "../headers/indParen.h"
#include "../headers/andParen.h"
#include "../headers/orParen.h"

class indParen;
class andParen;
class orParen;

class parse {
    public:
    
        static std::vector <base*> parseString(base* lastCommand, std::string userEntered, int &i, int &lastIndex);
};
#endif
