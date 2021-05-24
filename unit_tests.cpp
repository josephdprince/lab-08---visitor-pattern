#ifndef __UNIT_TEST_CPP__
#define __UNIT_TEST_CPP__

#include "gtest/gtest.h"

#include "VisitorLaTeX.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_DOUBLE_EQ(test->evaluate(), 8);
    EXPECT_EQ(test->number_of_children(), 0);
    EXPECT_EQ(test->get_child(0), nullptr);
}

TEST(MultTest, MultEvaluateNonZero) {
    Op* val1 = new Op(2);
    Op* val2 = new Op(3);
    Mult* test = new Mult(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->evaluate(), 6);
    EXPECT_DOUBLE_EQ(test->number_of_children(), 2);
    EXPECT_DOUBLE_EQ(test->get_child(0)->evaluate(), 2);
    EXPECT_EQ(test->stringify(), "(2*3)");
    EXPECT_EQ(visit->PrintLaTeX(test), "${({2}\\cdot{3})}$");
}

TEST(MultTest, MultEvaluatePosNeg) {
    Op* val1 = new Op(-5.7);
    Op* val2 = new Op(3.2);
    Mult* test = new Mult(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_FLOAT_EQ(test->evaluate(), -18.24);
    EXPECT_DOUBLE_EQ(test->number_of_children(), 2);
    EXPECT_DOUBLE_EQ(test->get_child(0)->evaluate(), -5.7);
    EXPECT_EQ(test->stringify(), "(-5.7*3.2)");
    EXPECT_EQ(visit->PrintLaTeX(test), "${({-5.7}\\cdot{3.2})}$");
}

TEST(MultTest, MultEvaluateOpInput) {
    Op* val1 = new Op(-4);
    Op* val2 = new Op(6);
    Mult* op1 = new Mult(val1, val2);
    Op* val3 = new Op(2.0);
    Mult* op2 = new Mult(op1, val3);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(op2->number_of_children(), 2);
    EXPECT_DOUBLE_EQ(op2->get_child(0)->evaluate(), -24);
    EXPECT_FLOAT_EQ(op2->evaluate(), -48);
    EXPECT_EQ(visit->PrintLaTeX(op2), "${({({-4}\\cdot{6})}\\cdot{2})}$");
}

TEST(DivTest, DivEvaluateNonZero) {
    Op* val1 = new Op(6);
    Op* val2 = new Op(3);
    Div* test = new Div(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->evaluate(), 2);
    EXPECT_EQ(test->stringify(), "(6/3)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0)->evaluate(), 6);
    EXPECT_EQ(visit->PrintLaTeX(test), "${\\frac{6}{3}}$");
}

TEST(DivTest, DivEvaluatePosNeg) {
    Op* val1 = new Op(-24.2);
    Op* val2 = new Op(2.0);
    Div* test = new Div(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_FLOAT_EQ(test->evaluate(), -12.1);
    EXPECT_EQ(test->stringify(), "(-24.2/2)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(1)->evaluate(), 2.0);
    EXPECT_EQ(visit->PrintLaTeX(test), "${\\frac{-24.2}{2}}$");
}

TEST(DivTest, DivEvaluateOpInput) {
    Op* val1 = new Op(-24);
    Op* val2 = new Op(6);
    Div* op1 = new Div(val1, val2);
    Op* val3 = new Op(2.0);
    Div* op2 = new Div(op1, val3);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_FLOAT_EQ(op2->evaluate(), -2);
    EXPECT_EQ(op2->number_of_children(), 2);
    EXPECT_EQ(op2->get_child(0)->evaluate(), -4);
    EXPECT_EQ(visit->PrintLaTeX(op2), "${\\frac{\\frac{-24}{6}}{2}}$");
}

TEST(AddTest, AddTwoPosNums) {
    Op* val1 = new Op(8);
    Op* val2 = new Op(4);
    Add* test = new Add(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->evaluate(), 12);
    EXPECT_EQ(test->stringify(), "(8+4)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0)->evaluate(), 8);
    EXPECT_EQ(visit->PrintLaTeX(test), "${({8}+{4})}$");
}

TEST(AddTest, AddPosNegNum) {
    Op* val1 = new Op(-4.3);
    Op* val2 = new Op(9.7);
    Add* test = new Add(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->evaluate(), 5.4);
    EXPECT_EQ(test->stringify(), "(-4.3+9.7)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0)->evaluate(), -4.3);
    EXPECT_EQ(visit->PrintLaTeX(test), "${({-4.3}+{9.7})}$");
}

TEST(AddTest, AddWithOperationChild) {
    Op* val1 = new Op(3.3);
    Op* val2 = new Op(7.9);
    Op* val3 = new Op(4.6);
    Add* add1 = new Add(val2, val3);
    Add* test = new Add(val1, add1);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->evaluate(), 15.8);
    EXPECT_EQ(test->stringify(), "(3.3+(7.9+4.6))");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(1)->evaluate(), 12.5);
    EXPECT_EQ(visit->PrintLaTeX(test), "${({3.3}+{({7.9}+{4.6})})}$");
}

TEST(PowTest, TwoPosNums) {
    Op* val1 = new Op(3.2);
    Op* val2 = new Op(2.0);
    Pow* test = new Pow(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->number_of_children(), 2);
        EXPECT_DOUBLE_EQ(test->get_child(1)->evaluate(), 2.0);
    EXPECT_DOUBLE_EQ(test->evaluate(), 10.24);
    EXPECT_EQ(test->stringify(), "(3.2**2)");
    EXPECT_EQ(visit->PrintLaTeX(test), "${({3.2}^{2})}$");
}

TEST(PowTest, NegExponent) {
    Op* val1 = new Op(2.7);
    Op* val2 = new Op(-2.0);
    Pow* test = new Pow(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_FLOAT_EQ(test->evaluate(), 0.137174211);
    EXPECT_DOUBLE_EQ(test->number_of_children(), 2);
    EXPECT_DOUBLE_EQ(test->get_child(0)->evaluate(), 2.7);
    EXPECT_EQ(test->stringify(), "(2.7**-2)");
    EXPECT_EQ(visit->PrintLaTeX(test), "${({2.7}^{-2})}$");
}

TEST(PowTest, PowOp) {
    Op* val1 = new Op(2.0);
    Op* val2 = new Op(2.0);
    Op* val3 = new Op(2.0);
    Pow* pow = new Pow(val2, val3);
    Pow* test = new Pow(val1, pow);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->number_of_children(), 2);
    EXPECT_DOUBLE_EQ(test->get_child(1)->evaluate(), 4.0);
    EXPECT_DOUBLE_EQ(test->evaluate(), 16.0);
    EXPECT_EQ(test->stringify(), "(2**(2**2))");
    EXPECT_EQ(visit->PrintLaTeX(test), "${({2}^{({2}^{2})})}$");
}

TEST(SubTest, SubTwoPosNums) {
    Op* val1 = new Op(4.3);
    Op* val2 = new Op(3.7);
    Sub* test = new Sub(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->evaluate(), 0.6);
    EXPECT_DOUBLE_EQ(test->number_of_children(), 2);
    EXPECT_DOUBLE_EQ(test->get_child(0)->evaluate(), 4.3);
    EXPECT_EQ(test->stringify(), "(4.3-3.7)");
    EXPECT_EQ(visit->PrintLaTeX(test), "${({4.3}-{3.7})}$");
}

TEST(SubTest, FirstNumLarger) {
    Op* val1 = new Op(3.7);
    Op* val2 = new Op(4.3);
    Sub* test = new Sub(val1, val2);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->number_of_children(), 2);
    EXPECT_DOUBLE_EQ(test->get_child(1)->evaluate(), 4.3);
    EXPECT_DOUBLE_EQ(test->evaluate(), -0.6);
    EXPECT_EQ(test->stringify(), "(3.7-4.3)");
    EXPECT_EQ(visit->PrintLaTeX(test), "${({3.7}-{4.3})}$");
}

TEST(SubTest, SubOpChild) {
    Op* val1 = new Op(3.79);
    Op* val2 = new Op(1.32);
    Op* val3 = new Op(2.95);
    Sub* sub = new Sub(val2, val3);
    Sub* test = new Sub(val1, sub);
    VisitorLaTeX* visit = new VisitorLaTeX();

    EXPECT_DOUBLE_EQ(test->number_of_children(), 2);
    EXPECT_DOUBLE_EQ(test->get_child(1)->evaluate(), -1.63);
    EXPECT_DOUBLE_EQ(test->evaluate(), 5.42);
    EXPECT_EQ(test->stringify(), "(3.79-(1.32-2.95))");
    EXPECT_EQ(visit->PrintLaTeX(test), "${({3.79}-{({1.32}-{2.95})})}$");
}

TEST(RandTest, RandOp) {
    Rand* val1 = new Rand();
    EXPECT_DOUBLE_EQ(val1->number_of_children(), 0);
    EXPECT_EQ(val1->get_child(0), nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif //__OP_TEST_HPP__
