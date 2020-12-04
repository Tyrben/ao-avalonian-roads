#include "portal.h"

#include <utility>

/*Portal::Portal(Portal::Type type_, std::chrono::time_point<std::chrono::system_clock> endTime_)
	: m_type( type_ )
	, m_endTime( endTime_ )
{

}*/

Portal::Portal(Type type_, const MapId& mapLeft_, const MapId& mapRight_)
	: m_id{ UniqueNumberGenerator::makeNew() }
	, m_type(type_)
	, m_positionLeft{ Position({ 0, 0 }, mapLeft_) }
	, m_positionRight{ Position({ 0 ,0 }, mapRight_) }
{
}

Portal::Portal(Type type_, Position positionLeft_, Position positionRight_)
	: m_id{ UniqueNumberGenerator::makeNew() }
	, m_type(type_)
	, m_positionLeft(positionLeft_)
	, m_positionRight(positionRight_)
{
}

const PortalId& Portal::getId() const
{
	return m_id;
}

//std::pair<const MapId&, const MapId&> Portal::getLink() const
std::pair<const MapId, const MapId> Portal::getLink() const
{
	//copie plutot ?
	return std::make_pair(m_positionLeft.mapId, m_positionRight.mapId);
}

bool Portal::isEnded() const
{
	if (m_type == Type::Static) return false;
	return true;
}
