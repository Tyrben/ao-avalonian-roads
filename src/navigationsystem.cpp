#include "navigationsystem.h"

#include <Graph.h>
#include <SimpleEdge.h>

#include <iostream> //for debug

void NavigationSystem::init_(Graph* g_) const
{
	// You can subclass Node, in order to add functionalities to the nodes.

	for (const auto& map : m_world->getMaps())
	{
		/*Node& currentNode = */g_->makeNode<Node>(map.getName());
	}

	for (const auto& portal : m_world->getPortals())
	{
		//TODO le portal a le bon ID, mais n'a pas les bons ID de maps
		auto link = portal.getLink();
		Node* left = g_->findNodeById(link.first);
		Node* right = g_->findNodeById(link.second);
		if (left && right)
			g_->makeBiEdge<SimpleEdge>(*left, *right, 100);
	}
}

void NavigationSystem::printRoute(MapName from_, MapName to_) const
{
	//TODO try catch, some operations can crash in Graph
	Graph g;
	init_(&g); //the World should continue evolve between two prints

	const Node* from = g.findNodeById(from_);
	const Node* to = g.findNodeById(to_);

	if (!from) return;
	if (!to) return;

	// find the shortest path between any type of nodes, regarding the weight of your edges
	auto path = g.findShortestPathDijkstra(*from, *to);
	for (Edge* edge : path)
	{
		if (!edge) return;
		// dynamic_cast to your Edge type is useful, if you have multiple different types of edges.
		SimpleEdge* pMyEdge = dynamic_cast<SimpleEdge*>(edge);
		if (pMyEdge)
		{
			std::cout << edge->toString() << '\n';
		}
	}
}

//TODO retake, this is not how the visitor pattern should be used
void NavigationSystem::visit(World* w_)
{
	m_world = w_;
}
