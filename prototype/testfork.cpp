#include <string>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	std::string out = "Whats scarier than one output? Two outputs!!";
	fork();
	std::cout << out << std::endl;
}
