#ifndef StubSink_H
#define StubSink_H

#include <string>
#include <iostream>

#include "../LoggerSink.h"

namespace logging
{
	
	class StubSink : public LoggerSink
	{
		virtual void log(const std::string &log)
		{
			std::cout << log;
		}
	};

}

#endif
