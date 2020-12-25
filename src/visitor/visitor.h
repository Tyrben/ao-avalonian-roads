#pragma once

template<class T>
class Visitor
{
public:
	virtual void visit(T* e) = 0;//TODO check with a reference
    virtual ~Visitor() = default;
};

// Inspired from https://sourcemaking.com/design_patterns/visitor/cpp/2
