using namespace std;
#include <iostream>

#ifndef BASIC_H
#define BASIC_H

// c style functions 

#ifdef __cplusplus
  extern "C" {
#endif 
  
  void basic_cfunc(int a);
  void quiet();

#ifdef __cplusplus
}
#endif 


// c++ style functions 
std::string location();
std::string location (int style);
#endif 