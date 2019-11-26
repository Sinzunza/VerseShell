#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>
#include <fstream>
#include <sys/stat.h>

class base
{
	public:
		base() { };
		bool isSuccessful(){ return succeeded; }
		bool isExit()	
		{
            return exited;
		}
		virtual void execute() = 0;
	protected:
		bool succeeded;
                bool exited;
		char* arguments[10];
		void runTest(){
                            struct stat tempStat;
                            if (strcmp(arguments[1], "-e") == 0 || arguments[2] == NULL) {
                                std::ifstream infile;
                                if (arguments[2] == NULL) {
                                    infile.open(arguments[1]);
                                }
                                else {
                                    infile.open(arguments[2]);
                                }
                                if(infile.good()) {
                                    std::cout << "(True)" << std::endl;
                                    succeeded = true;
                                }
                                else {
                                    std::cout << "(False)" << std::endl;
                                    succeeded = false;
                                }
                            }
                            else if (strcmp(arguments[1], "-f") == 0){
                                if(stat(arguments[2], &tempStat) == 0 && S_ISREG(tempStat.st_mode)) {
                                    std::cout << "(True)" << std::endl;
                                    succeeded = true;
                                }
                                else {
                                    std::cout << "(False)" << std::endl;
                                    succeeded = false;
                                }
                            }
                            else if (strcmp(arguments[1], "-d") == 0){
                                if(stat(arguments[2], &tempStat) == 0 && S_ISDIR(tempStat.st_mode)) {
                                    std::cout << "(True)" << std::endl;
                                    succeeded = true;
                                }
                                else {
                                   std::cout << "(False)" << std::endl;
                                    succeeded = false;
                                }
                            }
                            else {
                                std::cout << arguments[1] << " not valid test command!" << std::endl;
                            }
		}
};
#endif
