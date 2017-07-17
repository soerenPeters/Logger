#ifndef ConsoleSink_H
#define ConsoleSink_H

#include <string>
#include <iostream>

#include "../LoggerSink.h"

namespace logging
{

	class ConsoleSink : public LoggerSink
	{
		virtual void log(const std::string &log)
		{
			std::cout << log;
		}
	};

}

#endif
