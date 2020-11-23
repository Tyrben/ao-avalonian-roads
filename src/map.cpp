#include "map.h"
#include "portal.h"

int Map::getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const
{
	return 0;
}

int Map::getAbsoluteDistance(const Id& fromPortal_, const Id& toPortal_) const
{
	m_portals.find(fromPortal_);

	return 0;
}
