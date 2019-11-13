#ifndef ORCONNECTOR_HPP
#define ORCONNECTOR_HPP
#include "base.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class orConnector : public base {
	public: 
		orConnector(base *leftBase, char* args[]) : base(){
			this->leftBase = leftBase;
			for (unsigned i = 0; i < 10; i++)
			{
				arguments[i] = args[i];
			}
			succeeded = false;
		}       
		virtual void execute(){	
			if (!leftBase->getSucceeded()) {
            			pid_t pid = fork();
				if (pid < 0){
					 std::cout << "Fork failed." << std::endl;
				}
            			else if (pid == 0){
                			execvp(arguments[0],arguments);
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

