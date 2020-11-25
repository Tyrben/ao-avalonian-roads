cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(tests_SOURCES
	main.cpp
	../src/uniquenumbergenerator.h
	../src/uniquenumbergenerator.cpp
	uniquenumbergenerator_test.h)

add_executable(ao-avalonian-roads-tests ${tests_SOURCES})

target_include_directories(ao-avalonian-roads-tests
	PRIVATE ../vendor/catch )

target_include_directories(ao-avalonian-roads-tests
	PRIVATE ../src )

add_test(NAME ao-avalonian-roads-tests
	COMMAND ao-avalonian-roads-tests)
