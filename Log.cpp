#include "Log.h"

#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "StubLogger.h"

class LoggerException : public std::exception
{
	const char* what() const throw() {
		std::ostringstream getNr;
		getNr << "Logger Exception - Logger have to be initialized before logging!";
		return getNr.str().c_str();
	}
};

Log* Log::instance = nullptr;
Log::Level Log::logLevel = Level::HIGH;
Log::Level Log::localLogLevel = Level::LOW;

Log& Log::log()
{
	if (!instance)
		throw LoggerException();
	return *instance;
}

void Log::makeLogger(const std::string &logger)
{
	if(instance)
		delete instance;

	if(logger == "console")
		Log::instance = new ConsoleLogger();
	else if(logger == "file")
		Log::instance = new FileLogger();
	else if (logger == "console file")
		Log::instance = new StubLogger();
	else
		Log::instance = new StubLogger();
}

void Log::setDebugLevel(const Level &level)
{
	logLevel = level;
}


Log::~Log()
{
	if (instance)
		delete instance;
}

