#pragma once
#include <uniquenumbergenerator.h>

TEST_CASE( "Unique number returns different value each time", "[UniqueNumberGenerator]" ) {
	const unsigned long long a = UniqueNumberGenerator::makeNew();
	const unsigned long long b = UniqueNumberGenerator::makeNew();
	REQUIRE(a != b);
}
