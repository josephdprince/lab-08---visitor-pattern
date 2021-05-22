#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

#include "visitor.hpp"
#include "iterator.hpp"
#include <iostream>

class VisitorLaTeX : public Visitor {
    public:
	virtual void visit_op(Op* node) {
		std::cout << "{" << node->evaluate() << "}";
	}

        virtual void visit_rand(Rand* node) {
		std::cout << "{" << node->evaluate() << "}";
	}
	
	virtual void visit_add_begin(Add* node) {
		std::cout << "{(";
	}

        virtual void visit_add_middle(Add* node) {
		std::cout << "+";		
	}

        virtual void visit_add_end(Add* node) {
		std::cout << ")}";
	}

        virtual void visit_sub_begin(Sub* node) {
		std::cout << "{(";
	}

        virtual void visit_sub_middle(Sub* node) {
		std::cout << "-";
	}

        virtual void visit_sub_end(Sub* node) {
		std::cout << ")}";
	}

        virtual void visit_mult_begin(Mult* node) {
		std::cout << "{(";
	}

        virtual void visit_mult_middle(Mult* node) {
		std::cout << "\\cdot";
	}

        virtual void visit_mult_end(Mult* node) {
		std::cout << ")}";
	}

        virtual void visit_div_begin(Div* node) {
		std::cout << "{";
	}

        virtual void visit_div_middle(Div* node){
		std::cout << "\\frac";
	}

        virtual void visit_div_end(Div* node) {
		std::cout << "}";
	}

        virtual void visit_pow_begin(Pow* node) {
		std::cout << "{(";
	}

        virtual void visit_pow_middle(Pow* node) {
		std::cout << "^";
	}

        virtual void visit_pow_end(Pow* node) {
		std::cout << ")}";
	}

	std::string PrintLaTeX(Base* ptr) {
		Iterator* it = new Iterator(ptr);
        	while (!it->is_done()) {
                	Base* curr = it->current_node()
                	curr->accept(this, it->current_index());
                	it->next();
        	}

	}
#endif
