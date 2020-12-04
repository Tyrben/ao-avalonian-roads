#pragma once

#include "id.h"

#include <map>
#include <string>
#include <utility> // std::pair

class Map
{
public:
	Map(std::string name_);

	const MapId& getId() const;
	const std::string& getName() const;

	void setName(std::string newName_);

	friend bool operator< (const Map& left_, const Map& right_);

private:
	MapId m_id;
	std::string m_name;
};

bool operator< (const Map& left_, const Map& right_);
