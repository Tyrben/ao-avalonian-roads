#pragma once

#include "id.h"
#include "map.h"
#include "portal.h"

#include <map>
#include <utility> // std::pair

struct Coordinates
{
	unsigned int x;
	unsigned int y;
};

class Map
{
public:
	int getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const;
	int getAbsoluteDistance(const Id<Portal>& fromPortal_, const Id<Portal>& toPortal_) const;

private:
	Id<Map> m_id;
	std::map<Id<Portal>, Coordinates> m_portals;

};
