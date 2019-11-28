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
		
		orConnector(base *leftBase, std::string aCommand) : base()
        	{
			this->leftBase = leftBase;
			command = aCommand;
			succeeded = true; 
			exited = false;
		}  
    
		virtual void execute()
        	{	  
            		if (!leftBase->isSuccessful()) 
            		{
                        	int size;
                        	arguments = createCommand(command, size);
                
               			if (strcmp(arguments[0], "exit") == 0) //check if user wants to exit before anything
                        	{
                    			exited = true;
                		}
                        	else if (strcmp(arguments[0], "test") == 0 || (strcmp(arguments[0], "[") == 0 && (strcmp(arguments[2], "]") == 0 ||                                                                  strcmp(arguments[3], "]") == 0))) 
                        	{
                                	if(strcmp(arguments[0], "test") != 0 && strcmp(arguments[2], "]") == 0)
                                    	{
                                        	arguments[2] = NULL;
                                    	}
                                    	executeTest();  
                        	}
                		else {
                    			pid_t pid = fork();
                    			if (pid < 0)
                                	{
                        			std::cout << "Fork failed." << std::endl;
                    			}
            				else if (pid == 0)
                            		{
                        			execvp(arguments[0],arguments);
                        			perror("command execution failed");
            				}
            				else 
                            		{
                        			int status;
                        			waitpid(0, &status, WCONTINUED); 
                        			perror("wait for child:");
                        			if(status != 0)
                                    		{
                            				succeeded = false;
                        			}
                    			}
                    			if(pid == 0)
                                	{
                        			_exit(-1);
                    			}
                        	}
                
                        	for(unsigned j = 0; j < size; j++)
                        	{
                            		delete [] arguments[j];
                        	}
                        	delete [] arguments;
            		}
		}

	private:
		base *leftBase;

};

#endif
