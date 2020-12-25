#pragma once

#include "visitor.h"

template<class T>
class Element
{
public:
	virtual void accept(class Visitor<T>&) = 0;
    virtual ~Element() = default;
};
