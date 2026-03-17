/*

  Utilize pass by reference to sort(via mergesort) a vector object of numbers. 

*/

#include "mergesort.h"


int main()
{

  NumberV data = {5, 2, 8, 1, 0};

  mergesort(data, decreasing);
  
  // display sorted result 
  display(data); 
}



