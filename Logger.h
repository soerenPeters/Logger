#ifndef Logger_H
#define Logger_H

#include <string>
#include <sstream>
#include <memory>
#include <iostream>

namespace log
{
	class LogSink
	{
	public:
		virtual void log(const std::string &log)= 0;
	};

	class ConsoleSink : public LogSink
	{
		virtual void log(const std::string &log)
		{
			std::cout << log;
		}
	};

	class Logger
	{
	public:
		enum Level
		{
			HIGH = 3,
			INTERMEDIATE = 2,
			LOW = 1
		};

		static void makeLogger(const std::string &logger);

		static void setDebugLevel(const Level &level = Level::HIGH);

		virtual ~Logger();

		virtual Logger operator<<(const Level &level) { this->localLogLevel = level; }

		virtual Logger operator<<(const std::string log)
		{
			if(localLogLevel >= logLevel)
				logSink->log(log);
		}

	protected:
		static std::unique_ptr<LogSink> logSink;
		static Level logLevel;
		static Level localLogLevel;

	};

	static Logger out;

}

#endif
