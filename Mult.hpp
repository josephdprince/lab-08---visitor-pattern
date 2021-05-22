#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Mult : public Base {
    private:
        Base* val1;
        Base* val2;
    public:
        Mult(Base* op1, Base* op2) : Base() {
                this->val1 = op1;
                this->val2 = op2;
        }
        virtual double evaluate() {
                return val1->evaluate() * val2->evaluate();
        }

        virtual std::string stringify() {
                return "(" + val1->stringify() + "*" + val2->stringify() + ")";
        }

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
			visitor->visit_mult_begin(this);
		else if(index == 1)
			visitor->visit_mult_middle(this);
		else
			visitor->visit_mult_end(this);
	}
};
#endif
