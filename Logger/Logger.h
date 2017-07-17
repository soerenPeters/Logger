#ifndef Logger_H
#define Logger_H

#include "../Logger_EXPORT.h"

#include <string>

namespace logging
{
	class /*Logger_EXPORT */Logger
	{
	public:
		enum Level
		{
			HIGH = 3,
			INTERMEDIATE = 2,
			LOW = 1
		};

		Logger();
		virtual ~Logger();

		static void makeLogger(const std::string &logger, const std::string &path = "");
		static void setDebugLevel(const Level &level = Level::HIGH);
		virtual Logger operator<<(const Level &level);
		virtual Logger operator<<(const std::string log);

	private:
		class impl;
		impl* pimpl;
	};

	static Logger out;

}

#endif
