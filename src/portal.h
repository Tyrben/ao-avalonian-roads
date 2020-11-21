#pragma once

#include "id.h"
#include "map.h"
#include "portal.h"

class Portal
{
public:
	

private:
	Id<Map> m_mapIdLeft;
	Id<Map> m_mapIdRight;
	
	Type m_type;
	Timer m_timer;

	Id<Portal> m_id;
};
