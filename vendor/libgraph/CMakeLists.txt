cmake_minimum_required(VERSION 3.9)

project(libgraph
	VERSION 1.0
	DESCRIPTION "Dijkstra library"
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(libgraph_SOURCES
	Edge.h
	Edge.cpp
	Graph.h
	Graph.cpp
	Node.h
	Node.cpp
	SimpleEdge.h)

set( test_files
	testing_main.cpp)

add_library(libgraph STATIC ${libgraph_SOURCES})

target_include_directories(libgraph INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(libgraph PUBLIC -fpermissive)

add_executable(libgraph-tests EXCLUDE_FROM_ALL ${test_files} ${libgraph_SOURCES})
