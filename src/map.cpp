#include "map.h"

Map::Map(std::string name_)
	: m_id{ UniqueNumberGenerator::makeNew() }
	, m_name( name_ )
{
}

Map::Map(std::string name_, MapId forcedId_)
	: m_id{ forcedId_ }
	, m_name( name_ )
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
