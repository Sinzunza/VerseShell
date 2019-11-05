#ifndef INDCONNECTOR_HPP
#define INDCONNECTOR_HPP
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class indConnector : public base {
	public:
		indConnector() : base() { succeeded = false; }
        	virtual void execute(char* args[]){
            		pid_t pid = fork();
			if (pid < 0){
				 std::cout << "Fork failed." << std::endl;
			}
            		else if (pid == 0){
                		execvp(args[0],args);
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

