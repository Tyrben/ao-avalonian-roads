#pragma once

#include "visitor.h"
//WIP variadic visitor to be able to implement visit with parameters

template<class T>
class Element
{
public:
	virtual void accept(class Visitor<T>*...) = 0;
	virtual ~Element() = default;
};
