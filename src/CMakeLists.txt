cmake_minimum_required(VERSION 3.13)

add_library(ao-avalonian-roads-lib STATIC)

target_compile_features(ao-avalonian-roads-lib PUBLIC cxx_std_17)

target_sources(ao-avalonian-roads-lib
	PRIVATE conf/localdata.cpp
		csv/csvformat.cpp
		ini/iniformat.cpp
		map.cpp
		navigationsystem.cpp
		portal.cpp
		world.cpp
	PUBLIC conf/localdata.h
		csv/csvformat.h
		ini/iniformat.h
		map.h
		navigationsystem.h
		portal.h
		tools/stringtools.h
		world.h)

if(CMAKE_HOST_WIN32)
	target_sources(ao-avalonian-roads-lib
		PRIVATE conf/localdata_win32.cpp)
elseif(CMAKE_HOST_UNIX)
	target_sources(ao-avalonian-roads-lib
		PRIVATE conf/localdata_posix.cpp)
endif()

target_include_directories(ao-avalonian-roads-lib
	PRIVATE ../vendor/libgraph
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
