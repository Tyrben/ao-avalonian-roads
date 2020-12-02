#include "map.h"
#include "portal.h"

Map::Map(std::string name_)
	: m_name ( name_ )
{
}

const MapId& Map::getId() const
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
