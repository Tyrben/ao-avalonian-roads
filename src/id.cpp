#include "id.h"

Id::Id(Id(state state_)
{

}

Id::Id()
	: m_value{ UniqueNumberGenerator::makeNew() }
{
	//init the random value?
}

Id& Id::operator= (const Id& id_)
{
	m_value = id_.m_value;
	return *this;
}

//friend
bool operator== (const Id& left_, const Id& right_)
{
	return left_.m_value == right_.m_value;
}

//friend
bool operator< (const Id& left_, const Id& right_)
{
	return left_.m_value < right_.m_value;
}
