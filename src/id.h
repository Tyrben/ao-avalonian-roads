#pragma once

#include "uniquenumbergenerator.h"

template<class T>
class Id;

template<class T>
bool operator== (const Id<T>& left_, const Id<T>& right_);

//using Id = unsigned long long;
template<class T>
class Id
{
public:
	Id();

	Id<T>& operator= (const Id<T>& id_);

	friend bool operator== <T>(const Id<T>& left_, const Id<T>& right_);

private:
	unsigned long long m_value;
};

template<class T>
Id<T>::Id()
	: m_value { UniqueNumberGenerator::makeNew() }
{
	//init the random value?
}

template<class T>
Id<T>& Id<T>::operator= (const Id<T>& id_)
{
	m_value = id_.m_value;
	return *this;
}

template<class T>
bool operator== (const Id<T>& left_, const Id<T>& right_)
{
	return left_.m_value == right_.m_value;
}
