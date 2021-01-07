#pragma once
#include <ini/iniformat.h>

TEST_CASE( "Ini can load a stream", "[Ini]" ) {
	IniFormat ini;
	ini.loadFromFile("test.ini");
	REQUIRE(true);
}
