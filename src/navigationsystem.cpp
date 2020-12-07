#include "navigationsystem.h"

//#include "../vendor/libgraph/Graph.h"
//#include "../vendor/libgraph/SimpleEdge.h"
#include <Graph.h>
#include <SimpleEdge.h>


#include <iostream> //debug


/*
bool NavigationSystem::addPortal(const Portal& portal_, Coordinates coords_)
{
	m_portals[portal_.getId()] = coords_;
	return true;
}

bool NavigationSystem::addPortal(const PortalId& portalId_, Coordinates coords_)
{
	m_portals[portalId_] = coords_;
	return true;
}

int NavigationSystem::getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const
{
	return 0;
}

int NavigationSystem::getAbsoluteDistance(const PortalId& fromPortal_, const PortalId& toPortal_) const
{
	m_portals.find(fromPortal_);

	return 0;
}

const std::map<PortalId, Coordinates>& NavigationSystem::getPortals() const
{
	return m_portals;
}
*/


void NavigationSystem::init()
{
	Graph g;
	// You can subclass Node, in order to add functionallity to the nodes.

	for (const auto& map : maps)
	{
		Node& currentNode = g.makeNode<Node>(IdManip::toString(map.getId()));
	}

	for (const auto& portal : portals)
	{
		auto link = portal.getLink();
		std::string tmp1 = IdManip::toString(link.first);
		std::string tmp2 = IdManip::toString(link.second);
		Node* left = g.findNodeById(IdManip::toString(link.first));
		Node* right = g.findNodeById(IdManip::toString(link.second));
		g.makeBiEdge<SimpleEdge>(*left, *right, 100);
	}
}

void NavigationSystem::dontKnowYet()
{
	Node* from = g.findNodeById(IdManip::toString(map1.getId()));
	Node* to = g.findNodeById(IdManip::toString(map7.getId()));

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
