cmake_minimum_required(VERSION 3.13)

add_library(ao-avalonian-roads-lib STATIC)

target_compile_features(ao-avalonian-roads-lib PUBLIC cxx_std_17)

#TODO split into CMakeLists in each subdir
file(GLOB_RECURSE all_header_files
	*.h)
file(GLOB_RECURSE all_source_files
	*.cpp)

file(GLOB_RECURSE win32_header_files
	*_win32.h)
file(GLOB_RECURSE win32_source_files
	*_win32.cpp)

file(GLOB_RECURSE posix_header_files
	*_posix.h)
file(GLOB_RECURSE posix_source_files
	*_posix.cpp)

# Exclude specific architecture files
foreach(file_name ${win32_header_files})
	list(REMOVE_ITEM all_header_files "${file_name}")
endforeach()

foreach(file_name ${posix_header_files})
	list(REMOVE_ITEM all_header_files "${file_name}")
endforeach()

foreach(file_name ${win32_source_files})
	list(REMOVE_ITEM all_source_files "${file_name}")
endforeach()

foreach(file_name ${posix_source_files})
	list(REMOVE_ITEM all_source_files "${file_name}")
endforeach()


target_sources(ao-avalonian-roads-lib
	PRIVATE ${all_source_files}
	PUBLIC ${all_header_files})

if(CMAKE_HOST_WIN32)
	target_sources(ao-avalonian-roads-lib
		PRIVATE ${win32_source_files}
		PUBLIC ${win32_header_files})
elseif(CMAKE_HOST_UNIX)
	target_sources(ao-avalonian-roads-lib
		PRIVATE ${posix_source_files}
		PUBLIC ${posix_header_files})
endif()

target_include_directories(ao-avalonian-roads-lib
	PRIVATE ../../vendor/libgraph
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
