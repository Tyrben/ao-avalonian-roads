#pragma once

#include "visitor.h"
#include "world.h"
#include "map.h"
#include "portal.h"

#include <vector>

class Graph;
//auto shortestRoute = makeShortestRoute(World);

class NavigationSystem : public Visitor<World>
{
public:
/*	
	int getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const;
	int getAbsoluteDistance(const PortalId& fromPortal_, const PortalId& toPortal_) const;
	//const std::map<PortalId, Coordinates>& getPortals() const;

	int getAlignedDistance() const;

	Map& getMapById(const MapId&) const;
	Map& getMapByName(std::string) const;*/

	std::list<MapId> getShortestRoute(const World&, MapId, MapId);
	//std::list<MapId> getShortestRouteAt(from, to, date);
	//responseFormat directions(MapId, MapId);

	void printRoute() const;




	/*virtual*/ void visitElement(World*);

private:
	void init_(Graph* g_) const;
	//Graph m_graph;

	std::vector<Map> m_maps;
	std::vector<Portal> m_portals;
};
