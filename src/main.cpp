#include "map.h"
#include "portal.h"

#include <list>
#include <random>

int main(int argc, char argv[])
{
	//init random generation
	std::random_device rd;
	std::mt19937 mt(rd());
	UniqueNumberGenerator::initRandom(mt);

	std::list<Map>;
	std::list<Portal>;
	
	return 0;
}
