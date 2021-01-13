cmake_minimum_required(VERSION 3.13)

project(ao-avalonian-roads
	VERSION 0.1
	DESCRIPTION "Mapping system for AO Avalonian Roads"
	LANGUAGES CXX)

# Enable testing for the project
enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(app)

# Thirdparty vendor libraries
add_subdirectory(vendor/libgraph ./libgraph)
add_subdirectory(vendor/Lyra-master ./liblyra)
