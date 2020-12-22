#pragma once
#include <world.h>
#include <navigationsystem.h>

TEST_CASE("Map name is returned", "[Map]")
{
	Map map1("name1");
	REQUIRE(std::string("name1").compare(map1.getName()) == 0);
}

TEST_CASE("Display MapId contend in a map", "[Map]")
{
	Map map1("name1");
	Map map2("name2");
	Portal portal1(Portal::Type::Blue, map1.getId(), map2.getId());

	auto link = portal1.getLink();
	//note, si je reste en reference, j'aurai un décallage par la suite... attention
	MapId idFirst = link.first;
	MapId idSecond = link.second;

	std::string idFirstStr = IdManip::toString(idFirst);
	std::string idSecondStr = IdManip::toString(idSecond); //error ca trouve first aussi


	const MapId& map2id = map2.getId();
	std::string map2idStr = IdManip::toString(map2id);
}

void injectData(World& w_)
{
	//Small testing world:
	// map1 <-> map2 <-> map3       map6 <-> map7
	//           ^
	//           |
	//           v
	//          map4 <-> map5

	Map map1("name1");
	Map map2("name2");
	Map map3("name3");
	Map map4("name4");
	Map map5("name5");

	Portal portal1(Portal::Type::Blue, map1.getId(), map2.getId());
	Portal portal2(Portal::Type::Blue, map2.getId(), map3.getId());
	Portal portal3(Portal::Type::Blue, map2.getId(), map4.getId());
	Portal portal4(Portal::Type::Blue, map4.getId(), map5.getId());

	//------------
	Map map6("name6");
	Map map7("name7");

	Portal portal5(Portal::Type::Blue, map6.getId(), map7.getId());

	w_.addMap(map1);
	w_.addMap(map2);
	w_.addMap(map3);
	w_.addMap(map4);
	w_.addMap(map5);
	w_.addMap(map6);
	w_.addMap(map7);

	w_.addPortal(portal1);
	w_.addPortal(portal2);
	w_.addPortal(portal3);
	w_.addPortal(portal4);
	w_.addPortal(portal5);
}
