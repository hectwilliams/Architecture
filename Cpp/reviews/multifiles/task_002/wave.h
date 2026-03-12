
#pragma once 

#include <cmath> 

namespace Wave {
  constexpr double N {1024};
  constexpr double Fo {10}; 
  constexpr double Fo2 {5}; 
  constexpr double Fs {30}; 
  constexpr double PI {3.14159};
  constexpr double w1 = 2 * Wave::PI * Wave::Fo;  
  constexpr double w2 = 2 * Wave::PI * Wave::Fo2;  
}

void load_csv();
void generate_wave ();
