cmake_minimum_required(VERSION 3.13)

add_library(ao-avalonian-roads-lib STATIC)

target_compile_features(ao-avalonian-roads-lib PUBLIC cxx_std_17)

target_sources(ao-avalonian-roads-lib
	PRIVATE csv/csvformat.cpp
		ini/iniformat.cpp
		map.cpp
		navigationsystem.cpp
		persistence/localdata.cpp
		portal.cpp
		world.cpp
	PUBLIC csv/csvformat.h
		ini/iniformat.h
		map.h
		navigationsystem.h
		persistence/localdata.h
		portal.h
		tools/stringtools.h
		world.h)

if(CMAKE_HOST_WIN32)
	target_sources(ao-avalonian-roads-lib
		PRIVATE persistence/localdata_win32.cpp)
elseif(CMAKE_HOST_UNIX)
	target_sources(ao-avalonian-roads-lib
		PRIVATE persistence/localdata_posix.cpp)
endif()

target_include_directories(ao-avalonian-roads-lib
	PRIVATE ../vendor/libgraph
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
