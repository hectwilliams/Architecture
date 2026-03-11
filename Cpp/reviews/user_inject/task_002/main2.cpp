#include <iostream>
#include <string>

int main() {

  std::cout << "Enter full name: "; //: Shawn Paul
  
  std::string name{""};
  
  // input buffer [S,h,a,w,n,\n,P,a,u,l]
  
  std::getline(std::cin, name); // std::cin >> std::ws skips leading whitespace

  // input buffer []
  
  std::cout << name << std::endl;
  
  return 0;
}

