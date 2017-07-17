#include "Logger/Logger.h"



int main()
{
	logging::Logger::makeLogger("console");
	logging::Logger::setDebugLevel(logging::Logger::INTERMEDIATE);

	logging::out << logging::Logger::LOW << "not printed\n" << logging::Logger::HIGH << "printed\n";
}
