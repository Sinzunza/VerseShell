#ifndef ANDCONNECTOR_HPP
#define ANDCONNECTOR_HPP

#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "base.hpp"

class andConnector : public base {

    public:

        andConnector(base *leftBase, std::string command) : base() {
            this->leftBase = leftBase;
            this->command = command;
            succeeded = false;
            exited = false;
        }

        virtual void execute() {

            if (leftBase->isSuccessful()) {
                int size;
                arguments = createCommand(command, size);

                if (strcmp(arguments[0], "exit") == 0) { //check if user wants to exit, before anything
                    exited = true;
                }
                else if (strcmp(arguments[0], "test") == 0 || (strcmp(arguments[0], "[") == 0 && (strcmp(arguments[2], "]") == 0 || strcmp(arguments[3], "]") == 0))) {

                    if(strcmp(arguments[0], "test") != 0 && strcmp(arguments[2], "]") == 0) {
                        arguments[2] = NULL;
                    }

                    executeTest();
                }
                else {

                    std::string maybe_cd(arguments[0]);

                    if(maybe_cd == "cd") { //if changing dir, no need to fork
                        int num = chdir(arguments[1]);

                        if(num == 0) {
                            succeeded = true;
                        }
                        else {
                            perror("command execution failed");
                        }
                    }
                    else {
                        pid_t pid = fork();

                        if (pid < 0) {
                            std::cout << "Fork failed." << std::endl;
                        }
                        else if (pid == 0) { //child
                            std::string fileName;

                            for(unsigned i = 0; i < command.size() ; i++) { //check for redirection

                                if (command.substr(i,2) == ">>" || command.at(i) == '>' || command.at(i) == '<') {

                                    if(command.substr(i,2) == ">>") {
                                        fileName = command.substr(i+2);
                                        std::stringstream theStream;
                                        theStream << fileName;
                                        theStream >> fileName;
                                        command = command.substr(0,i);
                                        int fdsOutputFile = open(fileName.c_str(), O_WRONLY | O_APPEND);
                                        dup2(fdsOutputFile, 1);
                                    }
                                    else if(command.at(i) == '>') {
                                        fileName = command.substr(i+1);
                                        std::stringstream theStream;
                                        theStream << fileName;
                                        theStream >> fileName;
                                        command = command.substr(0,i);
                                        int fdsTemp = open(fileName.c_str(), O_TRUNC);
                                        close(fdsTemp);
                                        int fdsOutputFile = open(fileName.c_str(), O_WRONLY);
                                        dup2(fdsOutputFile, 1);
                                    }
                                    else {
                                        fileName = command.substr(i+1);
                                        std::stringstream theStream;
                                        theStream << fileName;
                                        theStream >> fileName;
                                        command = command.substr(0,i);
                                        int fdsInputFile = open(fileName.c_str(), O_RDONLY);
                                        dup2(fdsInputFile, 0);
                                    }

                                    arguments = createCommand(command, size);
                                }
                            }

                            execvp(arguments[0],arguments);
                            perror("command execution failed");
                        }
                        else { //parent
                            int status;
                            waitpid(0, &status, WCONTINUED);

                            if(status == 0) {
                                succeeded = true;
                            }
                        }

                        if(pid == 0) {
                            _exit(-1);
                        }
                    }
                }

                for(unsigned j = 0; j < size; j++) {
                    delete [] arguments[j];
                }

                delete [] arguments;
            }
        }

    private:

        base *leftBase;

};

#endif
