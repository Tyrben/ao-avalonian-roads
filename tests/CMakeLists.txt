cmake_minimum_required(VERSION 3.13)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-tests)

target_compile_features(ao-avalonian-roads-tests PRIVATE cxx_std_17)


# Any new _test.h file will be added to the batch test
file(GLOB_RECURSE all_test_files
	**/*_test.h)

target_sources(ao-avalonian-roads-tests
	PRIVATE ${all_test_files}
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
	PRIVATE ../src/lib )

add_test(NAME ao-avalonian-roads-tests
	COMMAND ao-avalonian-roads-tests)
