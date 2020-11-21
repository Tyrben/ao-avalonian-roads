#pragma once

#include <climits> //ULLONG_MAX
#include <random>

class UniqueNumberGenerator
{
public:
	static void initRandom(std::mt19937& generator_);
	static int makeNew();

private:
	static std::uniform_int_distribution<unsigned long long> m_distribution;
	static std::mt19937& m_randomGenerator;
};
