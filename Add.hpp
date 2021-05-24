#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Add : public Base {
    private:
	Base* value1;
	Base* value2;
    public:
	Add(Base* value1, Base* value2) : Base() {
		this->value1 = value1;
		this->value2 = value2;	
	}
	
	virtual double evaluate() { return value1->evaluate() + value2->evaluate(); }
	virtual std::string stringify() { return "(" + value1->stringify() + "+" + value2->stringify() + ")"; }
	virtual int number_of_children() {return 2;}
	virtual Base* get_child(int i) {
		if (i == 0) {
			return value1;
		}
		else {
			return value2;
		}
	}
	virtual void accept(Visitor* visitor, int index) {
		if (index == 0)
			visitor->visit_add_begin(this);
		else if (index == 1)
			visitor->visit_add_middle(this);
		else 
			visitor->visit_add_end(this);
	}
	
};

#endif
