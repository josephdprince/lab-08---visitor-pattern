#ifndef __RAND_HPP___
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    private:
        double value;
    public:
        Rand() : Base() { this->value = rand() % 100; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
	virtual int number_of_children() {
		return 2;
	}
	virtual Base* get_child() {
		if(i == 0)
			return val1;
		return val2;
	}
};

#endif //__RAND_HPP__
