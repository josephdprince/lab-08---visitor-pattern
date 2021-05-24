#include <iostream>
using namespace std;

#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "op.hpp"
#include "base.hpp"
#include "VisitorLaTeX.hpp"

int main() {
	/*
	//Ex 1:
	Op* op1 = new Op(1);
	Op* op2 = new Op(5);
	Op* op3 = new Op(0);

	Sub* sub = new Sub(op2, op3);
	Add* add = new Add(op1, sub);
	
	cout << add->stringify() << " => ";

	VisitorLaTeX* vist_1 = new VisitorLaTeX();
	vist_1->PrintLaTeX(add);

	
	//Ex 2:
	Op* op1 = new Op(5);
	Op* op2 = new Op(2);

	Pow* pow = new Pow(op1, op2);

	cout << pow->stringify() << " => ";
	
	VisitorLaTeX* vist_2 = new VisitorLaTeX();
	vist_2->PrintLaTeX(pow);
	

	//Ex 3:
	Op* op1 = new Op(2);
	Op* op2 = new Op(5);

	Mult* mult = new Mult(op1, op2);

	cout << mult->stringify() << " => ";

	VisitorLaTeX* vist_3 = new VisitorLaTeX();
	vist_3->PrintLaTeX(mult);

	
	//Ex 4:
	Op* op1 = new Op(2);
        Op* op2 = new Op(3);

        Div* div = new Div(op1, op2);

        cout << div->stringify() << " => ";

        VisitorLaTeX* vist_4 = new VisitorLaTeX();
        vist_4->PrintLaTeX(div);

	*/
	Op* op1 = new Op(2);
        Op* op2 = new Op(5);

        Mult* mult = new Mult(op1, op2);
	Pow* pow = new Pow(op2, op1);

	Div* div = new Div(mult, pow);

        cout << div->stringify() << " => ";

        VisitorLaTeX* vist_5 = new VisitorLaTeX();
        vist_5->PrintLaTeX(div);

	return 0;
}
