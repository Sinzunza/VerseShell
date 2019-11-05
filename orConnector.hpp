#ifndef ORCONNECTOR_HPP
#define ORDCONNECTOR_HPP
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
			(!leftBase->getSucceeded()) {
            			pid_t pid = fork();
            			if (pid == 0){
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

