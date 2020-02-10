# VerseShell

Sergio Inzunza,   
Garrett Pedvin

 ### Installation
Open the terminal and run these commands:
```
1. git clone --recursive https://github.com/Sinzunza93/RShell.git
2. cd VerseShell
3. cmake . 
4. make
5. ./VerseShell
```

### Introduction
This program is a unix command shell which is able to Print a command prompt (e.g. `$`). Read in a line of command(s) (and connector(s)) from standard input. And execute the appropriate commands using fork , execvp , and waitpid commands. We are using the composite pattern design for representing the commands and connecters. The inputs are ingested through the getline() function and then through iteration of the the string inputs are seperated and transformed into objects for each command, based on the previous connector (if applicable). Each object has an execute() function that will run the command stored within the object, as well as a createCommand function that transforms the stored string into a given argument list. VerseShell supports commented code, argument lists enclosed in quotations, operators including and (&&) and or (||), I/O redirection as well as an inbuilt test command (using either the *test* command or using square brackets) and precedence (e.g. parenthesis).

### Classes
We have a group of classes in the form of the composite pattern.

base - The base object for the various types of command objects. Contains flags for if the command ran successfully or is an exit command, the createCommand class that transforms a given portion of the input string into a usable vector of cstrings, and a pure virtual execute function.

indConnector - Subclass of base. Signifies that the previous connector was either a semicolon, or the command is the first found in a given input. Contains a constructor and an implementation of execute().

orConnector - Subclass of base. Signifies that the previous connector was an or connector, and thus the command object will not call execvp() if the previous command succeeded. Contains a constructor and an implementation of execute().

andConnector - Subclass of base. Signifies that the previous connector was an and connector, and thus the command object will not call execvp() if the previous command failed. Contains a constructor and an implementation of execute().

indParen, orParen, andParen - Wrapper classes of their respective connectors. Allows for precedence operations. Simply re-parses the string recursively in order to execute them in order of priority.

**Other/Miscellaneous Classes:**

parse - Helper class for main in order to digest and transform user input.

### Diagram
![OMT Diagram](https://github.com/Sinzunza93/RShell/blob/master/images/OMT%20Diagram.jpeg)

### Prototypes/Research
The **waitpid()**, **execvp()**, and **fork()** commands are how our program is able to address and execute commands. **fork()** creates a child process that is duplicate of the current, parent process, but exists with a process id of 0, so it can be distinguished and sent off to do other tasks with the **execvp()** command. The **execvp()** command allows us to choose a command as well as a character array of arguments and essentially send them to the command line. Meanwhile, the parent process calls **waitpid()**, enabling it to monitor for the child task's completion before returning back to regular code execution. These three functions will be used mainly in the class that handles the command requests themselves.

Parsing the input from the user can be easily subdivided into different tasks considering how commands will be entered. We can separate each string of text into commands and connectors, and each command can be digested and placed into a char const array where it will be sent off to the execvp() command. With the input string, we will work front to back to allow inorder traversal to be more viable. 

There are three different types of connectors we will be using. The semicolon (;) connector ensures that commands run in a proper sequence; when this connector is reached, all commands before it will be executed. The and (&&) connector enforces that commands areran until an unsuccessful execution is made, and the or (||) processor will run commands only up to the first one that is completed successfully. We will have classes differentiating how And and Or connectors work, while semicolon connectors will automatically be built into the input parser.

### Known Bugs 
- The symbolic representation for the *test* command as well as the precedence operators only function properly when a space exists between the symbol and the next character in the argument. (e.g.: ( echo hello ) works, but (echo hello) does not).


11/2019
