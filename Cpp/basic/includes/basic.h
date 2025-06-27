using namespace std;
#include <iostream>

#ifndef BASIC_H
#define BASIC_H

// c style functions 

#ifdef __cplusplus
  extern "C" {
#endif 
  
/*

  function: 
    
    basic_cfunc 

  input: 

    a - integer value  

  outputs: 

    None 

  remarks: 

    c library function
*/
  void basic_cfunc(int a);
  
  /*

  function: 
    
    quiet 

  input: 

    None 

  outputs: 

    None 

  remarks: 

    c library function

*/
  void quiet();

#ifdef __cplusplus
  }
#endif 

// c++ style functions 

/*

  function: 
    
    location 

  input: 

    None 

  outputs: 

    string 

  remarks: 

    an overloaded function

*/
std::string location();


/*
  function: 
    
    location 

  input: 

    style - integer value representing the string style to return

  outputs: 

    string 

  remarks:

    an overloaded function 

*/
std::string location (int style);

#endif 