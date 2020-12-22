#include "navigationsystem.h"
#include "world.h"
//#include <lyra/lyra.hpp>



int main(int argc, char* argv[])
{
	NavigationSystem ns;
	World w;
	w.accept(ns);



	Map map1("name1");
	Map map2("name2");
	Map map3("name3");
	Map map4("name4");
	Map map5("name5");

	Portal portal1(Portal::Type::Blue, map1.getId(), map2.getId()); //poor method
	Portal portal2(Portal::Type::Blue, map2.getId(), map3.getId());
	Portal portal3(Portal::Type::Blue, map2.getId(), map4.getId());
	Portal portal4(Portal::Type::Blue, map4.getId(), map5.getId());

	//------------
	Map map6("name6");
	Map map7("name7");

	Portal portal5(Portal::Type::Blue, map6.getId(), map7.getId());

	w.addMap(map1);
	w.addMap(map2);
	w.addMap(map3);
	w.addMap(map4);
	w.addMap(map5);
	w.addMap(map6);
	w.addMap(map7);
	w.addPortal(portal1);
	w.addPortal(portal2);
	w.addPortal(portal3);
	w.addPortal(portal4);
	w.addPortal(portal5);

	//TODO try catch ? not here... in printRoute
	ns.printRoute(map1.getId(), map5.getId());

	//bool hydrate(); // hydrate ca lit un fichier ou une base, si t'as déjà les data... c'est plutot des addPortal, addMap car la lecture se fait à l'extérieur

	//infos.execRequest(shortestRoute(response));

	//const Map& getMapByName(std::string name_);
	
	return 0;
}
