#ifndef FileSink_H
#define FileSink_H

#include <string>
#include <ctime>

#include "../LoggerSink.h"

namespace logging
{
	class FileSink : public LoggerSink
	{
	public:
		FileSink(const std::string &path);
		virtual void log(const std::string &log);

	private:
		void exitProgram(const std::string &path);
		void logTime();

		FILE *file;
	};

}

#endif
