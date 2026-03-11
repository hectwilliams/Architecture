#include <cassert> 
#include <iostream>
#include <limits> 
#include <cstdint> 

//constant INT64_MAX = std::numeric_limits<std::int64_t>::max();

constexpr bool  ovflow (std::int64_t base, std::int64_t result) {
  
  return result > INT64_MAX / base;

}

constexpr std::int64_t powint_safe(std::int64_t base, int exp ) {
  
  assert((exp >= 0) && "exp must be greater than or equal to exp" );
  
  bool neg_result {false};
 
  if (base < 0){
    neg_result=  exp & 1 ;
    base = -base;
  }
  
  std::int64_t result {1};
  
  while (exp >0 ) {
  
    if (exp & 1) {
      
      if (ovflow(result, base) )  {
        std::cerr << "overflowed";
        return INT64_MAX;
      }
      result *= base;

    }

    exp /=2;
    
    if (exp <=0) 
      break;

    if (ovflow(base,base) ) {

      std::cerr << "overflowed\n";
      return INT64_MAX;       

    }

    base *= base;
 
  }
  return result; 
  
}

int main (int argc, char * argv[]) {
  
  std::cout << "num elements: " << argc << '\n';
  assert(argc == 3 && "Two integers required for powint_safe");
  
  std::int64_t base {static_cast<std::int64_t>(std::stol(argv[1]))};
  int exp {std::stoi(argv[2])};

  std::int64_t result { powint_safe(base, exp)};
  
  std::cout << "pow(base, exp): " << result << '\n';
  return 0; 
}
