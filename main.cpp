#include <iostream>


#include "base.hpp"
#include "op.hpp"
#include "Rand.hpp"
#include "Mult.hpp"
#include "add.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "sub.hpp"
//#include "SevenOpMock.hpp"
#include "Factory.hpp"
int main (int argv, char** argc){
  Factory* mainFactory = new Factory();

  Base* output = mainFactory->parse(argc, argv);
  if (output == nullptr){
    cout << "input is nullptr" << endl;
  }
 else{
 cout << "Equation: " << output->stringify() << endl;
 cout << "Answer: " << output->evaluate() << endl;
}
    return 0;
}
