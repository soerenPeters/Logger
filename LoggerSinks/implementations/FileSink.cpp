#include "FileSink.h"

#include <iostream>


namespace logging
{

	FileSink::FileSink(const std::string &path)
	{
		file = fopen(path.c_str(), "a");
		if (!file)
			exitProgram(path);
		logTime();
	}

	void FileSink::log(const std::string &log)
	{
		fprintf(file, log.c_str());
	}

	FileSink::~FileSink()
	{
		fclose(file);
	}

	void FileSink::exitProgram(const std::string &path)
	{
		printf("can't open logging file. %s\n", path.c_str());
		exit(1);
	}

	void FileSink::logTime()
	{
		std::time_t t = std::time(0);
		struct tm tm = *localtime(&t);
		fprintf(file, "\n--START LOGGING : %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	}

}