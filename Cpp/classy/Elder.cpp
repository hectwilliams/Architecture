#include <iostream>
#include <Elder.h>

Elder::Elder() {

  std::cout << "Elder hi" << std::endl;

}

void Elder::speak() {

  std::cout << "I am getting old" << std::endl;
  
}
const bool Elder::has_virtigo = true; 
const bool Elder::has_grandkids = true; 
const bool Elder::is_dying = true; 
