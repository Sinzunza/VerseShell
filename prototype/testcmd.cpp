#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include <iostream>

int main()
{
	//set the arguments beforehand
	std::string command = "ls";
	std::string arg1 = "-f";
	char* args[3];
	args[0] = const_cast<char*>(command.c_str());
	args[1] = const_cast<char*>(arg1.c_str());
	args[2] = NULL;
	
	pid_t pid = fork(); //get your fork
	if (pid < 0) std::cout << "Fork you!" << std::endl;
	if (pid == 0) execvp(args[0],args);
	else if (pid > 0)
	{
		int* comments;
		pid_t finish = waitpid(0, comments, WCONTINUED);
		std::cout << "Child terminated with exit code " << comments << std::endl;
	}
	return 0;
}
