#ifndef LoggerSink_H
#define LoggerSink_H

#include <string>

namespace logging
{
	class LoggerSink
	{
	public:
		virtual void log(const std::string &log) = 0;
	};
}

#endif
