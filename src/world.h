#pragma once

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
