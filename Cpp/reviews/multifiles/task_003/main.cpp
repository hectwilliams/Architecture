/*
 
  File : 

  main.cpp 

  Purpose : 

  Use internal linkage  to show Goku and Vegeta using the same technique(i.e. function)  without conflicts within the compiler.

  Also, one is able to overload a symbol within their own file scope as shown below with function ultra_instinct(i.e. symbol) . 

  
*/

#include "goku.h"
#include "vegeta.h"
#include <iostream>

static void  ultra_instinct() {
  std::cout << "User does not have special power" << '\n'; 
}


int main() {
  ultra_instinct(); 
  goku_techniques();
  vegeta_techniques();
  
}
