#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>
#include <sys/stat.h>

class base
{
        public:
                base() { };
                bool isSuccessful()
                {
                    return succeeded;
                }
                bool isExit()
                {
                    return exited;
                }
                virtual void execute() = 0;
    
        protected:
                bool succeeded;
                bool exited;
                std::string command;
                char ** arguments;
    
                char** createCommand(std::string fragment,int &size)
                {
                    std::vector <std::string> vectorArgs;
                    std::string currArg = "";
                    std::stringstream tempStream;
                    tempStream << fragment;
                    while (tempStream >> currArg)
                    {
                        if (currArg.at(0) == '"')
                        { //group by quotation mark if found
                            std::string aString;
                            while (tempStream >> aString)
                            {
                                currArg = currArg + " " + aString;
                                if (currArg.at(currArg.length()-1) == '"')
                                {
                                    currArg = currArg.substr(1,currArg.length() - 2);
                                    break;
                                }
                            }
                        }

                        vectorArgs.push_back(currArg);
                    }

                    char ** chArgs = new char*[vectorArgs.size()+1]; //plus one because add null at end
                    for (unsigned i = 0; i < vectorArgs.size(); i++)
                    { //allocate new string literal and copy to arr
                        chArgs[i] = new char[vectorArgs[i].size() + 1];
                        strcpy(chArgs[i], vectorArgs[i].c_str());
                    }
                    chArgs[vectorArgs.size()] = NULL;
                    size = vectorArgs.size();

                    return chArgs;
                }
    
                void executeTest()
                {
                            struct stat tempStat;
                            if (strcmp(arguments[1], "-e") == 0 || arguments[2] == NULL)
			    {
                                std::ifstream infile;
                                if (arguments[2] == NULL)
				{
                                    infile.open(arguments[1]);
                                }
                                else 
				{
                                    infile.open(arguments[2]);
                                }
                                if(infile.good()) 
				{
                                    std::cout << "(True)" << std::endl;
                                    succeeded = true;
                                }
                                else 
				{
                                    std::cout << "(False)" << std::endl;
                                    succeeded = false;
                                }
                            }
                            else if (strcmp(arguments[1], "-f") == 0)
			    {
                                if(stat(arguments[2], &tempStat) == 0 && S_ISREG(tempStat.st_mode))
				{
                                    std::cout << "(True)" << std::endl;
                                    succeeded = true;
                                }
                                else
				{
                                    std::cout << "(False)" << std::endl;
                                    succeeded = false;
                                }
                            }
                            else if (strcmp(arguments[1], "-d") == 0)
			    {
                                if(stat(arguments[2], &tempStat) == 0 && S_ISDIR(tempStat.st_mode)) 
				{
                                    std::cout << "(True)" << std::endl;
                                    succeeded = true;
                                }
                                else 
				{
                                   std::cout << "(False)" << std::endl;
                                    succeeded = false;
                                }
                            }
                            else 
			    {
                                std::cout << arguments[1] << " not valid test command!" << std::endl;
                            }
                }
};
#endif
