#include "Logger/Logger.h"



int main()
{
	logging::Logger::makeLogger("console");
	logging::Logger::setDebugLevel(logging::Logger::INTERMEDIATE);

	logging::out << logging::Logger::LOW << "not printed\n" << logging::Logger::HIGH << "printed\n";

	logging::Logger::makeLogger("stub");
	logging::out << logging::Logger::HIGH << "not printed\n";

	logging::Logger::makeLogger("file", "../log.txt");
	logging::out << logging::Logger::HIGH << "printed to file...\n";

	logging::Logger::makeLogger("console file", "../log.txt");
	logging::out << logging::Logger::HIGH << "printed to file and console...\n";
}
