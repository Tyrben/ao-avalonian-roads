#include <id.h>

TEST_CASE("PortalId can be copied", "[Id]") {
	const PortalId a{ UniqueNumberGenerator::makeNew() };
	const PortalId b = a;
	REQUIRE(a == b);
}

TEST_CASE("MapId can be copied", "[Id]") {
	const MapId a{ UniqueNumberGenerator::makeNew() };
	const MapId b = a;
	REQUIRE(a == b);
}
