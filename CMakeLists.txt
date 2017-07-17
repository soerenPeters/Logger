cmake_minimum_required(VERSION 2.8)
project(Logger)

set(
    source_list
	"main.cpp"
    "Logger/Logger.cpp"
    "Logger/Logger.h"
    "LoggerSinks/LoggerSink.h"
    "LoggerSinks/implementations/FileSink.h"
	"LoggerSinks/implementations/FileSink.cpp"
	
	"LoggerSinks/implementations/ConsoleFileSink.h"
	"LoggerSinks/implementations/ConsoleFileSink.cpp"
	
	"LoggerSinks/implementations/ConsoleSink.h"
	"LoggerSinks/implementations/ConsoleSink.cpp"
	
	"LoggerSinks/implementations/StubSink.h"
	"LoggerSinks/implementations/StubSink.cpp"
)

foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()

include_directories(${CMAKE_SOURCE_DIR})
add_executable(Logger ${source_list})