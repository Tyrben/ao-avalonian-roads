cmake_minimum_required(VERSION 3.9)

project(libgraph
	VERSION 1.0
	DESCRIPTION "Dijkstra library"
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( source_files
	Edge.h
	Edge.cpp
	Graph.h
	Graph.cpp
	Node.h
	Node.cpp
	SimpleEdge.h)

set( test_files
	testing_main.cpp)

add_library(libgraph STATIC ${source_files})

target_compile_options(libgraph PRIVATE -fpermissive)
