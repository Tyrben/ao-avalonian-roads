#include "map.h"
#include "portal.h"

#include <list>

#include <iostream>

int main(int argc, char* argv[])
{
	std::list<Map> maps;
	std::list<Portal> portals;

	Portal portal1(Portal::Type::Blue, std::chrono::system_clock::now());

	Map map1("name");
	map1.addPortal(portal1, { 10,10 });

	Map map2("name");
	map2.addPortal(portal1, { 20,10 });
	
	return 0;
}
