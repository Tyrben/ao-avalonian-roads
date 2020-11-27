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

const Id& Map::getId() const
{
	return m_id;
}

const std::string& Map::getName() const
{
	return m_name;
}

void Map::setName(std::string newName_)
{
	m_name = newName_;
}

const std::map<Id, Coordinates>& Map::getPortals() const
{
	return m_portals;
}
