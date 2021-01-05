#pragma once
#include <world.h>

TEST_CASE( "World has no map by default", "[World]" ) {
	World w;
	REQUIRE(w.getMaps().empty());
}

TEST_CASE( "World has no portal by default", "[World]" ) {
	World w;
	REQUIRE(w.getPortals().empty());
}

TEST_CASE( "World can accumulate a map", "[World]" ) {
	World w;
	Map m1("test");
	w.addMap(m1);
	REQUIRE(w.getMaps().size() == 1);
}

TEST_CASE( "World can accumulate a portal", "[World]" ) {
	World w;
	Portal p1(Portal::Type::Blue, "map1", "map2");
	w.addPortal(p1);
	REQUIRE(w.getPortals().size() == 1);
}
