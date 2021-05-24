#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "visitor.hpp"

#include <sstream>
#include <iomanip>

class Op : public Base {
    private:
	double value;   
    public:
        Op(double value) : Base() { this->value = value; }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { 
		std::ostringstream out;
		out << std::setprecision(6) << value;
		return out.str();
	}
	virtual int number_of_children() {return 0;}
	virtual Base* get_child(int i) {return nullptr;}
	virtual void accept(Visitor* visitor, int index) {
		visitor->visit_op(this);
	}
}; 

#endif //__OP_HPP__
