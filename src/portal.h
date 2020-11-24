#pragma once

#include "id.h"
#include <chrono>

class Portal
{
public:
	enum class Type
	{
		Green,
		Blue,
		Gold
	};

	/**
	* endTime is used as a UTC time (warning)
	*/
	Portal(Type type_, std::chrono::time_point<std::chrono::system_clock> endTime_);
	Id getId() const;

private:
	//Id& m_mapIdLeft;
	//Id& m_mapIdRight;
	
	Type m_type;
	std::chrono::time_point<std::chrono::system_clock> m_endTime;
	Id m_id;
};
