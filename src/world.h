#pragma once

#include "visitor.h"

#include "map.h"
#include "portal.h"

#include <list>

class World
{
public:
	int deleteExpiredPortals();
	World getFuture(std::chrono::time_point<std::chrono::system_clock> date_);

	//World request(NO_EXPIRED_PORTALS);
	//World request(SET_DATE, date);

	//World request(NO_EXPIRED_PORTALS);
	//World request(SET_DATE, date);

	bool addPortal(const Portal& portal_, Coordinates coords_);
	bool addPortal(const PortalId& portalId_, Coordinates coords_);

	//bool execRequest(Functor);

	void accept(Visitor<World>&); ///< Visitor pattern

private:
	/**
	*
	*/
	
	std::list<Portal> m_portals;
	std::list<Map> m_maps;
};
