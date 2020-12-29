#pragma once

#include <map>
#include <string>

using MapName = std::string;

class Map
{
public:
	Map(const MapName& name_);
	Map(MapName&& name_);

	const MapName& getName() const;

	void setName(const MapName& newName_);
	void setName(MapName&& newName_);

	friend bool operator< (const Map&, const Map&);

private:
	std::string m_name;
};

bool operator< (const Map&, const Map&);
