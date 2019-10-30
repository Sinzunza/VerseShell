#include <iostream>
#include <string>

void createCommand(std::string);

int main()
{
	// Maximum allowed arguments = 8
	std::string input = "ls -f || touch meme.cpp && rm meme.cpp ; ls";
	while (input != "")
	{
		//Erase leading and trailing whitespace
		while(input.front() == ' ') {input.erase(0,1);}
		while(input.back() == ' ') {input.pop_back();}

		//Look for any connectors
		std::size_t posOfConnector;
		posOfConnector = input.rfind(";",0);
		if (posOfConnector!=std::string::npos)
		{
			createCommand(input.substr(posOfConnector+1, std::string::npos));
			input.erase(posOfConnector,std::string::npos);
			std::cout << "Semicolon connector found!" << std::endl;
		}
		else {
		posOfConnector = input.rfind("&&",0);
		if (posOfConnector!=std::string::npos)
		{
			createCommand(input.substr(posOfConnector+2, std::string::npos));
			input.erase(posOfConnector,std::string::npos);
			std::cout << "And connector found!" << std::endl;
		}
		else {
		posOfConnector = input.rfind("||",0);
		if (posOfConnector!=std::string::npos)
		{
			createCommand(input.substr(posOfConnector+2, std::string::npos));
			input.erase(posOfConnector,std::string::npos);
			std::cout << "Or connector found!" << std::endl;
		}
		//If there are no connectors, simply execute the given command
		else {
			createCommand(input);
			input.erase(0,std::string::npos);
			std::cout << "This should be the first command." << std::endl;
		}}}
	}
	std::cout << "All finished!" << std::endl;
	return 0;
}

void createCommand(std::string fragment)
{
	unsigned index = 0;
	char* execs[10];
	execs[9] = NULL; //TODO: Dynamically allocate the size of the array, and then tag on NULL onto the end of it.
	while(fragment != "")
	{
		size_t loc = fragment.find_first_of(' ',0);
		std::string temp = fragment.substr(0,loc+1);
		execs[index] = const_cast<char*>(temp.c_str());
		fragment.erase(0,loc+1);
		while(fragment.front() == ' ') {fragment.erase(0,1);}
		while(fragment.back() == ' ') {fragment.pop_back();}
	}
	std::cout << "I'm thinking of printing out ";	
	for (int i = 0; i < 9; i++)
	{
		std::cout << execs[i] << " ";
	}
	std::cout << std::endl;
}
