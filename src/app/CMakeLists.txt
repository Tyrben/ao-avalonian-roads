cmake_minimum_required(VERSION 3.13)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-gps)

target_compile_features(ao-avalonian-roads-gps PRIVATE cxx_std_17)

target_sources(ao-avalonian-roads-gps 
	PRIVATE main.cpp)

target_link_libraries(ao-avalonian-roads-gps
	PRIVATE ao-avalonian-roads-lib
	PRIVATE bfg::Lyra)
