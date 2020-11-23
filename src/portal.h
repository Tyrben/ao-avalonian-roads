#pragma once

#include "id.h"
#include "map.h"

enum Type
{
	A,
	B
};

class Portal
{
public:
	

private:
	Id m_mapIdLeft;
	Id m_mapIdRight;
	
	Type m_type;
	//Timer m_timer;

	Id m_id;
};
