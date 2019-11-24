#ifndef ORCONNECTOR_HPP
#define ORCONNECTOR_HPP
#include "base.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

class orConnector : public base {
	public: 
		
		orConnector(base *leftBase, char* args[]) : base(){
			this->leftBase = leftBase;
			for (unsigned i = 0; i < 10; i++)
			{
				arguments[i] = args[i];
			}
			succeeded = false; 
			exited = false;
		}       
		virtual void execute(){	
			if (!leftBase->isSuccessful()) {
               			if (strcmp(arguments[0], "exit") == 0){ //check if user wants to exit, before anything
                    			exited = true;
                		}		
                		else {
                    			pid_t pid = fork();
                    			if (pid < 0){
                        			std::cout << "Fork failed." << std::endl;
                    			}
            				else if (pid == 0){
                        			execvp(arguments[0],arguments);
                        			perror("command execution failed");
            				}
            				else {
                        			int status;
                        			waitpid(0, &status, WCONTINUED); 
                        			perror("wait for child failed");
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

	private:
		base *leftBase;

};

#endif
