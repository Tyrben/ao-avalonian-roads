#pragma once

#include "uniquenumbergenerator.h"

using MapId = unsigned long long;
using PortalId = unsigned long long;

struct IdManip
{
	static std::string toString(unsigned long long);
};

/*
class Id
{
public:
	//enum class state { UNBINDED };
	//Id(state state_ = state::UNBINDED);
	Id();

	virtual Id& operator= (const Id& id_);

	friend bool operator== (const Id& left_, const Id& right_);
	friend bool operator< (const Id& left_, const Id& right_);

	virtual std::string toString() const;

private:
	unsigned long long m_value;
};

bool operator== (const Id& left_, const Id& right_);
bool operator< (const Id& left_, const Id& right_);

class PortalId : public Id
{
};

class MapId : public Id
{
};
*/
