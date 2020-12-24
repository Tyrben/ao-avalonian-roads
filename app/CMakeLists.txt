cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-gps main.cpp)

#if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#target_compile_options(ao-avalonian-roads-gps PRIVATE -fpermissive)
#endif()
#TODO check if needed here or if we can herite from libgraph using PUBLIC or INTERFACE

#target_include_directories(ao-avalonian-roads-gps
#	PUBLIC ../vendor/libgraph )

# target_include_directories(ao-avalonian-roads-gps
# 	PUBLIC ../vendor/Lyra-master/include )

target_link_libraries(ao-avalonian-roads-gps
	LINK_PUBLIC ao-avalonian-roads-lib
	LINK_PUBLIC libgraph
	LINK_PUBLIC bfg::Lyra)
