#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>

class base
{
	public:
		base() { };
		bool isSuccessful(){ return succeeded; }
		bool isExit()	
		{
            return exited;
		}
		virtual void execute() = 0;
	protected:
		bool succeeded;
        bool exited;
		char* arguments[10];
};
#endif
