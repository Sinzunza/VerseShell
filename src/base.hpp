#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>

class base
{
	public:
		base() { };
		bool getSucceeded(){ return succeeded; }
		bool isExit()	
		{
			if (arguments[0] == "exit") {return true;}
			else {return false;}
		}
		virtual void execute() = 0;
	protected:
		bool succeeded;
		char* arguments[10];
};
#endif
