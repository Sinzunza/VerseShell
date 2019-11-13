#include <iostream>
#include <string>
#include "base.hpp"
#include "indConnector.hpp"
#include "orConnector.hpp"
#include "andConnector.hpp"
#include <vector>
char* createCommand(std::string fragment)
{

	char* ret[10];
	unsigned loc = 0;
	std::string arg = "";
	for (char c : fragment)
	{
		if (c == ' ')
		{
			ret[loc] = const_cast<char*>(arg.c_str());
			arg = "";
			loc++;
		}
		else
		{
			arg = arg + c;
		}
	}
	ret[loc] = const_cast<char*>(arg.c_str());
	loc++;
	ret[loc] = NULL;
	return ret[0];
}



int main(){
	vector<base> cmds;
	bool exited = false;
	while(!exited){
		std::cout << "$ ";
		std::string userEntered;
		getline(std::cin,userEntered);

		std::string currentCommand;

		int lastIndex = 0;  //keeps track of last connector
		for(unsigned i = 0; i < userEntered.length(); i++){
	        	if(userEntered.at(i) == ';' || userEntered.substr(i,2) == "&&" ||userEntered.substr(i,2) == "||" || i == userEntered.length()-1){
	            		if (lastIndex == 0){
        	        		if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex,i); } //checks if this is the last command. substr() different if so
                			else { currentCommand = userEntered.substr(lastIndex,i+1); }
                			lastIndex = i;
					char* a = createCommand(currentCommand);
                			//create command
	                        }
        	                else if (userEntered.at(lastIndex) == ';'){
                			if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex + 1,(i - (lastIndex+1))); } //checks if this is the last command.  substr() different if so
                			else { currentCommand = userEntered.substr(lastIndex + 1,(i - (lastIndex))); }
                			lastIndex = i;
					char* a = createCommand(currentCommand);
        	                        //create command
	                	}
	                	else if(userEntered.substr(lastIndex,2) == "&&"){
        	                	if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 2))); } //checks if this is the last command.  substr() different if so
                			else { currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 1))); }
               				lastIndex = i;
					char* a = createCommand(currentCommand);
               				//create command
             			}
              			else if(userEntered.substr(lastIndex,2) == "||"){
                			if(i != userEntered.length()-1){ currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 2))); } //checks if this is the last command.  substr() different if so
                			else { currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 1))); }
                			lastIndex = i;
					char* a = createCommand(currentCommand);
              				//create command
               			}
			}
		}       
	}
 
	return 0;
}

