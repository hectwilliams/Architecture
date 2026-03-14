#include <iostream>
#include <cmath>

const uint8_t NIBBLE {0b0110};
const uint8_t REG_BITS{3};
const uint8_t N_ROUNDS{30};
const int N_STATES{ 1 << REG_BITS };

void lsfr() {
  
  bool R1{};  
  bool R2{};  
  bool R3{};  
  bool xor1{};
  bool xor2{};
  uint8_t result{};
  int cyclic_counter{};
  int bit_index{};
  uint32_t histo[ N_STATES ]{};

  
  while (cyclic_counter < N_ROUNDS) {
    
    xor2 = (NIBBLE & ( 1 << bit_index ) ) != R3; // != is xor logic 
  
    R3 = R2;

    xor1 = (xor2 != R1);
   
    R2 = xor1;
    
    R1 = xor2; 
        
    result = result & (~result);
    
    result = (R1 << 2) | (R2 << 1) | (R3 << 0); 

//    std::cout << static_cast<unsigned>(result) << '\n';
  
    bit_index = (++bit_index)  % REG_BITS;
    
    cyclic_counter += static_cast<int>(bit_index == 0);
    
    histo[result] += 1;

  }
  
  // show histo on terminal 
  std::cout << "HISTOGRAM LSFR \n" << '\n';
  for ( int i = 0; i < N_STATES; i++) {
    std::cout << "[" << i << "]" << "|";
    for ( int k = 0; k < histo[i] ;  k++)
      std::cout << '*';
    std::cout << '\n';
  }

}
