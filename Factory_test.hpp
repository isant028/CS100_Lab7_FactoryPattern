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
   char* test_val[3];
 test_val[0] = "5"; 
test_val[1] = "-" ;
 test_val[2] = "4";
    Factory* subFact = new Factory();
    Base* test = subFact->parse(test_val, 3);
    string testStri = test->stringify();
    double testEval = test->evaluate();
    EXPECT_EQ("5 - 4", testStri);
    EXPECT_EQ(1, testEval);
}

#endif

