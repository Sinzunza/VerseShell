#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include "base.hpp"
#include "indConnector.hpp"
#include "orConnector.hpp"
#include "andConnector.hpp"

using namespace std;

bool exited = false;

std::string trim(std::string s)
{
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
	return s;
}

char** createCommand(std::string fragment,int &size)
{
	fragment = trim(fragment); //remove leading/trailing whitespaces
    vector <string> tempStrings;
	std::string arg = "";
	std::stringstream tempStream;
    tempStream << fragment;
    while(tempStream >> arg){
        tempStrings.push_back(arg);
    }
    char ** arr = new char*[tempStrings.size()+1];
    size_t i;
    for(i = 0; i < tempStrings.size(); i++){ //alocate new string literal and copy to arr
        arr[i] = new char[tempStrings[i].size() + 1];
        strcpy(arr[i], tempStrings[i].c_str());
    }
    arr[i] = NULL;
    size = tempStrings.size();
	return arr;
}

int main(){
        std::string cmdOne = "tempNullConnector";
        char *charOne = const_cast<char*>(cmdOne.c_str());
        char *charAr[2] = {charOne,NULL};
        base *lastCommand = new indConnector(charAr);
        while(!lastCommand->isExit()){
            std::cout << "\n$ ";
            std::string userEntered; //echo hello world; touch hello.txt && ls; mrkir newFolder || mkdir truefolder
            getline(std::cin,userEntered);

            std::size_t found = userEntered.find('#');
            if (found!=std::string::npos){
                userEntered = userEntered.substr(0,found);
            }
            std::cout << userEntered << std::endl;
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
                        char ** tempC = createCommand(currentCommand,size);
                        base *firstBase = new indConnector(tempC);
                        firstBase->execute();
                        for(size_t j = 0; j < size; j++){
                        delete [] tempC[j];
                        }
                        delete [] tempC;
                        lastCommand = firstBase;
                    }
                    else if (userEntered.at(lastIndex) == ';'){
                        if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex + 1,(i - (lastIndex+1))); }
                        else { currentCommand = userEntered.substr(lastIndex + 1,(i - (lastIndex))); }
                        lastIndex = i;
                        int size;
                        char ** tempC = createCommand(currentCommand,size);
                        base *indBase = new indConnector(tempC);
                        indBase->execute();
                        for(size_t j = 0; j < size; j++){
                        delete [] tempC[j];
                        }
                        delete [] tempC;
                        lastCommand = indBase;
                    }
                    else if(userEntered.substr(lastIndex,2) == "&&"){
                        if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 2))); }
                        else { currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 1))); }
                        lastIndex = i;
                        int size;
                        char ** tempC = createCommand(currentCommand,size);
                        base *andBase = new andConnector(lastCommand, tempC);
                        andBase->execute();
                        for(size_t j = 0; j < size; j++){
                        delete [] tempC[j];
                        }
                        delete [] tempC;
                        lastCommand = andBase;
                    }
                    else if(userEntered.substr(lastIndex,2) == "||"){
                        if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 2))); }
                        else { currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 1))); }
                        lastIndex = i;
                        int size;
                        char ** tempC = createCommand(currentCommand,size);
                        base *orBase = new orConnector(lastCommand, tempC);
                        orBase->execute();
                        for(size_t j = 0; j < size; j++){
                        delete [] tempC[j];
                        }
                        delete [] tempC;
                        lastCommand = orBase;
                    }
                }
            }


        }
	return 0;
}
