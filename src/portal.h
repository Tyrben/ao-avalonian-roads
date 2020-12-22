#pragma once

#include "id.h"
#include <chrono>

struct Coordinates
{
	unsigned int x;
	unsigned int y;
};

struct Position
{
	Position(Coordinates coordinates_, const MapId& mapid_)
		: coordinates{ coordinates_ }
		, mapId{ mapid_ }
	{
	}

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
	Portal(Type, const MapId&, const MapId&); //optionnel, ca construit les Positions
	Portal(Type, Position, Position); // TODO change parameters order?
	const PortalId& getId() const; // TODO plutot par copie que par reference, c'est un int
	std::pair<const MapId, const MapId> getLink() const; //TODO retake, reinterogate about needs

	void setEndTime(std::chrono::time_point<std::chrono::system_clock> endTime_);
	bool isEnded() const; // elapsed

private:
	Position m_positionLeft;
	Position m_positionRight;
	
	Type m_type;
	std::chrono::time_point<std::chrono::system_clock> m_endTime;
	PortalId m_id;
};
