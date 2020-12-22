#pragma once

#include "id.h"

#include <map>
#include <string>

class Map
{
public:
	Map(std::string name_);
	Map(std::string name_, MapId forcedId_);

	const MapId& getId() const;
	const std::string& getName() const;

	void setName(std::string newName_);

	friend bool operator< (const Map&, const Map&);

private:
	MapId m_id;
	std::string m_name;
};

bool operator< (const Map&, const Map&);
