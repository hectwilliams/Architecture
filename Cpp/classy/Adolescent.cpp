#include <iostream>
#include <Adolescent.h>

Adolescent::Adolescent() {

  std::cout << "Adolescent hi" << std::endl;

}

void Adolescent::speak() {

  std::cout << "the future looks bright" << std::endl;
  
}

const bool Adolescent::is_virgin = false; 
const bool Adolescent::used_drugs = false; 
const bool Adolescent::is_athletic = true; 
bool Adolescent::is_walking = true; 
