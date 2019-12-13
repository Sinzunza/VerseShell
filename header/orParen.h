#ifndef ORPAREN_H
#define ORPAREN_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

#include "../src/base.hpp"
#include "parse.h"

class parse;

class orParen : public base {
    public:
        orParen(base* leftBase, std::string command, int &iterator, int &lastIndex);
        virtual void execute();

    private:
        base *leftBase;
        std::vector <base*> allBases;
};
#endif
