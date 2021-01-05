#include "navigationsystem.h"
#include "world.h"
#include <lyra/lyra.hpp>


// hydrate ca lit un fichier ou une base, si t'as déjà les data... c'est plutot des addPortal, addMap
void hydrateForTest(World& w)
{
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
}

struct RouteCommand
{
	std::string originMapName;
	std::string destinationMapName;
	bool showHelp = false;

	RouteCommand(lyra::cli& cli)
	{
		cli.add_argument(
			lyra::command(
				"route", [this](const lyra::group & g) { this->executeCommand(g); })
			.help("Display the best route.")
			.add_argument(lyra::help(showHelp))
			.add_argument(
				lyra::opt(originMapName, "origin_map")
				.name("-o")
				.name("--origin")
				.required()
				.help(
					"The name of the map of origin."))
			.add_argument(
				lyra::opt(destinationMapName, "destination_map")
				.name("-d")
				.name("--destination")
				.required()
				.help(
					"The name of the map of destination.")));
	}

	void executeCommand(const lyra::group& g)
	{
		if (showHelp)
		{
			std::cout << g;
		}
		else
		{

			World w;

			//test tmp
			hydrateForTest(w);

			const Map& origin = w.getMapByName(originMapName);
			const Map& destination = w.getMapByName(destinationMapName);

			NavigationSystem ns;
			//ns.getShortestRoute(w, origin.getName(), destination.getName());

			ns.printRoute(w, origin.getName(), destination.getName());
		}
	}
};

int main(int argc, char* argv[])
{
	auto cli = lyra::cli();
	RouteCommand route { cli };
	auto result = cli.parse({ argc, argv });

	if (!result)
	{
		std::cerr << result.errorMessage() << '\n';
	}
	return result ? 0 : 1;
}
