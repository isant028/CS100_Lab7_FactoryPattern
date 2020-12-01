#ifndef _FACTORY_TEST_HPP
#define _FACTORY_TEST_HPP

using namespace std;
#include <iostream>
#include "div.hpp"
#include "op.hpp"
#include "add.hpp"
#include "base.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "Mult.hpp"
#include "Rand.hpp"
#include "Factory.hpp" 

TEST(FactoryTest, Sub) {
    char* test_val[4]; test_val[0] = "./calculator";
 test_val[1] = "5"; 
test_val[2] = "-" ;
 test_val[3] = "4";
    Factory* subFact = new Factory();
    Base* test = subFact->parse(test_val, 4);
    string testStri = test->stringify();
    double testEval = test->evaluate();
    EXPECT_EQ("5.000000 - 4.000000", testStri);
    EXPECT_EQ(1, testEval);
}
TEST(FactoryTest, Add) {
   char* test_val[4];test_val[0] = "./calculator";
 test_val[1] = "3";
test_val[2] = "+" ;
 test_val[3] = "2";
    Factory* addFact = new Factory();
    Base* test = addFact->parse(test_val, 4);
    string testStri = test->stringify();
    double testEval = test->evaluate();
    EXPECT_EQ("3.000000 + 2.000000", testStri);
    EXPECT_EQ(5, testEval);
}
TEST(FactoryTest, Div) {
   char* test_val[4];test_val[0] = "./calculator";
 test_val[1] = "10";
test_val[2] = "/" ;
 test_val[3] = "5";
    Factory* divFact = new Factory();
    Base* test = divFact->parse(test_val, 4);
    string testStri = test->stringify();
    double testEval = test->evaluate();
    EXPECT_EQ("10.000000 / 5.000000", testStri);
    EXPECT_EQ(2, testEval);
}
TEST(FactoryTest, Mult) {
   char* test_val[4];test_val[0] = "./calculator";
 test_val[1] = "12";
test_val[2] = "*" ;
 test_val[3] = "4";
    Factory* multFact = new Factory();
    Base* test = multFact->parse(test_val, 4);
    string testStri = test->stringify();
    double testEval = test->evaluate();
    EXPECT_EQ("12.000000*4.000000", testStri);
    EXPECT_EQ(48, testEval);
}
TEST(FactoryTest, Pow) { 
  char* test_val[4];test_val[0] = "./calculator";
 test_val[1] = "2";
test_val[2] = "**" ;
 test_val[3] = "3";
    Factory* powFact = new Factory();
    Base* test = powFact->parse(test_val, 4);
    string testStri = test->stringify();
    double testEval = test->evaluate();
    EXPECT_EQ("2.000000**3.000000", testStri);
    EXPECT_EQ(8, testEval);
}
TEST(FactoryTest, wrongInput){
  char* test_val[2]; test_val[0] = "./calculator"; test_val[1] = "qwerty";
  Factory* wrongFac = new Factory();
  Base* test = wrongFac->parse(test_val, 2);
  ASSERT_TRUE(test == nullptr);
  cout << "Invalid Input" << endl;
}
TEST(FactoryTest, addAndMult) {
  char* test_val[6];test_val[0] = "./calculator";
 test_val[1] = "2";
test_val[2] = "+" ;
 test_val[3] = "3";
test_val[4] = "*";
test_val[5] = "5";
    Factory* testFact = new Factory();
    Base* test = testFact->parse(test_val, 6);
    string testStri = test->stringify();
    double testEval = test->evaluate();
    EXPECT_EQ(25, testEval);
}
TEST(FactoryTest, oneNum) {
  char* test_val[2];test_val[0] = "./calculator";
 test_val[1] = "12";
    Factory* powFact = new Factory();
    Base* test = powFact->parse(test_val, 2);
    string testStri = test->stringify();
    double testEval = test->evaluate();
    EXPECT_EQ("12.000000", testStri);
    EXPECT_EQ(12, testEval);
}
#endif

