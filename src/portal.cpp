#include "portal.h"

Portal::Portal(Portal::Type type_, std::chrono::time_point<std::chrono::system_clock> endTime_)
	: m_type( type_ )
	, m_endTime( endTime_ )
{

}

Id Portal::getId() const
{
	return m_id;
}
