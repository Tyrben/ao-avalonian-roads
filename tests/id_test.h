#pragma once
#include <id.h>
//2 types of ids: PortalId and MapId

TEST_CASE("PortalId can be copied", "[Id]") {
	const PortalId a{ UniqueNumberGenerator::makeNew() };
	const PortalId b = a;
	REQUIRE(a == b);
}

TEST_CASE("PortalId can be pointed", "[Id]") {
	const PortalId a{ UniqueNumberGenerator::makeNew() };
	const PortalId* b = &a;
	REQUIRE(a == *b);
}

TEST_CASE("MapId can be copied", "[Id]") {
	const MapId a{ UniqueNumberGenerator::makeNew() };
	const MapId b = a;
	REQUIRE(a == b);
}

TEST_CASE("MapId can be pointed", "[Id]") {
	const MapId a{ UniqueNumberGenerator::makeNew() };
	const MapId* b = &a;
	REQUIRE(a == *b);
}
