#include <iostream>
#include <cmath>
using namespace std; 


std::string location() {

  /*
    returns a hardcoded string 
  */

  std::string result;

  result += "120 120 90";

  return result; 
}


std::string location(int style) {

  /*
    style arguments selects from table 
  */

  std::string tmp;

  switch (style)
  {

  case 0:

    tmp = "199";
    break;

  case 1:

    tmp = "0x100";
    break;

  default:

    std::cout << "invalid modes, please try again\n" << std::endl;
    break;

  }

  return tmp; 

}

