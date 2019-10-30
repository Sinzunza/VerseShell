# CS 100 RShell
Fall 2019

Sergio Inzunza, 86xxxxxxx, sinzu003@ucr.edu
//todo: please update your student id

Garrett Pedvin, 862085838, gpedv002@ucr.edu

### Introduction
- What will we accomplish with this project?
- What design patterns will be used?
- How are inputs ingested, transformed, and processed?

### Diagram
[Lucidchart will help.](https://www.lucidchart.com/pages/)

### Classes
Describe each class.

### Prototypes/Research
The **waitpid()**, **execvp()**, and **fork()** commands are how our program is able to address and execute commands. **fork()** creates a child process that is duplicate of the current, parent process, but exists with a process id of 0, so it can be distinguished and sent off to do other tasks with the **execvp()** command. The **execvp()** command allows us to choose a command as well as a character array of arguments and essentially send them to the command line. Meanwhile, the parent process calls **waitpid()**, enabling it to monitor for the child task's completion before returning back to regular code execution. These three functions will be used mainly in the class that handles the command requests themselves.

Parsing the input from the user can be easily subdivided into different tasks considering how commands will be entered. We can separate each string of text into commands and connectors, and each command can be digested and placed into a char const array where it will be sent off to the execvp() command. With the input string, we will work front to back to allow inorder traversal to be more viable. 

There are three different types of connectors we will be using. The semicolon (;) connector ensures that commands run in a proper sequence; when this connector is reached, all commands before it will be executed. The and (&&) connector enforces that commands areran until an unsuccessful execution is made, and the or (||) processor will run commands only up to the first one that is completed successfully. We will have classes differentiating how And and Or connectors work, while semicolon connectors will automatically be built into the input parser.

### Development and Testing Roadmap
- Create composite class structure
  - Create base class
    - Unit test base class with mocks
  - Create and (&&) connector class
    - Unit test
  - Create or (||) connector class
    - Unit test
  - Create command class
    - Unit test
  - Integration test with mock main
- Create main
  - Create main function loop
  - Create function parser
  - Thorough and rigorous unit testing
- Integration testing
  - Test single commands
  - Test connected commands
  - Test commands with comments
  - Test exit commands

//todo: add github issues and links with md
