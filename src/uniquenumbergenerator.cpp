#include "uniquenumbergenerator.h"

#include <random>

//static
std::uniform_int_distribution<unsigned long long> UniqueNumberGenerator::m_distribution(0, ULLONG_MAX);

//static
void UniqueNumberGenerator::initRandom(std::mt19937& generator_)
{
	m_randomGenerator = generator_;
}

//static
int UniqueNumberGenerator::makeNew()
{
	return m_distribution(m_randomGenerator);
}

//bool operator==(const MapId& left_, const MapId& right_)
//{
//	return left_.m_id == right_.m_id;
//}
