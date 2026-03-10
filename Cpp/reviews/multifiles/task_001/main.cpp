#include <iostream>
#include "rabbit.h"
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h> 

int main() {
  int x {};
  int y {};
  int* x_ptr = &x;
  int* y_ptr = &y;
  
  int h {};

  h = 10212;
  
  plog::init(plog::debug, "log.txt"); 

  moveup(x_ptr, y_ptr);
  
  PLOGD << "rabbit position "<< x << "," << y;
  
  moveup(x_ptr, y_ptr);
  
  PLOGD << "rabbit position "  << x << "," << y;
  
  movedown(x_ptr, y_ptr);
  
  PLOGD << "rabbit position " << x << "," << y;
  
  
  return 0; 
}
