#include "Logger.h"

namespace log
{
	Logger::Level Logger::logLevel = Level::HIGH;
	Logger::Level Logger::localLogLevel = Level::LOW;
	std::unique_ptr<LogSink> Logger::logSink = nullptr;

	void Logger::makeLogger(const std::string &logger) {
		logSink = std::unique_ptr<LogSink>(new ConsoleSink());

	}

	void Logger::setDebugLevel(const Level &level) {
		logLevel = level;
	}

	Logger::~Logger() {

	}

}
