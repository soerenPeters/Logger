#ifndef Log_h
#define Log_h

#include "Logger_EXPORT.h"
#include <string>
#include <exception>
#include <sstream>


class Log
{
public:
	enum Level {
		HIGH = 3,
		INTERMEDIATE = 2,
		LOW = 1
	};

	static Log Logger_EXPORT &log();

	static void Logger_EXPORT makeLogger(const std::string &logger);
	static void Logger_EXPORT setDebugLevel(const Level &level = Level::HIGH);

	virtual Logger_EXPORT ~Log();

	virtual Log Logger_EXPORT &operator << (const Level &level) = 0;
	virtual Log Logger_EXPORT &operator << (const int &arg) = 0;
	virtual Log Logger_EXPORT &operator << (const std::string &arg) = 0;
	virtual Log Logger_EXPORT &operator << (const double &arg) = 0;


protected:
	static Log* instance;
	static Level logLevel;
	static Level localLogLevel;

};


#endif
