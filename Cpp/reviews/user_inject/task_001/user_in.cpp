#include <iostream>
#include <string>
#include <regex>
#include <stdexcept>


void check_string(const std::string s) {
  
  std::regex re("[0-9]+\n");
  std::regex re2("[^0-9\n]"); 
  std::smatch m, m2;
  std::regex_search(s, m , re); // digits only 
  std::regex_search(s, m2 , re2);  // non digit
  
  if (!m2.empty() && !m.empty()) {
    
    throw std::runtime_error("non-integer found");

  }
 
  /* matches
  for (std::size_t n = 0; n < m.size(); n++) {    
    
    std::cout <<"m[" << n << "] = "  <<  m[n] << std::endl; 
   
  }
  */

}

int main() 

{

  int x;

  char ch;
  
  std::string s_buffer;  

  std::cin.clear(); // clear error flags
  
  std::cout << "Enter your age: "; 
  
  while (ch != '\n') {

    ch = std::cin.get(); // wait for user input 
  
    s_buffer += ch;

  } 

  check_string(s_buffer);
  
  std::cout << "You entered the follwing string: " << s_buffer << std::endl;

}
