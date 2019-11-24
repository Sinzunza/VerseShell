#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "base.hpp"
#include "indConnector.hpp"
#include "orConnector.hpp"
#include "andConnector.hpp"

std::string trim(std::string s)
{
	if(s.length() != 1) {
        while (s.at(0) == ' ')
        {
            s.erase(0,1);
        }
        while (s.at(s.size()-1) == ' ')
        {
            s.erase(s.size()-1,1);
        }
        while (s.at(s.size()-2) == ' ')
        {
            s.erase(s.size()-2,1);
        }
    }
    return s;
}

char** createCommand(std::string fragment,int &size)
{
    fragment = trim(fragment); //remove leading / trailing whitespaces
    std::vector <std::string> vectorArgs;
	std::string currArg = "";
	std::stringstream tempStream;
    tempStream << fragment;
    while(tempStream >> currArg){
        vectorArgs.push_back(currArg);
    }
    char ** chArgs = new char*[vectorArgs.size()+1]; //plus one because add null at end
    for(unsigned i = 0; i < vectorArgs.size(); i++){ //alocate new string literal and copy to arr
        chArgs[i] = new char[vectorArgs[i].size() + 1];
        strcpy(chArgs[i], vectorArgs[i].c_str());
    }
    chArgs[vectorArgs.size()] = NULL;
    size = vectorArgs.size();
	return chArgs;
}

int main(){
        bool isFirst = true;
        base *lastCommand;
        while(isFirst || !lastCommand->isExit()){
            std::cout << "\n$ ";
            std::string userEntered = ""; //echo hello world; touch hello.txt && ls; mrkir newFolder || mkdir truefolder
            getline(std::cin,userEntered);
            
            if(!userEntered.empty()) {
                std::size_t found = userEntered.find('#'); //if comment found trim anything after comment
                if (found!=std::string::npos){
                    userEntered = userEntered.substr(0,found);
                }
                userEntered = trim(userEntered);

                std::string currentCommand;
                int lastIndex = 0; 
                for(unsigned i = 0; i < userEntered.length(); i++){
                    if(userEntered.at(i) == ';' || userEntered.substr(i,2) == "&&" ||userEntered.substr(i,2) == "||" ||i == userEntered.length()-1){
                        if (lastIndex == 0){
                            if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex,i); }
                            else { currentCommand = userEntered.substr(lastIndex,i+1); }
                            lastIndex = i;
                            int size;
                            char ** chArgs = createCommand(currentCommand,size);
                            base *firstBase = new indConnector(chArgs);
                            firstBase->execute();
                            for(unsigned j = 0; j < size; j++){
                                delete [] chArgs[j];
                            }
                            delete [] chArgs;
                            lastCommand = firstBase;
                        }
                        else if (userEntered.at(lastIndex) == ';'){
                            if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex + 1,(i - (lastIndex+1))); }
                            else { currentCommand = userEntered.substr(lastIndex + 1,(i - (lastIndex))); }
                            lastIndex = i;
                            int size;
                            char ** chArgs = createCommand(currentCommand,size);
                            base *indBase = new indConnector(chArgs);
                            indBase->execute();
                            for(unsigned j = 0; j < size; j++){
                                delete [] chArgs[j];
                            }
                            delete [] chArgs;
                            lastCommand = indBase;
                        }
                        else if(userEntered.substr(lastIndex,2) == "&&" && lastIndex+1 != i){
                            if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 2))); }
                            else { currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 1))); }
                            lastIndex = i;
                            int size;
                            char ** chArgs = createCommand(currentCommand,size);
                            base *andBase = new andConnector(lastCommand, chArgs);
                            andBase->execute();
                            for(unsigned j = 0; j < size; j++){
                                delete [] chArgs[j];
                            }
                            delete [] chArgs;
                            lastCommand = andBase;
                        }
                        else if(userEntered.substr(lastIndex,2) == "||" && lastIndex+1 != i){
                            if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 2))); }
                            else { currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 1))); }
                            lastIndex = i;
                            int size;
                            char ** chArgs = createCommand(currentCommand,size);
                            base *orBase = new orConnector(lastCommand, chArgs);
                            orBase->execute();
                            for(unsigned j = 0; j < size; j++){
                                delete [] chArgs[j];
                            }
                            delete [] chArgs;
                            lastCommand = orBase;
                        }
                    }
                }
                isFirst = false;
            }
        }
	return 0;
}
