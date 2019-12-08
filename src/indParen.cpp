#include "../header/indParen.h"

indParen::indParen(std::string command, int &iterator, int &lastIndex) : base() 
{
    this->command = command;
    succeeded = false;
    exited = false;
    allBases = parse::parseString(NULL, command, iterator, lastIndex);
}
                
void indParen::execute()
{
                    
    for (int i = 0; i < allBases.size(); i++)
    {
        allBases.at(i)->execute();
        if(allBases.at(i)->isExit())
        {
            exited = true;
            break;
        }
    }
                        
    succeeded = allBases.back()->isSuccessful();
                    
}
