#pragma once

#include <climits> //ULLONG_MAX
#include <random>

class UniqueNumberGenerator
{
public:
	static unsigned long long makeNew();

private:
	static std::random_device m_rd;
	static std::mt19937 m_randomGenerator;
	static std::uniform_int_distribution<unsigned long long> m_distribution;
};
