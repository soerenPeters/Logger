#include "ConsoleSink.h"

namespace logging {

	void ConsoleSink::log(const std::string &log)
	{
		std::cout << log;
	}

}