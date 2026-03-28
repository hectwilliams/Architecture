/**

Name : main.cpp

Operation: Allocates an int array on stack and feed radix_sort().

**/

#include "radix_sort.h"

int main() {
  
  Array7 data {TEST_INTEGERS};
  
  Array7 data_sorted = radix_sort(data, sort_done_cb);

  for (const auto & item: data_sorted) {
     std::cout << "[" << item << "] ";    
     if (&item + 1 == data_sorted.end())
       std::cout << '\n';
   }
    
}
