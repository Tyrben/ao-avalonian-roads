#include <id.h>

TEST_CASE("Ids can be copied", "[Id]") {
	const Id a = Id();
	const Id b = a;
	REQUIRE(a == b);
}
