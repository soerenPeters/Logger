#ifndef FileSink_H
#define FileSink_H

#include <string>
#include <iostream>

#include "../LoggerSink.h"

namespace logging
{

	class FileSink : public LoggerSink
	{
		virtual void log(const std::string &log)
		{
			std::cout << log;
		}
	};

}

#endif
