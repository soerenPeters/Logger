#ifndef StubSink_H
#define StubSink_H

#include <string>

#include "../LoggerSink.h"

namespace logging
{
	
	class StubSink : public LoggerSink
	{
		virtual void log(const std::string &log)
		{
			
		}
	};

}

#endif
