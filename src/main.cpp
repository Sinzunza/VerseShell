#include <iostream>
#include <string>
#include <vector>

#include "base.hpp"
#include "../header/parse.h"

int main(){

    bool isFirst = true;
    bool exited = false;

    while(isFirst || !exited)
    {
        isFirst = false;
        std::cout << "$ ";
        std::string userEntered = "";
        getline(std::cin,userEntered);

        if(!userEntered.empty())
        {
            int iterator = 0;
            int lastIndex = 0;
            base *lastCommand;
            std::vector <base*> allCommands;
            allCommands =  parse::parseString(lastCommand, userEntered, iterator, lastIndex);
            for (int i = 0; i < allCommands.size(); i++)
            {
                allCommands.at(i)->execute();
                if (allCommands.at(i)->isExit())
                {
                    exited = true;
                    break;
                }
            }
        }
    }

    return 0;
}
