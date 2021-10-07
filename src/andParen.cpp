#include "../header/andParen.h"

andParen::andParen(base* leftBase, std::string command, int &iterator, int &lastIndex) : base() {
    this->leftBase = leftBase;
    this->command = command;
    succeeded = false;
    exited = false;
    allBases = parse::parseString(leftBase, command, iterator, lastIndex);
}

void andParen::execute() {

    if (leftBase->isSuccessful()) {

        for (int i = 0; i < allBases.size(); i++) {
            allBases.at(i)->execute();

            if(allBases.at(i)->isExit()) {
                exited = true;
                break;
            }
        }

        succeeded = allBases.back()->isSuccessful();
    }
}
