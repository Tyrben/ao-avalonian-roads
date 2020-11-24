#include "map.h"
#include "portal.h"

Map::Map(std::string name_)
	: m_name ( name_ )
{
}

bool Map::addPortal(const Portal& portal_, Coordinates coords_)
{
	m_portals[portal_.getId()] = coords_;
	return true;
}

bool Map::addPortal(const Id& portalId_, Coordinates coords_)
{
	m_portals[portalId_] = coords_;
	return true;
}

int Map::getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const
{
	return 0;
}

int Map::getAbsoluteDistance(const Id& fromPortal_, const Id& toPortal_) const
{
	m_portals.find(fromPortal_);

	return 0;
}
