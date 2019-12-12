#include "../header/parse.h"

std::vector <base*> parse::parseString(base* lastCommand, std::string userEntered, int &i, int &lastIndex)
{
                std::size_t found = userEntered.find('#'); //if comment found trim anything after comment
                if (found!=std::string::npos)
                {
                    userEntered = userEntered.substr(0,found);
                }
            
                std::string currentCommand;
                bool insideQuotes = false;
                std::vector <base*> allCommands;
                for (i; i < userEntered.length(); i++)
                {
                    if(userEntered.at(i) == ';' || userEntered.substr(i,2) == "&&" ||userEntered.substr(i,2) == "||" || userEntered.at(i) == '"' || userEntered.at(i) == '(' || userEntered.at(i) == ')' || i == userEntered.length()-1)
                    {
                        if(userEntered.at(lastIndex) == ')'){
                            lastIndex = i;
                        }
                        else {
                            if(userEntered.at(i) == '"' && i == userEntered.length()-1) //quotes
                            {
                                insideQuotes = false;
                            }
                            if(userEntered.at(i) == '"' && i != userEntered.length()-1)
                             {
                                    if(!insideQuotes)
                                    {
                                            insideQuotes = true;
                                    }
                                    else
                                    {
                                            insideQuotes = false;
                                    }
                            }

                            else if (lastIndex == 0 && !insideQuotes) //first command
                            {

                                if(i != userEntered.length()-1)
                                { 
                                    currentCommand = userEntered.substr(lastIndex,i);
                                }
                                else { 
                                    currentCommand = userEntered.substr(lastIndex,i+1); 
                                }

                                if (userEntered.at(i) == '(')
                                {
                                    userEntered.at(i) = ' ';
                                    base* firstParenBase = new indParen(userEntered, i, lastIndex);
                                    lastCommand = firstParenBase;
                                    allCommands.push_back(lastCommand);

                                }
                                else 
                                {
                                    lastIndex = i;
                                    if (userEntered.at(i) == ')')
                                    {
                                        currentCommand = currentCommand.substr(0, currentCommand.length() -1 );
                                    }
                                    base *firstBase = new indConnector(currentCommand);
                                    lastCommand = firstBase;
                                    allCommands.push_back(lastCommand);
                                    if (userEntered.at(i) == ')')
                                    {
                                        return allCommands;
                                    }
                                }
                                
                            }
                            else if (userEntered.at(lastIndex) == ';' && !insideQuotes ) //indConnector
                            {

                                if(i != userEntered.length()-1){
                                    currentCommand = userEntered.substr(lastIndex + 1,(i - (lastIndex+1)));
                                }
                                else { 
                                    currentCommand = userEntered.substr(lastIndex + 1,(i - (lastIndex)));
                                }

                                if (userEntered.at(i) == '(')
                                {
                                    userEntered.at(i) = ' ';
                                    base* indParenBase = new indParen(userEntered, i, lastIndex);
                                    lastCommand = indParenBase;
                                    allCommands.push_back(lastCommand);

                                }
                                else 
                                {
                                    lastIndex = i;
                                    if (userEntered.at(i) == ')')
                                    {
                                        currentCommand = currentCommand.substr(0, currentCommand.length() -1 );
                                    }
                                    base *indBase = new indConnector(currentCommand);
                                    lastCommand = indBase;
                                    allCommands.push_back(lastCommand);
                                    if (userEntered.at(i) == ')')
                                    {
                                        return allCommands;
                                    }
                                }

                            }
                            else if (userEntered.substr(lastIndex,2) == "&&" && !insideQuotes && lastIndex+1 != i) //andConnector
                            {
                                if (i != userEntered.length()-1) 
                                { 
                                    currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 2))); 
                                }
                                else 
                                { 
                                    currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 1))); 
                                }
                                
                                if (userEntered.at(i) == '(')
                                {
                                    userEntered.at(i) = ' ';
                                    base* andParenBase = new andParen(lastCommand, userEntered, i, lastIndex);
                                    lastCommand = andParenBase;
                                    allCommands.push_back(lastCommand);

                                }
                                else 
                                {
                                    lastIndex = i;
                                    if (userEntered.at(i) == ')')
                                    {
                                        currentCommand = currentCommand.substr(0, currentCommand.length() -1 );
                                    }
                                    base *andBase = new andConnector(lastCommand, currentCommand);
                                    lastCommand = andBase;
                                    allCommands.push_back(lastCommand);
                                    if (userEntered.at(i) == ')')
                                    {
                                        return allCommands;
                                    }
                                }

                            }
                            else if(userEntered.substr(lastIndex,2) == "||" && !insideQuotes &&  lastIndex+1 != i) //orConnector
                            {
                                if(i != userEntered.length()-1)
                                { 
                                    currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 2)));
                                }
                                else 
                                { 
                                    currentCommand = userEntered.substr(lastIndex + 2,(i - (lastIndex + 1)));
                                }
                                
                                if (userEntered.at(i) == '(')
                                {
                                    userEntered.at(i) = ' ';
                                    base* orParenBase = new orParen(lastCommand, userEntered, i, lastIndex);
                                    lastCommand = orParenBase;
                                    allCommands.push_back(lastCommand);

                                }
                                else 
                                {
                                    lastIndex = i;
                                    if (userEntered.at(i) == ')')
                                    {
                                        currentCommand = currentCommand.substr(0, currentCommand.length() -1 );
                                    }
                                    base *orBase = new orConnector(lastCommand,currentCommand);
                                    lastCommand = orBase;
                                    allCommands.push_back(lastCommand);
                                    if (userEntered.at(i) == ')')
                                    {
                                        return allCommands;
                                    }
                                }
                                
                            }
                        }
                    }
                }
            
                return allCommands;
}
