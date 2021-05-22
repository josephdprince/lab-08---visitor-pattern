#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath>
#include "visitor.hpp"

class Pow : public Base {
    private:
	Base* val1;
	Base* val2;
    public:
	Pow(Base* val1, Base* val2) : Base() {
		this->val1 = val1;
		this->val2 = val2;
	}

	virtual double evaluate() { return pow(val1->evaluate(), val2->evaluate()); }
	virtual std::string stringify() { return "(" + val1->stringify() + "**" + val2->stringify() + ")";}
	virtual int number_of_children() {
		return 2;
	}
	
	virtual Base* get_child(int i) {
		if(i == 0)
			return val1;
		return val2;
	}

	virtual void accept(Visitor* visitor, int index) {
                if(index == 0)
                        visitor->visit_pow_begin(this);
                else if(index == 1)
                        visitor->visit_pow_middle(this);
                else
                        visitor->visit_pow_end(this);
        }
};

#endif
