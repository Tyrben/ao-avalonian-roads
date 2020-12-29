#pragma once
#include <portal.h>

TEST_CASE("Coordinates stores a pair", "[Coordinates]") {
	Coordinates c1 {10u, 12u};

	REQUIRE(c1.x == 10u);
	REQUIRE(c1.y == 12u);
}

TEST_CASE("Position stores coordinates", "[Position]") {
	Position p1({ 10u, 12u }, "mapName");

	REQUIRE(p1.coordinates.x == 10u);
	REQUIRE(p1.coordinates.y == 12u);
}

TEST_CASE("Position stores a name", "[Position]") {
	Position p1({ 10u, 12u }, "mapName");

	REQUIRE(p1.mapName == "mapName");
}
