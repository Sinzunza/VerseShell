#include <iostream>
#include <string>
#include "base.hpp"
#include "indConnector.hpp"
#include "orConnector.hpp"
#include "andConnector.hpp"
#include <vector>

std::vector<base*> cmds;
bool exited = false;

void executeCommands()
{
	for(int i = 0; i < cmds.size(); i++)
	{
		if(cmds.at(i)->isExit())
		{
			exited = true;
			break;
		}
		else
		{
			cmds.at(i)->execute();
		}
	}
	cmds.clear();
}

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

char** createCommand(std::string fragment)
{
	fragment = trim(fragment); //remove leading/trailing whitespaces
	char* ret = new char*[10];
	unsigned loc = 0;
	std::string arg = "";
	for (unsigned i = 0; i < fragment.length()-1; i++)
	{
		if (fragment.at(i) == ' ') //add argument to args list
		{
			ret[loc] = const_cast<char*>(arg.c_str());
			arg = "";
			loc++;
		}
		else
		{
			arg = arg + fragment.at(i);
		}
	}
	ret[loc] = const_cast<char*>(arg.c_str()); //there won't be a space at the end
	loc++;
	ret[loc] = NULL; //finish up
	return ret;
}

void addToCmds(char prev, char* args[10])
{
	if (cmds.empty())
	{
		cmds.push_back(new indConnector(args));
	}
	else if (prev == '&')
	{
		cmds.push_back(new andConnector(cmds.at(cmds.size()-1), args));	
	}
	else if (prev == '|')
	{
		cmds.push_back(new orConnector(cmds.at(cmds.size()-1), args));
	}
	else
	{
		cmds.push_back(new indConnector(args));
	}
}

int main(){
	while(!exited){
		std::cout << "\n$ ";
		std::string userEntered;
		getline(std::cin,userEntered);

		std::string currentCommand; //addToCmds(userEntered.at(lastIndex), userEntered.at(i), createCommand(currentCommand));

		int lastIndex = 0;  //keeps track of last connector
		for(unsigned i = 0; i < userEntered.length(); i++){
	        	if (userEntered.substr(i,2) == "&&" || userEntered.substr(i,2) == "||"){
				i++;
				currentCommand = userEntered.substr(lastIndex, i-lastIndex);
				addToCmds(userEntered.at(lastIndex), createCommand(currentCommand));
				lastIndex = i;
			}
			else if (userEntered.at(i) == ';')
			{
				currentCommand = userEntered.substr(lastIndex, i-lastIndex+1);
				addToCmds(userEntered.at(lastIndex), createCommand(currentCommand));
				lastIndex = i;
			}
			else if (userEntered.size()-1 == i)
			{
				currentCommand = userEntered.substr(lastIndex, i-lastIndex+1);
				currentCommand = trim(currentCommand);
				if (currentCommand != "") {addToCmds(userEntered.at(lastIndex), createCommand(currentCommand));}
				lastIndex = i;
			}
		}
		executeCommands();
	}
	return 0;
}
