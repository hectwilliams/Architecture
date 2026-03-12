#include <iostream>
#include "techniques.h"

// private 
static void ultra_instinct () {
  std::cout << "Vegeta does not know UI" << '\n';  
}
static void galick_gun() {
  std::cout << "Vegeta - \" galicl-gun \" is my favorite technique" << '\n'; 
}

// public 
void vegeta_techniques() {
  ultra_instinct();
  galick_gun();
}
