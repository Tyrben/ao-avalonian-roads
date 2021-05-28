#include "csv/csvformat.h"
#include "navigationsystem.h"
#include "world.h"
#include <lyra/lyra.hpp>

#include <set>


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


			CsvFormat csv;
			csv.loadFromFile("D:\\git\\autres\\ao-avalonian-roads\\scripts\\static-maps.csv", true);

			std::map<std::string, std::string> idMapEquiv;
			std::set<std::string> uniqueMaps;

			for (const auto& map : csv.getData())
			{
				idMapEquiv[std::get<std::string>(map.at(0))] = std::get<std::string>(map.at(1));
				uniqueMaps.insert(std::get<std::string>(map.at(1)));
			}

			for (const auto& map : uniqueMaps)
			{
				Map map2(map);
				w.addMap(map2);
			}

			CsvFormat csvPortals;
			csvPortals.loadFromFile("D:\\git\\autres\\ao-avalonian-roads\\scripts\\static-portals.csv", true);

			for (const auto& portal : csvPortals.getData())
			{
				Portal portal2(Portal::Type::Static, idMapEquiv[std::get<std::string>(portal.at(0))], idMapEquiv[std::get<std::string>(portal.at(1))]);
				w.addPortal(portal2);
			}
			//test tmp
			//hydrateForTest(w);

			const Map& origin = w.getMapByName(originMapName);
			const Map& destination = w.getMapByName(destinationMapName);

			//TODO manager an empty response
			NavigationSystem ns;
			//ns.getShortestRoute(w, origin.getName(), destination.getName());

			//ns.printRoute(w, origin.getName(), destination.getName());
			ns.printRoute(w, originMapName, destinationMapName);
		}
	}
};

int main(int argc, char* argv[])
{
#ifdef _WIN32
#	ifdef _DEBUG
	// Activate memory leak control
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#	endif
#endif

	auto cli = lyra::cli();
	RouteCommand route { cli };
	auto result = cli.parse({ argc, argv });

	if (!result)
	{
		std::cerr << result.errorMessage() << '\n';
	}
	return result ? 0 : 1;
}
