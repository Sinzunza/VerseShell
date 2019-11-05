#ifndef ORCONNECTOR_HPP
#define ORCONNECTOR_HPP
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "base.hpp"

class orConnector : public base {
	public: 
		orConnector(base *leftBase) : base(){
			this->leftBase = leftBase;
			succeeded = false;
		}       
		virtual void execute(char* args[]){	
			if (!leftBase->getSucceeded()) {
            			pid_t pid = fork();
				if (pid < 0){
					 std::cout << "Fork failed." << std::endl;
				}
            			else if (pid == 0){
                			execvp(args[0],args);
            			}
            			else{
					int status;
					waitpid(0, &status, WCONTINUED); 
					if(WIFEXITED(status)){
						succeeded = true;
					}   
	    			}
	    		}		
		}
	private:
		base *leftBase;
};

#endif

