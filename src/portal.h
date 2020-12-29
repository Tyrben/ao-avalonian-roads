#pragma once
#include "map.h"

#include <chrono>

struct Coordinates
{
	unsigned int x;
	unsigned int y;
};

struct Position
{
	Position(Coordinates coordinates_, MapName mapName_)
		: coordinates{ coordinates_ }
		, mapName{ mapName_ }
	{
	}

	Coordinates coordinates;
	const MapName mapName;
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


	Portal(Type, const MapName&, const MapName&); //optionnel, ca construit les Positions
	Portal(Type, const Position&, const Position&); // TODO change parameters order?
	Portal(Type, Position&&, Position&&);

	std::pair<const MapName, const MapName> getLink() const; //TODO retake, reinterogate about needs
	//TODO pair of Position?

	void setEndTime(std::chrono::time_point<std::chrono::system_clock> endTime_);
	bool isEnded() const; // elapsed

private:
	Position m_positionLeft;
	Position m_positionRight;
	
	Type m_type;
	std::chrono::time_point<std::chrono::system_clock> m_endTime; //!< UTC time
};
