#pragma once

#include <persistence/localdata.h>
#include <fstream>

#ifdef _WIN32
#	include "localdata_win32_test.h"
#elif defined(__linux__)
#	include "localdata_posix_test.h"
#else
#	error "OS not supported"
#endif

TEST_CASE("LocalData can open a stream to the config file", "[LocalData]") {
	std::ifstream inputConfig;
	LocalData::openStreamOnConfig_(inputConfig, std::filesystem::path("/tmp") );
	REQUIRE(inputConfig.is_open());
	REQUIRE(inputConfig.good());
}

/*
TEST_CASE("LocalData can open a stream to the config file", "[LocalData]") {
	std::ifstream inputConfig;
	LocalData::openStreamOnConfig(inputConfig);
	REQUIRE(inputConfig.is_open());
	REQUIRE(inputConfig.good());
}*/
