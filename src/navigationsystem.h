#pragma once

#include "world.h"
#include "map.h"
#include "portal.h"

#include <list>
#include <vector>

class Graph;
//auto shortestRoute = makeShortestRoute(World);

class NavigationSystem
{
public:
/*	
	int getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const;
	int getAbsoluteDistance(const PortalId& fromPortal_, const PortalId& toPortal_) const;
	//const std::map<PortalId, Coordinates>& getPortals() const;

	int getAlignedDistance() const;

	Map& getMapById(const MapId&) const;
	Map& getMapByName(std::string) const;*/

	std::list<MapName> getShortestRoute(const World&, MapName, MapName) const;
	//std::list<MapId> getShortestRouteAt(from, to, date);
	//responseFormat directions(MapId, MapId);

	void printRoute(MapName, MapName, const Graph&) const;

	void printRoute(const World&, MapName, MapName) const;

private:
	void init_(Graph& g_, const World& world_) const;
};
