cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(tests_SOURCES
	main.cpp
	../src/uniquenumbergenerator.h
	../src/uniquenumbergenerator.cpp
	uniquenumbergenerator_test.h
	../src/id.h
	../src/id.cpp
	id_test.h
	../src/navigationsystem.h
	../src/navigationsystem.cpp
	navigationsystem_test.h)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-tests ${tests_SOURCES})

target_link_libraries(ao-avalonian-roads-tests
	LINK_PUBLIC libgraph)

target_include_directories(ao-avalonian-roads-tests
	PRIVATE ../vendor/libgraph )

target_include_directories(ao-avalonian-roads-tests
	PRIVATE ../vendor/catch )

target_include_directories(ao-avalonian-roads-tests
	PRIVATE ../src )

add_test(NAME ao-avalonian-roads-tests
	COMMAND ao-avalonian-roads-tests)
