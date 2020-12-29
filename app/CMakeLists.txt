cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-gps main.cpp)

target_link_libraries(ao-avalonian-roads-gps
	LINK_PUBLIC ao-avalonian-roads-lib
	LINK_PUBLIC libgraph
	LINK_PUBLIC bfg::Lyra)
