#pragma once
#include <world.h>
#include <navigationsystem.h>

TEST_CASE("Map name is returned", "[Map]")
{
	Map map1("name1");
	REQUIRE(std::string("name1").compare(map1.getName()) == 0);
}

TEST_CASE("Display MapName of a map", "[Map]")
{
	Map map1("name1");
	Map map2("name2");
	Portal portal1(Portal::Type::Blue, map1.getName(), map2.getName());

	auto link = portal1.getLink();
	//note, si je reste en reference, j'aurai un décallage par la suite... attention
	MapName idFirst = link.first;
	MapName idSecond = link.second;

	const MapName& map2name = map2.getName();
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

	Portal portal1(Portal::Type::Blue, map1.getName(), map2.getName());
	Portal portal2(Portal::Type::Blue, map2.getName(), map3.getName());
	Portal portal3(Portal::Type::Blue, map2.getName(), map4.getName());
	Portal portal4(Portal::Type::Blue, map4.getName(), map5.getName());

	//------------
	Map map6("name6");
	Map map7("name7");

	Portal portal5(Portal::Type::Blue, map6.getName(), map7.getName());

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
