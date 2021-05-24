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
	
	//Ex 1:
	Op* op1 = new Op(1);
	Op* op2 = new Op(5);
	Op* op3 = new Op(0);

	Sub* sub = new Sub(op2, op3);
	Add* add = new Add(op1, sub);
	
	cout << add->stringify() << " => ";

	VisitorLaTeX* vist_1 = new VisitorLaTeX();
	cout << vist_1->PrintLaTeX(add) << endl;
	
	
	//Ex 2:
	Op* op4 = new Op(5);
	Op* op5 = new Op(2);

	Pow* pow = new Pow(op4, op5);

	cout << pow->stringify() << " => ";
	
	VisitorLaTeX* vist_2 = new VisitorLaTeX();
	cout << vist_2->PrintLaTeX(pow) << endl;
	
	
	//Ex 3:
	Op* op6 = new Op(2);
	Op* op7 = new Op(5);

	Mult* mult = new Mult(op6, op7);

	cout << mult->stringify() << " => ";

	VisitorLaTeX* vist_3 = new VisitorLaTeX();
	cout << vist_3->PrintLaTeX(mult) << endl;
	
	//Ex 4:
	Op* op8 = new Op(2);
        Op* op9 = new Op(3);

        Div* div = new Div(op8, op9);

        cout << div->stringify() << " => ";

        VisitorLaTeX* vist_4 = new VisitorLaTeX();
        cout << vist_4->PrintLaTeX(div) << endl;

	//Ex 5:
	Op* op10 = new Op(2);
        Op* op11 = new Op(5);

        Mult* mult2 = new Mult(op10, op11);
	Pow* pow2 = new Pow(op11, op10);

	Div* div2 = new Div(mult2, pow2);

        cout << div2->stringify() << " => ";

        VisitorLaTeX* vist_5 = new VisitorLaTeX();
        cout << vist_5->PrintLaTeX(div2) << endl;
	
	return 0;
}
