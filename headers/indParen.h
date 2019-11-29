#ifndef INDPAREN_H
#define INDPAREN_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

#include "../src/base.hpp"
#include "parse.h"

class parse;

class indParen : public base {
        public:
            indParen(std::string command, int &iterator, int &lastIndex);
            virtual void execute();
    
        private:
            std::vector <base*> allBases;
};
#endif
