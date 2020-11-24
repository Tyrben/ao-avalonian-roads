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
	Map(std::string name_);
	int getAbsoluteDistance(const Portal& fromPortal_, const Portal& toPortal_) const;
	int getAbsoluteDistance(const Id& fromPortal_, const Id& toPortal_) const;
	bool addPortal(const Portal& portal_, Coordinates coords_);
	bool addPortal(const Id& portalId_, Coordinates coords_);

	friend bool operator< (const Map& left_, const Map& right_);

private:
	Id m_id;
	std::string m_name;
	std::map<Id, Coordinates> m_portals;
};

bool operator< (const Map& left_, const Map& right_);
