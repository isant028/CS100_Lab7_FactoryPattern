#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__



#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include "div.hpp"
#include "op.hpp"
#include "add.hpp"
#include "base.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "Mult.hpp"
#include "Rand.hpp"
#include <stack>
#include <queue>

#include <ctype.h>
#include <stdio.h>


using namespace std;


class base;

class Factory {
    public:
      Factory(){ };
      Base* parse(char** input, int length){
        queue<char*> qu;
        stack<char*> st;
        string stri;
        for (int i = 1; i < length; ++i){
           stri = static_cast<string>(input[i]);
          if (isdigit(stri.at(0))){
            qu.push(input[i]);
          }
          else if (stri == "+" || stri == "-" || stri == "*" || stri == "/" || stri == "**"){
            while(!st.empty()){
              qu.push(st.top());
              st.pop();
            }
            st.push(input[i]);
          }
          else{
            cout << "Invalid input" << endl;
            return nullptr;
          }
        }
        while(!st.empty()){
          qu.push(st.top());
          st.pop();

        }
        queue<Base*> qu2;
        Base* temp1;
        Base* temp2;
        Base* temp3;
        double temp4;
        while(!qu.empty()){
          stri = static_cast<string>(qu.front());
 if (stri == "-"){
           temp2 = qu2.front();
           qu2.pop();
           temp3 = qu2.front();
           qu2.pop();
           temp1 = new Sub(temp2, temp3);
           qu2.push(temp1);
           qu.pop();
          }
        else if (stri == "+"){
           temp2 = qu2.front();
           qu2.pop();
           temp3 = qu2.front();
           qu2.pop();
           temp1 = new Add(temp2, temp3);
           qu2.push(temp1);
           qu.pop();
          }
          else if (stri == "*"){
           temp2 = qu2.front();
           qu2.pop();
           temp3 = qu2.front();
           qu2.pop();
           temp1 = new Mult(temp2, temp3);
           qu2.push(temp1);
           qu.pop();
          }

          else if (stri == "**"){
           temp2 = qu2.front();
           qu2.pop();
           temp3 = qu2.front();
           qu2.pop();
           temp1 = new Pow(temp2, temp3);
           qu2.push(temp1);
           qu.pop();
          }

          else if (stri == "/"){
           temp2 = qu2.front();
           qu2.pop();
           temp3 = qu2.front();
           qu2.pop();
           temp1 = new Div(temp2, temp3);
           qu2.push(temp1);
           qu.pop();
          }

          else{
            temp4 = stod(stri);
            temp1 = new Op(temp4);
            qu.pop();
            qu2.push(temp1);
          }

        }
        return qu2.front();
      }
};

#endif

