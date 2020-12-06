cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(class_SOURCES
	map.h
	map.cpp
	portal.h
	portal.cpp
	grid.h
	grid.cpp
	id.h
	id.cpp
	uniquenumbergenerator.h
	uniquenumbergenerator.cpp)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-gps main.cpp ${class_SOURCES})

add_subdirectory(../vendor/libgraph ./lib)

target_compile_options(ao-avalonian-roads-gps PRIVATE -fpermissive)
#TODO check if needed here or if we can herite from libgraph using PUBLIC or INTERFACE

target_include_directories(ao-avalonian-roads-gps
	PRIVATE ../vendor/libgraph )

target_link_libraries(ao-avalonian-roads-gps PRIVATE libgraph)
