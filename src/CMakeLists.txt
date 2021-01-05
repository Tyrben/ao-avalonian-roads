cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(class_SOURCES
	csv/csvformat.h
	csv/csvformat.cpp
	map.h
	map.cpp
	navigationsystem.h
	navigationsystem.cpp
	portal.h
	portal.cpp
	world.h
	world.cpp)

add_library(ao-avalonian-roads-lib STATIC ${class_SOURCES})

target_include_directories(ao-avalonian-roads-lib
	PRIVATE ../vendor/libgraph
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
