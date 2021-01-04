#include "navigationsystem.h"

#include <Graph.h>
#include <SimpleEdge.h>

#include <iostream> //for debug

void NavigationSystem::init_(Graph* g_, const World* world_) const
{
	// You can subclass Node, in order to add functionalities to the nodes.

	for (const auto& map : world_->getMaps())
	{
		/*Node& currentNode = */g_->makeNode<Node>(map.getName());
	}

	for (const auto& portal : world_->getPortals())
	{
		//TODO le portal a le bon ID, mais n'a pas les bons ID de maps
		auto link = portal.getLink();
		Node* left = g_->findNodeById(link.first);
		Node* right = g_->findNodeById(link.second);
		if (left && right)
			g_->makeBiEdge<SimpleEdge>(*left, *right, 100);
	}
}

void NavigationSystem::printRoute(MapName from_, MapName to_, const Graph& g_) const
{
	const Node* from = g_.findNodeById(from_);
	const Node* to = g_.findNodeById(to_);

	if (!from) return;
	if (!to) return;

	// find the shortest path between any type of nodes, regarding the weight of your edges
	auto path = g_.findShortestPathDijkstra(*from, *to);
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
void NavigationSystem::visit(World* w_, std::va_list args_)
{
	//TODO try catch, some operations can crash in Graph
	Graph g;
	init_(&g, w_); //the World should continue evolve between two prints

	double num = va_arg(args_, double);
	double num2 = va_arg(args_, double);
}
