#pragma once
#include <visitor/element.h>
#include <visitor/visitor.h>

struct TestVisitedElement : public Element<TestVisitedElement>
{
    bool wasVisited = false;

    void accept(Visitor<TestVisitedElement>& visitor_)
    {
        visitor_.visit(this);
    }

	// Something (not part of the pattern) to test we have visited the Element
    bool getState() const
    {
        return wasVisited;
    }

    void setState(bool newState)
    {
        wasVisited = newState;
    }
};

struct TestVisitor : public Visitor<TestVisitedElement>
{
    void visit(TestVisitedElement* visited_)
    {
        visited_->setState(true);
    }
};

TEST_CASE( "Visitor can visit an element", "[Visitor]" ) {
    TestVisitedElement visited;
    TestVisitor visitor;
    visited.accept(visitor);
	
    REQUIRE(visited.getState());
}
