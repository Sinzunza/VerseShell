#ifndef ANDPAREN_H
#define ANDPAREN_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

#include "../src/base.hpp"
#include "parse.h"

class parse;

class andParen : public base {
    public:
        andParen(base* leftBase, std::string command, int &iterator, int &lastIndex);
        virtual void execute();

    private:
        base* leftBase;
        std::vector <base*> allBases;
};
#endif
