#include "map.h"
#include "portal.h"

#include <SimpleEdge.h>
#include <Graph.h>

#include <list>
#include <iostream> //debug

int main(int argc, char* argv[])
{
	std::list<Map> maps;
	std::list<Portal> portals;

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

	const MapId& map2id = map2.getId();
	std::string map2idStr = IdManip::toString(map2id);

	auto link = portal1.getLink();
	//note, si je reste en reference, j'aurai un décallage par la suite... attention
	MapId idFirst = link.first;
	MapId idSecond = link.second;

	std::string idFirstStr = IdManip::toString(idFirst);
	std::string idSecondStr = IdManip::toString(idSecond); //error ca trouve first aussi

	//------------
	Map map6("name6");
	Map map7("name7");

	Portal portal5(Portal::Type::Blue, map6.getId(), map7.getId());
	
	//------------
	maps.push_back(map1);
	maps.push_back(map2);
	maps.push_back(map3);
	maps.push_back(map4);
	maps.push_back(map5);
	maps.push_back(map6);
	maps.push_back(map7);

	portals.push_back(portal1);
	portals.push_back(portal2);
	portals.push_back(portal3);
	portals.push_back(portal4);
	portals.push_back(portal5);

	//const Map& getMapByName(std::string name_);

	//-- GPS ----------------------------------------

	Graph g;
	  // You can subclass Node, in order to add functionallity to the nodes.

	Node& nodeMap1 = g.makeNode<Node>(IdManip::toString(map1.getId()));
	Node& nodeMap2 = g.makeNode<Node>(IdManip::toString(map2.getId()));
	Node& nodeMap3 = g.makeNode<Node>(IdManip::toString(map3.getId()));
	Node& nodeMap4 = g.makeNode<Node>(IdManip::toString(map4.getId()));
	Node& nodeMap5 = g.makeNode<Node>(IdManip::toString(map5.getId()));
	Node& nodeMap6 = g.makeNode<Node>(IdManip::toString(map6.getId()));
	Node& nodeMap7 = g.makeNode<Node>(IdManip::toString(map7.getId()));


	for (const auto& portal : portals)
	{
		auto link = portal.getLink();
		std::string tmp1 = IdManip::toString(link.first);
		std::string tmp2 = IdManip::toString(link.second);
		Node* left = g.findNodeById(IdManip::toString(link.first));
		Node* right = g.findNodeById(IdManip::toString(link.second));
		g.makeBiEdge<SimpleEdge>(*left, *right, 100);
	}


	Node* from = g.findNodeById(IdManip::toString(map1.getId()));
	Node* to = g.findNodeById(IdManip::toString(map3.getId()));

	// find the shortest path between any type of nodes, regarding the weight of your edges
	auto path = g.findShortestPathDijkstra(*from, *to);
	for (Edge* pEdge : path)
	{
		// dynamic_cast to your Edge type is useful, if you have multiple different types of edges.
		SimpleEdge* pMyEdge = dynamic_cast<SimpleEdge*>(pEdge);
		if (pMyEdge)
		{
			std::cout << pEdge->toString() << std::endl;
		}
	}

	//------------------

	/*
	Node& rMunich = g.makeNode<Node>("Munich");
	Node& rHamburg = g.makeNode<Node>("Hamburg");
	Node& rBerlin = g.makeNode<Node>("Berlin");
	Node& rFrankfurt = g.makeNode<Node>("Frankfurt");

	// SimpleEdge is useful for some cases, but you can also subclass Edge.
	g.makeEdge<SimpleEdge>(rBerlin, rHamburg, 450);
	g.makeEdge<SimpleEdge>(rHamburg, rBerlin, 450);
	// You can make the edges bidirectional, too:
	g.makeBiEdge<SimpleEdge>(rBerlin, rMunich, 650);
	g.makeBiEdge<SimpleEdge>(rBerlin, rFrankfurt, 590);

	// find the shortest path between any type of nodes, regarding the weight of your edges
	auto path = g.findShortestPathDijkstra(rHamburg, rMunich);
	for (Edge* pEdge : path)
	{
		// dynamic_cast to your Edge type is useful, if you have multiple different types of edges.
		SimpleEdge* pMyEdge = dynamic_cast<SimpleEdge*>(pEdge);
		if (pMyEdge)
		{
			std::cout << pEdge->toString() << std::endl;
		}
	}*/



	
	return 0;
}
