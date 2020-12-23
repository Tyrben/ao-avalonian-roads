#pragma once

#include "map.h"
#include "portal.h"
#include "visitor/element.h"
#include "visitor/visitor.h"

#include <vector>

class World : public Element<World>
{
public:
	int deleteExpiredPortals();
	World getFuture(std::chrono::time_point<std::chrono::system_clock> date_);

	//World request(NO_EXPIRED_PORTALS);
	//World request(SET_DATE, date);

	//World request(NO_EXPIRED_PORTALS);
	//World request(SET_DATE, date);
	bool addMap(Map map_);

	bool addPortal(Portal portal_);
	//bool addPortal(Portal&& portal_, Coordinates coords_);
	//bool addPortal(PortalId& portalId_, Coordinates coords_);

	//bool execRequest(Functor);

	/*virtual*/ void accept(Visitor<World>&); ///< Visitor pattern

	const std::vector<Portal>& getPortals() const;
	const std::vector<Map>& getMaps() const;

private:
	/**
	*
	*/
	
	std::vector<Portal> m_portals;
	std::vector<Map> m_maps;
};
