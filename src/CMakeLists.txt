cmake_minimum_required(VERSION 3.9)

project(ao-avaloniqn-roads
	VERSION 0.1
	DESCRIPTION "Mapping system for AO Avalonian Roads"
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( source_files
	main.cpp
	map.h
	map.cpp
	portal.h
	portal.cpp
	id.h
	uniquenumbergenerator.h
	uniquenumbergenerator.cpp)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-gps ${source_files})

add_subdirectory(../vendor/libgraph ./lib)

target_include_directories(ao-avalonian-roads-gps
	PRIVATE ../vendor/libgraph )

target_link_libraries(ao-avalonian-roads-gps PRIVATE libgraph)
