#pragma once
#include <conf/localdata.h>

#include <fstream>

TEST_CASE( "LocalData Posix...", "[LocalData]" ) {
	std::ifstream inputConfig;
	LocalData::openStreamOnConfig(inputConfig);
	REQUIRE(true);
}
