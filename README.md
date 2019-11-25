# CS 100 RShell
Fall 2019


Sergio Inzunza, 862187623, sinzu003@ucr.edu
Garrett Pedvin, 862085838, gpedv002@ucr.edu

### Introduction
This program is a command shell which is able to Print a command prompt (e.g. `$`). Read in a line of command(s) (and connector(s)) from standard input. And execute the appropriate 
commands using fork , execvp , and waitpid Commands. We are using the composite pattern design for representing the commands and connecters. The inputs are ingested through the getline() function and then through iteration of the the string inputs are seperated and transformed into objects for each command. Those objects contain an execute() function which will run depending on the connector to it's left and, depending on that, the command to the left.

### Diagram
![alternative text](https://github.com/cs100/assignment-sigp/blob/master/images/OMT%20Diagram.jpeg)

### Classes
We have a group of classes in the form of the composite pattern.

base class - Is an abstract class. It has a pure virtual void execute() function. 

indConnector class - A sub-class of base. It is a leaf. It is used for objects of the first command or commands that have the ; connecter to the left. 
This class has no additional members. 

andConnector class - A sub-class of base. It has a base pointer as a private member. This is therefore a composite. This class is used to create objects of commands that have 
the && connector to the left. The object it takes in is the object of the command to it's left. In the execute function it checks if the object it is passed in has executed. 
If so it executes.

orConnector class - A sub-class of base. It has a base pointer as a private member. This is therefore a composite. This class is used to create objects of commands that have 
the || connector to the left. The object it takes in is the object of the command to it's left. In the execute function it checks if the object it is passed in has not executed. 
If not it executes.

### Prototypes/Research
The **waitpid()**, **execvp()**, and **fork()** commands are how our program is able to address and execute commands. **fork()** creates a child process that is duplicate of the current, parent process, but exists with a process id of 0, so it can be distinguished and sent off to do other tasks with the **execvp()** command. The **execvp()** command allows us to choose a command as well as a character array of arguments and essentially send them to the command line. Meanwhile, the parent process calls **waitpid()**, enabling it to monitor for the child task's completion before returning back to regular code execution. These three functions will be used mainly in the class that handles the command requests themselves.

Parsing the input from the user can be easily subdivided into different tasks considering how commands will be entered. We can separate each string of text into commands and connectors, and each command can be digested and placed into a char const array where it will be sent off to the execvp() command. With the input string, we will work front to back to allow inorder traversal to be more viable. 

There are three different types of connectors we will be using. The semicolon (;) connector ensures that commands run in a proper sequence; when this connector is reached, all commands before it will be executed. The and (&&) connector enforces that commands areran until an unsuccessful execution is made, and the or (||) processor will run commands only up to the first one that is completed successfully. We will have classes differentiating how And and Or connectors work, while semicolon connectors will automatically be built into the input parser.

### Development and Testing Roadmap
- Create composite class structure
  - Create base class - Completed!
    - Unit test base class with mocks
  - Create and (&&) connector class - Completed!
    - Unit test
  - Create or (||) connector class - Completed!
    - Unit test
  - Create command class - Completed!
    - Unit test
  - Integration test with mock main - Completed!
- Create main
  - Create main function loop - Completed!
  - Create function parser - Completed!
  - Thorough and rigorous unit testing - Completed!
  - Test single commands - Completed!
  - Test connected commands - Completed!
  - Test commands with comments - Completed!
  - Test exit commands - Completed!
