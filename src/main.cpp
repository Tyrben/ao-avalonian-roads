#include "navigationsystem.h"
#include "world.h"
//#include <lyra/lyra.hpp>



int main(int argc, char* argv[])
{
	NavigationSystem ns;
	World w;
	w.accept(ns);

	//bool hydrate(); // hydrate ca lit un fichier ou une base, si t'as d�j� les data... c'est plutot des addPortal, addMap car la lecture se fait � l'ext�rieur

	//infos.execRequest(shortestRoute(response));

	//const Map& getMapByName(std::string name_);
	
	return 0;
}
