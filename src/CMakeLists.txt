cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(class_SOURCES
	id.h
	id.cpp
	map.h
	map.cpp
	navigationsystem.h
	navigationsystem.cpp
	portal.h
	portal.cpp	
	uniquenumbergenerator.h
	uniquenumbergenerator.cpp)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-gps main.cpp ${class_SOURCES})


#target_compile_options(ao-avalonian-roads-gps PRIVATE -fpermissive)
#TODO check if needed here or if we can herite from libgraph using PUBLIC or INTERFACE

#target_include_directories(ao-avalonian-roads-gps
#	PUBLIC ../vendor/libgraph )

#target_include_directories(ao-avalonian-roads-gps
#	PRIVATE ../vendor/Lyra-master/include )

target_link_libraries(ao-avalonian-roads-gps
	LINK_PUBLIC libgraph)
#	PRIVATE bfg::lyra)
