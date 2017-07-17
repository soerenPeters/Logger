#include "ConsoleFileSink.h"
#include "FileSink.h"
#include "ConsoleSink.h"

namespace logging
{
	ConsoleFileSink::ConsoleFileSink(const std::string &path)
	{
		fileSink = std::shared_ptr<FileSink>(new FileSink(path));
		consoleSink = std::shared_ptr<ConsoleSink>(new ConsoleSink());
	}

	void ConsoleFileSink::log(const std::string &log)
	{
		fileSink->log(log);
		consoleSink->log(log);
	}

}