#ifndef ConsoleFileSink_H
#define ConsoleFileSink_H

#include <string>
#include <memory>

#include "../LoggerSink.h"

namespace logging
{
	class FileSink;
	class ConsoleSink;

	class ConsoleFileSink : public LoggerSink
	{
	public:
		ConsoleFileSink(const std::string &path);
		virtual void log(const std::string &log);

	private:
		std::shared_ptr<FileSink> fileSink;
		std::shared_ptr<ConsoleSink> consoleSink;
	};

}

#endif
