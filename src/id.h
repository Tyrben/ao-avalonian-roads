#pragma once

#include "uniquenumbergenerator.h"

//using Id = unsigned long long;

class Id
{
public:
	Id();

	Id& operator= (const Id& id_);

	friend bool operator== (const Id& left_, const Id& right_);
	friend bool operator< (const Id& left_, const Id& right_);

private:
	unsigned long long m_value;
};

bool operator== (const Id& left_, const Id& right_);
bool operator< (const Id& left_, const Id& right_);
