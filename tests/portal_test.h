#pragma once
#include <portal.h>

TEST_CASE( "Portal stores a link", "[Portal]" ) {
	Map m1("test1");
	Map m2("test2");
	Portal p1(Portal::Type::Blue, m1.getId(), m2.getId());
	auto link = p1.getLink();

	REQUIRE(link.first == m1.getId());
	REQUIRE(link.second == m2.getId());
}

//TODO test the Position class
