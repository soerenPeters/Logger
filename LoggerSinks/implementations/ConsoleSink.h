#ifndef ConsoleSink_H
#define ConsoleSink_H

#include <string>
#include <iostream>

#include "../LoggerSink.h"

namespace logging
{

	class ConsoleSink : public LoggerSink
	{
	public:
		virtual void log(const std::string &log);
	};

}

#endif
