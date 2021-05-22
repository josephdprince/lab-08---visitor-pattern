#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    private:
	Base* val1;
	Base* val2;
    public:
	Sub(Base* val1, Base* val2) : Base() {
		this->val1 = val1;
		this->val2 = val2;
	}

	virtual double evaluate() { return val1->evaluate() - val2->evaluate(); }
	virtual std::string stringify() { return "(" + val1->stringify() + "-" + val2->stringify() + ")"; }
	virtual int number_of_children() {
		return 2;
	}

	virtual Base* get_child(int i) {
		if(i == 0)
			return val1;
		return val2;
	}
};

#endif
