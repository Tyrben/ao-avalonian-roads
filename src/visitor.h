#pragma once

template<class T>
class Visitor
{
public:
	virtual void visitElement(T* e) = 0;//TODO check with a reference
};
