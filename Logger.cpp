#include "Logger.h"

#include <memory>

#include <LoggerSinks/LoggerSink.h>
#include <LoggerSinks/implementations/ConsoleSink.h>
#include <LoggerSinks/implementations/FileSink.h>
#include <LoggerSinks/implementations/StubSink.h>

namespace logging
{
	class Logger::impl
	{
	public:
		static std::unique_ptr<LoggerSink> logSink;
		static Level logLevel;
		static Level localLogLevel;
	};

	Logger::Level Logger::impl::logLevel = Level::HIGH;
	Logger::Level Logger::impl::localLogLevel = Level::LOW;
	std::unique_ptr<LoggerSink> Logger::impl::logSink = nullptr;

	Logger::Logger() : pimpl(new impl())
	{

	}

	Logger::~Logger()
	{
		delete pimpl;
	}

	void Logger::makeLogger(const std::string &logger, const std::string &path)
	{
		if(logger == "console")
			impl::logSink = std::unique_ptr<LoggerSink>(new ConsoleSink());
		else if (logger == "file")
			impl::logSink = std::unique_ptr<LoggerSink>(new FileSink(path));
		else
			impl::logSink = std::unique_ptr<LoggerSink>(new StubSink());
	}

	void Logger::setDebugLevel(const Level &level) 
	{
		impl::logLevel = level;
	}

	Logger Logger::operator<<(const std::string log)
	{
		if (impl::localLogLevel >= impl::logLevel)
			impl::logSink->log(log);

		return Logger();
	}

	Logger Logger::operator<<(const Level &level)
	{
		impl::localLogLevel = level;
		return Logger();
	}

}
