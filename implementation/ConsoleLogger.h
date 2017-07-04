#ifndef ConsoleLogger_h
#define ConsoleLogger_h

#include "Logger_EXPORT.h"
#include <iostream>


#include "Log.h"

class ConsoleLogger : public Log
{
public:
	virtual ~ConsoleLogger() {};

	ConsoleLogger() {}

	virtual Log& operator << (const int &arg) override
	{
		return log(arg);
	}

	virtual Log& operator << (const std::string &arg) override
	{
		return log(arg);
	}

	virtual Log& operator << (const double &arg) override
	{
		return log(arg);
	}


	virtual Log &operator <<(const Level &level) override
	{
		localLogLevel = level;
		return *instance;
	}

private:
	template <typename T>
	Log& log(const T& arg)
	{
		if(localLogLevel >= logLevel)
			std::cout << arg;
		return *instance;
	}

	ConsoleLogger(const ConsoleLogger&) {}

};


#endif
