cmake_minimum_required(VERSION 3.13)

add_library(ao-avalonian-roads-lib STATIC)

target_compile_features(ao-avalonian-roads-lib PUBLIC cxx_std_17)

#TODO collect all cpp and h with a file GLOB
# or split into CMakeLists in each subdir
file(GLOB_RECURSE all_header_files
	**/*.h)
file(GLOB_RECURSE all_source_files
	**/*.cpp)

target_sources(ao-avalonian-roads-lib
	PRIVATE ${all_source_files}
	PUBLIC ${all_header_files})

if(CMAKE_HOST_WIN32)
#	target_sources(ao-avalonian-roads-lib
#		PRIVATE persistence/localdata_win32.cpp)
elseif(CMAKE_HOST_UNIX)
#	target_sources(ao-avalonian-roads-lib
#		PRIVATE persistence/localdata_posix.cpp)
endif()

target_include_directories(ao-avalonian-roads-lib
	PRIVATE ../../vendor/libgraph
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
