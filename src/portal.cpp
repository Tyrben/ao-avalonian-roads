#include "portal.h"

#include <utility>

/*Portal::Portal(Portal::Type type_, std::chrono::time_point<std::chrono::system_clock> endTime_)
	: m_type( type_ )
	, m_endTime( endTime_ )
{

}*/

Portal::Portal(Type type_, const MapId& idLeft_, const MapId& idRight_)
	: m_type(type_)
	, m_mapIdLeft(idLeft_)
	, m_mapIdRight(idRight_)
{
}

const PortalId& Portal::getId() const
{
	return m_id;
}

std::pair<const MapId&, const MapId&> Portal::getLink() const
{
	return std::make_pair(m_mapIdLeft, m_mapIdRight);
}

bool Portal::isEnded() const
{
	if (m_type == Type::Static) return false;
	return true;
}
