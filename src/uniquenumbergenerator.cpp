#include "uniquenumbergenerator.h"

//static
std::random_device UniqueNumberGenerator::m_rd;
std::mt19937 UniqueNumberGenerator::m_randomGenerator(UniqueNumberGenerator::m_rd());
std::uniform_int_distribution<unsigned long long> UniqueNumberGenerator::m_distribution(0, ULLONG_MAX);

//static
unsigned long long UniqueNumberGenerator::makeNew()
{
	return UniqueNumberGenerator::m_distribution(UniqueNumberGenerator::m_randomGenerator);
}
