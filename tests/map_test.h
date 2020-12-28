#pragma once
#include <map.h>

TEST_CASE( "Map has a name", "[Map]" ) {
	Map m("test");
	REQUIRE(m.getName() == "test");
}
