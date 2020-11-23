#pragma once

#include "id.h"
//#include "portal.h"

#include <map>
#include <utility> // std::pair

class Portal;

struct Coordinates
{
	unsigned int x;
	unsigned int y;
};

class Map
{
public:
	int getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const;
	int getAbsoluteDistance(const Id& fromPortal_, const Id& toPortal_) const;
	friend bool operator< (const Map& left_, const Map& right_);

private:
	Id m_id;
	std::map<Id, Coordinates> m_portals;

};

bool operator< (const Map& left_, const Map& right_);
