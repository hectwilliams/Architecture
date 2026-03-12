#include <iostream>
#include "techniques.h"
#include "goku.h"

//private 
static void ultra_instinct () {
  std::cout << "Goku recently learned UI" << '\n';  
}

//public
static void spirit_bomb() {
  std::cout << "Goku used Spirit bomb was used to kill buu" << '\n';
}

void goku_techniques() {

  ultra_instinct();
  spirit_bomb();
}
