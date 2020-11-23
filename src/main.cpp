#include "map.h"
#include "portal.h"

#include <list>

#include <iostream>

int main(int argc, char* argv[])
{
	unsigned long long a = UniqueNumberGenerator::makeNew();
	unsigned long long b = UniqueNumberGenerator::makeNew();

	std::cout << a << " et " << b << '\n';

	std::list<Map> maps;
	std::list<Portal> portals;
	
	return 0;
}
