#include "navigationsystem.h"

//#include "../vendor/libgraph/Graph.h"
//#include "../vendor/libgraph/SimpleEdge.h"
#include <Graph.h>
#include <SimpleEdge.h>

#include <iostream> //debug

void NavigationSystem::init_(Graph* g_) const
{
	// You can subclass Node, in order to add functionallity to the nodes.

	for (const auto& map : m_world->getMaps())
	{
		/*Node& currentNode = */g_->makeNode<Node>(IdManip::toString(map.getId()));
	}

	//arrivé ici, le m_portals n'est plus bon dans m_world...
	for (const auto& portal : m_world->getPortals())
	{
		//TODO le portal a le bon ID, mais n'a pas les bons ID de maps
		auto link = portal.getLink();
		Node* left = g_->findNodeById(IdManip::toString(link.first));
		Node* right = g_->findNodeById(IdManip::toString(link.second));
		if (left && right)
			g_->makeBiEdge<SimpleEdge>(*left, *right, 100);
	}
}

void NavigationSystem::printRoute(MapId from_, MapId to_) const
{
	Graph g;
	init_(&g); //the World should continue evolve between two prints

	const Node* from = g.findNodeById(IdManip::toString(from_));
	const Node* to = g.findNodeById(IdManip::toString(to_));

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
}

void NavigationSystem::visit(World* w_)
{
	m_world = w_;
}

/*
//Original demo code from libgraph
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
