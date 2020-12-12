#pragma once
//rename directions?

#include "map.h"
#include "portal.h"
#include "visitor.h"

#include <list>




//friend or public accessors ?



auto shortestRoute = makeShortestRoute(WorldInfo);



class NavigationSystem : public Visitor<NavigationSystem>
{
public:
/*	
	int getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const;
	int getAbsoluteDistance(const PortalId& fromPortal_, const PortalId& toPortal_) const;
	//const std::map<PortalId, Coordinates>& getPortals() const;

	int getAlignedDistance() const;

	Map& getMapById(const MapId&) const;
	Map& getMapByName(std::string) const;*/

	std::list<MapId> getShortestRoute(const WorldInfo&, from, to);
	//std::list<MapId> getShortestRouteAt(from, to, date);

	responseFormat directions(origin, destination);

	void printRoute() const;


	void init();

	/*virtual*/ void visitElement(NavigationSystem*);

private:

	//Graph m_graph;

	std::list<Map> m_maps;
	std::list<Portal> m_portals;
};
