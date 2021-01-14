cmake_minimum_required(VERSION 3.13)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-tests)

target_compile_features(ao-avalonian-roads-tests PRIVATE cxx_std_17)

target_sources(ao-avalonian-roads-tests
	PRIVATE csvformat_test.h
		iniformat_test.h
		localdata_test.h
		map_test.h
		navigationsystem_test.h
		portal_test.h
		position_test.h
		world_test.h
		
		main.cpp)

if(CMAKE_HOST_WIN32)
	target_sources(ao-avalonian-roads-tests
		PRIVATE localdata_win32_test.h)
elseif(CMAKE_HOST_UNIX)
	target_sources(ao-avalonian-roads-tests
		PRIVATE localdata_posix_test.h)
endif()

target_link_libraries(ao-avalonian-roads-tests
	LINK_PUBLIC ao-avalonian-roads-lib
	LINK_PUBLIC libgraph)

# Keep compatibility with Debian 10 Buster (gcc 8.3)
if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS_EQUAL 8.3)
	target_link_libraries(ao-avalonian-roads-tests
		PRIVATE stdc++fs)
endif()

target_include_directories(ao-avalonian-roads-tests
	PRIVATE ../vendor/libgraph
	PRIVATE ../vendor/catch
	PRIVATE ../src )

add_test(NAME ao-avalonian-roads-tests
	COMMAND ao-avalonian-roads-tests)
