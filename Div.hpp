#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Div : public Base {
	private:
		Base* val1;
		Base* val2;
	public:
		Div(Base* op1, Base* op2) : Base() {
			this->val1 = op1;
			this->val2 = op2;
		}
		virtual double evaluate() {
			return val1->evaluate() / val2->evaluate();
		}
		virtual std::string stringify() {
			return "(" + val1->stringify() + "/" + val2->stringify() + ")";
		}
		virtual int number_of_children() {return 2;}
		virtual Base* get_child(int i) {
			if(i == 0) {
				return val1;
			}
			else {
				return val2;
			}
		}
		virtual void accept(Visitor* visitor, int index) {
			if (index == 0)
				visitor->visit_div_begin(this);
			else if (index == 1)
				visitor->visit_div_middle(this);
			else 
				visitor->visit_div_end(this);
		}
};	

#endif
