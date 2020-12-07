#pragma once
//rename directions?

#include "map.h"
#include "portal.h"

#include <list>

class WorldInfo
{
public:
	int deleteExpiredPortals();
	WorldInfo getFuture(date);

	WorldInfo request(NO_EXPIRED_PORTALS);
	WorldInfo request(SET_DATE, date);

	Graph request(NO_EXPIRED_PORTALS);
	Graph request(SET_DATE, date);
	graph.diskstra();

	bool addPortal(const Portal& portal_, Coordinates coords_);
	bool addPortal(const PortalId& portalId_, Coordinates coords_);

	bool execRequest(Functor);

	infos.execRequest(shortestRoute(response));

	accept(NavigationSystem); // Visitor pattern

private:
	/**
	*
	*/
	bool hydrate(); // hydrate ca lit un fichier ou une base, si t'as déjà les data... c'est plutot des addPortal, addMap car la lecture se fait à l'extérieur

	std::list<Portal> m_portals;
	std::list<Map> m_maps;
};


auto shortestRoute = makeShortestRoute(WorldInfo);



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

	std::list<MapId> getShortestRoute(const WorldInfo&, from, to);
	//std::list<MapId> getShortestRouteAt(from, to, date);

	responseFormat directions(origin, destination);


	void init();

private:

	//Graph m_graph;

	std::list<Map> m_maps;
	std::list<Portal> m_portals;
};
