#pragma once

#include "uniquenumbergenerator.h"

//using Id = unsigned long long;

class Id
{
public:
	//enum class state { UNBINDED };
	//Id(state state_ = state::UNBINDED);
	Id();

	Id& operator= (const Id& id_);

	friend bool operator== (const Id& left_, const Id& right_);
	friend bool operator< (const Id& left_, const Id& right_);

private:
	unsigned long long m_value;
};

bool operator== (const Id& left_, const Id& right_);
bool operator< (const Id& left_, const Id& right_);
