#include "gtest/gtest.h"

//#include "op_test.hpp"

//#include "Mult_Test.hpp"
//#include "div_test.hpp"
//#include "sub_test.hpp"
//#include "add_test.hpp" 
//#include "pow_test.hpp"
//#include "Rand_Test.hpp"
#include "Factory_test.hpp"
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
