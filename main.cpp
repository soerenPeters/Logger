#include "Logger/Logger.h"

using namespace logging;

int main()
{
	Logger::makeLogger("console");
	Logger::setDebugLevel(Logger::INTERMEDIATE);

	out << Logger::LOW << "not printed\n" << Logger::HIGH << "printed\n";

	Logger::makeLogger("stub");
	out << Logger::HIGH << "not printed\n";

	Logger::makeLogger("file", "../log.txt");
	out << Logger::HIGH << "printed to file...\n";

	Logger::makeLogger("console file", "../log.txt");
	out << Logger::HIGH << "printed to file and console...\n";
}
