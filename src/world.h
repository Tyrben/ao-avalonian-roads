#pragma once

#include "map.h"
#include "portal.h"

#include <vector>

class World
{
public:
	int deleteExpiredPortals();
	World getFuture(std::chrono::time_point<std::chrono::system_clock> date_);

	//World request(NO_EXPIRED_PORTALS);
	//World request(SET_DATE, date);

	//World request(NO_EXPIRED_PORTALS);
	//World request(SET_DATE, date);
	bool addMap(Map);

	bool addPortal(Portal);
	//bool addPortal(Portal&& portal_, Coordinates coords_);
	//bool addPortal(PortalId& portalId_, Coordinates coords_);

	//bool execRequest(Functor);
    const Map& getMapByName(const MapName& name_) const;

	const std::vector<Portal>& getPortals() const;
	const std::vector<Map>& getMaps() const;

private:
	/**
	*
	*/
	
	std::vector<Portal> m_portals;
	std::vector<Map> m_maps;
};
