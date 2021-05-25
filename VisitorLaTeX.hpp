#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include "visitor.hpp"
#include "iterator.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

#include "op.hpp"
#include "Rand.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Pow.hpp"


class VisitorLaTeX : public Visitor {
    private:
	std::string equation;
    public:
	virtual void visit_op(Op* node) {
		std::ostringstream out;
		out << std::setprecision(6) << node->evaluate();
		equation += ("{" + out.str() + "}");
	}

        virtual void visit_rand(Rand* node) {
		std::ostringstream out;
		out << std::setprecision(6) << node->evaluate();
		equation += ("{" + out.str() + "}");
	}
	
	virtual void visit_add_begin(Add* node) {
		equation +=  "{(";
	}

        virtual void visit_add_middle(Add* node) {
		equation += "+";		
	}

        virtual void visit_add_end(Add* node) {
		equation += ")}";
	}

        virtual void visit_sub_begin(Sub* node) {
		equation += "{(";
	}

        virtual void visit_sub_middle(Sub* node) {
		equation += "-";
	}

        virtual void visit_sub_end(Sub* node) {
		equation += ")}";
	}

        virtual void visit_mult_begin(Mult* node) {
		equation += "{(";
	}

        virtual void visit_mult_middle(Mult* node) {
		equation += "\\cdot";
	}

        virtual void visit_mult_end(Mult* node) {
		equation += ")}";
	}

        virtual void visit_div_begin(Div* node) {
		equation +=  "{\\frac";
	}

        virtual void visit_div_middle(Div* node){
		equation +=  "";
	}

        virtual void visit_div_end(Div* node) {
		equation +=  "}";
	}

        virtual void visit_pow_begin(Pow* node) {
		equation += "{(";
	}

        virtual void visit_pow_middle(Pow* node) {
		equation +=  "^";
	}

        virtual void visit_pow_end(Pow* node) {
		equation += ")}";
	}

	std::string PrintLaTeX(Base* ptr) {
		equation = "$";
		Iterator* it = new Iterator(ptr);
        	while (it->is_done() == false) {
                	Base* curr = it->current_node();
                	curr->accept(this, it->current_index());
                	it->next();
        	}
		equation += "$";
		delete it;
		return equation;
	}
};
#endif
