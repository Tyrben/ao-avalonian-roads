cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(tests_SOURCES
	csvformat_test.h
	id_test.h
	navigationsystem_test.h
	uniquenumbergenerator_test.h
	visitor_test.h
	world_test.h)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-tests main.cpp ${tests_SOURCES})

target_link_libraries(ao-avalonian-roads-tests
	LINK_PUBLIC ao-avalonian-roads-lib
	LINK_PUBLIC libgraph)

target_include_directories(ao-avalonian-roads-tests
	PRIVATE ../vendor/libgraph
	PRIVATE ../vendor/catch
	PRIVATE ../src )

add_test(NAME ao-avalonian-roads-tests
	COMMAND ao-avalonian-roads-tests)
