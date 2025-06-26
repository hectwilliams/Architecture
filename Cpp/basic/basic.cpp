#include <iostream>
#include <cmath>
using namespace std; 


std::string location() {
  std::string result;

  result += "120 120 90";

  return result; 
}

std::string location(int style) {
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

    std::cout << "invalid modes, please try again" << std::endl;
    break;

  }

  return tmp; 

}

