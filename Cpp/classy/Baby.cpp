#include <string>
#include <iostream>
#include <Baby.h>

Baby::Baby() {
  
  std::cout << "baby hi" << std::endl; 

}

void Baby::speak() {
  
  std::cout << "goo-goo--gaa--gaa" << std::endl; 

}

const std::string  Baby::birthday = "01-01-1111";
const std::string  Baby::eye_color = "blue";
const std::string  Baby::hair_color = "green";
const std::string  Baby::color = "black";
const std::string  Baby::height = "1'7";
bool Baby::is_walking = false; 