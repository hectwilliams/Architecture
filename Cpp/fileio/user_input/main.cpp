#include <string>
#include <iostream>
#include <main.h>
#include <random>
#include <sstream>
#include <regex> 

string trim (const string &str) {
  return std::regex_replace( str, std::regex("^\\s+|\\s+$") , ""); // regex starts with space or ends with space
}

bool is_valid_line (std::string &s) {

  char delim = ' ';

  std::string result = ""; 
  
  std::string token;

  std::istringstream stream(s);

  while (std::getline(stream, token, delim)) {
    // similar to forEach(token_array...)

    token = trim(token) ;

    if (token.length() > 0) {

      std::cout << token << std::endl;
      
      result += token  + ' '; 

    }

  }
  
  result = result.substr(0, result.length() -1); // removes end char ' '
  
  if (result.length() == 0) {
    
    return false;

  } else {

    s = result; 

    return true; 

  }
   
}


int main () {
  
  std::string name;

  do {

    std::cout << "Enter your first name: ";

    std::getline(std::cin, name ); // read stdin line

  } while (!is_valid_line(name));
    
  std::cout << "name:" + name  << std::endl; 

}