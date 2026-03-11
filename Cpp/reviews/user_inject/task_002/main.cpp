#include <iostream>
#include <string>

int main() {

  std::cout << "Enter full name: "; //: Shawn Paul
  
  std::string name{""};
  
  // buffer [S,h,a,w,n,\n,P,a,u,l]
  
  std::cin >> name; // pops Shawn out queue, terminates ones newline is read 
  
  // buffer [\n,P,a,u,l]
  
  std::cout << name << std::endl;
  
  std::cin >> name;  

  std::cout << name << std::endl;
  
  return 0;
}

