#pragma once
#include <portal.h>

TEST_CASE( "Portal stores a link", "[Portal]" ) {
	Map m1("test1");
	Map m2("test2");
	Portal p1(Portal::Type::Blue, m1.getName(), m2.getName());
	auto link = p1.getLink();

	REQUIRE(link.first == m1.getName());
	REQUIRE(link.second == m2.getName());
}
