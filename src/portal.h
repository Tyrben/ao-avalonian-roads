#pragma once

#include "id.h"



class Portal
{
public:
	enum class Type
	{
		Green,
		Blue,
		Gold
	};

	Id getId() const;

private:
	//Id& m_mapIdLeft;
	//Id& m_mapIdRight;
	
	Type m_type;
	//Timer m_timer;

	Id m_id;
};
