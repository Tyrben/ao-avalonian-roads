cmake_minimum_required(VERSION 3.13)

link_directories(../vendor/libgraph)

add_executable(ao-avalonian-roads-tests)

target_compile_features(ao-avalonian-roads-tests PRIVATE cxx_std_17)

# Any new _test.h file will be added to the batch test
file(GLOB_RECURSE all_test_files
	*_test.h)

file(GLOB_RECURSE win32_test_files
	*_win32_test.h)

file(GLOB_RECURSE posix_test_files
	*_posix_test.h)

# Exclude specific architecture files
foreach(file_name ${win32_test_files})
	list(REMOVE_ITEM all_test_files "${file_name}")
endforeach()

foreach(file_name ${posix_test_files})
	list(REMOVE_ITEM all_test_files "${file_name}")
endforeach()


# Generate the main file
configure_file(${CMAKE_SOURCE_DIR}/tests/main.cpp.in ${CMAKE_SOURCE_DIR}/tests/main.cpp COPYONLY)

foreach(test_file IN ITEMS ${all_test_files})
	file(RELATIVE_PATH relative_test_file ${CMAKE_SOURCE_DIR}/tests ${test_file})
	file(APPEND ${CMAKE_SOURCE_DIR}/tests/main.cpp "#include \"${relative_test_file}\"\n")
endforeach()

target_sources(ao-avalonian-roads-tests
	PRIVATE ${all_test_files}
		main.cpp)

if(CMAKE_HOST_WIN32)
	foreach(test_file IN ITEMS ${win32_test_files})
		file(RELATIVE_PATH relative_test_file ${CMAKE_SOURCE_DIR}/tests ${test_file})
		file(APPEND ${CMAKE_SOURCE_DIR}/tests/main.cpp "#include \"${relative_test_file}\"\n")
	endforeach()

	target_sources(ao-avalonian-roads-tests
		PRIVATE ${win32_test_files})
elseif(CMAKE_HOST_UNIX)
	foreach(test_file IN ITEMS ${posix_test_files})
		file(RELATIVE_PATH relative_test_file ${CMAKE_SOURCE_DIR}/tests ${test_file})
		file(APPEND ${CMAKE_SOURCE_DIR}/tests/main.cpp "#include \"${relative_test_file}\"\n")
	endforeach()
	
	target_sources(ao-avalonian-roads-tests
		PRIVATE ${posix_test_files})
endif()

target_link_libraries(ao-avalonian-roads-tests
	PRIVATE ao-avalonian-roads-lib)

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
