#include "world.h"

//for Visitor pattern
void World::accept(Visitor<World>* visitor_...)
{
	va_list args;
	va_start(args, visitor_);
	visitor_->visit(this, args);
	va_end(args);
}

const std::vector<Portal>& World::getPortals() const
{
	return m_portals;
}

const std::vector<Map>& World::getMaps() const
{
	return m_maps;
}

bool World::addPortal(Portal portal_)
{
	m_portals.emplace_back(portal_); //TODO use a reference?
	return true;
}

bool World::addMap(Map map_)
{
	m_maps.emplace_back(map_); //TODO use a reference?
	return true;
}

const Map& World::getMapByName(const MapName& name_) const
{
	for (const Map& map : m_maps)
	{
		if (map.getName() == name_)
			return map;
	}
}

/*
bool World::addPortal(const Portal& portal_, Coordinates coords_)
{
	m_portals[portal_.getId()] = coords_;
	return true;
}

bool World::addPortal(const PortalId& portalId_, Coordinates coords_)
{
	m_portals[portalId_] = coords_;
	return true;
}

int World::getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const
{
	return 0;
}

int World::getAbsoluteDistance(const PortalId& fromPortal_, const PortalId& toPortal_) const
{
	m_portals.find(fromPortal_);

	return 0;
}

const std::map<PortalId, Coordinates>& World::getPortals() const
{
	return m_portals;
}
*/
