#include "map.h"

Map::Map(const MapName& name_)
	: m_name( name_ )
{
}

Map::Map(MapName&&  name_)
	: m_name{ std::move(name_) }
{
}

const MapName& Map::getName() const
{
	return m_name;
}

void Map::setName(const MapName& newName_)
{
	m_name = newName_;
}

void Map::setName(MapName&& newName_)
{
	m_name = std::move(newName_);
}
