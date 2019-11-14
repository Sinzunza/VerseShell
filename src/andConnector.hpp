#ifndef ANDCONNECTOR_HPP
#define ANDCONNECTOR_HPP
#include "base.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

class andConnector : public base
{
	private:
		base *leftBase;
	public:
		andConnector(base *leftBase, char* args[]) : base(){
			this->leftBase = leftBase;
			for(unsigned i = 0; i < 10; i++)
			{
				arguments[i] = args[i];
			}
			succeeded = false;
            tempExit = false;
		}
		virtual void execute(){
			if (leftBase->getSucceeded())
			{
                if (strcmp(arguments[0], "exit") == 0){
                        tempExit = true;
                }
                else {
				pid_t pid = fork();
				if (pid < 0) { std::cout << "Fork failed." << std::endl; }
				else if (pid == 0)
				{
					execvp(arguments[0], arguments);
					perror("command execution failed");
				}
				else
				{
					int status;
					waitpid(0, &status, WCONTINUED);
				 	if(status == 0){
                                        	succeeded = true;
                                	}
                        	}
                        	if(pid == 0){
                        		_exit(-1);
                        	}
                }
			}	
		}		
};
#endif
