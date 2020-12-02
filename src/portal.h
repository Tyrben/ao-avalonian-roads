#pragma once

#include "id.h"
#include <chrono>

struct Coordinates
{
	unsigned int x;
	unsigned int y;
};

struct Pin
{
	Coordinates coordinates;
	const MapId& mapId;
};

class Portal
{
public:
	//TODO invent a notion of gate to use it between normal maps
	enum class Type
	{
		Green,
		Blue,
		Gold,
		Static
	};

	/**
	* endTime is used as a UTC time (warning)
	*/
	Portal(Type type_, const MapId&, const MapId&);
	Portal(Type type_, Pin, Pin);
	const PortalId& getId() const;
	std::pair<const MapId&, const MapId&> getLink() const;

	void setEndTime(std::chrono::time_point<std::chrono::system_clock> endTime_);
	bool isEnded() const; // elapsed

private:
	Pin m_pinLeft;
	Pin m_pinRight;
	
	Type m_type;
	std::chrono::time_point<std::chrono::system_clock> m_endTime;
	PortalId m_id;
};
