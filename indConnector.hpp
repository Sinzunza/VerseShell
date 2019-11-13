#ifndef INDCONNECTOR_HPP
#define INDCONNECTOR_HPP
#include "base.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class indConnector : public base {
	public:
		indConnector(char* args[]) : base() {
			for(unsigned i = 0; i < 10; i++)
			{
				arguments[i] = args[i];
			}
		       	succeeded = false; }
        	virtual void execute(){
            		pid_t pid = fork();
			if (pid < 0){
				 std::cout << "Fork failed." << std::endl;
			}
            		else if (pid == 0){
                		execvp(arguments[0],arguments);
            		}
            		else {
				int status;
            			waitpid(0, &status, WCONTINUED);
				if(WIFEXITED(status)){
					succeeded = true;
				}	     
	    		}
		}
		
};

#endif

