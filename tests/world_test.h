#pragma once
#include <world.h>

TEST_CASE( "World", "[World]" ) {
    const unsigned long long a = UniqueNumberGenerator::makeNew();
    const unsigned long long b = UniqueNumberGenerator::makeNew();
    REQUIRE(a != b);
}
