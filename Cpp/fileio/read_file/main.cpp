#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <main.h> 

void handleCsvLine (const char * s) {
  
  // splits csv line on delimiter and prints each token on a seperate line 

   int column = 0;

  char delim = ',';
  
  std::string token; 
  
  std::istringstream stream(s);

  while (std::getline(stream, token, delim)) {

    std::cout << "[" + std::to_string(column++) + "]  " + token << std:: endl;
    
  }

}

int main() {

  char buffer[CHARS_PER_LINE];
  
  try {
    
    std::ifstream file("sinfft.csv", std::ifstream::in); // file , mode?-open for reading
    
    file.getline(buffer, CHARS_PER_LINE); // ->[?][?][?]
    
    while (file.good()) {
      
      std::cout << buffer << std:: endl;

      handleCsvLine(buffer);
      
      file.getline(buffer, CHARS_PER_LINE); // [?]->[?][?]

    }
  
  } catch(...) {
    
    std::cout << "caught an exception" << std::endl; 

  }

}
