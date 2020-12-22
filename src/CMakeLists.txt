cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(class_SOURCES
	element.h
	id.h
	id.cpp
	map.h
	map.cpp
	navigationsystem.h
	navigationsystem.cpp
	portal.h
	portal.cpp
	uniquenumbergenerator.h
	uniquenumbergenerator.cpp
	visitor.h
	world.h
	world.cpp)

#link_directories(../vendor/libgraph)

add_library(ao-avalonian-roads-lib STATIC ${class_SOURCES})

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_compile_options(ao-avalonian-roads-lib PRIVATE -fpermissive)
endif()
#TODO check if needed here or if we can herite from libgraph using PUBLIC or INTERFACE

target_include_directories(ao-avalonian-roads-lib
	PRIVATE ../vendor/libgraph )

#target_include_directories(ao-avalonian-roads-gps
#	PRIVATE ../vendor/Lyra-master/include )

#target_link_libraries(ao-avalonian-roads-gps
#	LINK_PUBLIC libgraph)
#	PRIVATE bfg::lyra)

target_include_directories(ao-avalonian-roads-lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
