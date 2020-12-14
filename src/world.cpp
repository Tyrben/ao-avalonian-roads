#include "world.h"

//for Visitor pattern
void World::accept(Visitor<World>& visitor_)
{
	visitor_.visitElement(this);
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