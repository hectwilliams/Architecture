#include <iostream>
#include <Elder.h>
#include <string>

Elder::Elder() {

  std::cout << "Elder hi" << std::endl;

}

void Elder::speak() {

  std::cout << "I am getting old" << std::endl;
  
}

void Elder::ailments () {

  if (this->has_cancer ) {

    std::cout << "Elder has cancer" << std::endl;

  } else {

    std::cout << "Elder does not have cancer" << std::endl;

  }

}

const bool Elder::has_cancer = true;
const bool Elder::has_virtigo = true; 
const bool Elder::has_grandkids = true; 
const bool Elder::is_dying = true; 
