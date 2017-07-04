#ifndef StubLogger_H
#define StubLogger_H

#include "Logger_EXPORT.h"
#include <iostream>


#include "Log.h"

class StubLogger : public Log
{
public:
	virtual ~StubLogger() {};

	StubLogger() {}

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


	virtual Log Logger_EXPORT &operator <<(const Level &level) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

private:
	template <typename T>
	Log& log(const T& arg)
	{
		
		return *instance;
	}


	StubLogger(const StubLogger&) {}

};

#endif
