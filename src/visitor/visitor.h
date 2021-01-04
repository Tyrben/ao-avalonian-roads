#pragma once

#include <cstdarg>
/*
 * TODO retqke pqttern with parameters
 *
 * public interface ISomethingVisitor
{
	void visit(Foo foo, VisitOptions params);
}

public interface ISomethingVisitable
{
	void accept(ISomethingVisitor visitor, VisitOptions params);
}

idea : variadic

*/
template<class T>
class Visitor
{
public:
	virtual void visit(T* e, std::va_list args) = 0;//TODO check with a reference
	virtual ~Visitor() = default;
};

// Inspired from https://sourcemaking.com/design_patterns/visitor/cpp/2
